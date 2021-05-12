#pragma once
#include "Core.h"

namespace Eula {

	class EULA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined by the client(application)
	Application* CreateApplication();

}