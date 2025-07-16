#pragma once
#include <string>
namespace Constants {
	constexpr int WINDOW_WIDTH = 800;
	constexpr int WINDOW_HEIGHT = 600;
	const std::string& WINDOW_TITLE = "3D_World";

	constexpr float NEAR_PLANE = 0.1f;
	constexpr float FAR_PLANE = 1000.0f;

	constexpr int MAX_LIGHT = 10;

	const std::string RESOURCES = "../../resources/";
	
}