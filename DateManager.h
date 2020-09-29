#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <time.h>
#include <string>

#include <iostream>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    int getNumberOfMonthDays(int month, int year);

public:
    string getCurrentDate();
    bool checkIfDateIsCorrect(string date);

};

#endif
