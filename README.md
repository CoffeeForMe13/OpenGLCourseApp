
Hello,
This repository contains the code I wrote from the course < Computer Graphics with Modern OpenGL and C++ > that can be found on Udemy.
Check out the course if you are interested. The video for the setup can be previewed without purchasing the course :D

The setup steps bellow describe the process I went through before reaching the state of the initial commit.

I. Setup steps
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
		- Add _$(SolutionDir)/../../External Libs/GLEW/include_ 
			(the number of ../ depends on where you put the External Libs folder. To verify that it works, go back to main and type "#include \<GL\>")
		- Add _$(SolutionDir)/../../External Libs/GLFW/include_
			(the number of ../ depends on where you put the External Libs folder. To verify that it works, go back to main and type "#include \<GLFW\>")
6. Tell it where our libraries are
	- Go back into properties
	- Under Configuration Properties -> Linker -> General edit Additional Library Directories
		- Add _$(SolutionDir)/../../External Libs/GLEW/lib/Release/Win32_ 
			(the number of ../ depends on where you put the External Libs folder)
		- Add _$(SolutionDir)/../../External Libs/GLFW/lib-vc2022_
			(the number of ../ depends on where you put the External Libs folder)
			(<lib-vc2022> should correspond to the verion of Visual Studio you have installed (2022 in my case))
	- Under Configuration Properties -> Linker -> Input edit Additional Dependencies
		- Add _opengl32.lib_
		- Add _glew32.lib_
		- Add _glfw3.lib_ (verify the name under External Libs/GLFW/lib-vc2022)

7. Last thing we need to do is copy glew32.dll from External Libs/GLEW/lib/Release/Win32 and paste it in the location of the code inside the project (where the main.cpp file is - inside OpenGLCourseApp/OpenGLCourseApp in my case)



-------------------------------------
The following section describes the steps required to add the Assimp library to the project. This is described in < Section 4 >, lesson < 31. [CODING] Model Importing > at the time I wrote this repository. 

II. Using the Asset Import Librar
-------------------------------------
1. Downloads
	- Asset Import Librar from [Assimp Website](https://sourceforge.net/projects/assimp/)
 		- Extract it
	- CMake from [Here](https://cmake.org/download/). I used the version from Binary - Windows x64 ZIP.
		- Extract it
		- Rename it to CMake
		- Move it to C:\
		- In system environment variables -> Environment Variables... -> Add _C:\CMake\bin_ to Path under System variables

2. Go to the location of **assimp-3.1.1** and open cmd
	- In cmd, run _cmake ./ -DCMAKE_POLICY_VERSION_MINIMUM=3.5_
	- If you get a directX error, you need to [install DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812). If the installation of directX fails, try [following these steps](https://stackoverflow.com/questions/4102259/directx-sdk-june-2010-installation-problems-error-code-s1023).

3. After the installation is completed
   	- Open the solution Assimp.sln (Make sure that the project is set in the same manner as the OpenGLCourseAPP (Release, Win32))
	- From Build
		- Clean Solution (Optional)
		- Build solution

4. After the build is finished
	- Create an **ASSIMP** directory in the **External Libs** folder
	- Copy the **include** folder from **assimp-3.1.1** to **ASSIMP**
	- Create a **lib** folder inside **ASSIMP**
	- Copy **assimp.lib** (the name may vary) from **assimp-3.1.1\lib\Release** to the **lib** folder
	- Copy **assimp.dll** from **assimp-3.1.1\bin\Release** to **OpenGLCourseAPP\OpenGLCourseAPP** (where **main.cpp** is located)
 
7. In Visual Studio
	- Right click OpenGLCourseAPP -> Properties -> Configuration Properties -> C/C++ -> General edit Additional Include Directories
 		- Add _$(SolutionDir)/../../External Libs/ASSIMP/include_
	- Right click OpenGLCourseAPP -> Properties -> Configuration Properties -> Linker -> General edit Additional Library Directories
 		- Add _$(SolutionDir)/../../External Libs/ASSIMP/lib_
	- Right click OpenGLCourseAPP -> Properties -> Configuration Properties -> Linker -> Input edit Additional Dependencies
 		- Add _assimp.lib_ (name may vary)
