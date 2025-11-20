

if (NANOGUI_BUILD_PYTHON)
  message(STATUS "NanoGUI: building with Python plugin")

  # Required libraries, flags, and include files for compiling and linking against nanogui (all targets)
  set(NANOGUI_EXTRA_LIBS "")
  set(NANOGUI_EXTRA_DEFS "")
  set(NANOGUI_EXTRA_INCS "")

  # Detect Python Packages
  # Try to autodetect Python (can be overridden manually if needed)
  set(Python_ADDITIONAL_VERSIONS 3.12 3.11 3.10 3.9 3.8 3.7 3.6 3.5 3.4)
  find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
  if (NOT Python3_FOUND)
    # Python not found -- disable the plugin
    # set(NANOGUI_BUILD_PYTHON OFF CACHE BOOL "Build a Python plugin for NanoGUI?" FORCE)
    message(FATAL "NanoGUI: not building the Python plugin!")
  else()
    message(STATUS "Found Python3 ${Python3_INCLUDE_DIR}")
    message(STATUS "Python include dir: " ${Python3_INCLUDE_DIRS})
    message(STATUS "Python library : " ${Python3_LIBRARIES})
  endif()
  find_package(pybind11 REQUIRED HINTS "ext/pybind11/include")

  # Configure
  add_library(nanogui-python-obj OBJECT)
  target_link_libraries(nanogui-python-obj PUBLIC Python3::Python)
  target_link_libraries(nanogui-python-obj PUBLIC pybind11::pybind11)
  target_link_libraries(nanogui-python-obj PUBLIC nanovg)

  # Python support: add NANOGUI_PYTHON flag to all targets
  target_compile_definitions(nanogui-python-obj PUBLIC -DNANOGUI_PYTHON)

  # Sources
  target_sources(nanogui-python-obj PUBLIC
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
    python.h
    py_doc.h)

  if (APPLE OR CMAKE_SYSTEM MATCHES "Linux")
    # Include coroutine support for running the mainloop in detached mode
    add_definitions(-DCORO_SJLJ)
    include_directories(../ext/coro)
    target_sources(nanogui-python-obj PRIVATE ../ext/coro/coro.c)
  endif()

  # Need PIC code in libnanogui even when compiled as a static library
  set_target_properties(nanogui-python-obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

  if (NANOGUI_VULKAN_BACKEND AND NANOGUI_GLFW_NOSDK)
    set_target_properties(glfw_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)
  endif()

  if (NANOGUI_OPENGL_BACKEND AND NANOGUI_GLFW_NOSDK)
    set_target_properties(glfw_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)

    target_sources(nanogui-python-obj PUBLIC
        glcanvas.cpp
        glutil.cpp)
  endif()

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
endif()
