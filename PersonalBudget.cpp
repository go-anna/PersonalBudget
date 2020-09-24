#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

void PersonalBudget::userLogin()
{
    userManager.userLogin();
}

void PersonalBudget::userLogout()
{
    userManager.userLogout();
}

bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void PersonalBudget::changeThePasswordOfLoggedInUser()
{
    userManager.changeThePasswordOfLoggedInUser();
}

int PersonalBudget::addIncome()
{
    operationHistoryManager -> addIncome();
}

int PersonalBudget::addExpense()
{
    operationHistoryManager -> addExpense();
}

void PersonalBudget::showCurrentMonthBalance()
{
    operationHistoryManager -> showCurrentMonthBalance();
}

void PersonalBudget::showPreviousMonthBalance()
{
    operationHistoryManager -> showPreviousMonthBalance();
}

void PersonalBudget::showSelectedPeriodBalance()
{
    operationHistoryManager -> showSelectedPeriodBalance();
}
