#include "FileProcessor.h"
#include "Translator.h"

FileProcessor::FileProcessor() {} //default constructor
FileProcessor::~FileProcessor() {} //destructor


void FileProcessor::processFile(string inputFile, string outputFile,
  string translationType) {

  Translator currTranslator;
  string textHolder;
  fstream readFile;
  fstream writeFile;

  readFile.open(inputFile, ios::in); //open file to read

  /* If the file successfully opened, assign each line to textHolder. Write
  tutnese translation of textHolder to the output file. Takes translationType
  into consideration before looping for efficiency. Include error message */
  if ((readFile.is_open()) && (translationType == "E2T")) {
    writeFile.open(outputFile, ios::out); //open file to write to
    while(getline(readFile, textHolder)) { //while there is line to read, read
      if (writeFile.is_open()) {
        writeFile << currTranslator.translateEnglishSentence(textHolder) << endl;
      }
    }
  }
  else if ((readFile.is_open()) && (translationType == "T2E")) {
    writeFile.open(outputFile, ios::out); //open file to write to
    while(getline(readFile, textHolder)) { //while there is line to read, read
      if (writeFile.is_open()) {
        writeFile << currTranslator.translateTutneseSentence(textHolder) << endl;
      }
    }
  }
  else { //Give error message and close program
    cout << "Error: Invalid input. The file may be spelled inproperly or " <<
    "without \".txt\"." << endl << endl;
    exit(1);
  }

  /* Close files */
  readFile.close();
  writeFile.close();
}
