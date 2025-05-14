#pragma once
#include <string>

/** Enter the Command pattern. */
class MenuOption {
protected:
  const int id_;
  const std::string name_;

public:
  MenuOption(const int id, const std::string name) : id_(id), name_(name) {}
  std::string getName() { return name_; }
  int getId() { return id_; }
  virtual void execute() = 0;
  virtual ~MenuOption() = 0;
};
