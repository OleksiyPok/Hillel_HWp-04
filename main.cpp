
// HW-04. Імплементація логера на патернах проектування
//-----------------------------------------------

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>

#include "./hpp/logger.hpp"

using string = std::string;

void handleErrorMessage(char **argv, string errMessage);
int makeLogging(int argc, char **argv);

int main(int argc, char **argv) {

  switch (argc) {
  case 1: {
    handleErrorMessage(argv, ">> Required arguments are missing.");
    break;
  }
  case 2: {
    handleErrorMessage(argv, ">> One of the required arguments is missing.");
    break;
  }
  case 3: {
    makeLogging(argc, argv);
    break;
  }

  default: {
    handleErrorMessage(argv, ">> Too many arguments.");
  }
  }
  return 0;
}

void handleErrorMessage(char **argv, string errMessage) {
  std::filesystem::path filePath(argv[0]);
  std::string fileName = filePath.filename().string();

  std::cerr << errMessage << " The command format must be: " << std::endl
            << ">> \'" << fileName << " <SinkType> <message>\'" << std::endl;
};

int makeLogging(int argc, char **argv) {

  string message = argv[2];

  string sinkTypeStr = argv[1];
  std::transform(sinkTypeStr.begin(), sinkTypeStr.end(), sinkTypeStr.begin(), ::tolower);

  SinkType sinkType = SinkType::NONE;
  if (sinkTypeStr == "console") {
    sinkType = SinkType::CONSOLE;
  } else if (sinkTypeStr == "file") {
    sinkType = SinkType::FILE;
  } else if (sinkTypeStr == "none") {
    sinkType = SinkType::NONE;
  } else {
    std::cerr << ">> Invalid sink type: '" << sinkTypeStr
              << "' (The type must be: CONSOLE, FILE or NONE)" << std::endl;
  }

  Logger::instance().set_sink(sinkType);
  Logger::instance().log(message);

  return 0;
};