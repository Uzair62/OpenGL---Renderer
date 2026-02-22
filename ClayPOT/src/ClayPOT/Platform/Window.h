#pragma once
#include <GLFW/glfw3.h>
#include "ClayPOT/macros.h"
#include "ClayPOT/Events/Event.h"
#include "ClayPOT/Log.h"

namespace cp
{

	using CallBackFn = std::function<void(Event&)>;

	struct WindowData
	{
		std::string w_Title;
		unsigned int w_Width;
		unsigned int w_Height;
		bool w_Vsync;
		CallBackFn e_CallBack;

	};

	class CP_API Window
	{

	public:

		Window();
		virtual ~Window();

		void Init();
		void ShutDown();

		void OnUpdate();
		inline void setEventCallBack(const CallBackFn& callback) { cp_WinData.e_CallBack = callback; }

	private:

		GLFWwindow* cp_Win;
		WindowData cp_WinData;

	};

}
