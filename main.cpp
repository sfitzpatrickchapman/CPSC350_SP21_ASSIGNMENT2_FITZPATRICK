#include <iostream>
#include "ModelT2E.h"
#include "ModelE2T.h"
#include "Translator.h"
#include "FileProcessor.h"
using namespace std;


int main(int argc, char **argv) {
  string inputFile;
  string outputFile;
  string translationType;

  /* Prompt and input */
  cout << "\nPlease enter the name of the input file (.txt file): ";
  cin >> inputFile;
  cout << "Please enter the desired output file name (.txt file): ";
  cin >> outputFile;
  cout << "Please enter \"E2T\" for English->Tut or \"T2E\" for Tut->English: ";
  cin >> translationType;

  while ((translationType != "E2T") || (translationType != "T2E")) {
    cout << "Invalid translation type. Please enter \"E2T\" for English->Tut" <<
    " or \"T2E\" for Tut->English: ";
    cin >> translationType;
  }

  /* File initiation and run the translation methods */
  FileProcessor translation;
  translation.processFile(inputFile, outputFile, translationType);

  /* Program success message */
  cout << "The file, " << inputFile << ", has successfully been translated" <<
  " to tutnese and has been output to " << outputFile << "." << endl << endl;

  return 0;
}
