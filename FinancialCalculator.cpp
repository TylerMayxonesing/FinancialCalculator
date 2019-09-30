//
// Created by T Alpha 1 on 9/29/2019.
//

#include "FinancialCalculator.h"

void prompt() {
  char input;
  do {
    std::cout << "(M)onthly loan payment, (I)nflation calculator,\n(R)eal interest rate, (Y)ears to savings goal\nEnter what you want to calculate: ";
    std::cin >> input;
  }
  while (tolower(input) != 'M' && tolower(input) != 'I' && tolower(input) != 'R' && tolower(input) != 'Y');
  if (tolower(input) == 'm'){
    monthlyLoan();
  }
  else if (tolower(input) == 'i'){
    inflationCalculator();
  }
  else if (tolower(input) == 'r'){
    realInterestRate();
  }
  else if (tolower(input) == 'y'){
    yearToSavingsGoal();
  }
}

void monthlyLoan() {
  double principle;
  double term;
  double rates;
  double payment;

  std::cout << "Enter principal: ";
  std::cin >> principle;

  std::cout << "Enter term (years): ";
  std::cin >> term;

  std::cout << "Enter annual interest rate: ";
  std::cin >> rates;

  if (rates !=0) {
    payment =(principle * (rates / 12) * pow((1 + (rates / 12)), (12 * term))) / (pow((1 + (rates / 12)), (12 * term)) - 1);
  }

  if (rates == 0){
    payment = (principle/12)/(term);
  }

  std::cout << "Your monthly payment is $" <<std::fixed<< std::setprecision(2) << (payment) <<  "." << std::endl;

}
void inflationCalculator() {
  double year;
  double amount;
  double endingYear;
  double inflation;
  double equivalence;
  double time;

  std::cout << "Enter the starting year: ";
  std::cin >> year;



  std::cout<<"Enter the amount of " << year << " dollars: ";
  std::cin >> amount;

  std::cout<<"Enter the ending year: ";
  std::cin >> endingYear;

  time = endingYear-year;

  std::cout<<"Enter the inflation rate: ";
  std::cin >> inflation;

  equivalence = amount*pow((1 + inflation),time);

  std::cout << "$" << std::fixed << std::setprecision(2) << amount << " in "<< std::fixed << std::setprecision(0) << year << " has the same value as " << "$" << std::fixed << std::setprecision(2) << equivalence << " in " << std::fixed << std::setprecision(0) << endingYear << "." << std::endl;
}
void realInterestRate() {
  float nominalInterest;
  float inflation;
  float realInterest;

  std::cout << "Enter nominal interest rate: ";
  std::cin >> nominalInterest;

  std::cout << "Enter inflation rate: ";
  std::cin >> inflation;

  realInterest = ((1+nominalInterest)/(1+inflation)) -1;

  std::cout << "The real interest rate is " << std::fixed << std::setprecision(2) << realInterest << "." << std::endl;
}
void yearToSavingsGoal() {
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

  if (interest !=0) {
    years = log((interest / 12) * ((((goal - current) / contribution))) + 1) / (log(1 + (interest / 12)));
  }
  if (interest == 0){
    years = (goal - current)/(contribution) ;
  }

  std::cout << "The savings goal of $" << std::fixed << std::setprecision(2) << goal << " will be reached in " << years/12 <<" years." << std::endl;
}


