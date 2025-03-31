#include "FileRead.h"
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

void FileObj::CountLines() {
  ifstream f(FilePath);
  int fileLines = 0;
  string line;
  while (getline(f, line)) {
    fileLines++;
  }
  LineCount = fileLines;
  f.close();
}

FileObj::FileObj(string filePath) {
  FilePath = filePath;
  CountLines();
  FileStream.open(filePath);
  if (!FileStream.good()) {
    throw invalid_argument("Please correct input file");
  }
}