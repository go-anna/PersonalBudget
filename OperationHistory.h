#ifndef OPERATIONHISTORY_H
#define OPERATIONHISTORY_H

#include <iostream>

using namespace std;

class OperationHistory
{

    string stringDate;
    int intDate;
    int userId;
    int id;
    string item;
    double amount;

public:
    OperationHistory(string stringDate = "", int intDate = 0, int userId = 0, int id = 0, string item = "", double amount = 0)
    {
        this -> stringDate = stringDate;
        this -> intDate = intDate;
        this -> userId = userId;
        this -> id = id;
        this -> item = item;
        this -> amount = amount;

    }
    bool operator > (const OperationHistory& str) const
    {
        return (intDate < str.intDate);
    }
    void setStringDate(string newStringDate);
    void setIntDate(int newIntDate);
    void setUserId(int newUserId);
    void setId(int newId);
    void setItem(string newItem);
    void setAmount(double newAmount);

    string getStringDate();
    int getIntDate();
    int getUserId();
    int getId();
    string getItem();
    double getAmount();

};
#endif
