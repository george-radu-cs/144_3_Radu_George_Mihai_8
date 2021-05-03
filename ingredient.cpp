#include "ingredient.h"

Ingredient::Ingredient()
    : m_denumire(""), m_cantitate(0.0), m_pret_unitar(0.0) {}

Ingredient::Ingredient(std::string denumire, double cantitate,
                       double pret_unitar)
    : m_denumire(denumire), m_cantitate(cantitate), m_pret_unitar(pret_unitar) {
}

Ingredient::Ingredient(const Ingredient &ingredient) {
  m_denumire = ingredient.getDenumire();
  m_cantitate = ingredient.getCantitate();
  m_pret_unitar = ingredient.getPretUnitar();
}

Ingredient::~Ingredient() {}

Ingredient &Ingredient::operator=(const Ingredient &ing) {
  if (this != &ing) {
    m_denumire = ing.getDenumire();
    m_cantitate = ing.getCantitate();
    m_pret_unitar = ing.getPretUnitar();
  }

  return *this;
}

std::istream &operator>>(std::istream &in, Ingredient &ing) {
  /* TODO add here a try catch  */
  in >> ing.m_denumire >> ing.m_cantitate >> ing.m_pret_unitar;

  return in;
}

std::ostream &operator<<(std::ostream &out, const Ingredient &ing) {
  out << ing.m_denumire << " " << ing.m_cantitate << " " << ing.m_pret_unitar;

  return out;
}
