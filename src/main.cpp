#include <cctype>
#include <iostream>
#include <string>

#include "fixed_linear_rate.h"
#include "paystation.h"

typedef struct StateTag {
  int shouldExit;
  std::string input;
  Paystation *ps;
} State;

class Choice {
private:
  std::string name;

public:
  Choice(std::string n) { name = n; }
  std::string getName() { return name; }
  virtual void execute(State &s) = 0;
};

class ExitChoice : public Choice {
  using Choice::Choice;
  void execute(State &s) override {
    std::cout << "Good-bye..." << '\n';
    s.shouldExit = 1;
  }
};

class RepeatChoice : public Choice {
  using Choice::Choice;
  void execute(State &s) override { std::cout << s.input << '\n'; }
};

void clrscr();
void printChoices(const auto &choices);

int main() {
  /* Initializations */
  std::unordered_map<char, Choice *> choiceMap = {
      {'e', new ExitChoice("Exit")}, {'r', new RepeatChoice("Repeat")}};
  clrscr();
  FixedLinearRate *flr = new FixedLinearRate(0, 0.5);
  State state = {0, "", new Paystation(flr)};

  /* Main loop */
  std::cout << "Welcome to Paystation!" << '\n' << '\n';
  while (!state.shouldExit) {
    printChoices(choiceMap);
    std::getline(std::cin, state.input);
    if (state.input.size() == 0)
      continue;
    if (choiceMap.find(std::tolower(state.input[0])) != choiceMap.end()) {
      Choice *choice = choiceMap.at(std::tolower(state.input[0]));
      choice->execute(state);
    } else {
      state.input = "";
      continue;
    }
  }
  return 0;
}

void printChoices(const auto &choices) {
  using namespace std;
  cout << "Please select an option:" << '\n';
  for (const auto &[key, value] : choices) {
    std::string n = value->getName();
    cout << '\t';
    cout << "[" << n[0] << "]";
    cout << n.substr(1, n.size()) << '\n';
  }
}

void clrscr() { std::cout << "\033[2J\033[1;1H"; }
