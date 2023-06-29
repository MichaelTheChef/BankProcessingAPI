#include "Transaction.hpp"

Transaction::Transaction(const std::string& transactionId, double amount, long timestamp) {
    this->transactionId = transactionId;
    this->amount = amount;
    this->timestamp = timestamp;
}

std::string Transaction::getTransactionId() {
    return transactionId;
}

double Transaction::getAmount() {
    return amount;
}

long Transaction::getTimestamp() {
    return timestamp;
}
