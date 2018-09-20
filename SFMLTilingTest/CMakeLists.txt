cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project (SFMLTilingTest)

#Add required packages
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
set(SFML_STATIC_LIBRARIES TRUE)


add_executable(
	SFMLTilingTest
	SFMLTilingTest.cpp
	TwoDimRenderingEngine.cpp RenderingEngine.cpp RenderLayer.cpp
	GameWindow.cpp
	AssetManager.cpp Entity.cpp ByteArray.cpp
	)

target_link_libraries(SFMLTilingTest sfml-graphics sfml-audio)
	