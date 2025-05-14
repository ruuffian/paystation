#pragma once
#include <string>

/** Enter the Command pattern. */
class MenuOption {
protected:
  const std::string name_;

public:
  MenuOption(const std::string name) : name_(name) {}
  std::string getName() { return name_; }
  virtual void execute() = 0;
  virtual ~MenuOption() = 0;
};
