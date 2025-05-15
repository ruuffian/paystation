#include "Exit.h"

namespace GenericMenuOption {
Exit::Exit(Menu *m) : MenuOption("Exit"), menu_(m) {}

void GenericMenuOption::Exit::execute() { menu_->exit(); }
} // namespace GenericMenuOption
