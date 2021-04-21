#include "pizza.h"
#include <unordered_map>

template <class T> class Meniu {
private:
  /* retine un meniu */
  /* foloseste pointer catre un obiect de tip produs intrucat din el vom crea
   * mai multe tipuri de pizza, sau din clasa de pizza TODO alege varianta */
  std::unordered_map<int, T *> comenzi;

  /* id-ul unei pizza in meniu trebuie sa fie unic, putem folosi acest id si
   * pentru a afla cate pizza se afla intr-un meniu */
  static int id_pizza;

public:
  Meniu();

  Meniu(const Meniu &meniu);

  ~Meniu();

  Meniu &operator=(const Meniu &meniu);

  friend std::istream &operator>>(std::istream &in, Meniu &meniu);

  friend std::ostream &operator<<(std::ostream &out, const Meniu &meniu);
};

template <class T> int Meniu<T>::id_pizza = 0;
