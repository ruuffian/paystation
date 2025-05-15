#pragma once
#include <string>

/** Enter the Command pattern. */
namespace Menu {
class Option {
protected:
  const std::string name_;

public:
  Option(const std::string name) : name_(name) {}
  std::string getName() { return name_; }
  virtual void execute() = 0;
  virtual ~Option() = default;
};
} // namespace Menu
