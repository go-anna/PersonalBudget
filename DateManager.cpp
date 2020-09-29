#include "DateManager.h"


string DateManager::getCurrentDate()
{
    string date;
    SYSTEMTIME st;
    GetSystemTime(&st);
    string year = AuxiliaryMethods::convertIntToString(st.wYear);
    string month = AuxiliaryMethods::convertIntToString(st.wMonth);
    if (month.length() == 1)
        month = '0' + month;
    string day = AuxiliaryMethods::convertIntToString(st.wDay);
    if (day.length() == 1)
        day = '0' + day;
    date = year + '-' + month + '-' + day ;
    return date;
}

bool DateManager::checkIfDateIsCorrect(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if((date[i] < 48 || date[i] > 57) && date[i] != '-')
        {
            cout << "Wrong date format. Enter the date again!" << endl;
            return false;
        }
    }
    if( date.length() == 10 && date[4] == '-' && date[7] == '-' )
    {

        string year = date.substr(0,4);
        string month = date.substr(5,2);
        string day = date.substr(8,2);
        string todaysDate = getCurrentDate();
        int todaysDateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(todaysDate);
        int dateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(date);
        int yearInt = AuxiliaryMethods::convertStringToInt(year);
        int monthInt = AuxiliaryMethods::convertStringToInt(month);
        int dayInt = AuxiliaryMethods::convertStringToInt(day);
        if (dateInt > todaysDateInt)
        {
            cout << "You cannot enter a date later than today!" << endl;
            return false;
        }
        if (dateInt < 20000101)
        {
            cout << "Please enter a date later than or equal to 2000-01-01!" << endl;
            return false;
        }
        if (yearInt > 0 && monthInt > 0 && monthInt <= 12 && dayInt > 0 && dayInt <= getNumberOfMonthDays(monthInt, yearInt))
        {
            cout << "The date entered correctly." << endl;
            return true;
        }
        else
        {
            cout << "Bad date values. Enter the date again!" << endl;
            return false;
        }

    }
    else
    {
        cout << "Wrong date format. Enter the date again!" << endl;
            return false;
    }
}

int DateManager::getNumberOfMonthDays(int month, int year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
    {
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            return 29;
        else
            return 28;
    }
    break;
    }
    return 0;
}
