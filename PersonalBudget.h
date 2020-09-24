#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "OperationHistoryManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    OperationHistoryManager *operationHistoryManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        operationHistoryManager = NULL;
    };
    ~PersonalBudget()
    {
        delete operationHistoryManager;
        operationHistoryManager = NULL;
    };

    void userRegistration();
    void userLogin();
    void userLogout();
    void changeThePasswordOfLoggedInUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    bool checkIfUserIsLoged();
    bool isUserLoggedIn();
    int addIncome();
    int addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();

};

#endif
