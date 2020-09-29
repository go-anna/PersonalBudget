#include "PersonalBudget.h"

char PersonalBudget::mainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::userMenu()
{
    userManager.userMenu();
}

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

int PersonalBudget::userLogin()
{
    userManager.userLogin();
    if (userManager.isUserLoggedIn())
    {
        operationHistoryManager = new OperationHistoryManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getUserLogin());
    }

}

bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

int PersonalBudget::userLogout()
{
    userManager.userLogout();
    delete operationHistoryManager;
    operationHistoryManager = NULL;
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
