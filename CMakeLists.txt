cmake_minimum_required(VERSION 3.20)
project(telemetry LANGUAGE CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(telequery apps/telequery.cpp)