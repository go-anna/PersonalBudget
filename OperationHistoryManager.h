#ifndef OPERATIONHISTORYMANAGER_H
#define OPERATIONHISTORYMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <algorithm>

#include "ExpenseFile.h"
#include "IncomeFile.h"
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class OperationHistoryManager
{
   const int ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    ExpenseFile expenseFile;
    IncomeFile incomeFile;
    DateManager dateManager;

    Income setIncomeDataOfToday();
    Income setIncomeDataFromAnotherDay();
    Expense setExpenseDataOfToday();
    Expense setExpenseDataFromAnotherDay();
    void showDataOfIncome(Income income);
    void showDataOfExpense(Expense expense);
    void displaySearchIncomesAndSum(int numberOfIncomes, double incomesSum);
    void displaySearchExpensesAndSum(int numberOfExpenses, double incomesSum, double expensesSum);
    char incomeMenu();
    char expenseMenu();

public:
    OperationHistoryManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser)
        : incomeFile(nameOfFileWithIncomes), expenseFile(nameOfFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = incomeFile.getLastIncomeId(ID_OF_LOGGED_USER);
        expenses = expenseFile.getLastExpenseId(ID_OF_LOGGED_USER);
    };
    int addIncome();
    int addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
};

#endif
