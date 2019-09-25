#pragma once
// #include <gl/GLU.h>
// #include <gl/GL.h>
#include <glad/glad.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>

int Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	return 0;
}


