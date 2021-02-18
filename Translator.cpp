#include "Translator.h"
#include "ModelT2E.h"
#include "ModelE2T.h"

Translator::Translator() {} //default constructor
Translator::~Translator() {} //destructor


string Translator::translateEnglishWord(string engWord) {
  ModelE2T currModel;
  string tutWord; //tutnese translation

  /* Use respective translate (model) methods whether single or doubled char.
  Prevent double char check at the last index (to stay in boundaries) and use
  tolower to account for any capitlization differences */
  for (int i = 0; i < engWord.size(); ++i) {
    if ((i < engWord.size() - 1) &&
    (tolower(engWord.at(i)) == tolower(engWord.at(i + 1)))) {
      tutWord.append(currModel.translateDoubleCharacter(engWord.at(i)));
      i++; //to skip the next repeating letter
    }
    else //single char translation
      tutWord.append(currModel.translateSingleCharacter(engWord.at(i)));
  }

  return tutWord;
}


string Translator::translateEnglishSentence(string engSentence) {
  ModelE2T currModel;
  string tutSentence;
  bool allCaps = true; //to later initialize all caps preservation

  /* Use respective translate (model) methods whether single or doubled char.
  Prevent double char check at the last index (to stay in boundaries) and use
  tolower to account for any capitlization differences */
  for (int i = 0; i < engSentence.size(); ++i) {
    if ((i < engSentence.size() - 1) &&
    (tolower(engSentence.at(i)) == tolower(engSentence.at(i + 1)))) {
      tutSentence.append(currModel.translateDoubleCharacter(engSentence.at(i)));
      i++; //to skip the next repeating letter
    }
    else //single char translation
      tutSentence.append(currModel.translateSingleCharacter(engSentence.at(i)));
  }

  /* Check if the input is all caps. If so, convert the output to all caps */
  for (int i = 0; i < engSentence.size(); ++i) //check
    if (islower(engSentence[i]))
      allCaps = false;
  if (allCaps) //apply
    for (int i = 0; i < tutSentence.size(); ++i)
      tutSentence[i] = toupper(tutSentence[i]);

  return tutSentence;
}


string Translator::translateTutneseSentence(string tutSentence) {
  ModelT2E currModel;
  string engString;
  string engLetter;
  string token;

  /* While the tut sentence has characters, add spaces to the english string
  when needed, */
  while (tutSentence.size() > 0) {
    if (tutSentence[0] == ' ') { //if whitespace, add whitespace to engString
      tutSentence = tutSentence.substr(1, tutSentence.size() - 1); //remove 1st index
      engString += " ";
    }
    else {
      token = currModel.tokenFinder(tutSentence); //assign tut chunk as token
      if (token == "") { //exception 1
        cout << "ERROR: Invalid tutnese string." << endl;
        exit(1); //exit program
      }
      engLetter = currModel.tokenConverter(token); //convert token to english
      if (token == "") { //exception 2
        cout << "ERROR: Cannot parse tutnese string." << endl;
        exit(2); //exit program
      }
      engString.append(engLetter); //add english letter to english string
      tutSentence = tutSentence.substr(token.size(), tutSentence.size() - token.size());
      /* ^^^ delete the already processed part of tut sentence */
    }
  }

  return engString;
}
