cmake_minimum_required(VERSION 3.17)

set(CoreHeaders
        include/GEngine/Core/GEngine.hpp
        include/GEngine/Core/GApplication.hpp
        include/GEngine/Core/GWindow.hpp include/GEngine/Core/GObject.hpp)

set(CoreSources
        src/Core/GEngine.cpp
        src/Core/GWindow.cpp)

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

set(ViewHeaders
        include/GEngine/View/GViewport.hpp
        include/GEngine/View/GCamera.hpp
)

set(ViewSources
        src/View/GViewport.cpp
        src/View/GCamera.cpp
)

set(GraphicsHeaders
        include/GEngine/Graphics/GRenderer.hpp
        include/GEngine/Graphics/GDrawable.hpp include/GEngine/Graphics/GSprite.hpp include/GEngine/Graphics/GTransformable.hpp include/GEngine/Graphics/GTransform.hpp)

add_library(GEngine.Framework STATIC
        ${CoreHeaders}
        ${MathHeaders}
        ${InputHeaders}
        ${EventHeaders}
        ${ViewHeaders}
        ${GraphicsHeaders}

        ${CoreSources}
        ${MathSources}
        ${InputSources}
        ${ViewSources}

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

target_link_libraries(GEngine.Framework PUBLIC
        MiniKit::MiniKit
        entityx
)

add_library(GEngine::GEngine ALIAS GEngine.Framework)