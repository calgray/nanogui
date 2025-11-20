cmake_minimum_required(VERSION 3.5)

if (POLICY CMP0048)
  # cmake warns if loaded from a min-3.0-required parent dir, so silence the warning:
  cmake_policy(SET CMP0048 NEW)
endif()
if (POLICY CMP0058)
  cmake_policy(SET CMP0058 NEW)
endif()
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

project("NanoGUI")

# ===== Options ===========

option(NANOGUI_BUILD_EXAMPLE "Build NanoGUI example application? (requires glfw)" ON)
option(NANOGUI_BUILD_EDITOR  "Build NanoGUI editor application?" ON)
option(NANOGUI_BUILD_HONSU   "Build NanoGUI timetracker application?" OFF)
option(NANOGUI_BUILD_SHARED  "Build NanoGUI as a shared library?" ON)
option(NANOGUI_BUILD_PYTHON  "Build a Python plugin for NanoGUI?" OFF)
option(NANOGUI_INSTALL       "Install NanoGUI on `make install`?" ON)
option(NANOGUI_VULKAN_NOSDK  "Build vulkan with headers from ext folder. Travis-ci builds only" OFF)
option(NANOGUI_NANOVG_NOSDK  "Build nanovg with headers from ext folder" True)

set(NANOGUI_PYTHON_VERSION "" CACHE STRING "Python version to use for compiling the Python plugin")

# Graphics backend option

set(NANOGUI_GRAPHICS_BACKEND_VALUES "VULKAN" "GL" "DX11" "DX12")
set(NANOGUI_GRAPHICS_BACKEND "VULKAN" CACHE STRING "Select a graphics backend")
set_property(CACHE NANOGUI_GRAPHICS_BACKEND PROPERTY STRINGS ${NANOGUI_GRAPHICS_BACKEND_VALUES})
if(NANOGUI_GRAPHICS_BACKEND STREQUAL "VULKAN")
  set(NANOGUI_VULKAN_BACKEND ON)
  add_definitions(-DNANOGUI_VULKAN_BACKEND=1)
else()
  set(NANOGUI_VULKAN_BACKEND OFF)
endif()
if(NANOGUI_GRAPHICS_BACKEND STREQUAL "GL")
  set(NANOGUI_OPENGL_BACKEND ON)
  set(NANOGUI_USE_GLAD ON)
  add_definitions(-DNANOGUI_OPENGL_BACKEND=1)
else()
  set(NANOGUI_OPENGL_BACKEND OFF)
endif()
if(NANOGUI_GRAPHICS_BACKEND STREQUAL "DX11")
  set(NANOGUI_DX11_BACKEND ON)
  add_definitions(-DNANOGUI_DX11_BACKEND=1)
else()
  set(NANOGUI_DX11_BACKEND OFF)
endif()
if(NANOGUI_GRAPHICS_BACKEND STREQUAL "DX12")
  set(NANOGUI_DX12_BACKEND ON)
  add_definitions(-DNANOGUI_DX12_BACKEND=1)
else()
  set(NANOGUI_DX12_BACKEND OFF)
endif()
# check for at least 1 backend
if (NANOGUI_DX11_BACKEND OR NANOGUI_OPENGL_BACKEND OR NANOGUI_DX12_BACKEND OR NANOGUI_VULKAN_BACKEND)
else()
  message(FATAL_ERROR "No backends selected! "
     "Select one of backends: opengl(NANOGUI_OPENGL_BACKEND), dx11(NANOGUI_DX11_BACKEND), dx12(NANOGUI_DX12_BACKEND), vulkan(NANOGUI_VULKAN_BACKEND)"
  )
endif()

# Display backend option

set(NANOGUI_DISPLAY_BACKEND_VALUES "GLFW" "SDL2" "BGFX")
set(NANOGUI_DISPLAY_BACKEND "GLFW" CACHE STRING "Select a display backend")
set_property(CACHE NANOGUI_DISPLAY_BACKEND PROPERTY STRINGS ${NANOGUI_DISPLAY_BACKEND_VALUES})
if(NANOGUI_DISPLAY_BACKEND STREQUAL "GLFW")
  set(NANOGUI_GLFW_BACKEND ON)
else()
  set(NANOGUI_GLFW_BACKEND OFF)
endif()
if(NANOGUI_DISPLAY_BACKEND STREQUAL "SDL2")
  set(NANOGUI_SDL2_BACKEND ON)
  message(FATAL_ERROR "SDL2 not yet supported")
else()
  set(NANOGUI_SDL2_BACKEND OFF)
endif()
if(NANOGUI_DISPLAY_BACKEND STREQUAL "BGFX")
  set(NANOGUI_BGFX_BACKEND ON)
  message(FATAL_ERROR "BGFX not yet supported")
else()
  set(NANOGUI_BGFX_BACKEND OFF)
endif()

# ========= Compiler Settings ============

if(APPLE AND NANOGUI_BUILD_SHARED)
  set(CMAKE_MACOSX_RPATH ON)
endif()

include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()
string(TOUPPER "${CMAKE_BUILD_TYPE}" U_CMAKE_BUILD_TYPE)

macro(CHECK_CXX_COMPILER_AND_LINKER_FLAGS _RESULT _CXX_FLAGS _LINKER_FLAGS)
  set(CMAKE_REQUIRED_FLAGS ${_CXX_FLAGS})
  set(CMAKE_REQUIRED_LIBRARIES ${_LINKER_FLAGS})
  set(CMAKE_REQUIRED_QUIET TRUE)
  check_cxx_source_runs("int main(int argc, char **argv) { return 0; }" ${_RESULT})
  set(CMAKE_REQUIRED_FLAGS "")
  set(CMAKE_REQUIRED_LIBRARIES "")
endmacro()

if (MSVC)
  # Disable annoying MSVC warnings (all targets)
  add_definitions("/D_CRT_SECURE_NO_WARNINGS")

  # Parallel build on MSVC (all targets)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

  if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")

  endif()
endif()

# Compile with compiler warnings turned on
if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /W4505")
  endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "^(GNU|Clang|Intel)$")
  CHECK_CXX_COMPILER_FLAG("-std=c++14" HAS_CPP14_FLAG)
  CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CPP11_FLAG)

  if (HAS_CPP14_FLAG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
  elseif (HAS_CPP11_FLAG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  else()
    message(FATAL_ERROR "Unsupported compiler -- pybind11 requires C++11 support!")
  endif()
endif()

# Various optimizations for shared library release builds
if (NANOGUI_BUILD_SHARED)
  if (U_CMAKE_BUILD_TYPE MATCHES REL AND CMAKE_CXX_COMPILER_ID MATCHES "^(GNU|Clang)$")
    # Set the default symbol visibility to hidden
    if (NOT CMAKE_CXX_FLAGS MATCHES "-fvisibility")
      set(CMAKE_CXX_FLAGS "-fvisibility=hidden ${CMAKE_CXX_FLAGS}")
    endif()

    # Enable link time optimization
    if (NOT CMAKE_CXX_FLAGS MATCHES "-flto")
      if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(LTO_CXX_FLAGS "-flto=thin")
        set(LTO_LINKER_FLAGS "-flto=thin")
        if (NOT APPLE AND U_CMAKE_BUILD_TYPE MATCHES MINSIZEREL)
            # Clang Gold plugin does not support -Os
            set(LTO_CXX_FLAGS "${LTO_CXX_FLAGS} -O3")
        endif()
      else()
        set(LTO_CXX_FLAGS "-flto -fno-fat-lto-objects")
        set(LTO_LINKER_FLAGS "-flto")
      endif()

      CHECK_CXX_COMPILER_AND_LINKER_FLAGS(HAS_LTO ${LTO_CXX_FLAGS} ${LTO_LINKER_FLAGS})

      if (HAS_LTO)
        message(STATUS "NanoGUI: LTO support enabled.")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LTO_LINKER_FLAGS}")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LTO_LINKER_FLAGS}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LTO_CXX_FLAGS}")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LTO_CXX_FLAGS}")
      else()
        message(STATUS "NanoGUI: LTO not supported by the compiler.")
      endif()
    endif()
  elseif(MSVC)
    set(Configurations RELEASE RELWITHDEBINFO MINSIZEREL)
    set(LinkTypes EXE SHARED MODULE STATIC)
    foreach(Configuration ${Configurations})
      set("CMAKE_CXX_FLAGS_${Configuration}" "${CMAKE_CXX_FLAGS_${Configuration}} /GL")
      foreach(LinkType ${LinkTypes})
        set("CMAKE_${LinkType}_LINKER_FLAGS_${Configuration}" "${CMAKE_${LinkType}_LINKER_FLAGS_${Configuration}} /LTCG")
      endforeach()
    endforeach()
    message(STATUS "NanoGUI: LTO support enabled.")
  endif()
endif()

# Always use libc++ on Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  EXECUTE_PROCESS( COMMAND ${CMAKE_CXX_COMPILER} --version OUTPUT_VARIABLE clang_full_version_string )
  string (REGEX REPLACE ".*clang version ([0-9]+\\.[0-9]+).*" "\\1" CLANG_VERSION_STRING ${clang_full_version_string})
  if (CLANG_VERSION_STRING VERSION_GREATER 3.7)
    message(STATUS "NanoGUI: using libc++ because clang greater 3.7")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  else ()
    CHECK_CXX_COMPILER_AND_LINKER_FLAGS(HAS_LIBCPP "-stdlib=libc++" "-stdlib=libc++")
    if (HAS_LIBCPP)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
      set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
      CHECK_CXX_COMPILER_AND_LINKER_FLAGS(HAS_LIBCPPABI "-stdlib=libc++" "-stdlib=libc++ -lc++abi")
      if(HAS_LIBCPPABI)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lc++abi")
        message(STATUS "NanoGUI: using libc++ and libc++abi.")
      else()
        message(STATUS "NanoGUI: using libc++.")
      endif()
    else()
      message(STATUS "NanoGUI: NOT using libc++.")
    endif()
  endif()
endif()


# ===== Project =============

# Set library type
if (NANOGUI_BUILD_SHARED)
  set(NANOGUI_LIBRARY_TYPE "SHARED")
else()
  set(NANOGUI_LIBRARY_TYPE "STATIC")
endif()

# Compile main NanoGUI library
add_library(nanogui ${NANOGUI_LIBRARY_TYPE})
target_sources(nanogui PRIVATE
  src/common.cpp
  src/keyboard.cpp
  src/widget.cpp
  src/theme.cpp
  src/layout.cpp
  src/screen.cpp
  src/label.cpp
  src/window.cpp
  src/listbox.cpp
  src/popup.cpp
  src/meter.cpp
  src/checkbox.cpp
  src/spinner.cpp
  src/separator.cpp
  src/color.cpp
  src/switchbox.cpp
  src/tolerancebar.cpp
  src/dropdownbox.cpp
  src/button.cpp
  src/popupbutton.cpp
  src/combobox.cpp
  src/progressbar.cpp
  src/slider.cpp
  src/dial.cpp
  src/messagedialog.cpp
  src/textbox.cpp
  src/imagepanel.cpp
  src/imageview.cpp
  src/themebuilder.cpp
  src/treeview.cpp
  src/treeviewitem.cpp
  src/vscrollpanel.cpp
  src/colorwheel.cpp
  src/colorpicker.cpp
  src/picflow.cpp
  src/graph.cpp
  src/textarea.cpp
  src/stackedwidget.cpp
  src/tabheader.cpp
  src/tabwidget.cpp
  src/searchbox.cpp
  src/contextmenu.cpp
  src/editworkspace.cpp
  src/editproperties.cpp
  src/widgetsfactory.cpp
  src/scrollbar.cpp
  src/widgetsfactory.cpp
  src/foldout.cpp
  src/windowmenu.cpp
  src/ledmatrix.cpp
  src/table.cpp
  src/perfchart.cpp
  src/toolbutton.cpp
  src/splitter.cpp
)
if (NANOGUI_OPENGL_BACKEND OR NANOGUI_VULKAN_BACKEND AND NANOGUI_GLFW_NOSDK)
  target_sources(nanogui PRIVATE $<TARGET_OBJECTS:glfw_objects>)
endif()
target_include_directories(nanogui PUBLIC include)

# Shared library mode: add dllimport/dllexport flags to all symbols
if (NANOGUI_BUILD_SHARED)
  target_compile_definitions(nanogui PRIVATE -DNANOGUI_SHARED -DNVG_SHARED -DGLAD_GLAPI_EXPORT)
endif()

# Build and include GLAD
if (NANOGUI_OPENGL_BACKEND AND NANOGUI_USE_GLAD)
  target_sources(nanogui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/src/glad.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/include/glad/glad.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/include/KHR/khrplatform.h
  )
  if (MSVC)
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/src/glad.c"
      PROPERTIES COMPILE_FLAGS "/wd4055 ")
  endif()
  include_directories(ext/glad/include)
  target_compile_definitions(nanogui PRIVATE -DNANOGUI_GLAD)
  target_include_directories(nanogui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/include)
endif()

# Eigen3
find_package(Eigen3 REQUIRED)
target_link_libraries(nanogui PUBLIC Eigen3::Eigen)

# NanoVG
if (NANOGUI_NANOVG_NOSDK)
  set(NANOVG_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
  add_subdirectory(ext/nanovg)
  target_include_directories(nanogui PUBLIC ext/nanovg/src)
  target_link_libraries(nanogui PUBLIC nanovg)
  # Quench warnings while compiling NanoVG
  if (CMAKE_COMPILER_IS_GNUCC)
    set_source_files_properties(ext/nanovg/src/nanovg.c PROPERTIES COMPILE_FLAGS -Wno-unused-result)
  elseif(MSVC)
    set_source_files_properties(ext/nanovg/src/nanovg.c PROPERTIES COMPILE_FLAGS "/wd4005 /wd4456 /wd4457")
  endif()
else()
  find_library(NanoVG REQUIRED)
  target_link_libraries(nanovg PUBLIC NanoVG::NanoVG)
endif()

# NanoVG extensions
if (NANOGUI_OPENGL_BACKEND)
  target_compile_definitions(nanogui PRIVATE -DNANOVG_GL3)
endif()
if(NANOGUI_VULKAN_BACKEND)
  target_compile_definitions(nanogui PRIVATE -DNANOVG_VULKAN)
endif()
if(NANOGUI_DX11_BACKEND)
  target_compile_definitions(nanogui PRIVATE -DNANOVG_D3D11)
endif()
if(NANOGUI_DX11_BACKEND)
  target_compile_definitions(nanogui PRIVATE -DNANOVG_D3D12)
endif()

# Required core libraries on various platforms
if (NANOGUI_OPENGL_BACKEND)
  find_package(OpenGL REQUIRED)
  target_link_libraries(nanogui PUBLIC OpenGL::OpenGL)
  if (WIN32)
    target_link_libraries(nanogui PUBLIC opengl32)
  elseif (APPLE)
    find_library(cocoa_library Cocoa)
    find_library(opengl_library OpenGL)
    find_library(corevideo_library CoreVideo)
    find_library(iokit_library IOKit)
    target_link_libraries(nanogui PUBLIC ${cocoa_library} ${opengl_library} ${corevideo_library} ${iokit_library})
    target_sources(nanogui PRIVATE src/darwin.mm)
  elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR ${CMAKE_SYSTEM_NAME} MATCHES "BSD")
    target_link_libraries(nanogui PUBLIC Xxf86vm Xrandr Xinerama Xcursor Xi X11 pthread)
    if (NOT ${CMAKE_SYSTEM_NAME}_NAME MATCHES "OpenBSD")
      target_link_libraries(nanogui PUBLIC rt)
    endif()
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
      target_link_libraries(nanogui PUBLIC dl)
    endif()
  endif()
elseif (NANOGUI_VULKAN_BACKEND)
  if (NANOGUI_VULKAN_NOSDK)
    set(Vulkan_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext/vulkan/Include")
    set(Vulkan_LIBRARY "${CMAKE_CURRENT_BINARY_DIR}/blob/vulkan-1.lib")
  else()
    find_package(Vulkan REQUIRED)
  endif()
  target_link_libraries(nanogui PUBLIC Vulkan::Vulkan)
  if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR ${CMAKE_SYSTEM_NAME} MATCHES "BSD")
    target_link_libraries(nanogui PUBLIC Xxf86vm Xrandr Xinerama Xcursor Xi X11 pthread)
    if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
      target_link_libraries(nanogui PUBLIC rt)
    endif()
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
      target_link_libraries(nanogui PUBLIC dl)
    endif()
  endif()
elseif (NANOGUI_DX11_BACKEND)
  target_link_libraries(nanogui PUBLIC d3d11 dxguid)
elseif (NANOGUI_DX12_BACKEND)
  target_link_libraries(nanogui PUBLIC dxgi)
endif()

include_directories(include ${CMAKE_CURRENT_BINARY_DIR})

## Presentation backends

set (NANOGUI_GLFW_NOSDK OFF)
if (NANOGUI_OPENGL_BACKEND OR NANOGUI_VULKAN_BACKEND)
  if(NANOGUI_GLFW_NOSDK)
    # Build GLFW from source
    if (NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ext/glfw/src")
      message(FATAL_ERROR "The NanoGUI dependency repositories (GLFW, etc.) are missing! "
        "You probably did not clone the project with --recursive. It is possible to recover "
        "by calling \"git submodule update --init --recursive\"")
    endif()

    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL " " FORCE)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL " " FORCE)
    set(GLFW_BUILD_INSTALL OFF CACHE BOOL " " FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL " " FORCE)
    set(GLFW_USE_CHDIR OFF CACHE BOOL " " FORCE)
    set(BUILD_SHARED_LIBS ${NANOGUI_BUILD_SHARED} CACHE BOOL " " FORCE)

    add_subdirectory(ext/glfw)
    set_target_properties(glfw
      PROPERTIES
        EXCLUDE_FROM_ALL 1
        EXCLUDE_FROM_DEFAULT_BUILD 1)
    include_directories(ext/glfw/include)
  else()
    find_package(glfw3 REQUIRED)
    set_target_properties(glfw PROPERTIES EXCLUDE_FROM_ALL 1 EXCLUDE_FROM_DEFAULT_BUILD 1)
    target_link_libraries(nanogui PUBLIC glfw)
  endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Quench annoying deprecation warnings when compiling GLFW on OSX
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated-declarations")
endif()

# ======= NanoGUI extensions ==========

# Run simple cmake converter to put font files into the data segment

# Glob up resource files
file(GLOB resources "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.ttf")

# Concatenate resource files into a comma separated string
string (REGEX REPLACE "([^\\]|^);" "\\1," resources_string "${resources}")
string (REGEX REPLACE "[\\](.)" "\\1" resources_string "${resources_string}")

# Create command line for running bin2c cmake script
set(bin2c_cmdline
  -DOUTPUT_C=nanogui_resources.cpp
  -DOUTPUT_H=nanogui_resources.h
  "-DINPUT_FILES=${resources_string}"
  -P "${CMAKE_CURRENT_SOURCE_DIR}/resources/bin2c.cmake")

# Run bin2c on resource files
add_custom_command(
  OUTPUT nanogui_resources.cpp nanogui_resources.h
  COMMAND ${CMAKE_COMMAND} ARGS ${bin2c_cmdline}
  DEPENDS ${resources}
  COMMENT "Running bin2c"
  PRE_BUILD VERBATIM)

# Needed for generated files
include_directories(${CMAKE_CURRENT_BINARY_DIR})

if (APPLE)
  # Use automatic reference counting for Objective-C portions
  add_compile_options(-fobjc-arc)
endif()

add_definitions(${NANOGUI_EXTRA_DEFS})

if (NANOGUI_OPENGL_BACKEND)
  target_sources(nanogui PRIVATE
    src/opengl/glcanvas.cpp
    src/opengl/glutil.cpp
    src/opengl/common_glfw_gl.cpp
    src/opengl/perfchart.cpp
  )
elseif (NANOGUI_VULKAN_BACKEND)
target_sources(nanogui PRIVATE
    include/nanogui/nanovg_vk.h
    src/vulkan/vulkan_util.h
    src/vulkan/common_glfw_vk.cpp
    src/vulkan/shaders_vk.cpp
    src/vulkan/gpu_vk.cpp
  )
elseif (NANOGUI_DX11_BACKEND)
  target_sources(nanogui PRIVATE
    src/dx11/common_dx11.cpp
    src/dx11/gpu_dx11.cpp
  )
elseif (NANOGUI_DX12_BACKEND)
  target_sources(nanogui PRIVATE
    src/dx12/common_dx12.cpp
    src/dx12/gpu_dx12.cpp

    src/dx12/nanovg_d3d12.cpp
    src/dx12/nanovg_dx12_utils.cpp
    src/dx12/nanovg_dx12_render.cpp
    src/dx12/nanovg_dx12_alloc.cpp
    src/dx12/nanovg_dx12_res.cpp

    src/dx12/dx12_dyn_imports.h src/dx12/dx12_dyn_imports.cpp
    src/dx12/dx12_subset.h src/dx12/dx12_subset.cpp
    src/dx12/dx12_subset_resource.h src/dx12/dx12_subset_resource.cpp
    src/dx12/dx12_subset_dheap.h src/dx12/dx12_subset_dheap.cpp
    src/dx12/dx12_subset_pso_lib.cpp
  )
endif()

# Transpiled resources
target_sources(nanogui PRIVATE nanogui_resources.cpp)

if (NANOGUI_BUILD_SHARED)
  set_property(TARGET nanogui PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()

# Compile/link flags for NanoGUI
set_property(TARGET nanogui APPEND PROPERTY COMPILE_DEFINITIONS "NANOGUI_BUILD;NVG_BUILD")

if (NANOGUI_USE_GLAD AND NANOGUI_BUILD_SHARED)
  set_property(TARGET nanogui APPEND PROPERTY COMPILE_DEFINITIONS
    "GLAD_GLAPI_EXPORT;GLAD_GLAPI_EXPORT_BUILD")
endif()

if (NANOGUI_INSTALL)
  install(TARGETS nanogui
          LIBRARY DESTINATION lib
          ARCHIVE DESTINATION lib)

  install(DIRECTORY include/nanogui DESTINATION include
          FILES_MATCHING PATTERN "*.h")
endif()

if (NANOGUI_BUILD_SHARED AND NANOGUI_OPENGL_BACKEND)
  # When GLFW is merged into the NanoGUI library, this flag must be specified
  set_property(TARGET nanogui APPEND PROPERTY COMPILE_DEFINITIONS "_GLFW_BUILD_DLL;NVG_SHARED")
endif()

if (NANOGUI_BUILD_SHARED AND NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEB)
  # Platform-specific strip flags for reducing the library size.
  if (APPLE)
    # Strip .dylib library on OSX
    add_custom_command(TARGET nanogui POST_BUILD COMMAND strip -u -r "$<TARGET_FILE_DIR:nanogui>/$<TARGET_FILE_NAME:nanogui>")
  elseif(UNIX)
    # Strip .so library on Linux
    add_custom_command(TARGET nanogui POST_BUILD COMMAND strip "$<TARGET_FILE_DIR:nanogui>/$<TARGET_FILE_NAME:nanogui>")
  endif()
endif()

# Optional Python support
add_subdirectory(python)

# Optional example applications
add_subdirectory(examples)

# ========== export definitions =============

get_directory_property(NANOGUI_HAS_PARENT PARENT_DIRECTORY)
if(NANOGUI_HAS_PARENT)
else()
  # Create documentation for python plugin (optional target for developers)

  string(REPLACE " " ";" MKDOC_CXX_FLAGS_LIST ${CMAKE_CXX_FLAGS})
  get_property(MKDOC_INCLUDE_DIRECTORIES DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
  get_property(MKDOC_COMPILE_DEFINITIONS DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY COMPILE_DEFINITIONS)

  foreach (value ${MKDOC_INCLUDE_DIRECTORIES})
    list(APPEND MKDOC_CXX_FLAGS_LIST -I${value})
  endforeach()

  # Make sure platform specific code gets kept in py_doc.h (specifically __doc_nanogui_chdir_to_bundle_parent)
  list(APPEND MKDOC_COMPILE_DEFINITIONS "DOXYGEN_DOCUMENTATION_BUILD")
  foreach (value ${MKDOC_COMPILE_DEFINITIONS})
    list(APPEND MKDOC_CXX_FLAGS_LIST -D${value})
  endforeach()

  add_custom_target(mkdoc COMMAND
    python3 ${PROJECT_SOURCE_DIR}/docs/mkdoc_rst.py
      ${MKDOC_CXX_FLAGS_LIST}
      ${PROJECT_SOURCE_DIR}/include/nanogui/*.h
      > ${CMAKE_CURRENT_SOURCE_DIR}/python/py_doc.h)

endif()

# vim: set et ts=2 sw=2 ft=cmake nospell:
