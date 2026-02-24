#include "cph.h"
#include "Renderer.h"


namespace cp
{
	Renderer::Renderer(GLFWwindow* window) : cp_Window(window)
	{
		Init();
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Init()
	{
		gladLoadGL();
		glViewport(0, 0, 1280, 720);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(cp_Window);
	}

	const char* Renderer::getVertexShaderSource()
	{
		return ("#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0");
	}

	const char* Renderer::getFragmentShaderSource()
	{
		return ("#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
			"}\n\0");
	}

	void Renderer::shutdown()
	{

	}

	void Renderer::UpdateScene()
	{

	}


}