#pragma once
#include "Log.h"

#ifdef CP_PLATFORM_WINDOWS

extern cp::CPCreator* cp::CreateApplication();

int main(int argc, char** argv)
{

	cp::Log::init();
	CP_CORE_INFO("Initialized Log!");

	auto app = cp::CreateApplication();
	CP_CORE_INFO("Created Application!");

	CP_INFO("Running Application!");
	app->run();
	delete app;
	return 0;
}

#endif