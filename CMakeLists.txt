cmake_minimum_required(VERSION 3.17)

project(Engine VERSION 1.0 LANGUAGES CXX)

add_subdirectory(external/minikit)
add_subdirectory(external/entityx)
add_subdirectory(modules)
add_subdirectory(sandbox)
