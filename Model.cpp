#include "Model.h"

Model::Model() {} //default constructor
Model::~Model() {} //destructor


string Model::translateSingleCharacter(char inputChar) {
  string returnString;
  /* Finds the corresponding translation for each consonant. Switch inputs are
  converted to lowercase for standardization */
  switch(tolower(inputChar)) {
    case 'b':
      returnString = "bub";
      break;
    case 'c':
      returnString = "cash";
      break;
    case 'd':
      returnString = "dud";
      break;
    case 'f':
      returnString = "fuf";
      break;
    case 'g':
      returnString = "gug";
      break;
    case 'h':
      returnString = "hash";
      break;
    case 'j':
      returnString = "jay";
      break;
    case 'k':
      returnString = "kuck";
      break;
    case 'l':
      returnString = "lul";
      break;
    case 'm':
      returnString = "mum";
      break;
    case 'n':
      returnString = "nun";
      break;
    case 'p':
      returnString = "pub";
      break;
    case 'q':
      returnString = "quack";
      break;
    case 'r':
      returnString = "rug";
      break;
    case 's':
      returnString = "sus";
      break;
    case 't':
      returnString = "tut";
      break;
    case 'v':
      returnString = "vuv";
      break;
    case 'w':
      returnString = "wack";
      break;
    case 'x':
      returnString =  "ex";
      break;
    case 'y':
      returnString = "yub";
      break;
    case 'z':
      returnString = "zub";
      break;
    default: //return the original input if it isn't a consonant
      return returnString + inputChar;
  }

  /* If uppercase, use capitalilization for first tutnese letter */
  if (isupper(inputChar))
    returnString[0] = toupper(returnString[0]);

  return returnString;
}


string Model::translateDoubleCharacter(char inputChar) {
  string returnString;
  /* Finds the corresponding translation for a doubled letter represented by
  a single char. Switch inputs converted to lowercase for standardization */
  switch(tolower(inputChar)) {
    case 'a':
      returnString = "squata";
      break;
    case 'b':
      returnString = "squab";
      break;
    case 'c':
      returnString = "squac";
      break;
    case 'd':
      returnString = "squad";
      break;
    case 'e':
      returnString = "squate";
      break;
    case 'f':
      returnString = "squaf";
      break;
    case 'g':
      returnString = "squag";
      break;
    case 'h':
      returnString = "squah";
      break;
    case 'i':
      returnString = "squati";
      break;
    case 'j':
      returnString = "squaj";
      break;
    case 'k':
      returnString = "squak";
      break;
    case 'l':
      returnString = "squal";
      break;
    case 'm':
      returnString = "squam";
      break;
    case 'n':
      returnString = "squan";
      break;
    case 'o':
      returnString = "squato";
      break;
    case 'p':
      returnString = "squap";
      break;
    case 'q':
      returnString = "squaq";
      break;
    case 'r':
      returnString = "squar";
      break;
    case 's':
      returnString = "squas";
      break;
    case 't':
      returnString = "squat";
      break;
    case 'u':
      returnString = "squatu";
      break;
    case 'v':
      returnString = "squav";
      break;
    case 'w':
      returnString = "squaw";
      break;
    case 'x':
      returnString = "squax";
      break;
    case 'y':
      returnString = "squay";
      break;
    case 'z':
      returnString = "squaz";
      break;
    default: //return the non-letter doubled (since 2nd index will be skipped)
      return returnString + inputChar + inputChar;
  }

  /* If uppercase, use capitalilization for first tutnese letter */
  if (isupper(inputChar))
    returnString[0] = toupper(returnString[0]);

  return returnString;
}
