#pragma once

#include "Core.h"

namespace RobbEngine {

	class ROBBENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in a client
	Application* CreateApplication();

}

