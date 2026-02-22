#pragma once
#include "macros.h"
#include "ClayPOT/Platform/Window.h"
#include "ClayPOT/Events/ApplicationEvent.h"

namespace cp
{
	class CP_API CPCreator
	{
	public:
		CPCreator();
		virtual ~CPCreator() = default;

		void run();
		void OnEvent(Event& e);
		


	private:

		void initWindow();

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> cp_Window;
		bool cp_Running = true;
	};

	CPCreator* CreateApplication();

}