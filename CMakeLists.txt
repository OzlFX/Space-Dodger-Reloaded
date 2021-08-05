cmake_minimum_required(VERSION 3.19)
project(KeplerEngine)

#The Project Version Number
SET(Kepler_Engine_VERSION_MAJOR 1)
SET(Kepler_Engine_VERSION_MINOR 0)

include_directories(
	src
	Dependencies/glm
	Dependencies/SDL2-2.0.14/include
	Dependencies/SDL2_mixer-2.0.4/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/Dependencies/lib/x86/SDL2.lib
)

#Add the libraries to the project
add_library(KeplerEngine SHARED
	src/KeplerEngine/Core/Core.h
	src/KeplerEngine/Core/Application.h
	src/KeplerEngine/Core/Application.cpp
	src/KeplerEngine/Core/EntryPoint.h
	src/KeplerEngine/Window/Window.h
	src/KeplerEngine/Window/Window.cpp
	src/KeplerEngine/RenderSystem/Renderer.h
	src/KeplerEngine/RenderSystem/Renderer.cpp
	src/KeplerEngine/RenderSystem/Texture.h
	src/KeplerEngine/RenderSystem/Texture.cpp
	src/KeplerEngine/System/System.h
	src/KeplerEngine/System/System.cpp
	src/KeplerEngine/Components/Base/Components.h
	src/KeplerEngine/Components/Base/Components.cpp
	src/KeplerEngine/Components/Transform.h
	src/KeplerEngine/Components/Transform.cpp
	src/KeplerEngine/Components/RenderComponent.h
	src/KeplerEngine/Components/RenderComponent.cpp
	src/KeplerEngine/GameObjects/Base/GameObject.h
	src/KeplerEngine/GameObjects/Base/GameObject.cpp
)

set_target_properties( KeplerEngine
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(KeplerEngine SDL2)

target_compile_definitions(
	KeplerEngine
	PRIVATE -DBUILD_DLL
)

#Add main executable
add_executable(Game
	src/Game/Program.cpp
)

target_link_libraries(Game KeplerEngine)

set_target_properties( Game
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)