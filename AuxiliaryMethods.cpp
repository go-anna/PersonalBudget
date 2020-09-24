#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

double AuxiliaryMethods::convertStringToDouble(string number)
{
    if(number.length() == 0)
    {
        number = "0";
    }
    for(int i = 0; i <= number.length()-1; i++)
    {
        if(number[i] == ',')
            number[i] = '.';
        if(number[i] == ' ')
            number.replace(i,1,"");
    }
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}

string AuxiliaryMethods::convertDoubleToString(double number)
{
    ostringstream ss;
    ss.precision(15);
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertDateFromStringToIntWithoutDash(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if(date[i] == '-')
            date.replace(i,1,"");
    }
    int dateInt = convertStringToInt(date);
    return dateInt;
}
string AuxiliaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return character;
}

string AuxiliaryMethods::replaceFirstLetterToUppercaseAndRemainderLowercase(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
