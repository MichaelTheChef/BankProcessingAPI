#include "BankAccount.hpp"

BankAccount::BankAccount(const std::string& accountNumber, double balance) {
    this->accountNumber = accountNumber;
    this->balance = balance;
}

std::string BankAccount::getAccountNumber() {
    return accountNumber;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}
