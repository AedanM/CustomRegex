#include "input/ArgParser.h"
#include "regexTypes/Groups.h"
#include "regexTypes/MetaChars.h"
#include "regexTypes/PositionAnchors.h"
#include <iostream>
#include "tests/testSuite.h"

using namespace std;



int main(int argc, char *argv[]) {
  InputArgs i = InputArgs(argc, argv);
  if (i.Help) {
    cout << "Help Text" << endl;
  } else {
    cout << "Using " << i.Pattern << " on " << i.FileName << endl;
  }
  RunAllTests();


  return 0;
}