#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Barrel
{
	class BARREL_API Log
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
//Core log macros
#define BR_CORE_TRACE(...)    ::Barrel::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define BR_CORE_INFO(...)     ::Barrel::Log::GetCoreLogger()->info(__VA_ARGS__);
#define BR_CORE_WARN(...)     ::Barrel::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define BR_CORE_ERROR(...)    ::Barrel::Log::GetCoreLogger()->error(__VA_ARGS__);
#define BR_CORE_CRITICAL(...) ::Barrel::Log::GetCoreLogger()->critical(__VA_ARGS__);

//Client log macros
#define BR_TRACE(...)    ::Barrel::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BR_INFO(...)     ::Barrel::Log::GetClientLogger()->info(__VA_ARGS__);
#define BR_WARN(...)     ::Barrel::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BR_ERROR(...)    ::Barrel::Log::GetClientLogger()->error(__VA_ARGS__);
#define BR_CRITICAL(...) ::Barrel::Log::GetClientLogger()->critical(__VA_ARGS__);


