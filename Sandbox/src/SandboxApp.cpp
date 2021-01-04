#include "RobbEngine.h"

class ExampleLayer : public RobbEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		RE_INFO("ExampleLayer::Update");
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
	}

	~Sandbox()
	{

	}
};

RobbEngine::Application* RobbEngine::CreateApplication()
{
	return new Sandbox();
}
