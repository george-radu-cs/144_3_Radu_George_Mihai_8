#include "produs.h"
#include "ingredient.h"
#include <vector>

class Pizza : public Produs {
private:
  std::vector<Ingredient> ingrediente;
  constexpr static double pret_manopera = 15.0;

public:
  Pizza();

  Pizza(const Pizza &pizza);

  ~Pizza();

  double pret() override;

  Pizza &operator=(const Pizza &pizza);

  friend std::istream &operator>>(std::istream &in, Pizza &pizza);

  friend std::ostream &operator<<(std::ostream &out, const Pizza &pizza);
};
