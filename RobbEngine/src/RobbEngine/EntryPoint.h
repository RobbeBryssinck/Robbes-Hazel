#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RobbEngine::Application* RobbEngine::CreateApplication();

int main(int argc, char** argv)
{
	RobbEngine::Log::Init();
	RE_CORE_WARN("Initialized Log!");
	int a = 5;
	RE_INFO("Hello! {0}", a);

	auto app = RobbEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
