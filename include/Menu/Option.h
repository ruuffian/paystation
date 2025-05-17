#pragma once
#include <iostream>
#include <sstream>
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
  /* Takes in a stream to append output to (allows chaining). */
  virtual void execute(std::ostringstream &out) = 0;
  virtual ~Option() = default;
};
} // namespace Menu
