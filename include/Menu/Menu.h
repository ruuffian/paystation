#pragma once
#include "Header.h"
#include "Option.h"
#include <map>

namespace Menu {
class Menu {
private:
  // We use a std::map because it's keys are sorted in Ascending order-
  // we rely on this fact to print the options in a deterministic order.
  std::map<int, Option *> options_;
  int should_exit_ = 0;
  Header *header_;

public:
  /* Begin rendering loop, usually exited via the GenericOption Exit(). */
  void runMenu();
  /* Adds an option to the options_. */
  void addOption(Option *c);
  /* Lookup an int and return associated Option, NULL otherwise. */
  Option *processInput(const int &in);
  void exit();
  /* Print header block associated with Menu, if any. */
  void printHeader();
  /* Set header_ */
  void setHeader(Header *header_);
  /* Print registered menu options in order of insertion. */
  void printOptions();
  /* Deletes header_ and members of options_ */
  ~Menu();
};
} // namespace Menu
