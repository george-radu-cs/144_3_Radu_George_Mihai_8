#include "functions.h"

/* functie de convertire din string in double - in caz de erori arunca exceptii
 * care nu sunt tratate aici, trebuie prinse atunci cand este apelata functia */
double StringToDouble(std::string &str) {
  /* daca stringul este gol nu avem la ce valori sa il convertim */
  if (str.length() == 0) {
    throw IsEmpty(str);
  }

  /* verifica daca sunt litere in string */
  if (std::any_of(str.begin(), str.end(), isalpha)) {
    throw NotADouble(str);
  }

  /* calculam maximul de cifre care pot forma un double */
  int max_digits_double = 3 + DBL_MANT_DIG - DBL_MIN_EXP;
  /* verificam pentru overflow */
  if (str.length() > static_cast<long unsigned int>(max_digits_double)) {
    throw Overflow(str);
  }

  double result{0};
  result = std::stod(str);

  /* valoarea nu poate sa fie 0 */
  if (result == 0) {
    throw NotZero(str);
  }

  return result;
}

/* functie de convertire din string in int - in caz de erori arunca exceptii
 * care nu sunt tratate aici, trebuie prinse atunci cand este apelata functia */
int StringToInt(std::string &str) {
  /* daca stringul este gol nu avem la ce valori sa il convertim */
  if (str.length() == 0) {
    throw IsEmpty(str);
  }

  /* verifica daca sunt litere in string */
  if (std::any_of(str.begin(), str.end(), isalpha)) {
    throw NotAnInt(str);
  }

  /* calculam maximul de cifre care pot forma un double */
  int max_digits_int = std::to_string(INT32_MIN).length();
  /* verificam pentru overflow */
  if (str.length() > static_cast<long unsigned int>(max_digits_int)) {
    throw Overflow(str);
  }

  int result = std::stoi(str);

  /* valoarea nu poate sa fie 0 */
  if (result == 0) {
    throw NotZero(str);
  }

  return result;
}
