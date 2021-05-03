#include "pizza_online.h"

PizzaOnline::PizzaOnline() : Pizza() {}

PizzaOnline::PizzaOnline(const PizzaOnline &pizza) : Pizza(pizza) {
  m_distanta = pizza.m_distanta;
}

PizzaOnline::~PizzaOnline() {}

double PizzaOnline::pret() const {
  /* obtinem pretul normal pentru pizza */
  double pret = Pizza::pret();

  /* taxa livrare + 5% din pret la fiecare 10km */
  pret += (pret / 20) * (m_distanta / 10);

  return pret;
}

PizzaOnline &PizzaOnline::operator=(const PizzaOnline &pizza) {
  if (this != &pizza) {
  }

  return *this;
}

std::istream &operator>>(std::istream &in, PizzaOnline &pizza) {
  in >> dynamic_cast<Pizza &>(pizza);

  std::string str; /* vom retine inputul intr-un string pe care vom incerca sa
                    il convertim intr-un double */
  in >> str;
  pizza.m_distanta = StringToInt(str);

  return in;
}

std::ostream &operator<<(std::ostream &out, const PizzaOnline &pizza) {
  out << dynamic_cast<const Pizza &>(pizza);
  out << "Distanta: " << pizza.m_distanta << '\n';

  return out;
}
