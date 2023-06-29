#ifndef Server_hpp
#define Server_hpp

#include "BankAccountManager.hpp"

class Server {
public:
    Server();
    void start();

private:
    BankAccountManager bankAccountManager;
    void handleRequest(const std::string& request);
};

#endif /* Server_hpp */
