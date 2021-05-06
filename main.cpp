#include "comenzi_pizza_enum.h"
#include "meniu.h"
#include <fstream>

int main() {
  //////////////////////////////////////////////////
  /********************** teste *******************/
  //////////////////////////////////////////////////

  /* std::ifstream fin("comenzi.in"); /1* de unde vom citi comenzile *1/ */
  /* PizzaVegetarianaLocala *pizza = new PizzaVegetarianaLocala(); */
  /* std::string tip; */
  /* fin >> tip; */
  /* fin >> *pizza; */
  /* PizzaVegetarianaLocala *pizza2 = new PizzaVegetarianaLocala(*pizza); */
  /* PizzaVegetarianaLocala *pizza3 = new PizzaVegetarianaLocala(); */
  /* *pizza3 = *pizza; */
  /* std::cout << *pizza << *pizza2 << *pizza3; */
  /* delete pizza; */
  /* std::cout << *pizza2; */
  /* delete pizza2; */
  /* std::cout << *pizza3; */
  /* delete pizza3; */

  /* fin.close(); */
  /* Ingredient ing; */
  /* std::cin >> ing; */
  /* std::cout << ing; */

  /* Pizza p1; */
  /* PizzaOnline p2; */
  /* std::cout << typeid(p1).name() << " " << typeid(p2).name(); */
  /* std::cout << "citire pizza:\n"; */
  /* std::cin >> p; */
  /* std::cout << p; */
  /* std::cout << p.pret(); */

  /* comenzi >> meniu_pizza_local; */
  /* comenzi >> meniu_pizza_online; */

  //////////////////////////////////////////////////
  /******************* program ********************/
  //////////////////////////////////////////////////

  /* vom avea 2 meniuri pentru comenzi locale si online
   * intrucat o sa avem 2 rapoarte diferite de facut */
  Meniu<Pizza> meniu_pizza_local;
  Meniu<PizzaOnline> meniu_pizza_online;
  Meniu<PizzaVegetarianaOnline> meniu_pizza_veg_online;

  std::ifstream comenzi("comenzi.in"); /* de unde vom citi comenzile */
  if (!comenzi.is_open()) { /* fisierul nu exista sau nu a putut fi deschis  */
    std::cout << "Nu exista comenzi; Adaugati comenzile in fisierul meniu.in\n";
    comenzi.close();
    return -1;
    comenzi >> meniu_pizza_local;
    comenzi >> meniu_pizza_online;
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
      if (!(map_comenzi_pizza.find(tip_comanda) != map_comenzi_pizza.end())) {
        try {
          throw InvalidPizzaType(tip_comanda);
        } catch (const InvalidPizzaType &e) {
          std::cout << e.what() << '\n';
        }
        continue;
      }

      switch (map_comenzi_pizza[tip_comanda]) {
      case PizzaType::LOCAL:
        pizza = new Pizza();
        try {
          iss_comanda >> *pizza;
          meniu_pizza_local += pizza;
        } catch (const IsEmpty &e) {
          std::cout << e.what() << '\n';
        } catch (const NotAnInt &e) {
          std::cout << e.what() << '\n';
        } catch (const NotADouble &e) {
          std::cout << e.what() << '\n';
        } catch (const Overflow &e) {
          std::cout << e.what() << '\n';
        } catch (const NotZero &e) {
          std::cout << e.what() << '\n';
        } catch (const std::invalid_argument &e) {
          std::cout << e.what() << '\n';
        }
        break;

      case PizzaType::ONLINE:
        pizza = new PizzaOnline();
        try {
          iss_comanda >> *dynamic_cast<PizzaOnline *>(pizza);
          meniu_pizza_online += dynamic_cast<PizzaOnline *>(pizza);
        } catch (std::exception &e) { /* prinde toate tipurile de exceptii */
          std::cout << e.what() << '\n';
        }
        break;

      case PizzaType::VEGETARIANA_LOCALA:
        pizza = new PizzaVegetarianaLocala();
        try {
          iss_comanda >> *dynamic_cast<PizzaVegetarianaLocala *>(pizza);
          meniu_pizza_local += dynamic_cast<PizzaVegetarianaLocala *>(pizza);
        } catch (const std::invalid_argument &e) {
          std::cout << e.what() << '\n';
        }
        break;

      case PizzaType::VEGETARIANA_ONLINE:
        pizza = new PizzaVegetarianaOnline();
        try {
          iss_comanda >> *dynamic_cast<PizzaVegetarianaOnline *>(pizza);
          meniu_pizza_veg_online +=
              dynamic_cast<PizzaVegetarianaOnline *>(pizza);
        } catch (std::exception &e) { /* prinde toate tipurile de exceptii */
          std::cout << e.what() << '\n';
        }
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

  std::ofstream fo_meniu_pizza_veg_online("meniu_pizza_vegetariana_online.out");
  if (!fo_meniu_pizza_veg_online.is_open()) {
    /* fisierul nu exista sau nu a putut fi deschis */
    std::cout << "EROARE! Nu a putut fi creat raportul pentru pizza "
                 "vegetariana servita online\n";
  } else {
    /* scrie raportul pentru pizza locala */
    fo_meniu_pizza_veg_online << meniu_pizza_veg_online;
  }
  fo_meniu_pizza_veg_online.close();

  return 0;
}
