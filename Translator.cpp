#include "Translator.h"
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
  string engString;
  string engLetter;
  string token;

  /* While the tut sentence has characters, add spaces to the english string
  when needed, */
  while (tutSentence.size() - 1 > 0) {
    if (tutSentence[0] == ' ') { //if whitespace, add whitespace to engString
      tutSentence = tutSentence.substr(1, tutSentence.size() - 1); //remove 1st index
      engString += " ";
    }
    else {
      token = tokenFinder(tutSentence); //assign tut chunk as token
      if (token == "") { //exception 1
        cout << "ERROR: Invalid tutnese string. Must only be raw tutnese text."
        << endl << endl;
        exit(1); //exit program
      }
      engLetter = tokenConverter(token); //convert token to english
      if (token == "") { //exception 2
        cout << "ERROR: Cannot parse tutnese string." << endl << endl;
        exit(2); //exit program
      }
      engString.append(engLetter); //add english letter to english string
      tutSentence = tutSentence.substr(token.size(), tutSentence.size() - token.size());
      /* ^^^ delete the already processed part of tut sentence */
    }
  }

  return engString;
}


string Translator::tolowercase(string word) {
  /* Turns entire strings into lowercase */
  for (int i = 0; i < word.size(); ++i)
    if (isupper(word[i]))
      word[i] = tolower(word[i]);
  return word;
}


string Translator::tokenFinder(string tutWord) {
  /* Regex initializization. Allows to read all kinds of caps input. 1 is vowels,
  2-5 are normal tut tokens, and 6 is double letter tokens */
  regex regex1("[aeiouAEIOU]");
  regex regex2("[eE][xX]");
  regex regex3("[bB][uU][bB]|[dD][uU][dD]|[fF][uU][fF]|[gG][uU][gG]|[jJ][aA][yY]|[lL][uU][lL]|[mM][uU][mM]|[nN][uU][nN]|[pP][uU][bB]|[rR][uU][gG]|[sS][uU][sS]|[tT][uU][tT]|[vV][uU][vV]|[yY][uU][bB]|[zZ][uU][bB]");
  regex regex4("[cC][aA][sS][hH]|[hH][aA][sS][hH]|[kK][uU][cC][kK]|[wW][aA][cC][kK]");
  regex regex5("[qQ][uU][aA][cC][kK]");
  regex regex6("[sS][qQ][uU][aA][tT][aA]|[sS][qQ][uU][aA][tT][eE]|[sS][qQ][uU][aA][tT][iI]|[sS][qQ][uU][aA][tT][oO]|[sS][qQ][uU][aA][tT][uU]");
  regex regexPunc("[,<.>?:;{}`~!@#$%^&*()_+=]");

  if (tutWord.length() >= 6) //squat(x); (double char english equiv)
    if (regex_match(tutWord.substr(0, 6), regex6))
      return tutWord.substr(0, 6);

  if (tutWord.length() >= 5)
    if (regex_match(tutWord.substr(0,5), regex5)) //5 letters
      return tutWord.substr(0 ,5);

  if (tutWord.length() >= 4)
    if (regex_match(tutWord.substr(0, 4), regex4)) //4 letters
      return tutWord.substr(0, 4);

  if (tutWord.length() >= 3)
    if (regex_match(tutWord.substr(0, 3), regex3)) //3 letters
      return tutWord.substr(0, 3);

  if (tutWord.length() >= 2)
    if (regex_match(tutWord.substr(0, 2), regex2)) //2 letters
      return tutWord.substr(0, 2);

  if (tutWord.length() >= 1)
    if (regex_match(tutWord.substr(0, 1), regex1)) //vowels
      return tutWord.substr(0, 1);

    if (regex_match(tutWord.substr(0, 1), regexPunc)) //punctuation
      return tutWord.substr(0, 1);

  return ""; //leads to program exit and error message
}


string Translator::tokenConverter(string token) {
  bool firstUpper = false;
  string engLetter;

  if (isupper(token[0])) //remember uppercase (first letter)
    firstUpper = true;

  token = tolowercase(token); //lowercase for standardization

  /* Search for all tutnese language character sequences (and punctuation) */
  if (token == "squata")
    engLetter = "aa";
  else if (token == "squate")
    engLetter = "ee";
  else if (token == "squati")
    engLetter = "ii";
  else if (token == "squato")
    engLetter = "oo";
  else if (token == "squatu")
    engLetter = "uu";
  else if (token == "quack")
    engLetter = "q";
  else if (token == "cash")
    engLetter = "c";
  else if (token == "hash")
    engLetter = "h";
  else if (token == "kuck")
    engLetter = "k";
  else if (token == "wack")
    engLetter = "w";
  else if (token == "bub")
    engLetter = "b";
  else if (token == "dud")
    engLetter = "d";
  else if (token == "fuf")
    engLetter = "f";
  else if (token == "gug")
    engLetter = "g";
  else if (token == "jay")
    engLetter = "j";
  else if (token == "lul")
    engLetter = "l";
  else if (token == "mum")
    engLetter = "m";
  else if (token == "nun")
    engLetter = "n";
  else if (token == "pub")
    engLetter = "p";
  else if (token == "rug")
    engLetter = "r";
  else if (token == "sus")
    engLetter = "s";
  else if (token == "tut")
    engLetter = "t";
  else if (token == "vuv")
    engLetter = "v";
  else if (token == "yub")
    engLetter = "y";
  else if (token == "zub")
    engLetter = "z";
  else if (token == "ex")
    engLetter = "x";
  else if (token == "a")
    engLetter = "a";
  else if (token == "e")
    engLetter = "e";
  else if (token == "i")
    engLetter = "i";
  else if (token == "o")
    engLetter = "o";
  else if (token == "u")
    engLetter = "u";
  else if (token == ",")
    engLetter = ",";
  else if (token == "<")
    engLetter = "<";
  else if (token == ".")
    engLetter = ".";
  else if (token == ">")
    engLetter = ">";
  else if (token == "?")
    engLetter = "?";
  else if (token == ":")
    engLetter = ":";
  else if (token == ";")
    engLetter = ";";
  else if (token == "{")
    engLetter = "{";
  else if (token == "}")
    engLetter = "}";
  else if (token == "`")
    engLetter = "`";
  else if (token == "~")
    engLetter = "~";
  else if (token == "!")
    engLetter = "!";
  else if (token == "@")
    engLetter = "@";
  else if (token == "#")
    engLetter = "#";
  else if (token == "$")
    engLetter = "$";
  else if (token == "%")
    engLetter = "%";
  else if (token == "^")
    engLetter = "^";
  else if (token == "&")
    engLetter = "&";
  else if (token == "*")
    engLetter = "*";
  else if (token == "(")
    engLetter = "(";
  else if (token == ")")
    engLetter = ")";
  else if (token == "_")
    engLetter = "_";
  else if (token == "+")
    engLetter = "+";
  else if (token == "=")
    engLetter = "=";
  else //if no tut sequence found
    return ""; //will return invalid tut error message and program exit

  if (firstUpper && isalpha(engLetter[0])) {
    engLetter[0] = toupper(engLetter[0]); //return first char to uppercase
  }

  return engLetter;
}
