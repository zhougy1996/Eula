#pragma once

#ifdef EULA_PLATFORM_WINDOWS

extern Eula::Application* Eula::CreateApplication();

int main(int argc, char** argv)
{
	Eula::Log::Init();
	EULA_CORE_INFO("Welcome to Eula!");
	EULA_FATAL("Eula!");


	auto app = Eula::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#else
	#error Eula only supports Windows!
#endif // EULA_PLATFORM_WINDOWS