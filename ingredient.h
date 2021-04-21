#include <iostream>
#include <string>

class Ingredient {
private:
  std::string m_denumire;
  double m_cantitate;
  double m_pret_unitar;

public:
  Ingredient();

  Ingredient(std::string denumire, double cantitate, double pret_unitar);

  Ingredient(const Ingredient &ing);

  ~Ingredient();

  std::string getDenumire() const { return m_denumire; }

  double getCantitate() const { return m_cantitate; }

  double getPretUnitar() const { return m_pret_unitar; }

  void setDenumire(std::string denumire) { m_denumire = denumire; }

  void setCantitate(double cantitate) { m_cantitate = cantitate; }

  void setPretUnitar(double pret_unitar) { m_pret_unitar = pret_unitar; }

  Ingredient &operator=(const Ingredient &ing);

  friend std::istream &operator>>(std::istream &in, Ingredient &ing);

  friend std::ostream &operator<<(std::ostream &out, const Ingredient &ing);
};
