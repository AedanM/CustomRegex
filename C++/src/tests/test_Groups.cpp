#include "../regexTypes/Groups.h"
#include "test_Groups.h"
#include <cassert>
#include <iostream>

using namespace std;
#define assertm(exp, msg) assert((void(msg), exp))

void TestGroups() {
  assert(EvaluateGroup("[abcdef,]", ',') == true);
  assert(EvaluateGroup("[a-zA-Z0-9_]", 'v') == true);
  assert(EvaluateGroup("[^a-zA-Z0-9_]", 'v') == false);
  assert(EvaluateGroup("[a-zA-Z0-9_]", '3') == true);
  assert(EvaluateGroup("[^a-zA-Z0-9_]", '3') == false);
  assert(EvaluateGroup("[\\D]", 'v') == true);
  assert(EvaluateGroup("[.]", 'v') == true);
  assert(EvaluateGroup("[^.]", 'v') == false);
  assert(EvaluateGroup("[\\d]", '5') == true);
  assert(EvaluateGroup("[^a-zA-Z]", '+') == true);
  assert(EvaluateGroup("[^\\S]", ' ') == true);
  assert(EvaluateGroup("[\\S]", ' ') == false);
}