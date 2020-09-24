#include "OperationHistoryManager.h"

int OperationHistoryManager::addIncome()
{
    Income income;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
        choice = incomeMenu();

        switch (choice)
        {
        case '1':
            income = setIncomeDataOfToday();
            incomes.push_back(income);
            if (incomeFile.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;
        case '2':
            income = setIncomeDataFromAnotherDay();
            incomes.push_back(income);
            if (incomeFile.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;
        case '3':
            return 0;
            break;
        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Income OperationHistoryManager::setIncomeDataOfToday()
{
    Income income;

    string date, amount, item;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);
    income.setId(incomeFile.getIdOfLastIncomeFromFile() + 1);

    date = dateManager.getCurrentDate();
    dateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(date);

    cout << "Enter the Item: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Enter the amount of income: ";
    amount = AuxiliaryMethods::loadLine();
    amountDouble = AuxiliaryMethods::convertStringToDouble(amount);

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setItem((item));
    income.setAmount(amountDouble);

    return income;
}

Income OperationHistoryManager::setIncomeDataFromAnotherDay()
{
    Income income;

    string date, amount, item;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);
    income.setId(incomeFile.getIdOfLastIncomeFromFile() + 1);

    cout << "Enter the date in rrrr-mm-dd format: ";

    do
    {
        date = AuxiliaryMethods::loadLine();
    } while(dateManager.checkIfDateIsCorrect(date) == false);
    dateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(date);

    cout << "Write the Item: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Enter the amount of income: ";
    amount = AuxiliaryMethods::loadLine();
    amountDouble = AuxiliaryMethods::convertStringToDouble(amount);

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setItem((item));
    income.setAmount(amountDouble);

    return income;
}

int OperationHistoryManager::addExpense()
{
    Expense expense;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
        choice = expenceMenu();

        switch (choice)
        {
        case '1':
            expense = setExpenseDataOfToday();
            expenses.push_back(expense);
            if (expenseFile.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;
        case '2':
            expense = setExpenseDataFromAnotherDay();
            expenses.push_back(expense);
            if (expenseFile.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;
        case '3':
            return 0;
            break;
        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Expense OperationHistoryManager::setExpenseDataOfToday()
{
    Expense expense;

    string date, amount, item;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setId(expenseFile.getIdOfLastExpenseFromFile() + 1);

    date = dateManager.getCurrentDate();
    dateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(date);

    cout << "Enter the Item: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Enter the amount of expense: ";
    amount = AuxiliaryMethods::loadLine();
    if(amount[0] != '-')
    amount = '-' + amount;
    amountDouble = AuxiliaryMethods::convertStringToDouble(amount);

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setItem((item));
    expense.setAmount(amountDouble);

    return expense;
}

Expense OperationHistoryManager::setExpenseDataFromAnotherDay()
{
    Expense expense;

    string date, amount, item;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setId(expenseFile.getIdOfLastExpenseFromFile() + 1);

    cout << "Enter the date in rrrr-mm-dd format: ";
    do
    {
        date = AuxiliaryMethods::loadLine();
    } while(dateManager.checkIfDateIsCorrect(date) == false);
    dateInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(date);

    cout << "Write the Item: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Enter the amount of expense: ";
    amount = AuxiliaryMethods::loadLine();
    if(amount[0] != '-')
    amount = '-' + amount;
    amountDouble = AuxiliaryMethods::convertStringToDouble(amount);

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setItem((item));
    expense.setAmount(amountDouble);

    return expense;
}

void OperationHistoryManager::showCurrentMonthBalance()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = dateManager.getCurrentDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            if ( year == yearOfIncome && month == monthOfIncome)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displaySearchIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            if ( year == yearOfExpense && month == monthOfExpense)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displaySearchExpensesAndSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void OperationHistoryManager::showPreviousMonthBalance()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = dateManager.getCurrentDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    int monthInt = AuxiliaryMethods::convertStringToInt(month) - 1;
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            int monthOfIncomeInt = AuxiliaryMethods::convertStringToInt(monthOfIncome);
            if ( year == yearOfIncome && monthInt == monthOfIncomeInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displaySearchIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            int monthOfExpenseInt = AuxiliaryMethods::convertStringToInt(monthOfExpense);
            if ( year == yearOfExpense && monthInt == monthOfExpenseInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displaySearchExpensesAndSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void OperationHistoryManager::showSelectedPeriodBalance()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string firstDay, lastDay;
    int firstDayInt, lastDayInt;
    double incomesSum = 0;
    double expensesSum = 0;

    cout << "Enter first day in rrrr-mm-dd format: ";
    do
    {
        firstDay = AuxiliaryMethods::loadLine();
    } while(dateManager.checkIfDateIsCorrect(firstDay) == false);
    firstDayInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(firstDay);

    cout << "Enter last day in rrrr-mm-dd format: ";
    do
    {
        lastDay = AuxiliaryMethods::loadLine();
    } while(dateManager.checkIfDateIsCorrect(lastDay) == false);
    lastDayInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(lastDay);

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            int dateOfIncomeInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(dateOfIncome);
            if ( dateOfIncomeInt >= firstDayInt && dateOfIncomeInt <= lastDayInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displaySearchIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            int dateOfExpenseInt = AuxiliaryMethods::convertDateFromStringToIntWithoutDash(dateOfExpense);
            if ( dateOfExpenseInt >= firstDayInt && dateOfExpenseInt <= lastDayInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displaySearchExpensesAndSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void OperationHistoryManager::displaySearchIncomesAndSum(int numberOfIncomes, double incomesSum)
{
    if (numberOfIncomes == 0)
        cout << endl << "There are no incomes in a selected period." << endl;
    else
        cout << endl << "The amount of incomes in a selected period is: " << numberOfIncomes << endl;
    cout << "The Sum of incomes: " << setprecision(15) << incomesSum << endl << endl;
}

void OperationHistoryManager::displaySearchExpensesAndSum(int numberOfExpenses, double incomesSum, double expensesSum)
{
    if (numberOfExpenses == 0)
        cout << endl << "There are no expenses in a selected period." << endl;
    else
        cout << endl << "The amount of expenses in a selected period is: " << numberOfExpenses << endl;
    cout << "The Sum of Expenses: " << setprecision(15) << expensesSum << endl << endl;
    cout << "TOTAL INCOME IN THE SELECTED PERIOD: " << setprecision(15) << incomesSum + expensesSum;
        cout << endl << endl;
}

void OperationHistoryManager::showDataOfIncome(Income income)
{
    cout << endl << "IncomeID:                 " << income.getId() << endl;
    cout << "Date:                 " << income.getStringDate() << endl;
    cout << "Item:          " << income.getItem() << endl;
    cout << "Amount:               " << setprecision(15) << income.getAmount() << endl;
}

void OperationHistoryManager::showDataOfExpense(Expense expense)
{
    cout << endl << "ExpenseID:                 " << expense.getId() << endl;
    cout << "Date:                 " << expense.getStringDate() << endl;
    cout << "Item:          " << expense.getItem() << endl;
    cout << "Amount:               " << setprecision(15) << expense.getAmount() << endl;

}

char OperationHistoryManager::incomeMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's income" << endl;
    cout << "2 - Income from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char OperationHistoryManager::expenceMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's expense" << endl;
    cout << "2 - Expense from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
