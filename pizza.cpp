#include "pizza.h"

Pizza::Pizza() {}

Pizza::Pizza(const Pizza &pizza) {
  for (const auto &ing : m_ingrediente) {
    Ingredient *new_ing = new Ingredient();
    new_ing->setDenumire(ing->getDenumire());
    new_ing->setCantitate(ing->getCantitate());
    new_ing->setPretUnitar(ing->getPretUnitar());
    m_ingrediente.push_back(new_ing);
  }
}

Pizza::~Pizza() {
  /* stergem pointerii din vector */
  for (auto *p : m_ingrediente) {
    delete p;
  }
  m_ingrediente.clear();
}

double Pizza::pret() const {
  double pret{0};

  /* calculeaza pretul ingredientelor */
  for (const auto &ing : m_ingrediente) {
    pret += ing->getCantitate() * ing->getPretUnitar();
  }

  /* adauga pretul manoperei */
  pret += m_pret_manopera;

  return pret;
}

Pizza &Pizza::operator=(const Pizza &pizza) {
  if (this != &pizza) {
    for (const auto &ing : m_ingrediente) {
      Ingredient *new_ing = new Ingredient();
      new_ing->setDenumire(ing->getDenumire());
      new_ing->setCantitate(ing->getCantitate());
      new_ing->setPretUnitar(ing->getPretUnitar());
      m_ingrediente.push_back(new_ing);
    }
  }

  return *this;
}

std::istream &operator>>(std::istream &in, Pizza &pizza) {
  std::string str; /* vom retine inputul intr-un string pe care vom incerca sa
                      il convertim intr-un int */
  in >> str;
  int n = StringToInt(str); /* nr ingrediente */

  for (int i = 0; i < n; i++) { /* incercam sa citim cele n ingrediente */
    Ingredient *ing = new Ingredient();

    /* citirea ingredientelor ar putea intoarce un throw in cazul in care nu
     * s-au primit informatii, caz in care avem in plus si exceptia cand numarul
     * de ingrediente spuse ca vor fi primite nu a fost egal cu cele primite */
    try {
      in >> *ing;
    } catch (const IsEmpty &e) {
      std::cout << e.what() << " | ";
      throw InvalidNumberIngredients("received " + std::to_string(n));
    }

    /* daca ingredientul a fost citit corect atunci il putem adauga in lista de
     * ingrediente */
    pizza.m_ingrediente.push_back(ing);
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const Pizza &pizza) {
  out << "Lista ingrediente pizza:\n";
  for (const auto *ing : pizza.m_ingrediente) {
    out << *ing << '\n';
  }
  out << "Pret: " << pizza.pret() << '\n';

  return out;
}
