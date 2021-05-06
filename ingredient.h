#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include "functions.h"

class Ingredient {
private:
  std::string m_denumire; /* denumirea ingredientului */
  double m_cantitate; /* cantitatea in u.m. in functie de ce ingredient e */
  double m_pret_unitar; /* pretul unitar in lei */

public:
  Ingredient();

  Ingredient(std::string denumire, double cantitate, double pret_unitar);

  Ingredient(const Ingredient &ing);

  ~Ingredient();

  /* getters */
  std::string getDenumire() const { return m_denumire; }

  double getCantitate() const { return m_cantitate; }

  double getPretUnitar() const { return m_pret_unitar; }

  /* setters */
  void setDenumire(std::string denumire) { m_denumire = denumire; }

  void setCantitate(double cantitate) { m_cantitate = cantitate; }

  void setPretUnitar(double pret_unitar) { m_pret_unitar = pret_unitar; }

  Ingredient &operator=(const Ingredient &ing);

  /* citim informatiile despre un ingredient */
  friend std::istream &operator>>(std::istream &in, Ingredient &ing);

  /* afisam toate informatiile despre ingredient separate de un spatiu */
  friend std::ostream &operator<<(std::ostream &out, const Ingredient &ing);
};

#endif
