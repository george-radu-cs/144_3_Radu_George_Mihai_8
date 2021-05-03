#ifndef COMENZI_PIZZA_ENUM_H
#define COMENZI_PIZZA_ENUM_H

#include <map>
#include <string>

/* tipuri de pizza servite */
enum class PizzaType {
  LOCAL,
  ONLINE,

  MAX_PIZZA_TYPE
};

std::map<std::string, PizzaType> map_comenzi_pizza = {
    {"local", PizzaType::LOCAL}, {"online", PizzaType::ONLINE}};

#endif
