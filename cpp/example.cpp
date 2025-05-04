#include <fstream>
#include <iostream>
#include <memory>
#include <string>

struct LogSink {
  virtual void write(const std::string &msg) = 0;
  virtual ~LogSink() = default;
};

struct ConsoleSink : public LogSink {
  void write(const std::string &msg) override { std::cout << msg << std::endl; }
};

struct FileSink : public LogSink {
  void write(const std::string &msg) override {
    std::ofstream file("app.log", std::ios::app);
    if (file.is_open()) {
      file << msg << std::endl;
    }
  }
};

struct NullSink : public LogSink {
  void write(const std::string &) override {}
};

enum class SinkType { CONSOLE, FILE, NONE };

class Logger {
public:
  static Logger &instance() {
    static Logger instance;
    return instance;
  }

  void set_sink(SinkType type) {
    switch (type) {
    case SinkType::CONSOLE:
      sink_ = std::make_unique<ConsoleSink>();
      break;
    case SinkType::FILE:
      sink_ = std::make_unique<FileSink>();
      break;
    case SinkType::NONE:
    default:
      sink_ = std::make_unique<NullSink>();
      break;
    }
  }

  void log(const std::string &msg) {
    if (sink_) {
      sink_->write(msg);
    }
  }

private:
  Logger() : sink_(std::make_unique<NullSink>()) {}
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  std::unique_ptr<LogSink> sink_;
};

//---------------------------------------------------------

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class LogSink {
public:
  virtual void write(const std::string &msg) = 0;
  virtual ~LogSink() = default;
};

class ConsoleSink : public LogSink {
public:
  void write(const std::string &msg) override { std::cout << msg << std::endl; }
};

class FileSink : public LogSink {
public:
  void write(const std::string &msg) override {
    std::ofstream file("app.log", std::ios::app);
    if (file.is_open()) {
      file << msg << std::endl;
    }
  }
};

class NullSink : public LogSink {
public:
  void write(const std::string &) override {}
};

enum class SinkType { CONSOLE, FILE, NONE };

class Logger {
public:
  static Logger &instance() {
    static Logger instance;
    return instance;
  }

  void set_sink(SinkType type) {
    switch (type) {
    case SinkType::CONSOLE:
      sink_ = std::make_unique<ConsoleSink>();
      break;
    case SinkType::FILE:
      sink_ = std::make_unique<FileSink>();
      break;
    case SinkType::NONE:
    default:
      sink_ = std::make_unique<NullSink>();
      break;
    }
  }

  void log(const std::string &msg) {
    if (sink_) {
      sink_->write(msg);
    }
  }

private:
  Logger() : sink_(std::make_unique<NullSink>()) {}
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  std::unique_ptr<LogSink> sink_;
};
