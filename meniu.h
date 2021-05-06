#ifndef MENIU_TEMPLATE_H
#define MENIU_TEMPLATE_H

#include "comenzi_pizza_enum.h"
#include "pizza_vegetariana_locala.h"
#include "pizza_vegetariana_online.h"
#include <sstream>
#include <unordered_map>

template <class T> class Meniu;

template <class T> std::istream &operator>>(std::istream &in, Meniu<T> &meniu);

template <class T>
std::ostream &operator<<(std::ostream &out, const Meniu<T> &meniu);

template <class T> class Meniu {
private:
  /* retine un meniu */
  /* foloseste pointer catre un obiect de tip produs intrucat din el vom crea
   * mai multe tipuri de pizza, sau din clasa de pizza TODO alege varianta */
  std::unordered_map<int, T *> m_comenzi;

  /* id-ul unei pizza in meniu trebuie sa fie unic, putem folosi acest id si
   * pentru a afla cate pizza se afla intr-un meniu */
  static int s_id_pizza;

public:
  Meniu() {}

  Meniu(const Meniu<T> &meniu) {}

  ~Meniu() {}

  static void incrementeazaIdPizza() { s_id_pizza++; }

  Meniu<T> &operator=(const Meniu<T> &meniu) {
    if (this != &meniu) {
      for (const std::pair<int, T *> &comanda : meniu.m_comenzi) {
        m_comenzi.insert(
            std::make_pair<int, T *>(comanda.first, comanda.second));
      }
    }

    return *this;
  }

  Meniu<T> &operator+=(T *pizza) {

    m_comenzi.insert(std::make_pair<int, T *>(
        static_cast<int>(Meniu<T>::s_id_pizza), static_cast<T *>(pizza)));
    incrementeazaIdPizza();

    return *this;
  }

  friend std::istream &operator>><>(std::istream &in, Meniu<T> &meniu);

  friend std::ostream &operator<<<>(std::ostream &out, const Meniu<T> &meniu);
};

template <class T> int Meniu<T>::s_id_pizza = 0;

template <class T> std::istream &operator>>(std::istream &in, Meniu<T> &meniu) {
  std::string comanda; /* retinem o comanda */

  /* cat timp nu mai avem comenzi de preluat */
  while (std::getline(in, comanda)) {
    std::istringstream iss_comanda(comanda);

    std::string tip_comanda;
    iss_comanda >> tip_comanda;

    /* acceptam doar pizza comanda in local */
    if (map_comenzi_pizza[tip_comanda] != PizzaType::LOCAL)
      continue;

    /* citim comanda de pizza */
    T *pizza = new T;
    iss_comanda >> *pizza;

    /* adaugam comanda in evidenta */
    meniu.m_comenzi.insert(std::make_pair<int, T *>(
        static_cast<int>(Meniu<T>::s_id_pizza), static_cast<T *>(pizza)));

    Meniu<T>::incrementeazaIdPizza();
  }

  return in;
}

/* specializare */
template <>
std::istream &operator>>(std::istream &in, Meniu<PizzaOnline> &meniu) {
  std::string comanda; /* retinem o comanda */

  /* cat timp nu mai avem comenzi de preluat */
  while (std::getline(in, comanda)) {
    std::istringstream iss_comanda(comanda);

    std::string tip_comanda;
    iss_comanda >> tip_comanda;

    /* acceptam doar pizza comanda in local */
    if (map_comenzi_pizza[tip_comanda] != PizzaType::ONLINE)
      continue;

    /* citim comanda de pizza */
    PizzaOnline *pizza = new PizzaOnline;
    iss_comanda >> *pizza;

    /* adaugam comanda in evidenta */
    meniu.m_comenzi.insert(std::make_pair<int, PizzaOnline *>(
        static_cast<int>(Meniu<PizzaOnline>::s_id_pizza),
        static_cast<PizzaOnline *>(pizza)));

    Meniu<PizzaOnline>::incrementeazaIdPizza();
  }

  return in;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Meniu<T> &meniu) {
  double venit{0.0};

  for (const std::pair<int, T *> &comanda : meniu.m_comenzi) {
    out << "Cheie: " << comanda.first << " valoare: " << *comanda.second
        << "\n";
    venit += comanda.second->pret();
  }

  out << "Venit: " << venit << '\n';

  return out;
}

#endif
