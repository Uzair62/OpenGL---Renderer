#include "cph.h"
#include "Window.h"
#include "ClayPOT/Events/ApplicationEvent.h"


namespace cp
{

	Window::Window()
	{
		Init();
		initRenderer();
	}

	Window::~Window()
	{
		ShutDown();
	}

	void Window::Init()
	{
		//Initialize GLFW and giving the window properties
		//Start
		glfwInit();
		cp_WinData.w_Title = "ClayPOT Engine";
		cp_WinData.w_Width = 1280;
		cp_WinData.w_Height = 720;
		//End


		//Context of OpenGL
		//Start
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//End


		//Create Window
		//Start
		cp_Win = glfwCreateWindow(cp_WinData.w_Width, cp_WinData.w_Height, cp_WinData.w_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(cp_Win);
		glfwSetWindowUserPointer(cp_Win, &cp_WinData);
		glfwSetWindowCloseCallback(cp_Win, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.e_CallBack(event);
			});
		//End

	}

	void Window::initRenderer()
	{
		cp_Renderer = std::make_unique<Renderer>(cp_Win);
	}

	void Window::ShutDown()
	{
		glfwDestroyWindow(cp_Win);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(cp_Win);
	}


}
