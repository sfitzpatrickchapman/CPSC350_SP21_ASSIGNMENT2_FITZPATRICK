#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <string>
using namespace std;

class Model {
public:
  Model(); //default constructor
  ~Model(); //destructor
  string translateSingleCharacter(char userChar);
  string translateDoubleCharacter(char userChars);
};

#endif
