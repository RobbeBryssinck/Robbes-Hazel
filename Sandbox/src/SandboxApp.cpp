#include "RobbEngine.h"

class Sandbox : public RobbEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

RobbEngine::Application* RobbEngine::CreateApplication()
{
	return new Sandbox();
}
