//
// Created by Vanhuljo on 07/11/2023.
//

#include "BankAccount.h"

#include <iostream>

using namespace std;
using std::string;

int main() {
  string sacno = "SB-123";
  double Opening_balance, deposit_amt, withdrawal_amt;
  Opening_balance = 1000;
  cout << "A/c. No." << sacno << " Balance: " << Opening_balance << endl;

  BankAccount account(sacno, Opening_balance);

  deposit_amt = 1500;
  cout << "Deposit Amount: " << deposit_amt << endl;
  account.deposit(deposit_amt);

  withdrawal_amt = 230;
  cout << "withdrawal Amount: " << withdrawal_amt << endl;
  account.withdraw(withdrawal_amt);

  return 0;
}
