#include "LogUtil.h"

LogUtil::LogUtil(/* args */)
{
}

LogUtil::~LogUtil()
{
}

void LogUtil::InitLogger()
{
	// 1. 创建两个独立的 sink
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/async_log.txt");

	// 2. 为每个 sink 设置不同格式
	console_sink->set_pattern("[%H:%M:%S] [%^%l%$] [thread %t] %v");
	file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] [thread %t] %v");

	// 3. 创建 logger 并添加两个 sink
	std::vector<spdlog::sink_ptr> sinks = {console_sink, file_sink};
	auto logger = std::make_shared<spdlog::logger>("spdlog", sinks.begin(), sinks.end());
	spdlog::set_default_logger(logger);
	spdlog::set_level(spdlog::level::debug); // 设置全局日志级别

	spdlog::flush_on(spdlog::level::debug); // 设置日志刷新级别
}