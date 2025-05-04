#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

struct LogSink {
  virtual void write(const std::string &msg) = 0;
  virtual ~LogSink() = default;
};

struct NullSink : public LogSink {
  void write(const std::string &msg) override;
};

struct ConsoleSink : public LogSink {
  void write(const std::string &msg) override;
};

struct FileSink : public LogSink {
  void write(const std::string &msg) override;
};