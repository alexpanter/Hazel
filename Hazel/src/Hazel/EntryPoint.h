#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	const int major_version = 0;
	const int minor_version = 1;
	const int revision = 15;

	Hazel::Log::Init();
	HZ_CORE_INFO("Initializing Hazel Engine v.{}.{}.{}",
		major_version, minor_version, revision); // green
	HZ_INFO("Hello!");                           // green

	HZ_CORE_WARN("some core warn");   // yellow
	HZ_CORE_TRACE("some core trace"); // red (could it be another color ?)
	HZ_CORE_FATAL("some core fatal"); // red background, white text
	HZ_CORE_ERROR("some core error"); // red

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
