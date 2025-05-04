#pragma once

#include <memory>

#include "sink.hpp"

enum class SinkType { CONSOLE, FILE, NONE };

class Logger {
public:
  static Logger &instance();
  void set_sink(SinkType type);
  void log(const std::string &msg);

private:
  Logger();
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  std::unique_ptr<LogSink> m_sink;
};
