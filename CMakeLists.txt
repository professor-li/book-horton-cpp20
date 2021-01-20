# To build a program:
# $ cmake -S . -B build
# $ cmake --build build -t ex1_01

cmake_minimum_required(VERSION 3.17)
project(book_horton_cpp20)

# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(PREBUILT_MODULE_PATH "${CMAKE_BINARY_DIR}/modules")

function(add_module name)
    file(MAKE_DIRECTORY "${PREBUILT_MODULE_PATH}")
    add_custom_target(${name}.pcm
            COMMAND
            ${CMAKE_CXX_COMPILER}
            -std=c++2a
            -fmodules
            -c
            "${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}"
            -Xclang
            -emit-module-interface
            -o "${PREBUILT_MODULE_PATH}/${name}.pcm"
            )
endfunction()

add_compile_options(-std=c++2a)
add_compile_options(-fmodules)
add_compile_options(-fimplicit-modules)
add_compile_options(-fbuiltin-module-map)
add_compile_options(-fimplicit-module-maps)

add_executable(ex1_01 "Examples/Modules/Chapter 01/Ex1_01.cpp")

add_subdirectory("Examples/NoModules/Appendix A/ExA_01")
add_subdirectory("Examples/NoModules/Appendix A/ExA_02")
