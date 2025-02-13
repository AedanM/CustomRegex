#ifndef POSANC_H
#define POSANC_H
#include <string>
using namespace std;

typedef struct PositionAnchors {
  bool isEnd;
  string Identifier;
  PositionAnchors(string id, bool ending) {
    isEnd = ending;
    Identifier = id;
  };
} PositionAnchors;

const PositionAnchors POSITION_ANCHORS[] = {
    PositionAnchors("^", false),   PositionAnchors("$", true),
    PositionAnchors("\\<", false), PositionAnchors("\\>", true),
    PositionAnchors("\\A", false), PositionAnchors("\\Z", true),
    PositionAnchors("\\b", true),  PositionAnchors("\\b", false)};

const int POSITION_ANCHORS_COUNT =
    sizeof(POSITION_ANCHORS) / sizeof(PositionAnchors);

#endif