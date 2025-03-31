#include "input/ArgParser.h"
#include "input/FileRead.h"
#include "regexTypes/Groups.h"
#include "tests/testSuite.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  InputArgs input = InputArgs(argc, argv);
  if (input.Help) {
    cout << "Help Text" << endl;
    exit(0);
  }
  cout << "Using " << input.Pattern << " on " << input.FileName << endl;

  FileObj f(input.FileName);
  string line;
  cout << f.LineCount << endl;
  while (getline(f.FileStream, line)) {
    bool match = false;
    for (unsigned int i = 0; i < line.length(); i++) {
      match = EvaluateGroup(input.Pattern, line[i]);
      if (match) {
        cout << line << endl;
        break;
      }
    }
  }
  if (input.RunTests) {
    RunAllTests();
  }

  return 0;
}