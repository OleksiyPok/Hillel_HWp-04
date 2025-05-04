
// HW-04. Імплементація логера на патернах проектування
//-----------------------------------------------

#include "main.hpp"

int main(int argc, char **argv) {
  makeLogging(argc, argv);
  return 0;
}

int makeLogging(int argc, char **argv) {

  string sinkTypeStr = "CONSOLE";
  if (argc > 1) {
    sinkTypeStr = argv[1];
  }
  std::transform(sinkTypeStr.begin(), sinkTypeStr.end(), sinkTypeStr.begin(), ::toupper);

  SinkType sinkType = SinkType::CONSOLE;
  if (sinkTypeStr == "FILE") {
    sinkType = SinkType::FILE;
  } else if (sinkTypeStr == "NONE") {
    sinkType = SinkType::NONE;
  }

  Logger::instance().set_sink(sinkType);
  Logger::instance().log("Test message");

  return 0;
};