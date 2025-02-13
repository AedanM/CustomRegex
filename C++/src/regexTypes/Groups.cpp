#include "Groups.h"
#include "MetaChars.h"
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>
#include <stdexcept>

using namespace std;
vector<tuple<int, int>> FindRanges(string workingStr) {
  char start = -1;
  vector<tuple<int, int>> ranges;
  for (uint8_t i = 0; i < workingStr.length(); i++) {
    if (start < 0 && workingStr[i] != '-') {
      start = workingStr[i];
    } else if (start < 0 && workingStr[i] == '-') {
      throw invalid_argument("Invalid Pattern");
    } else if (workingStr[i] != '-' && workingStr[i - 1] == '-') {
      ranges.push_back({start, workingStr[i]});
      start = -1;
    } else if (workingStr[i] != '-') {
      ranges.push_back({start, start});
      start = workingStr[i];
    }
  }
  if (start > 0) {
    ranges.push_back({start, start});
  }
  return ranges;
}

tuple<int, string> CheckMeta(string str, char c) {
  int outputVal = 0;
  for (int i = 0; i < META_CHARS_COUNT; i++) {
    auto idLocation = str.find(META_CHARS[i].Identifier);
    if (idLocation != string::npos) {
      if (!EvaluateGroup(META_CHARS[i].GroupPattern, c)) {
        return {-1, str};
      }
      str.erase(idLocation, META_CHARS[i].Identifier.length());
      outputVal = 1;
    }
  }
  return {outputVal, str};
}

bool EvaluateGroup(string group, char testChar) {
  bool returnVal = false;
  string workingStr = group;
  bool negate = false;

  if (workingStr[0] == '[') {
    workingStr = workingStr.substr(1, workingStr.length() - 2);
  }
  if (workingStr[workingStr.length() - 1] == ']') {
    workingStr = workingStr.substr(0, workingStr.length() - 2);
  }
  if (workingStr[0] == '^') {
    negate = true;
    workingStr = workingStr.substr(1, workingStr.length() - 1);
  }

  tuple<int, string> metaCheck = CheckMeta(workingStr, testChar);
  if (get<0>(metaCheck) < 0) {
    return false;
  }
  returnVal = (bool)get<0>(metaCheck);
  workingStr = get<1>(metaCheck);

  if (workingStr.length() > 0) {
    vector<tuple<int, int>> ranges = FindRanges(workingStr);
    for (uint8_t i = 0; i < ranges.size(); i++) {
      if (testChar >= get<0>(ranges[i]) && testChar <= get<1>(ranges[i])) {
        returnVal = true;
        break;
      }
    }
  }

  return negate ? !returnVal : returnVal;
}
