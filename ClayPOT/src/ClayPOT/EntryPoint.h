#pragma once

#ifdef CP_PLATFORM_WINDOWS

extern cp::CPCreator* cp::CreateApplication();

int main(int argc, char** argv)
{
	auto app = cp::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif