#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace RobbEngine {

	class ROBBENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RE_CORE_TRACE(...)    ::RobbEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_CORE_INFO(...)     ::RobbEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)     ::RobbEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)    ::RobbEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_FATAL(...)    ::RobbEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RE_TRACE(...)         ::RobbEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RE_INFO(...)          ::RobbEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define RE_WARN(...)          ::RobbEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)         ::RobbEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define RE_FATAL(...)         ::RobbEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
