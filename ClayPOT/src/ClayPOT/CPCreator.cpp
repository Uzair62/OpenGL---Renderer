#include "cph.h"
#include "CPCreator.h"

#define CP_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace cp
{

	CPCreator::CPCreator()
	{
		
		initWindow();
		cp_Window->setEventCallBack(CP_BIND_EVENT_FN(CPCreator::OnEvent));

	}

	void CPCreator::run()
	{
		while (cp_Running)
		{
			cp_Window->OnUpdate();
		}
	}

	void CPCreator::OnEvent(Event& e)
	{
		Dispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(CP_BIND_EVENT_FN(CPCreator::OnWindowClose));
		
	}

	void CPCreator::initWindow()
	{
		cp_Window = std::make_unique<Window>();
	}

	bool CPCreator::OnWindowClose(WindowCloseEvent& e)
	{
		cp_Running = false;
		return true;
	}

}
