#include "logger.hpp"

#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <filesystem>
#include <memory>

std::shared_ptr<spdlog::logger> Logger::spd_logger;

Logger::Logger(std::string_view path_file) {
    try {
        std::filesystem::path path(path_file);
        if (path.has_parent_path()) {
            std::filesystem::create_directories(path.parent_path());
        }
        auto console_sink =
            std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::info);

        // Read Log level from cmake for debug
        // if (static_cast<int>(LogLevel::DEBUG) >= LOG_LEVEL_CMAKE) {
        //     std::cout << "LOG LEVEL: " << LOG_LEVEL_CMAKE;
        // }
        auto file_sink =
            std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                std::string(path_file), 5 * 1024 * 1024, 3);
        file_sink->set_level(spdlog::level::debug);

        //  logger(std::string name, sinks_init_list sinks)
        //     : logger(std::move(name), sinks.begin(), sinks.end())
        // {   }
        spd_logger = std::make_shared<spdlog::logger>(
            "car_logging",
            spdlog::sinks_init_list{file_sink, console_sink});
        spd_logger->set_level(spdlog::level::trace);
        spd_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
        spdlog::set_default_logger(spd_logger);
        spd_logger->info("Create logger done!");
    } catch (const std::exception& ex) {
        std::cout << "Error!!!!!! \n";
    }
}
void Logger::log_impl(LogLevel level, std::string_view fmt_str,
                      fmt::format_args args,
                      const std::source_location& loc) {
    if (!spd_logger) {
        return;
    }
    std::filesystem::path path(loc.file_name());
    // std::string_view path = loc.file_name();
    std::string_view source_info =
        fmt::format("{}:{} [{}]", path.filename().string(), loc.line(),
                    loc.function_name());

    std::string user_msg = fmt::vformat(fmt_str, args);
    std::string msg = fmt::format("{:<45} | {}", source_info, user_msg);

    switch (level) {
        case LogLevel::INFO:
            spd_logger->info(msg);
            break;
        case LogLevel::DEBUG:
            spd_logger->debug(msg);
            break;
        case LogLevel::WARN:
            spd_logger->warn(msg);
            break;
        case LogLevel::CRITICAL:
            spd_logger->critical(msg);
            break;
        case LogLevel::ERROR:
            spd_logger->error(msg);
            break;
        default:
            break;
    }
}
Logger::~Logger() {
    if (spd_logger) {
        spd_logger->info("Destructor!");
        spdlog::shutdown();
    }
}