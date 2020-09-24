#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"
#include "Markup.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeFile : public XmlFile
{

public:
    IncomeFile(string fileName) : XmlFile(fileName){};
    bool addIncomeToFile(Income income);
    vector <Income> getLastIncomeId(int ID_OF_LOGGED_USER);
    int getIdOfLastIncomeFromFile();
};

#endif
