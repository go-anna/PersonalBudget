#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <time.h>
#include <string>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {

    int getNumberOfMonthDays(int month, int year);

public:
    string getCurrentDate();
    int getDays(string date);
    bool checkIfDateIsCorrect(string date);
    bool isLeap(int year);


};

#endif
