//
// Created by T Alpha 1 on 9/29/2019.
//

#include <iomanip>
#include "FinancialCalculator.h"

std::string prompt(char input) {
  std::cout << "$ ./FinanceCalculator\n"
               "(M)onthly loan payment, (I)nflation calculator,\n"
               "(R)eal interest rate, (Y)ears to savings goal\n"
               "Enter what you want to calculate:";
  char choice = tolower(input);
}

int monthlyLoan() {
  float principle;
  float term;
  float rates;
  float payment;

  std::cout << "Enter principal: ";
  std::cin >> principle;

  std::cout << "Enter term (years): ";
  std::cin >> term;

  std::cout << "Enter annual interest rate: ";
  std::cin >> rates;

  payment = (principle*(rates/12)*pow((1+(rates/12)),(12*term)))/(pow((1+(rates/12)),(12*term))-1);

  std::cout << "Your monthly payment is " <<std::fixed<< std::setprecision(2)<<(payment) << std::endl;

  return 0;
}
