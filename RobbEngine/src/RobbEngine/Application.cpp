#include "repch.h"
#include "Application.h"

#include "RobbEngine/Events/ApplicationEvent.h"
#include "RobbEngine/Log.h"

namespace RobbEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RE_TRACE(e);
		}

		while (true);
	}

}
