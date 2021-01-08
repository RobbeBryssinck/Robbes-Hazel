#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RobbEngine::Application* RobbEngine::CreateApplication();

int main(int argc, char** argv)
{
	RobbEngine::Log::Init();
	RE_CORE_INFO("Initialized Log!");

	auto app = RobbEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
