cmake_minimum_required(VERSION 3.22.1)

project(piperunity)

add_library(
    piperunity
    SHARED
    piperunity.cpp
)

find_library(
    log-lib
    log
)

target_link_libraries(
    piperunity
    ${log-lib}
)

target_link_options(
    piperunity
    PRIVATE
    "-Wl,-z,max-page-size=16384"
)
