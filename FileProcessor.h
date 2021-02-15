#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor {
public:
  FileProcessor(); //default constructor
  ~FileProcessor(); //destructor
  void processFile(string inputFile, string outputFile);
};

#endif
