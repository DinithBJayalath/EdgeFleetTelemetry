cmake_minimum_required(VERSION 3.20)
project(telemetry LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(telemetry STATIC 
    src/packet.cpp
    #src/segment.cpp
)
target_include_directories(telemetry PUBLIC include)

# add_executable(telequery apps/telequery.cpp)
# target_link_libraries(telequery PRIVATE telemetry)

add_executable(tele-smoke apps/packet_smoke.cpp)
target_link_libraries(tele-smoke PRIVATE telemetry)