#include "comenzi_pizza_enum.h"
#include "meniu.h"
#include <fstream>
#include <sstream>

int main() {
  /* teste */
  /* Ingredient ing; */
  /* std::cin >> ing; */
  /* std::cout << ing; */

  /* PizzaOnline p; */
  /* std::cout << "citire pizza:\n"; */
  /* std::cin >> p; */
  /* std::cout << p; */
  /* std::cout << p.pret(); */

  /* comenzi >> meniu_pizza_local; */
  /* comenzi >> meniu_pizza_online; */

  /* vom avea 2 meniuri pentru comenzi locale si online
   * intrucat o sa avem 2 rapoarte diferite de facut */
  Meniu<Pizza> meniu_pizza_local;
  Meniu<PizzaOnline> meniu_pizza_online;

  std::ifstream comenzi("comenzi.in"); /* de unde vom citi comenzile */
  if (!comenzi.is_open()) { /* fisierul nu exista sau nu a putut fi deschis */
    std::cout << "Nu exista comenzi; Adaugati comenzile in fisierul meniu.in\n";
    comenzi.close();
    return -1;
    /* comenzi >> meniu_pizza_local; */
    /* comenzi >> meniu_pizza_online; */
  } else {
    std::string comanda; /* fiecare comanda se afla pe cate un rand */

    /* citim toate comenzile din meniu */
    while (std::getline(comenzi, comanda)) {
      /* transformam stringul citit intr-un stream */
      std::istringstream iss_comanda(comanda);

      Pizza *pizza = nullptr; /* detalii despre o noua comanda de pizza */

      /* obtinem tipul comenzii */
      std::string tip_comanda;
      iss_comanda >> tip_comanda;

      /* verificam daca comanda este valida */
      if (!(map_comenzi_pizza.find(tip_comanda) != map_comenzi_pizza.end()))
        break;

      /* TODO schimba aici dintr-un if/else intr-un switch bazat pe un enum
       * class de tip comenzi, ar fi mai util daca se mai adauga tipuri de pizza
       */

      switch (map_comenzi_pizza[tip_comanda]) {
      case PizzaType::LOCAL:
        pizza = new Pizza();
        iss_comanda >> *pizza;
        meniu_pizza_local += pizza;
        break;

      case PizzaType::ONLINE:
        pizza = new PizzaOnline();
        iss_comanda >> *dynamic_cast<PizzaOnline *>(pizza);
        meniu_pizza_online += dynamic_cast<PizzaOnline *>(pizza);
        break;

      default:
        break;
      }
    }
  }

  comenzi.close();

  std::ofstream fo_meniu_pizza_local("meniu_pizza_local.out");
  if (!fo_meniu_pizza_local.is_open()) {
    /* fisierul nu exista sau nu a putut fi deschis */
    std::cout
        << "EROARE! Nu a putut fi creat raportul pentru pizza servita local\n";
  } else {
    /* scrie raportul pentru pizza locala */
    fo_meniu_pizza_local << meniu_pizza_local;
  }
  fo_meniu_pizza_local.close();

  std::ofstream fo_meniu_pizza_online("meniu_pizza_online.out");
  if (!fo_meniu_pizza_online.is_open()) {
    /* fisierul nu exista sau nu a putut fi deschis */
    std::cout
        << "EROARE! Nu a putut fi creat raportul pentru pizza servita online\n";
  } else {
    /* scrie raportul pentru pizza locala */
    fo_meniu_pizza_online << meniu_pizza_online;
  }
  fo_meniu_pizza_online.close();

  return 0;
}
