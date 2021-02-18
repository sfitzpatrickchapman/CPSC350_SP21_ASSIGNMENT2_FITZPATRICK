#ifndef MODELE2T_H
#define MODELE2T_H
#include <iostream>
#include <string>
using namespace std;

class ModelE2T {
public:
  ModelE2T(); //default constructor
  ~ModelE2T(); //destructor
  string translateSingleCharacter(char userChar);
  string translateDoubleCharacter(char userChars);
};

#endif
