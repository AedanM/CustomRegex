#include "test_Args.h"
#include "../input/ArgParser.h"
#include <cassert>
using namespace std;

void TestArgs() {
  char arg1[] = "main.exe";
  char flag1[] = "-f";
  char flag2[] = "-p";
  char arg2[] = ".\\sampleText.txt";
  char arg3[] = "[^a-z,A-Z]$";
  char *arg[] = {arg1, flag1, arg2, flag2, arg3};
  auto i = InputArgs(5, arg);
  assert(i.FileName == arg2 && i.Pattern == arg3 && !i.Help);
  //   {"main.exe", "[^a-z,A-Z]$", ".\\sampleText.txt"};
  //   char *args[] = {"main.exe", "-p", "[^a-z,A-Z]$", "-f",
  //   ".\sampleText.txt"}; char *args[] = {"main.exe", "-p", "[^a-z,A-Z]$",
  //   "-f", ".\sampleText.txt"};
}