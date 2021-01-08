#include "RobbEngine.h"

class ExampleLayer : public RobbEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnAttach() override
	{
		RE_INFO("Attached ExampleLayer!");
	}

	void OnUpdate() override
	{
		if (RobbEngine::Input::IsKeyPressed(RE_KEY_TAB))
			RE_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(RobbEngine::Event& event) override
	{
		if (event.GetEventType() == RobbEngine::EventType::KeyPressed)
		{
			RobbEngine::KeyPressedEvent& e = (RobbEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == RE_KEY_TAB)
				RE_TRACE("Tab key is pressed (event)!");
			RE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public RobbEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new RobbEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

RobbEngine::Application* RobbEngine::CreateApplication()
{
	return new Sandbox();
}
