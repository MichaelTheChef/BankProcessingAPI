#ifndef Transaction_hpp
#define Transaction_hpp

#include <string>

class Transaction {
public:
    Transaction(const std::string& transactionId, double amount, long timestamp);
    std::string getTransactionId();
    double getAmount();
    long getTimestamp();

private:
    std::string transactionId;
    double amount;
    long timestamp;
};

#endif /* Transaction_hpp */
