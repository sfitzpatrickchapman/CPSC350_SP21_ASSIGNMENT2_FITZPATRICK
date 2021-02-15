#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <string>
using namespace std;

class Translator {
public:
  Translator(); //default constructor
  ~Translator(); //destructor
  string translateEnglishWord(string inputWord);
  string translateEnglishSentence(string inputSentence);
};

#endif
