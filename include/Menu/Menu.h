#pragma once
#include "Header.h"
#include "Option.h"
#include <map>

namespace Menu {
class Menu {
private:
  // 1-indexed sorted map: allows us to print options in a deterministic order.
  std::map<int, Option *> options_{};
  int should_exit_ = 0;
  Header *header_{};

public:
  /* Begin rendering loop, usually exited via the GenericOption Exit(). */
  void render();
  /* Accept input from stdin, returns a registered Option* */
  Option *readInput();
  /* Adds an option to the options_. */
  void addOption(Option *c);
  /* Set header_. If header_ is not null, returns the old value.*/
  Header *setHeader(Header *header_);
  /* Print header block associated with Menu, if any. */
  void renderHeader();
  /* Print registered menu options in order of insertion. */
  void renderOptions();
  /* Print footer block, if present */
  void renderFooter();
  /* Ends the menu rendering loop */
  void exit();
  /* Deletes header_ and members of options_ */
  ~Menu();
};
} // namespace Menu
