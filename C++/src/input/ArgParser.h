#ifndef INPUT_H
#define INPUT_H
#include <string>
using namespace std;

class InputArgs {
public:
  string Pattern = "";
  string FileName = "";
  bool Help = false;

  InputArgs(int argc, char *argv[]);

private:
  int _FindFlagIdx(int argc, char *argv[], string flag);
};

#endif