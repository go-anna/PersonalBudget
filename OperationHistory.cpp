#include "OperationHistory.h"

using namespace std;

void OperationHistory::setStringDate(string newStringDate)
{
    stringDate = newStringDate;
}

void OperationHistory::setIntDate(int newIntDate)
{
    intDate = newIntDate;
}

void OperationHistory::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}

void OperationHistory::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}

void OperationHistory::setItem(string newItem)
{
    item = newItem;
}

void OperationHistory::setAmount(double newAmount)
{
    amount = newAmount;
}

string OperationHistory::getStringDate()
{
    return stringDate;
}

int OperationHistory::getIntDate()
{
    return intDate;
}

int OperationHistory::getUserId()
{
    return userId;
}

int OperationHistory::getId()
{
    return id;
}

string OperationHistory::getItem()
{
    return item;
}

double OperationHistory::getAmount()
{
    return amount;
}

