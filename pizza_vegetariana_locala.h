#ifndef PIZZA_VEGETARIANA_LOCALA_H
#define PIZZA_VEGETARIANA_LOCALA_H

#include "pizza.h"

class PizzaVegetarianaLocala : public Pizza {
public:
  PizzaVegetarianaLocala(); /* constructor de initializare */

  /* constructor de copiere, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaVegetarianaLocala(const PizzaVegetarianaLocala &pizza);

  virtual ~PizzaVegetarianaLocala();

  virtual double pret() const override;

  /* operatorul=, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaVegetarianaLocala &operator=(const PizzaVegetarianaLocala &pizza);

  /* citim informatiile despre o pizza dintr-un input stream */
  friend std::istream &operator>>(std::istream &in,
                                  PizzaVegetarianaLocala &pizza);

  /* scriem id-ul pizzei, ingredientele sale si pretul livrare */
  friend std::ostream &operator<<(std::ostream &out,
                                  const PizzaVegetarianaLocala &pizza);
};

#endif
