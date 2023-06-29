#ifndef BankAccountManager_hpp
#define BankAccountManager_hpp

#include <unordered_map>
#include "BankAccount.hpp"
#include "Transaction.hpp"

class BankAccountManager {
public:
    BankAccountManager();
    BankAccount createAccount();
    void deposit(const std::string& accountNumber, double amount);
    void withdraw(const std::string& accountNumber, double amount);
    double getBalance(const std::string& accountNumber);

private:
    std::unordered_map<std::string, BankAccount> accounts;
    std::vector<Transaction> transactions;
    std::string generateAccountNumber();
    std::string generateTransactionId();
};

#endif /* BankAccountManager_hpp */
