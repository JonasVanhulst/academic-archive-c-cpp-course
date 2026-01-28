//
// Created by Vanhuljo on 07/11/2023.
//

/*
 * Write a C++ program to implement a class called BankAccount that has private
 * member variables for account number and balance. Include member functions to
 * deposit and withdraw money from the account.
 * */
#ifndef OOP_LEARNING_BANKACCOUNT_H
#define OOP_LEARNING_BANKACCOUNT_H

#include <iostream>

using namespace std;
using std::string;

class BankAccount {
 private:
  string AccountNumber;
  double Balance;

 public:
  BankAccount(string account, double balance)
      : AccountNumber(account), Balance(balance) {}

  double deposit(double moneyValue) {
    Balance += moneyValue;
    cout << "Deposit successful. Current balance: " << Balance << std::endl;
  }

  double withdraw(double moneyValue) {
    if (moneyValue <= Balance) {
      Balance -= moneyValue;
      cout << "Withdrawal successful. Current balance: " << Balance
           << std::endl;
    } else {
      cout << "Insufficient balance. Cannot withdraw." << std::endl;
    }
  }
};

#endif  // OOP_LEARNING_BANKACCOUNT_H
