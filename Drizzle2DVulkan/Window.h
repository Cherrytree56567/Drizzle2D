#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

class Window {
public:
	int width = 800;
	int height = 600;
	char* WindowTitle = (char*)"New Drizzle2D Game";
	GLFWwindow* window;
	void CreateWindow();
	bool Mainloop();
	void CloseWindow();
};

