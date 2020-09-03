#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account {
    float balance;

public:
    Account();

    Account(int balance);

    int deposit(int amount);

    int withdraw(int amount);

    float get_balance();

    int add_interest(float rate);

};
#endif // !ACCOUNT_H

