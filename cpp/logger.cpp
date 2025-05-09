#include "../hpp/logger.hpp"

Logger::Logger() : m_sink(std::make_unique<NullSink>()) {}

Logger &Logger::instance() {
  static Logger instance;
  return instance;
}

void Logger::set_sink(SinkType type) {
  switch (type) {
  case SinkType::FILE:
    m_sink = std::make_unique<FileSink>();
    break;
  case SinkType::NONE:
    break;
  case SinkType::CONSOLE:
    m_sink = std::make_unique<ConsoleSink>();
    break;

  default:
    m_sink = std::make_unique<ConsoleSink>();
    break;
  }
}

void Logger::log(const std::string &msg) {
  if (m_sink) {
    m_sink->write(msg);
  }
}
