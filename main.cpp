#include <iostream>

#include "PersonalBudget.h"

using namespace std;

char mainMenu();
char userMenu();

int main()
{
    char choice;

    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true)
    {
        if (personalBudget.isUserLoggedIn() == false)
        {
            choice = mainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = userMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showCurrentMonthBalance();
                break;
            case '4':
                personalBudget.showPreviousMonthBalance();
                break;
            case '5':
                personalBudget.showSelectedPeriodBalance();
                break;
            case '6':
                personalBudget.changeThePasswordOfLoggedInUser();
                break;
            case '7':
                personalBudget.userLogout();
                break;
            default:
                cout << endl << "There is no option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}

char mainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> PERSONAL BUDGET <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User Registration" << endl;
    cout << "2. User Login" << endl;
    cout << "9. End Program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char userMenu()
{
    char choice;
    cin.get();
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance " << endl;
    cout << "5. Balance from selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
