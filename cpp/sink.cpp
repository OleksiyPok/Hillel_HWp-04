#include "../hpp/sink.hpp"

using string = std::string;

void NullSink::write(const string &msg) {};

void ConsoleSink::write(const string &msg) { std::cout << msg << std::endl; };

void FileSink::write(const string &msg) {
  std::ofstream file("app.log", std::ios::app);
  if (file.is_open()) {
    file << msg << std::endl;
    file.close();
  }
}