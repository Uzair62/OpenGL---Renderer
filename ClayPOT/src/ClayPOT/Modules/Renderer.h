#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace cp
{
	class Renderer
	{
	public:

		Renderer(GLFWwindow* window);
		~Renderer();

		void UpdateScene();

	private:

		void Init();
		const char* getVertexShaderSource();
		const char* getFragmentShaderSource();
		void shutdown();
		void setWindow(GLFWwindow* window) { cp_Window = window; }


	private:

		GLuint cp_VertexShader;
		GLuint cp_FragmentShader;
		GLuint cp_ShaderProgram;

		GLuint cp_VAO;
		GLuint cp_VBO;

		const char* cp_VertexShaderSource;
		const char* cp_FragmentShaderSource;

		GLFWwindow* cp_Window;

	};

}
