#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <string>

class BankAccount {
public:
    BankAccount(const std::string& accountNumber, double balance = 0.0);
    std::string getAccountNumber();
    double getBalance();
    void setBalance(double balance);

private:
    std::string accountNumber;
    double balance;
};

#endif /* BankAccount_hpp */
