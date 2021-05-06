#ifndef PIZZA_H
#define PIZZA_H

#include "ingredient.h"
#include "produs.h"
#include <sstream>
#include <string>
#include <vector>

class Pizza : public Produs {
protected:
  /* ingredientele necesare pentru gatirea pizzei */
  std::vector<Ingredient *> m_ingrediente;

  /* pretul manoperei pentru gatirea pizzei, valoarea este stabilita aici
   * intrucat este o constanta stabilita de pizzerie */
  constexpr static double m_pret_manopera = 15.0;

public:
  Pizza(); /* constructor initializare */

  /* constructor de copiere, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  Pizza(const Pizza &pizza);

  virtual ~Pizza();

  /* calculeaza pretul pizzei (pret ingrediente + manopera) */
  virtual double pret() const override;

  /* operatorul=, in cazul in care se fac mai multe comenzi de
   * acelasi tip */
  Pizza &operator=(const Pizza &pizza);

  /* citim informatiile despre o pizza dintr-un input stream */
  friend std::istream &operator>>(std::istream &in, Pizza &pizza);

  /* scriem id-ul pizzei, ingredientele sale si pretul */
  friend std::ostream &operator<<(std::ostream &out, const Pizza &pizza);
};

#endif
