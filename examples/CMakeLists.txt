# Build example application if desired
if(NANOGUI_BUILD_EDITOR)
  add_executable(editorl
    editor/editor.cpp editor/widgetctor.cpp)
  target_link_libraries(editorl PUBLIC nanogui)

  file(COPY ../resources/icons DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

if(NANOGUI_BUILD_HONSU)
  add_executable(honsu
  honsu/honsu_main.cpp
  )
  target_include_directories(honsu PUBLIC ext/cpp-httplib)

  find_package(OpenSSL REQUIRED)
  target_link_libraries(honsu PUBLIC OpenSSL::SSL OpenSSL::Crypto)

  if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
  endif()
  target_link_libraries(honsu PUBLIC nanogui ${HONSU_OPENSSL_LIBS})
  set_property(TARGET honsu PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  # file(COPY resources/icons DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
  file(COPY resources/ca-bundle.crt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

if(NANOGUI_BUILD_EXAMPLE)
  add_executable(example1             example1.cpp)
  add_executable(example2             example2.cpp)
  add_executable(example3             example3.cpp)
  add_executable(example4             example4.cpp)
  add_executable(example_icons        example_icons.cpp)
  target_link_libraries(example1      nanogui)
  target_link_libraries(example2      nanogui)
  target_link_libraries(example3      nanogui)
  target_link_libraries(example4      nanogui)
  target_link_libraries(example_icons nanogui)

  # Copy icons for example application
  file(COPY ../resources/icons DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()
