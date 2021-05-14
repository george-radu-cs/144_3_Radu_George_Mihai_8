#include <exception>
#include <string>

class NotEnoughTokens : public std::exception {
protected:
  std::string message;

  void setMessage(const std::string &msg) { message = msg; }

public:
  NotEnoughTokens(const std::string msg) : message(msg) {
    setMessage(std::string("Not enough values: ") + msg);
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

/* tipurile de exceptii de la citirea datelor unei pizza */
class PizzaException : public std::exception {
protected:
  std::string message;

  void setMessage(const std::string &msg) { message = msg; }

public:
  PizzaException(const std::string &msg) : message(msg) {}

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class InvalidPizzaType : public PizzaException {
public:
  InvalidPizzaType(const std::string &msg) : PizzaException(msg) {
    setMessage(std::string("Invalid pizza type! ") + msg +
               std::string(" isn't a type offered by the pizzeria."));
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class InvalidNumberIngredients : public PizzaException {
public:
  InvalidNumberIngredients(const std::string &msg) : PizzaException(msg) {
    setMessage(std::string("The number of ingredients given didn't match with "
                           "the number of ingredients received! ") +
               msg);
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

/* tipurile de exceptii de la convertirea unui string in double */
class StofException : public std::exception {
protected:
  std::string message;

  void setMessage(const std::string &msg) { message = msg; }

public:
  StofException(const std::string &msg) : message(msg) {}

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class IsEmpty : public StofException {
public:
  IsEmpty(const std::string &msg) : StofException(msg) {
    setMessage(std::string("Value can't be empty: ") + msg);
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class NotAnInt : public StofException {
public:
  NotAnInt(const std::string &msg) : StofException(msg) {
    setMessage(std::string("Not a double exception: ") + msg);
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class NotADouble : public StofException {
public:
  NotADouble(const std::string &msg) : StofException(msg) {
    setMessage(std::string("Not a double exception: ") + msg);
  }

  virtual const char *what() const noexcept override { return message.c_str(); }
};

class Overflow : public StofException {
public:
  Overflow(const std::string &msg) : StofException(msg) {
    setMessage(std::string("Overflow double exception: ") + msg);
  }
  virtual const char *what() const noexcept override { return message.c_str(); }
};

class NotZero : public StofException {
public:
  NotZero(const std::string &msg) : StofException(msg) {
    setMessage(std::string("The value can't be a zero: ") + msg);
  }
  virtual const char *what() const noexcept override { return message.c_str(); }
};
