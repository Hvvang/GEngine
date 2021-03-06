cmake_minimum_required(VERSION 3.17)

set(CoreHeaders
        include/GEngine/Core/GEngine.hpp
        include/GEngine/Core/GApplication.hpp
)

set(CoreSources
        src/Core/GEngine.cpp
)

set(MathHeaders
        include/GEngine/Math/GVector.hpp
        include/GEngine/Math/GRect.hpp
        include/GEngine/Math/GColor.hpp
)

set(MathSources
)

set(InputHeaders
        include/GEngine/Input/GInputManager.hpp
        include/GEngine/Input/GMouse.hpp
        include/GEngine/Input/GKeyboard.hpp
)

set(InputSources
        src/Input/GInputManager.cpp
)

set(EventHeaders
        include/GEngine/Event/GBaseHandler.hpp
        include/GEngine/Event/GEvent.hpp
        include/GEngine/Event/GEventSystem.hpp
        include/GEngine/Event/GHandler.hpp
)


add_library(GEngine.Framework STATIC
        ${MathHeaders}
        ${InputHeaders}
        ${EventHeaders}
        ${CoreHeaders}

        ${MathSources}
        ${InputSources}
        ${CoreSources}

)

if (APPLE)
    target_compile_options(GEngine.Framework PRIVATE "-fobjc-arc")
elseif (WIN32)
    # none
endif()

target_compile_features(GEngine.Framework PUBLIC cxx_std_17)

target_precompile_headers(GEngine.Framework
        PRIVATE
        <iostream>
        <vector>
        <set>
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