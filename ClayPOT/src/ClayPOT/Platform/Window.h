#pragma once
#include <ClayPOT/Modules/Renderer.h>
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
		inline GLFWwindow* getCurrentContext() const { return cp_Win; }

	private:

		void initRenderer();

		GLFWwindow* cp_Win;
		std::unique_ptr<Renderer> cp_Renderer;

		WindowData cp_WinData;

	};

}
