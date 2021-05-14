#include "comenzi_pizza_enum.h"
#include "meniu.h"
#include "string_tokenizer.h"
#include <fstream>

class MeniuInteractiv {
private:
  /* vom avea 2 meniuri pentru comenzi locale si online
   * intrucat o sa avem 2 rapoarte diferite de facut */
  Meniu<Pizza> meniu_pizza_local;
  Meniu<PizzaOnline> meniu_pizza_online;
  Meniu<PizzaVegetarianaOnline> meniu_pizza_veg_online;

  enum class Comenzi_meniu_int {
    CITESTE_COMANDA_TASTATURA,
    CITESTE_COMENZI_FISIER,
    SCRIE_RAPORT,

    MAX_COMENZI
  };

  /* citeste o lista de ingrediente dintr-un tokenizer, acesta va overi nr de
   * ingrediente si detalii despre ingrediente */
  std::vector<Ingredient *>
  citesteIngrediente(StringTokenizer &comanda_str_token) {
    /* salvam tokenurile de tip string si le prelucram */
    std::string str_tok;

    std::vector<Ingredient *> ingrediente;
    int nr_ingrediente;

    /* verificam daca mai avem tokene inainte de a lua unul */
    if (comanda_str_token.hasMoreTokens()) {
      str_tok = comanda_str_token.getNextToken();
      nr_ingrediente = StringToInt(str_tok);
    } else {
      throw NotEnoughTokens("lipsesc nr ingrediente");
    }

    /* informatii despre un ingredient */
    std::string nume_ingredient;
    double cantitate, pret_unitar;

    /* citim n ingrediente spuse ca le avem */
    for (int i = 0; i < nr_ingrediente; i++) {
      /* daca am primit mai putine ingrediente decat ar fi trebuit */
      if (!comanda_str_token.hasMoreTokens()) {
        throw InvalidNumberIngredients(std::to_string(nr_ingrediente));
      }

      /* incercam sa preluam denumirea ingredientului */
      if (comanda_str_token.hasMoreTokens()) {
        str_tok = comanda_str_token.getNextToken();
        nume_ingredient = str_tok;
      } else {
        throw NotEnoughTokens("lipseste denumire ingredient");
      }

      /* incercam sa preluam cantitatea ingredientului */
      if (comanda_str_token.hasMoreTokens()) {
        str_tok = comanda_str_token.getNextToken();
        cantitate = StringToDouble(str_tok);
      } else {
        throw NotEnoughTokens("lipseste cantitate ingredient");
      }

      /* incercam sa preluam pretul unitar al ingredientului */
      if (comanda_str_token.hasMoreTokens()) {
        str_tok = comanda_str_token.getNextToken();
        pret_unitar = StringToDouble(str_tok);
      } else {
        throw NotEnoughTokens("lipseste pret unitar ingredient");
      }

      /* construim un obiect de tipul ingredient cu datele obtinute si il
       * adaugam in lista de ingrediente */
      Ingredient *ing = new Ingredient(nume_ingredient, cantitate, pret_unitar);
      ingrediente.push_back(ing);
    }

    /* daca am primit mai multe ingrediente decat ar fi trebuit */
    if (comanda_str_token.hasMoreTokens()) {
      throw InvalidNumberIngredients(std::to_string(nr_ingrediente));
    }

    return ingrediente;
  }

  void citesteComandaPizza(std::string &comanda) {
    /* transformam stringul primit intr-un tokenizer de tip string din care vom
     * scoate tokenii si ii vom procesa, delimitatorul in cazul nostru este un
     * spatiu " " */
    StringTokenizer comanda_str_token(comanda, " ");

    Pizza *pizza = nullptr; /* detalii despre o noua comanda de pizza */

    /* obtinem tipul comenzii */
    std::string tip_comanda;
    if (comanda_str_token.hasMoreTokens()) {
      tip_comanda = comanda_str_token.getNextToken();
    } else {
      throw NotEnoughTokens("lipseste tipul pizzei");
    }

    /* verificam daca comanda este valida */
    if (!(map_comenzi_pizza.find(tip_comanda) != map_comenzi_pizza.end())) {
      try {
        throw InvalidPizzaType(tip_comanda);
      } catch (const InvalidPizzaType &e) {
        std::cout << e.what() << '\n';
      }
      return;
    }

    /* citim comanda de pizza si o adaugam in meniul potrivit tipului ei */
    switch (map_comenzi_pizza[tip_comanda]) {
    case PizzaType::LOCAL:
      pizza = new Pizza();
      try {
        /* obtinem ingredientele */
        std::vector<Ingredient *> ingrediente =
            citesteIngrediente(comanda_str_token);
        pizza->setIngrediente(ingrediente);

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
        /* obtinem ingredientele */
        std::vector<Ingredient *> ingrediente =
            citesteIngrediente(comanda_str_token);
        dynamic_cast<PizzaOnline *>(pizza)->setIngrediente(ingrediente);

        /* obtinem distanta de livrare */
        if (comanda_str_token.hasMoreTokens()) {
          std::string str_tok = comanda_str_token.getNextToken();
          double distanta = StringToDouble(str_tok);
          dynamic_cast<PizzaOnline *>(pizza)->setDistanta(distanta);
        } else {
          throw NotEnoughTokens(
              "lipseste distanta pentru comanda de pizza online");
        }

        meniu_pizza_online += dynamic_cast<PizzaOnline *>(pizza);
      } catch (std::exception &e) { /* prinde toate tipurile de exceptii */
        std::cout << e.what() << '\n';
      }
      break;

    case PizzaType::VEGETARIANA_LOCALA:
      pizza = new PizzaVegetarianaLocala();
      try {
        /* obtinem ingredientele */
        std::vector<Ingredient *> ingrediente =
            citesteIngrediente(comanda_str_token);
        dynamic_cast<PizzaVegetarianaLocala *>(pizza)->setIngrediente(
            ingrediente);

        meniu_pizza_local += dynamic_cast<PizzaVegetarianaLocala *>(pizza);
      } catch (const std::invalid_argument &e) {
        std::cout << e.what() << '\n';
      }
      break;

    case PizzaType::VEGETARIANA_ONLINE:
      pizza = new PizzaVegetarianaOnline();
      try {
        /* obtinem ingredientele */
        std::vector<Ingredient *> ingrediente =
            citesteIngrediente(comanda_str_token);
        dynamic_cast<PizzaVegetarianaOnline *>(pizza)->setIngrediente(
            ingrediente);

        /* obtinem distanta de livrare */
        if (comanda_str_token.hasMoreTokens()) {
          std::string str_tok = comanda_str_token.getNextToken();
          double distanta = StringToDouble(str_tok);
          dynamic_cast<PizzaVegetarianaOnline *>(pizza)->setDistanta(distanta);
        } else {
          throw NotEnoughTokens(
              "lipseste distanta pentru comanda de pizza online");
        }

        meniu_pizza_veg_online += dynamic_cast<PizzaVegetarianaOnline *>(pizza);
      } catch (std::exception &e) { /* prinde toate tipurile de exceptii */
        std::cout << e.what() << '\n';
      }
      break;

    default:
      break;
    }
  }

  void scrieRaport() {
    std::ofstream fo_meniu_pizza_local("meniu_pizza_local.out");
    if (!fo_meniu_pizza_local.is_open()) {
      /* fisierul nu exista sau nu a putut fi deschis */
      std::cout << "EROARE! Nu a putut fi creat raportul pentru pizza "
                   "servita local\n";
    } else {
      /* scrie raportul pentru pizza locala */
      fo_meniu_pizza_local << meniu_pizza_local;
    }
    fo_meniu_pizza_local.close();

    std::ofstream fo_meniu_pizza_online("meniu_pizza_online.out");
    if (!fo_meniu_pizza_online.is_open()) {
      /* fisierul nu exista sau nu a putut fi deschis */
      std::cout << "EROARE! Nu a putut fi creat raportul pentru pizza "
                   "servita online\n";
    } else {
      /* scrie raportul pentru pizza locala */
      fo_meniu_pizza_online << meniu_pizza_online;
    }
    fo_meniu_pizza_online.close();

    std::ofstream fo_meniu_pizza_veg_online(
        "meniu_pizza_vegetariana_online.out");
    if (!fo_meniu_pizza_veg_online.is_open()) {
      /* fisierul nu exista sau nu a putut fi deschis */
      std::cout << "EROARE! Nu a putut fi creat raportul pentru pizza "
                   "vegetariana servita online\n";
    } else {
      /* scrie raportul pentru pizza locala */
      fo_meniu_pizza_veg_online << meniu_pizza_veg_online;
    }
    fo_meniu_pizza_veg_online.close();
  }

public:
  MeniuInteractiv() {
    std::map<std::string, Comenzi_meniu_int> mapComenzi{
        {"citeste_comanda_tastatura",
         Comenzi_meniu_int::CITESTE_COMANDA_TASTATURA},
        {"citeste_comenzi_fisier", Comenzi_meniu_int::CITESTE_COMENZI_FISIER},
        {"scrie_raport", Comenzi_meniu_int::SCRIE_RAPORT}};

    std::string comanda_meniu_intr{""};
    bool program_running{true};

    while (program_running) {
      bool inputComandaFormatCorect{false};

      while (!inputComandaFormatCorect) {
        std::cout << "\nComenzi:\n-> citeste_comanda_tastatura (urmat de "
                     "comanda de pizza pe aceeasi linie)\n-> "
                     "citeste_comenzi_fisier\n-> scrie_raport (la scrierea "
                     "raportului programul se va termina)\n";
        std::cin >> comanda_meniu_intr;
        inputComandaFormatCorect =
            (mapComenzi.find(comanda_meniu_intr) != mapComenzi.end());
      }

      switch (mapComenzi[comanda_meniu_intr]) {
      case Comenzi_meniu_int::CITESTE_COMANDA_TASTATURA: {
        std::string comanda;
        std::getline(std::cin, comanda);
        citesteComandaPizza(comanda);
      } break;

      case Comenzi_meniu_int::CITESTE_COMENZI_FISIER: {
        std::cout << "Nume fisier date intrare: ";
        std::string nume_fiser_intrare{""};
        std::cin >> nume_fiser_intrare;
        std::ifstream comenzi(
            nume_fiser_intrare); /* de unde vom citi comenzile */

        /* fisierul nu exista sau nu a putut fi deschis  */
        if (!comenzi.is_open()) {
          std::cout
              << "Nu exista comenzi; Adaugati comenzile in fisierul dat.\n";
          comenzi.close();
          break;
        } else {
          std::string comanda; /* fiecare comanda se afla pe cate un rand */

          /* citim toate comenzile din meniu */
          while (std::getline(comenzi, comanda)) {
            citesteComandaPizza(comanda);
          }
        }

        comenzi.close();

      } break;

      case Comenzi_meniu_int::SCRIE_RAPORT:
        scrieRaport();
        program_running = false;
        break;

      default:
        break;
      }
    }
  }

  ~MeniuInteractiv() {}
};

int main() {
  MeniuInteractiv meniu_interactiv;

  /* for testing */
  /* std::ifstream fin("comenzi.in"); */
  /* std::string str; */
  /* while (getline(fin, str)) { */
  /* StringTokenizer str_token(str, " "); */
  /* while (str_token.hasMoreTokens()) { */
  /* std::cout << "|" << str_token.getNextToken() << "|\n"; */
  /* } */
  /* break; */
  /* } */
  /* fin.close(); */

  return 0;
}
