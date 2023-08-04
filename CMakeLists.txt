cmake_minimum_required(VERSION 3.16)

project(NeuNetMath LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NeuNetMath
    pch.h
    Array.h
    Vector.h
    NeuNetMath.h
    main.cpp
)

target_precompile_headers(NeuNetMath PRIVATE pch.h)

install(TARGETS NeuNetMath
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
