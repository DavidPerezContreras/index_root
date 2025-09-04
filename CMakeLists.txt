cmake_minimum_required(VERSION 3.10)
project(index_root VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(index_root main.c)

# Enable AddressSanitizer only if supported
if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(index_root PRIVATE -fsanitize=address -g)
    target_link_options(index_root PRIVATE -fsanitize=address)
elseif(MSVC)
    message(STATUS "MSVC detected — enabling runtime checks")
    target_compile_options(index_root PRIVATE /Zi /Od /RTC1)
    target_link_options(index_root PRIVATE /DEBUG)
endif()

