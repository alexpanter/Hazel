#pragma once

#include <memory>

#include "Core.h"

// a lot of code inside spdlog generates compiler warning.
// They are annoying to look at, so we disable them temporarily
// while including the library.
#pragma warning(push)
#pragma warning(disable : 26451)  // arithmetic overflow
#pragma warning(disable : 26812)  // disable warning about unscoped enums
#pragma warning(disable: 26495)   // unitizialized member variable
#pragma warning(disable: 6385)    // reading invalid data (readable size is 4 bytes,
                                  // but 'fspecs.sign' bytes may be read)
#ifdef HZ_PLATFORM_WINDOWS
	#pragma warning(disable: 6387)
#endif
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

namespace Hazel
{
	class HAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
#pragma warning(disable: 4251) // declare as dll export
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
#pragma warning(default: 4251)
	};
}

// Core log macros
#define HZ_CORE_TRACE(...)   ::Hazel::Log::GetCoreLogger()->trace   (__VA_ARGS__);
#define HZ_CORE_INFO(...)    ::Hazel::Log::GetCoreLogger()->info    (__VA_ARGS__);
#define HZ_CORE_WARN(...)    ::Hazel::Log::GetCoreLogger()->warn    (__VA_ARGS__);
#define HZ_CORE_ERROR(...)   ::Hazel::Log::GetCoreLogger()->error   (__VA_ARGS__);
#define HZ_CORE_FATAL(...)   ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__);

// Client log macros
#define HZ_TRACE(...) ::Hazel::Log::GetCoreLogger()->trace   (__VA_ARGS__);
#define HZ_INFO(...)  ::Hazel::Log::GetCoreLogger()->info    (__VA_ARGS__);
#define HZ_WARN(...)  ::Hazel::Log::GetCoreLogger()->warn    (__VA_ARGS__);
#define HZ_ERROR(...) ::Hazel::Log::GetCoreLogger()->error   (__VA_ARGS__);
#define HZ_FATAL(...) ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__);
