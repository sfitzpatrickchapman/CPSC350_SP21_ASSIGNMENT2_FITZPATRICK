#ifndef MODELT2E_H
#define MODELT2E_H
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
using namespace std;

class ModelT2E {
public:
  ModelT2E(); //default constructor
  ~ModelT2E(); //destructor
  string tolowercase(string word);
  string tokenFinder(string tutWord);
  string tokenConverter(string token);

};

#endif
