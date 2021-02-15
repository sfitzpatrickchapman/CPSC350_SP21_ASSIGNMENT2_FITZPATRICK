#include "FileProcessor.h"
#include "Translator.h"

FileProcessor::FileProcessor() {} //default constructor
FileProcessor::~FileProcessor() {} //destructor


void FileProcessor::processFile(string inputFile, string outputFile) {
  Translator currTranslator;
  string textHolder;
  fstream readFile;
  fstream writeFile;

  readFile.open(inputFile, ios::in); //open file to read

  /* If the file successfully opened, assign each line to textHolder. Write
  tutnese translation of textHolder to the output file */
  if (readFile.is_open()) {
    writeFile.open(outputFile, ios::out); // open file to write to

    while(getline(readFile, textHolder)) {
      if (writeFile.is_open())
        writeFile << currTranslator.translateEnglishSentence(textHolder) << endl;
    }
  }
  else { // Give error message and close program
    cout << "Error: Invalid input. The file may be spelled inproperly or " <<
    "without \".txt\"." << endl << endl;
    exit(1);
  }

  /* Close files */
  readFile.close();
  writeFile.close();
}
