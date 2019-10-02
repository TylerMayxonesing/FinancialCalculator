#include <iostream>
#include "FinancialCalculator.h"
int main() {
  std::string answer;
  do {
    prompt();
    std::cout << "Do you want to do another calculation [y/n]? ";
    std::cin >> answer;
  }
  while (answer== "y" || answer == "Y");


  return 0;
}