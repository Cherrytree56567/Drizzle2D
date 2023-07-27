CC=gcc
CPPC=g++
OBJ = main.obj
CFLAGS = -std=c++17 -O2 -Istb -I. -DLinux
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SRCRENDERER = CommandBuffer.cpp Debug.cpp Device.cpp framebuffer.cpp Frames.cpp GraphicsPipeline.cpp ImageViews.cpp LogicalDevice.cpp PhysicalDevice.cpp Renderer.cpp Renderer.h Shader.cpp Surface.cpp Swapchain.cpp Textures.cpp UniformBuffer.cpp
SRCWINDOW = Window.cpp Window.h
SRC = main.cpp

Drizzle2D: 
	wget -qO - http://packages.lunarg.com/lunarg-signing-key-pub.asc | sudo apt-key add - 
	sudo wget -qO /etc/apt/sources.list.d/lunarg-vulkan-focal.list http://packages.lunarg.com/vulkan/lunarg-vulkan-focal.list
	sudo apt update -y
	sudo apt-get install vulkan-sdk libglfw3-dev libglfw3 libxinerama-dev libxcursor-dev libxi-dev libxxf86vm-dev vulkan-tools libglm-dev vulkan-validationlayers-dev spirv-tools -y
	git clone https://github.com/nothings/stb.git
	$(CPPC) -c $(CFLAGS) CommandBuffer.cpp -o x64/Release/CommandBuffer.obj
	$(CPPC) -c $(CFLAGS) Debug.cpp -o x64/Release/Debug.obj
	$(CPPC) -c $(CFLAGS) Device.cpp -o x64/Release/Device.obj
	$(CPPC) -c $(CFLAGS) framebuffer.cpp -o x64/Release/framebuffer.obj
	$(CPPC) -c $(CFLAGS) Frames.cpp -o x64/Release/Frames.obj
	$(CPPC) -c $(CFLAGS) GraphicsPipeline.cpp -o x64/Release/GraphicsPipeline.obj
	$(CPPC) -c $(CFLAGS) "Image Views.cpp" -o x64/Release/ImageViews.obj
	$(CPPC) -c $(CFLAGS) "Logical Device.cpp" -o x64/Release/LogicalDevice.obj
	$(CPPC) -c $(CFLAGS) "Physical Device.cpp" -o x64/Release/PhysicalDevice.obj
	$(CPPC) -c $(CFLAGS) Renderer.cpp -o x64/Release/Renderer.obj
	$(CPPC) -c $(CFLAGS) Shader.cpp -o x64/Release/Shader.obj
	$(CPPC) -c $(CFLAGS) Surface.cpp -o x64/Release/Surface.obj
	$(CPPC) -c $(CFLAGS) Swapchain.cpp -o x64/Release/Swapchain.obj
	$(CPPC) -c $(CFLAGS) Textures.cpp -o x64/Release/Textures.obj
	$(CPPC) -c $(CFLAGS) UniformBuffer.cpp -o x64/Release/UniformBuffer.obj
	$(CPPC) -c $(CFLAGS) Window.cpp -o x64/Release/Window.obj
	$(CPPC) -c $(CFLAGS) main.cpp -o x64/Release/main.obj
	$(CPPC) $(CFLAGS) -o Drizzle2D.elf x64/Release/*.obj $(LDFLAGS)

.PHONY: test clean

test: 
	./Drizzle2D.elf

clean:
	rm -f x64/Release/*
	rm -R -f stb
