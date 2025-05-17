#include "Exit.h"

namespace GenericMenu {
Exit::Exit(Menu::Menu *m) : Menu::Option("Exit"), menu_(m) {}

void Exit::execute(std::ostringstream &out) {
  out << "Good-bye!" << '\n';
  menu_->exit();
}
} // namespace GenericMenu
