#ifndef GROUPS_H
#define GROUPS_H
#include <string>
#include <vector>
using namespace std;

tuple<int, string> CheckMeta(string str, char c);
bool EvaluateGroup(string group, char testChar);
vector<tuple<int, int>> FindRanges(string workingStr);

#endif