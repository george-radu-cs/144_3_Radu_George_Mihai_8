#include "pizza_online.h"

PizzaOnline::PizzaOnline() : Pizza() {}

PizzaOnline::PizzaOnline(const PizzaOnline &pizza) : Pizza(pizza) {
  m_distanta = pizza.m_distanta;
}

PizzaOnline::~PizzaOnline() {}

void PizzaOnline::setIngrediente(const std::vector<Ingredient *> &ingrediente) {
  Pizza::setIngrediente(ingrediente);
}

void PizzaOnline::setDistanta(const double distanta) { m_distanta = distanta; }

double PizzaOnline::pret() const {
  /* obtinem pretul normal pentru pizza */
  double pret = Pizza::pret();

  /* taxa livrare + 5% din pret la fiecare 10km */
  pret += (pret / 20) * (m_distanta / 10);

  return pret;
}

PizzaOnline &PizzaOnline::operator=(const PizzaOnline &pizza) {
  if (this != &pizza) {
    Pizza::operator=(pizza);
    this->m_distanta = pizza.m_distanta;
  }

  return *this;
}

std::istream &operator>>(std::istream &in, PizzaOnline &pizza) {
  /* citim informatiile despre pizza locala */
  in >> dynamic_cast<Pizza &>(pizza);

  /* citim restul de informatii specifice unei pizza online, i.e. distanta de
   * livrare */
  std::string str; /* vom retine inputul intr-un string pe care vom incerca sa
                    il convertim intr-un double */
  in >> str;
  pizza.m_distanta = StringToDouble(str);

  return in;
}

std::ostream &operator<<(std::ostream &out, const PizzaOnline &pizza) {
  /* afisam informatiile pe care le afisam despre o pizza servita local   */
  out << dynamic_cast<const Pizza &>(pizza);

  /* in plus afisam distanta de livrare */
  out << "Distanta: " << pizza.m_distanta << '\n';

  return out;
}
