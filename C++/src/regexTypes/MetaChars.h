#ifndef META_H
#define META_H
#include <string>
using namespace std;

typedef struct MetaChars {
  string GroupPattern;
  string Identifier;
  MetaChars(string id, string group) {
    GroupPattern = group;
    Identifier = id;
  };
} MetaChars;

const MetaChars META_CHARS[] = {
    MetaChars("\\d", "0-9"),        MetaChars("\\D", "^0-9"),
    MetaChars("\\w", "a-zA-Z0-9_"), MetaChars("\\W", "^a-zA-Z0-9_"),
    MetaChars("\\s", " \t\n\r\f"),  MetaChars("\\S", "^ \t\n\r\f"),
    MetaChars(".", "^\n"),          MetaChars("\\B", "^\\b")};

const int META_CHARS_COUNT = sizeof(META_CHARS) / sizeof(MetaChars);
#endif