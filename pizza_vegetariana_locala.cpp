#include "pizza_vegetariana_locala.h"

PizzaVegetarianaLocala::PizzaVegetarianaLocala() : Pizza() {}

PizzaVegetarianaLocala::PizzaVegetarianaLocala(
    const PizzaVegetarianaLocala &pizza)
    : Pizza(pizza) {}

PizzaVegetarianaLocala::~PizzaVegetarianaLocala() {}

void PizzaVegetarianaLocala::setIngrediente(const std::vector<Ingredient *> &ingrediente){
  Pizza::setIngrediente(ingrediente);
}

double PizzaVegetarianaLocala::pret() const { return Pizza::pret(); }

PizzaVegetarianaLocala &
PizzaVegetarianaLocala::operator=(const PizzaVegetarianaLocala &pizza) {
  if (this != &pizza) {
    Pizza::operator=(pizza);
  }

  return *this;
}

std::istream &operator>>(std::istream &in, PizzaVegetarianaLocala &pizza) {
  in >> dynamic_cast<Pizza &>(pizza);

  return in;
}

std::ostream &operator<<(std::ostream &out, const PizzaVegetarianaLocala &pizza) {
  out << dynamic_cast<const Pizza &>(pizza);

  return out;
}
