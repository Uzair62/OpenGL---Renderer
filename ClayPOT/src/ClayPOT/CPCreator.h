#pragma once
#include "macros.h"

namespace cp
{
	class CP_API CPCreator
	{
	public:
		CPCreator() = default;
		virtual ~CPCreator() = default;

		void run();
	};

	CPCreator* CreateApplication();
}