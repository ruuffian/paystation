#pragma once
#include <string>

/** Enter the Command pattern. */
template <class... inject> class MenuOption {
protected:
  const int id_;
  const std::string name_;

public:
  MenuOption(const int id, const std::string name) : id_(id), name_(name) {}
  std::string getName() { return name_; }
  int getId() { return id_; }
  virtual void execute(inject... args) = 0;
};
