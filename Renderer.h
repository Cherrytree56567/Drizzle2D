#pragma once
#define DRIZZLE_TRUE VK_TRUE
#define DRIZZLE_FALSE VK_FALSE
#ifdef Linux
#define s 1
#endif
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <fstream>
#include <optional>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <array>
#include <chrono>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

struct UniformBufferObject {
	alignas(16) glm::mat4 model;
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};

struct Vertex {
	glm::vec2 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription bindingDescription{};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return bindingDescription;
	}

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};

		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}
};

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

class Renderer {
public:
	VkDevice device;
	void drawFrame();
	bool anisotropyEnable = VK_TRUE;
	void DestructRenderer();
	void InitRenderer(char* WT, GLFWwindow* windowa);
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<Renderer*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
	}
private:
	char* WindowTitle;
	GLFWwindow* window;
	VkInstance instance;
	VkImage textureImage;
	VkBuffer indexBuffer;
	VkSurfaceKHR surface;
	VkQueue presentQueue;
	VkBuffer vertexBuffer;
	VkQueue graphicsQueue;
	VkFence inFlightFence;
	VkRenderPass renderPass;
	VkSwapchainKHR swapChain;
	VkSampler textureSampler;
	VkCommandPool commandPool;
	uint32_t currentFrame = 0;
	VkExtent2D swapChainExtent;
	VkPipeline graphicsPipeline;
	VkImageView textureImageView;
	VkFormat swapChainImageFormat;
	VkCommandBuffer commandBuffer;
	VkDescriptorPool descriptorPool;
	VkPipelineLayout pipelineLayout;
	bool framebufferResized = false;
	VkDeviceMemory indexBufferMemory;
	VkDeviceMemory vertexBufferMemory;
	VkDeviceMemory textureImageMemory;
	const int MAX_FRAMES_IN_FLIGHT = 2;
	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	std::vector<VkFence> inFlightFences;
	std::vector<VkBuffer> uniformBuffers;
	std::vector<VkImage> swapChainImages;
	VkDebugUtilsMessengerEXT debugMessenger;
	std::vector<void*> uniformBuffersMapped;
	VkDescriptorSetLayout descriptorSetLayout;
	std::vector<VkCommandBuffer> commandBuffers;
	std::vector<VkDescriptorSet> descriptorSets;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkDeviceMemory> uniformBuffersMemory;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};
	const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif
	void createSurface();
	void createInstance();
	void createSwapChain();
	void createImageViews();
	void createRenderPass();
	void cleanupSwapChain();
	void createIndexBuffer();
	void createSyncObjects();
	void recreateSwapChain();
	void createCommandPool();
	void createTextureImage();
	void createVertexBuffer();
	void pickPhysicalDevice();
	void createFramebuffers();
	void createCommandBuffer();
	void setupDebugMessenger();
	void createLogicalDevice();
	void createTextureSampler();
	void createDescriptorPool();
	void createDescriptorSets();
	void createUniformBuffers();
	void createTextureImageView();
	void createGraphicsPipeline();
	void createDescriptorSetLayout();
	bool checkValidationLayerSupport();
	VkCommandBuffer beginSingleTimeCommands();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void updateUniformBuffer(uint32_t currentImage);
	std::vector<const char*> getRequiredExtensions();
	void endSingleTimeCommands(VkCommandBuffer commandBuffer);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	VkImageView createImageView(VkImage image, VkFormat format);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	VkShaderModule createShaderModule(const std::vector<char>& code);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	static std::vector<char> readFile(const std::string& filename) {
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file!");
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
	static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		return attributeDescriptions;
	}
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
};

