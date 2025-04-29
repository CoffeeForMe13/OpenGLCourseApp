
Hello,
This repository contains the code I wrote from the course < Computer Graphics with Modern OpenGL and C++ > that can be found on Udemy.
Check out the course if you are interested. The video for the setup can be previewed without purchasing the course :D

The setup steps bellow describe the process I went through before reaching the state of the initial commit.

Setup steps
-------------------------------------

0. Update your graphics card driver.

1. Go to [glew.sourceforge.net](https://sourceforge.net/projects/glew/), under Downloads click GLEW and download glew-2.1.0-win32.zip (or the current version).

2. Go to [www.glfw.org/download.html](https://www.glfw.org/download.html), under Windows pre-compiled binaries download 32-bit Windows binaries.
	
3. Extract both zip files
	- Rename glew-2.1.0 to GLEW
	- Rename glfw-3.2.1.bin.WIN32 to GLFW
	- Create a new folder named External Libs and move both libraries inside it
	- Move the External Libs folder in the same directory as the root of the projects that will use it
	
4. Open Visual Studio
	- Create new project as an empty console application (named OpenGLCourseApp in this case)
	- Create an initial file named main.cpp
	- Create a simple main file
	- Set the platform to x86

5. Link up the libraries
	- Right click on the project (OpenGLCourseApp) and go to properties
	- Set Configuration to All Configurations
	- Set Platform to All Platforms
	- Under Configuration Properties -> C/C++ -> General edit the Additional Include Directories
		- Add $(SolutionDir)/../../../External Libs/GLEW/include 
			(the number of ../ depends on where you put the External Libs folder. To verify that it works, go back to main and type "#include \<GL\>")
		- Add $(SolutionDir)/../../../External Libs/GLFW/include
			(the number of ../ depends on where you put the External Libs folder. To verify that it works, go back to main and type "#include \<GLFW\>")
6. Tell it where our libraries are
	- Go back into properties
	- Under Configuration Properties -> Linker -> General edit Additional Library Directories
		- Add $(SolutionDir)/../../../External Libs/GLEW/lib/Release/Win32 
			(the number of ../ depends on where you put the External Libs folder)
		- Add $(SolutionDir)/../../../External Libs/GLFW/lib-vc2022
			(the number of ../ depends on where you put the External Libs folder)
			(<lib-vc2022> should correspond to the verion of Visual Studio you have installed (2022 in my case))
	6.3. Under Configuration Properties -> Linker -> Input edit Additional Dependencies
		- Add opengl32.lib
		- Add glew32.lib
		- Add glfw3.lib (verify the name under External Libs/GLFW/lib-vc2022)

7. Last thing we need to do is copy glew32.dll from External Libs/GLEW/lib/Release/Win32 and paste it in the location of the code inside the project (where the main.cpp file is - inside OpenGLCourseApp/OpenGLCourseApp in my case)
