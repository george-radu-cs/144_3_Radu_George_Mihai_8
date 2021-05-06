#ifndef PIZZA_VEGETARIANA_ONLINE_H
#define PIZZA_VEGETARIANA_ONLINE_H

#include "pizza_online.h"

class PizzaVegetarianaOnline : public PizzaOnline {
public:
  PizzaVegetarianaOnline(); /* constructor de initializare */

  /* constructor de copiere, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaVegetarianaOnline(const PizzaVegetarianaOnline &pizza);

  virtual ~PizzaVegetarianaOnline();

  virtual double pret() const override;

  /* operatorul=, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaVegetarianaOnline &operator=(const PizzaVegetarianaOnline &pizza);

  /* citim informatiile despre o pizza dintr-un input stream */
  friend std::istream &operator>>(std::istream &in,
                                  PizzaVegetarianaOnline &pizza);

  /* scriem id-ul pizzei, ingredientele sale si pretul livrare */
  friend std::ostream &operator<<(std::ostream &out,
                                  const PizzaVegetarianaOnline &pizza);
};

#endif
