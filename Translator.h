#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
using namespace std;

class Translator {
public:
  Translator(); //default constructor
  ~Translator(); //destructor
  string translateEnglishWord(string engWord);
  string translateEnglishSentence(string engSentence);
  string translateTutneseSentence(string tutSentence);
  string tolowercase(string word);
  string tokenFinder(string tutWord);
  string tokenConverter(string token);
};

#endif
