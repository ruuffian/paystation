#include "Exit.h"

namespace GenericMenu {
Exit::Exit(Menu::Menu *m) : Menu::Option("Exit"), menu_(m) {}

void Exit::execute() { menu_->exit(); }
} // namespace GenericMenu
