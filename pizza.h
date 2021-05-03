#ifndef PIZZA_H
#define PIZZA_H

#include "ingredient.h"
#include "produs.h"
#include <vector>

class Pizza : public Produs {
protected:
  std::vector<Ingredient *> m_ingrediente;
  constexpr static double m_pret_manopera = 15.0;

public:
  Pizza();

  Pizza(const Pizza &pizza);

  virtual ~Pizza();

  virtual double pret() const override;

  Pizza &operator=(const Pizza &pizza);

  friend std::istream &operator>>(std::istream &in, Pizza &pizza);

  friend std::ostream &operator<<(std::ostream &out, const Pizza &pizza);
};

#endif
