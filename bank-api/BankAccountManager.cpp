#include "BankAccountManager.hpp"
#include <iostream>

BankAccountManager::BankAccountManager() {
    // Initialize the bank account manager
}

BankAccount BankAccountManager::createAccount() {
    std::string accountNumber = generateAccountNumber();
    BankAccount account(accountNumber);
    accounts[accountNumber] = account;
    return account;
}

void BankAccountManager::deposit(const std::string& accountNumber, double amount) {
    auto accountIterator = accounts.find(accountNumber);
    if (accountIterator != accounts.end()) {
        BankAccount& account = accountIterator->second;
        account.setBalance(account.getBalance() + amount);
        std::string transactionId = generateTransactionId();
        Transaction transaction(transactionId, amount, std::time(nullptr));
        transactions.push_back(transaction);
        std::cout << "Deposit of " << amount << " successful for Account " << accountNumber << std::endl;
    } else {
        std::cout << "Account " << accountNumber << " not found" << std::endl;
    }
}

void BankAccountManager::withdraw(const std::string& accountNumber, double amount) {
    auto accountIterator = accounts.find(accountNumber);
    if (accountIterator != accounts.end()) {
        BankAccount& account = accountIterator->second;
        if (account.getBalance() >= amount) {
            account.setBalance(account.getBalance() - amount);
            std::string transactionId = generateTransactionId();
            Transaction transaction(transactionId, -amount, std::time(nullptr));
            transactions.push_back(transaction);
            std::cout << "Withdrawal of " << amount << " successful for Account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance in Account " << accountNumber << std::endl;
        }
    } else {
        std::cout << "Account " << accountNumber << " not found" << std::endl;
    }
}

double BankAccountManager::getBalance(const std::string& accountNumber) {
    auto accountIterator = accounts.find(accountNumber);
    if (accountIterator != accounts.end()) {
        BankAccount& account = accountIterator->second;
        return account.getBalance();
    } else {
        std::cout << "Account " << accountNumber << " not found" << std::endl;
        return 0.0;
    }
}

std::string BankAccountManager::generateAccountNumber() {
    std::string accountNumber = "ACC" + std::to_string(std::rand());
    return accountNumber;
}

std::string BankAccountManager::generateTransactionId() {
    std::string transactionId = "TXN" + std::to_string(std::rand());
    return transactionId;
}
