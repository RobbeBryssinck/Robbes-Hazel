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
	}

	void OnEvent(RobbEngine::Event& event) override
	{
		RE_TRACE("{0}", event);
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
