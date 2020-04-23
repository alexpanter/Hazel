#pragma once

#pragma warning(disable : 26812) // disable warning about unscoped enums

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_ERROR("Initialized Log!");
	Hazel::Log::GetClientLogger()->info("Hello!");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
