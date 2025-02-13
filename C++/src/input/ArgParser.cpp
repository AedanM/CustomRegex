#include "ArgParser.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <string>

using namespace std;

InputArgs::InputArgs(int argc, char *argv[]) {
  int patternIdx = _FindFlagIdx(argc, argv, "-p");
  int fileIdx = _FindFlagIdx(argc, argv, "-f");
  int helpIdx = _FindFlagIdx(argc, argv, "-h");
  int helpLongIdx = _FindFlagIdx(argc, argv, "--help");

  if (helpIdx > 0 || helpLongIdx > 0) {
    Help = true;
  } else if (patternIdx < 0 && fileIdx < 0 && argc >= 2) {
    Pattern = argv[1];
    FileName = argv[2];

  } else {
    if (patternIdx != -1) {
      Pattern = argv[patternIdx + 1];
    } else {
      throw std::invalid_argument("No Pattern (-p) provided");
    }
    if (fileIdx != -1) {
      FileName = argv[fileIdx + 1];
    } else {
      throw std::invalid_argument("No File (-f) provided");
    }
  }
}

int InputArgs::_FindFlagIdx(int argc, char *argv[], string flag) {
  const char *cflag = flag.c_str();
  auto it = find_if(argv, argv + argc, [&cflag](const char *arg) {
    return strcmp(arg, cflag) == 0;
  });
  if (it - argv < argc) {
    return it - argv;
  } else {
    return -1;
  }
}