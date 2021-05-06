#include "pizza_vegetariana_online.h"

PizzaVegetarianaOnline::PizzaVegetarianaOnline() : PizzaOnline() {}

PizzaVegetarianaOnline::PizzaVegetarianaOnline(
    const PizzaVegetarianaOnline &pizza)
    : PizzaOnline(pizza) {}

PizzaVegetarianaOnline::~PizzaVegetarianaOnline() {}

double PizzaVegetarianaOnline::pret() const { return Pizza::pret(); }

PizzaVegetarianaOnline &
PizzaVegetarianaOnline::operator=(const PizzaVegetarianaOnline &pizza) {
  if (this != &pizza) {
    Pizza::operator=(pizza);
  }

  return *this;
}

std::istream &operator>>(std::istream &in, PizzaVegetarianaOnline &pizza) {
  in >> dynamic_cast<PizzaOnline &>(pizza);

  return in;
}

std::ostream &operator<<(std::ostream &out,
                         const PizzaVegetarianaOnline &pizza) {
  out << dynamic_cast<const PizzaOnline &>(pizza);

  return out;
}
