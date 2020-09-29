#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string number);
    static string convertDoubleToString(double number);
    static int convertDateFromStringToIntWithoutDash(string date);
    static string loadLine();
    static char loadCharacter();
    static string replaceFirstLetterToUppercaseAndRemainderLowercase(string tekst);
};

#endif
