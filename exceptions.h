#include <exception>
#include <string>

/* tipurile de exceptii de la convertirea unui string in double */
class StofException : public std::exception {
protected:
  std::string message;

  void setMessage(const std::string &msg) { message = msg; }

public:
  StofException(const std::string &msg) : message(msg) {}

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
