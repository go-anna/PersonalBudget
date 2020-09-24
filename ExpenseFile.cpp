#include "ExpenseFile.h"

bool ExpenseFile::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(XML_FILE);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "ExpenseID", expense.getId());
    xml.AddElem( "UserID", expense.getUserId());
    xml.AddElem( "Date", expense.getStringDate());
    xml.AddElem( "Item", expense.getItem());
    xml.AddElem( "Amount", AuxiliaryMethods::convertDoubleToString(expense.getAmount()));


    xml.Save(XML_FILE);
    return true;
}

vector <Expense> ExpenseFile::getLastExpenseId(int ID_OF_LOGGED_USER)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;

    xml.Load(XML_FILE);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "ExpenseID" );
        expense.setId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "UserID" );
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Date" );
        expense.setStringDate(xml.GetData());
        expense.setIntDate(AuxiliaryMethods::convertDateFromStringToIntWithoutDash(expense.getStringDate()));
        xml.FindElem( "Item" );
        expense.setItem(xml.GetData());
        xml.FindElem( "Amount" );
        expense.setAmount(atof( MCD_2PCSZ(xml.GetData())));
        xml.OutOfElem();
        if (ID_OF_LOGGED_USER == expense.getUserId())
            expenses.push_back(expense);
    }
    return expenses;
}

int ExpenseFile::getIdOfLastExpenseFromFile()
{
    Expense expense;
    CMarkup xml;
    int idOfLastExpense;

    bool fileExists = xml.Load(XML_FILE);

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") )
        {
            xml.IntoElem();
            xml.FindElem( "ExpenseID" );
            idOfLastExpense = atoi( MCD_2PCSZ(xml.GetData()));
            xml.OutOfElem();
        }
    }
    else
        idOfLastExpense = 0;

    return idOfLastExpense;
}
