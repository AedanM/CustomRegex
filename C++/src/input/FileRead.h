#ifndef FILEREAD_H
#define FILEREAD_H

#include <fstream>
class FileObj {
public:
  int LineCount;
  std::string FilePath;
  std::ifstream FileStream;

  FileObj(std::string fileName);

private:
  void CountLines();
};

#endif