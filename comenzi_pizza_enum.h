#ifndef COMENZI_PIZZA_ENUM_H
#define COMENZI_PIZZA_ENUM_H

#include <map>
#include <string>

/* tipuri de pizza servite */
enum class PizzaType {
  LOCAL,
  ONLINE,
  VEGETARIANA_LOCALA,
  VEGETARIANA_ONLINE,

  MAX_PIZZA_TYPE
};

std::map<std::string, PizzaType> map_comenzi_pizza = {
    {"local", PizzaType::LOCAL},
    {"online", PizzaType::ONLINE},
    {"vegetariana_locala", PizzaType::VEGETARIANA_LOCALA},
    {"vegetariana_online", PizzaType::VEGETARIANA_ONLINE}};

#endif
