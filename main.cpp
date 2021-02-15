#include <iostream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
using namespace std;


int main(int argc, char **argv) {
  string inputFile;
  string outputFile;

  /* Prompt and input */
  cout << "\nPlease enter the name of the input file (.txt file): ";
  cin >> inputFile;
  cout << "Please enter the desired output file name (.txt file): ";
  cin >> outputFile;

  /* File initiation and run the translation methods */
  FileProcessor translation;
  translation.processFile(inputFile, outputFile);

  /* Program success message */
  cout << "The file, " << inputFile << ", has successfully been translated" <<
  " to tutnese and has been output to " << outputFile << "." << endl << endl;

  return 0;
}
