#include "ModelT2E.h"

ModelT2E::ModelT2E() {} //default constructor
ModelT2E::~ModelT2E() {} //destructor

string tolowercase(string word) {
  /* Turns entire strings into lowercase */
  for (int i = 0; i < word.size(); ++i)
    if (isupper(word[i]))
      word[i] = tolower(word[i]);
  return word;
}

string tokenFinder(string tutWord) {
  /* Regex initializization. Allows to read all kinds of caps input. 1 is vowels,
  2-5 are normal tut tokens, and 6 is double letter tokens */
  regex regex1("[aeiouAEIOU]");
  regex regex2("[eE][xX]");
  regex regex3("[bB][uU][bB]|[dD][uU][dD]|[fF][uU][fF]|[gG][uU][gG]|[jJ][aA][yY]|[lL][uU][lL]|[mM][uU][mM]|[nN][uU][nN]|[pP][uU][bB]|[rR][uU][gG]|[sS][uU][sS]|[tT][uU][tT]|[vV][uU][vV]|[yY][uU][bB]|[zZ][uU][bB]");
  regex regex4("[cC][aA][sS][hH]|[hH][aA][sS][hH]|[kK][uU][cC][kK]|[wW][aA][cC][kK]");
  regex regex5("[qQ][uU][aA][cC][kK]");
  regex regex6("[sS][qQ][uU][aA][tT][aA]|[sS][qQ][uU][aA][tT][eE]|[sS][qQ][uU][aA][tT][iI]|[sS][qQ][uU][aA][tT][oO]|[sS][qQ][uU][aA][tT][uU]");

  if (tutWord.length() >= 6) { //search for double (in tut)
    if (regex_match(tutWord.substr(0, 6), regex6)) {
      return tutWord.substr(0, 6);
    }
  }
  if (tutWord.length() >= 5) {
    if (regex_match(tutWord.substr(0,5), regex5)) {
      return tutWord.substr(0 ,5);
    }
  }
  if (tutWord.length() >= 4) {
    if (regex_match(tutWord.substr(0, 4), regex4)) {
      return tutWord.substr(0, 4);
    }

  }
  if (tutWord.length() >= 3) {
    if (regex_match(tutWord.substr(0, 3), regex3)) {
      return tutWord.substr(0, 3);
    }

  }
  if (tutWord.length() >= 2) {
    if (regex_match(tutWord.substr(0, 2), regex2)) {
      return tutWord.substr(0, 2);
    }

  }
  if (tutWord.length() >= 1) { //search for vowels
    if (regex_match(tutWord.substr(0, 1), regex1)) {
      return tutWord.substr(0, 1);
    }
  }

  return ""; //leads to program exit and error message
}

string tokenConverter(string token) {
  token = tolowercase(token); //lowercase for standardization

  if (token == "squata")
    return "aa";
  if (token == "squate")
    return "ee";
  if (token == "squati")
    return "ii";
  if (token == "squato")
    return "oo";
  if (token == "squatu")
    return "uu";
  if (token == "quack")
    return "q";
  if (token == "cash")
    return "c";
  if (token == "hash")
    return "h";
  if (token == "kuck")
    return "k";
  if (token == "wack")
    return "w";
  if (token == "bub")
    return "b";
  if (token == "dud")
    return "d";
  if (token == "fuf")
    return "f";
  if (token == "gug")
    return "g";
  if (token == "jay")
    return "j";
  if (token == "lul")
    return "l";
  if (token == "mum")
    return "m";
  if (token == "nun")
    return "n";
  if (token == "pub")
    return "p";
  if (token == "rug")
    return "r";
  if (token == "sus")
    return "s";
  if (token == "tut")
    return "t";
  if (token == "vuv")
    return "v";
  if (token == "yub")
    return "y";
  if (token == "zub")
    return "z";
  if (token == "ex")
    return "x";
  if (token == "a")
    return "a";
  if (token == "e")
    return "e";
  if (token == "i")
    return "i";
  if (token == "o")
    return "o";
  if (token == "u")
    return "u";

  return ""; //will return error message and program exit
}
