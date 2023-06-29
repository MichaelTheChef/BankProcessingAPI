#include `Server.hpp`
#include <iostream>
#include <cpp-httplib/httplib.h>

Server::Server() {
    // Initialize the server
}

void Server::start() {
    httplib::Server server;

    server.Post(`/accounts/create`, [this](const httplib::Request& req, httplib::Response& res) {
        BankAccount account = bankAccountManager.createAccount();
        res.set_content(account.getAccountNumber(), "text/plain");
    });

    server.Post(`/accounts/deposit`, [this](const httplib::Request& req, httplib::Response& res) {
        std::string accountNumber = req.get_param_value("accountNumber");
        double amount = std::stod(req.get_param_value("amount"));

        bankAccountManager.deposit(accountNumber, amount);
        res.set_content("Deposit successful", "text/plain");
    });

    server.Post(`/accounts/withdraw`, [this](const httplib::Request& req, httplib::Response& res) {
        std::string accountNumber = req.get_param_value("accountNumber");
        double amount = std::stod(req.get_param_value("amount"));

        bankAccountManager.withdraw(accountNumber, amount);
        res.set_content("Withdrawal successful", "text/plain");
    });

    server.Get(`/accounts/balance`, [this](const httplib::Request& req, httplib::Response& res) {
        std::string accountNumber = req.get_param_value("accountNumber");

        double balance = bankAccountManager.getBalance(accountNumber);
        res.set_content(std::to_string(balance), "text/plain");
    });

    std::cout << "Server started on port 8080" << std::endl;
    server.listen("localhost", 8080);
}
