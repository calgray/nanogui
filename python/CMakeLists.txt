cmake_minimum_required (VERSION 2.8.12)

message(STATUS "NanoGUI: building with Python plugin")
# Detect Python

if (NOT ${NANOGUI_PYTHON_VERSION} EQUAL "")
  message(STATUS "NanoGUI: building with Python plugin, manual options set")
else()  
  list(APPEND CMAKE_MODULE_PATH "../ext/pybind11/tools")

  set(Python_ADDITIONAL_VERSIONS 3.11 3.10 3.9 3.8 3.7 3.6 3.5 3.4)
  find_package(PythonLibsNew ${NANOGUI_PYTHON_VERSION})

  message(STATUS "PYTHON_VALUES: " "${_PYTHON_VALUES}")

  if (NOT PYTHONLIBS_FOUND)
    # Python not found -- disable the plugin
    # set(NANOGUI_BUILD_PYTHON OFF CACHE BOOL "Build a Python plugin for NanoGUI?" FORCE)
    message(WARNING "NanoGUI: not building the Python plugin!")
  else()
    set(PYTHON_INCLUDE_DIRS ${PYTHON_INCLUDE_DIR})
  endif()    
endif()
# Try to autodetect Python (can be overridden manually if needed)

include_directories(${PYTHON_INCLUDE_DIRS})
message(STATUS "Python include dir: " ${PYTHON_INCLUDE_DIR})
message(STATUS "Python library: " ${PYTHON_LIBRARIES})

# Need PIC code in libnanogui even when compiled as a static library
set_target_properties(nanogui-obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

set(PYTHON_BACKEND_SOURCES "")
if (NANOGUI_WINDOW STREQUAL "GLFW")
  set_target_properties(glfw_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()  

if (NANOGUI_GL_BACKEND)
  set_target_properties(glfw_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)

  list(APPEND PYTHON_BACKEND_SOURCES 
       glcanvas.cpp 
       glutil.cpp)
endif()


include_directories("../ext/pybind11/include" ${PYTHON_INCLUDE_DIRS})
add_library(nanogui-python-obj OBJECT
  main.cpp
  constants_ui.cpp
  constants_entypo.cpp
  widget.cpp
  layout.cpp
  basics.cpp
  button.cpp
  tabs.cpp
  textbox.cpp
  theme.cpp
  
  formhelper.cpp
  misc.cpp

  nanovg.cpp
  python.h py_doc.h
  ${PYTHON_BACKEND_SOURCES}
  ${LIBNANOGUI_PYTHON_EXTRA_SOURCE})

add_library(nanogui-python SHARED $<TARGET_OBJECTS:nanogui-python-obj>)
set_property(TARGET nanogui-python-obj PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(nanogui-python PROPERTIES OUTPUT_NAME "nanogui")
target_link_libraries(nanogui-python nanogui ${NANOGUI_EXTRA_LIBS} ${Python_LIBRARIES})

# Quench warnings on GCC
if (CMAKE_COMPILER_IS_GNUCC)
  set_property(TARGET nanogui-python-obj APPEND PROPERTY COMPILE_OPTIONS "-Wno-unused-variable")
endif()

set_target_properties(nanogui-python PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/python)
# The prefix and extension are provided by FindPythonLibsNew.cmake
set_target_properties(nanogui-python PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}")
set_target_properties(nanogui-python PROPERTIES SUFFIX "${PYTHON_MODULE_EXTENSION}")

if (WIN32)
  # Set output path
  set_target_properties(nanogui-python PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE "Release/python")
  set_target_properties(nanogui-python PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG "Debug/python")
  set_target_properties(nanogui-python PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL "MinSizeRel/python")
  set_target_properties(nanogui-python PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "RelWithDebInfo/python")
  set_target_properties(nanogui-python PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "Release/python")
  set_target_properties(nanogui-python PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "Debug/python")
  set_target_properties(nanogui-python PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "MinSizeRel/python")
  set_target_properties(nanogui-python PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "RelWithDebInfo/python")

  # Link against the Python shared library
  target_link_libraries(nanogui-python ${PYTHON_LIBRARY})

  if (MSVC)
    # Optimize for size, /bigobj is needed for due to the heavy template metaprogramming in pybind11
    set_property(TARGET nanogui-python-obj APPEND PROPERTY COMPILE_OPTIONS
      "/bigobj" "$<$<CONFIG:Release>:/Os>" "$<$<CONFIG:MinSizeRel>:/Os>"
      "$<$<CONFIG:RelWithDebInfo>:/Os>")
  endif()
elseif(UNIX)
  # Optimize for size
  if (U_CMAKE_BUILD_TYPE MATCHES REL)
    set_property(TARGET nanogui-python-obj APPEND PROPERTY COMPILE_OPTIONS "-Os")
  endif()

  # Strip unnecessary sections of the binary on Linux/Mac OS
  if(APPLE)
    set_target_properties(nanogui-python PROPERTIES MACOSX_RPATH ".")
    set_target_properties(nanogui-python PROPERTIES LINK_FLAGS "-undefined dynamic_lookup ")

    if (NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEB)
      add_custom_command(TARGET nanogui-python POST_BUILD COMMAND strip -u -r $<TARGET_FILE:nanogui-python>)
    endif()
  else()
    if (NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEB)
      add_custom_command(TARGET nanogui-python POST_BUILD COMMAND strip $<TARGET_FILE:nanogui-python>)
    endif()
  endif()
endif()

if (NANOGUI_INSTALL)
  install(TARGETS nanogui-python
          LIBRARY DESTINATION lib
          ARCHIVE DESTINATION lib)
endif()