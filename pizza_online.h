#ifndef PIZZA_ONLINE_H
#define PIZZA_ONLINE_H

#include "pizza.h"

class PizzaOnline : public Pizza {
private:
  double m_distanta; /* distanta de la pizzerie pana la locul de livrare */

public:
  PizzaOnline(); /* constructor de initializare */

  /* constructor de copiere, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaOnline(const PizzaOnline &pizza);

  ~PizzaOnline();

  /* calculeaza pretul pizzei: pretul pizzei daca era servita local + 5% din
   * acest pret la fiecare 10Km din distanta de livrare */
  virtual double pret() const override;

  /* operatorul=, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  PizzaOnline &operator=(const PizzaOnline &pizza);

  /* citim informatiile despre o pizza dintr-un input stream */
  friend std::istream &operator>>(std::istream &in, PizzaOnline &pizza);

  /* scriem id-ul pizzei, ingredientele sale, pretul si distanta de
   * livrare */
  friend std::ostream &operator<<(std::ostream &out, const PizzaOnline &pizza);
};

#endif
