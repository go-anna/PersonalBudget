#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "XmlFile.h"
#include "Markup.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenseFile : public XmlFile
{

public:
    ExpenseFile(string fileName) : XmlFile(fileName){};
    bool addExpenseToFile(Expense expense);
    vector <Expense> getLastExpenseId(int ID_OF_LOGGED_USER);
    int getIdOfLastExpenseFromFile();

};

#endif
