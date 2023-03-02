cmake_minimum_required (VERSION 2.8.12)

add_executable(editorl
    editor.cpp
    widgetctor.cpp
)
target_link_libraries(editorl nanogui ${NANOGUI_EXTRA_LIBS})
