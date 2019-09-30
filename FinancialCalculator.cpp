//
// Created by T Alpha 1 on 9/29/2019.
//

#include "FinancialCalculator.h"

void prompt() {
  char input;
  //char choice = tolower(input);
  do {
    std::cout << "$ ./FinanceCalculator\n(M)onthly loan payment,(I)nflation calculator, " << std::endl;
    std::cout << "(R)eal interest rate, (Y)ears to savings goal" << std::endl;
    std::cout << "Enter what you want to calculate: ";
    std::cin >> input;
  }
  while (input != 'M' && input != 'I' && input != 'R' && input != 'Y');
  if (input == 'M'){
    monthlyLoan();
  }
  else if (input == 'I'){
    inflationCalculator();
  }
  else if (input == 'R'){
    realInterestRate();
  }
  else if (input == 'Y'){
    yearToSavingsGoal();
  }
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
int inflationCalculator() {
  float year;
  float amount;
  float endingYear;
  float inflation;
  float equivalence;
  float time;

  std::cout << "Enter the starting year: ";
  std::cin >> year;



  std::cout<<"Enter the amount of 1969 dollars: ";
  std::cin >> amount;

  std::cout<<"Enter the ending year: ";
  std::cin >> endingYear;

  time = endingYear-year;

  std::cout<<"Enter the inflation rate: ";
  std::cin >> inflation;

  equivalence = amount*pow((1 + inflation),time);

  std::cout << "$" << amount << " in "<< year << " has the same value as " << "$" << equivalence << " in " <<endingYear << "." << std::endl;
}
int realInterestRate() {
  float nominalInterest;
  float inflation;
  float realInterest;

  std::cout << "Enter the nominal interest rate: ";
  std::cin >> nominalInterest;

  std::cout << "Enter the inflation rate: ";
  std::cin >> inflation;

  realInterest = ((1+nominalInterest)/(1+inflation)) -1;

  std::cout << "The real interest rate is " << std::fixed << std::setprecision(2) << realInterest << "." << std::endl;
}
int yearToSavingsGoal() {
  double goal;
  double current;
  double contribution;
  double interest;
  double years;

  std::cout << "Enter savings goal: ";
  std::cin >> goal;

  std::cout << "Enter current savings: ";
  std::cin >> current;

  std::cout << "Enter monthly contribution: ";
  std:: cin >> contribution;

  std::cout << "Enter annual interest rate: ";
  std::cin >> interest;

  years = log((interest/12)*((((goal-current)/contribution)))+1)/(log(1+(interest/12)));

  std::cout << "The savings goal of " << goal << " will be reached in " << years <<"." << std::endl;
}


