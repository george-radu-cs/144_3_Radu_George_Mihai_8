#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include <regex>
#include <string>
#include <vector>

class StringTokenizer {
private:
  std::vector<std::string> tokens;
  std::vector<std::string>::iterator it;

public:
  StringTokenizer();

  StringTokenizer(std::string &str, const char *delim);

  ~StringTokenizer();

  std::string getNextToken();

  bool hasMoreTokens();
};

#endif
