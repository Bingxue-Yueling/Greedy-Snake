#pragma once
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

class LogUtil
{
private:
    /* data */
public:
    LogUtil(/* args */);
    ~LogUtil();
    void InitLogger();
};