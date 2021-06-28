cmake_minimum_required(VERSION 3.17)

project(Engine VERSION 1.0 LANGUAGES CXX OBJCXX)

add_definitions(-DDEBUG)

add_executable(sandbox
        main.cpp
)

if (APPLE)
    target_compile_options(sandbox PRIVATE "-fobjc-arc")
elseif (WIN32)
    # none
endif()

target_link_libraries(sandbox
        PRIVATE
        MiniKit::MiniKit
        GEngine::GEngine
)