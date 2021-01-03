#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RobbEngine::Application* RobbEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = RobbEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
