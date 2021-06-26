cmake_minimum_required(VERSION 3.17)

set(MathHeaders
        include/GEngine/Math/Vector.hpp
        include/GEngine/Math/Rect.hpp
)

set(MathSources
)

set(InputHeaders
        include/GEngine/Input/InputManager.hpp
        include/GEngine/Input/Mouse.hpp
        include/GEngine/Input/Keyboard.hpp
)

set(InputSources
        src/Input/InputManager.cpp
)


add_library(GEngine.Framework STATIC
        ${MathHeaders}
        ${InputHeaders}

        ${MathSources}
        ${InputSources}

)

if (APPLE)
    target_compile_options(GEngine.Framework PRIVATE "-fobjc-arc")
elseif (WIN32)
    # none
endif()

target_compile_features(GEngine.Framework PUBLIC cxx_std_17)

target_precompile_headers(GEngine.Framework
        PRIVATE
        <cstdint>
        <memory>
        <string>
        <type_traits>
        <vector>
)

target_include_directories(GEngine.Framework
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src
)

target_link_libraries(GEngine.Framework PUBLIC MiniKit::MiniKit)

add_library(GEngine::GEngine ALIAS GEngine.Framework)