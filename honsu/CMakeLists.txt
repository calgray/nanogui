cmake_minimum_required (VERSION 2.8.12)

include_directories("../ext/cpp-httplib")
set(HONSU_OPENSSL_LIBS "")

if(MSVC)
include_directories("c:/Program Files/OpenSSL-Win64/include")
link_directories("c:/Program Files/OpenSSL-Win64/lib")

list(APPEND HONSU_OPENSSL_LIBS libssl libcrypto)
elseif (APPLE)  
include_directories("/usr/local/opt/openssl/include")
link_directories("/usr/local/opt/openssl/lib")
list(APPEND HONSU_OPENSSL_LIBS ssl crypto)
else ()
find_package(OpenSSL REQUIRED)

message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

list(APPEND HONSU_OPENSSL_LIBS ${OPENSSL_LIBRARIES})
endif()
add_executable(honsu
    honsu_main.cpp
)

if (MSVC)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()
target_link_libraries(honsu nanogui ${NANOGUI_EXTRA_LIBS} ${HONSU_OPENSSL_LIBS})
set_property(TARGET honsu PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})