#include "cph.h"
#include "Window.h"
#include "ClayPOT/Events/ApplicationEvent.h"


namespace cp
{

	Window::Window()
	{
		Init();
	}

	Window::~Window()
	{
		ShutDown();
	}

	void Window::Init()
	{
		glfwInit();
		cp_WinData.w_Title = "ClayPOT Engine";
		cp_WinData.w_Width = 1280;
		cp_WinData.w_Height = 720;
		cp_Win = glfwCreateWindow(cp_WinData.w_Width, cp_WinData.w_Height, cp_WinData.w_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(cp_Win);
		glfwSetWindowUserPointer(cp_Win, &cp_WinData);
		glfwSetWindowCloseCallback(cp_Win, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.e_CallBack(event);
			});
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
