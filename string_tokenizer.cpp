#include "string_tokenizer.h"

StringTokenizer::StringTokenizer() { it = tokens.begin(); }

StringTokenizer::StringTokenizer(std::string &str, const char *delim) {
  /* convertim str din string in array de chars */

  /* metodele string size si length au complexitatea nespecificata pana la C++11
   * si O(1) de la C++11 inclusiv, motiv pentru care nu salvam sizeul intr-un
   * int pentru a nu-l calcula de 3 ori */
  char cstr[str.size() + 1];
  str.copy(cstr, str.size() + 1);
  cstr[str.size()] = '\0';

  /* construim tokenii */
  char *token;
  char *rest = cstr; /* retine pointerul */
  while ((token = strtok_r(rest, delim, &rest))) {
    tokens.push_back(token);
  }

  /* stabilim iteratorul pentru tokens */
  it = tokens.begin();
}

StringTokenizer::~StringTokenizer() {}

std::string StringTokenizer::getNextToken() { return *it++; }

bool StringTokenizer::hasMoreTokens() { return it != tokens.end(); }
