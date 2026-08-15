#pragma once
// Third-party library
#include <fmt/format.h>

#include <iostream>
#include <source_location>
#include <string_view>

namespace spdlog {
    class logger;
}

class Logger {
private:
    enum class LogLevel { DEBUG = 0, INFO, WARN, ERROR, CRITICAL };
    void log_impl(LogLevel level, std::string_view fmt_str,
                  fmt::format_args args, const std::source_location& loc);
    static std::shared_ptr<spdlog::logger> spd_logger;

public:
    Logger(std::string_view path_file);
    ~Logger();
    template <typename... Args>
    void debug(
        fmt::format_string<Args...> fmt, Args&&... args,
        const std::source_location loc = std::source_location::current()) {
        if constexpr (static_cast<int>(Logger::LogLevel::DEBUG) >=
                      LOG_LEVEL_CMAKE) {
            log_impl(Logger::LogLevel::DEBUG, fmt,
                     fmt::make_format_args(args...), loc);
        }
    }
    template <typename... Args>
    void warn(
        fmt::format_string<Args...> fmt, Args&&... args,
        const std::source_location loc = std::source_location::current()) {
        if constexpr (static_cast<int>(Logger::LogLevel::WARN) >=
                      LOG_LEVEL_CMAKE) {
            log_impl(Logger::LogLevel::WARN, fmt,
                     fmt::make_format_args(args...), loc);
        }
    }
    template <typename... Args>
    void info(
        fmt::format_string<Args...> fmt, Args&&... args,
        const std::source_location loc = std::source_location::current()) {
        if constexpr (static_cast<int>(Logger::LogLevel::INFO) >=
                      LOG_LEVEL_CMAKE) {
            log_impl(Logger::LogLevel::INFO, fmt::string(fmt),
                     fmt::make_format_args(args...), loc);
        }
    }
    template <typename... Args>
    void error(
        fmt::format_string<Args...> fmt, Args&&... args,
        const std::source_location loc = std::source_location::current()) {
        if constexpr (static_cast<int>(Logger::LogLevel::ERROR) >=
                      LOG_LEVEL_CMAKE) {
            log_impl(Logger::LogLevel::ERROR, fmt,
                     fmt::make_format_args(args...), loc);
        }
    }
};