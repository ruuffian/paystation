#pragma once
#include <iostream>
#include <string>

/** Enter the Command pattern. */
namespace Menu {
class Option {
protected:
  const std::string name_{};

public:
  Option(const std::string name) : name_(name) {}
  virtual void render(const int &id) {
    std::cout << '\t' << id << " : " << name_ << '\n';
  };
  virtual void execute() = 0;
  virtual ~Option() = default;
};
} // namespace Menu
