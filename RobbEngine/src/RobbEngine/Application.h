#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "RobbEngine/Events/ApplicationEvent.h"

#include "Window.h"

namespace RobbEngine {

	class ROBBENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in a client
	Application* CreateApplication();

}
