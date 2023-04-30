#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "Renderer.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

class Window {
public:
	int width = 800;
	int height = 600;
	bool resizable = false;
	char* WindowTitle = (char*)"New Drizzle2D Game";
	GLFWwindow* window;
	void CreateWin();
	bool Mainloop();
	void CloseWindow();
	Window();
	Renderer Render;
};

