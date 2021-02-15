#include "Translator.h"
#include "Model.h"

Translator::Translator() {} //default constructor
Translator::~Translator() {} //destructor


string Translator::translateEnglishWord(string inputWord) {
  Model currModel;
  string tutWord; //tutnese translation

  /* Use respective translate (model) methods whether single or doubled char.
  Prevent double char check at the last index (to stay in boundaries) and use
  tolower to account for any capitlization differences */
  for (int i = 0; i < inputWord.size(); ++i) {
    if ((i < inputWord.size() - 1) &&
    (tolower(inputWord.at(i)) == tolower(inputWord.at(i + 1)))) {
      tutWord.append(currModel.translateDoubleCharacter(inputWord.at(i)));
      i++; //to skip the next repeating letter
    }
    else //single char translation
      tutWord.append(currModel.translateSingleCharacter(inputWord.at(i)));
  }

  return tutWord;
}


string Translator::translateEnglishSentence(string inputSentence) {
  Model currModel;
  string tutSentence;
  bool allCaps = true; //to later initialize all caps preservation

  /* Use respective translate (model) methods whether single or doubled char.
  Prevent double char check at the last index (to stay in boundaries) and use
  tolower to account for any capitlization differences */
  for (int i = 0; i < inputSentence.size(); ++i) {
    if ((i < inputSentence.size() - 1) &&
    (tolower(inputSentence.at(i)) == tolower(inputSentence.at(i + 1)))) {
      tutSentence.append(currModel.translateDoubleCharacter(inputSentence.at(i)));
      i++; //to skip the next repeating letter
    }
    else //single char translation
      tutSentence.append(currModel.translateSingleCharacter(inputSentence.at(i)));
  }

  /* Check if the input is all caps. If so, convert the output to all caps */
  for (int i = 0; i < inputSentence.size(); ++i) //check
    if (islower(inputSentence[i]))
      allCaps = false;
  if (allCaps) //apply
    for (int i = 0; i < tutSentence.size(); ++i)
      tutSentence[i] = toupper(tutSentence[i]);

  return tutSentence;
}
