#ifndef PIZZA_ONLINE_H
#define PIZZA_ONLINE_H

#include "pizza.h"

class PizzaOnline : public Pizza {
private:
  double m_distanta;

public:
  PizzaOnline();

  PizzaOnline(const PizzaOnline &pizza);

  ~PizzaOnline();

  virtual double pret() const override;

  PizzaOnline &operator=(const PizzaOnline &pizza);

  friend std::istream &operator>>(std::istream &in, PizzaOnline &pizza);

  friend std::ostream &operator<<(std::ostream &out, const PizzaOnline &pizza);
};

#endif
