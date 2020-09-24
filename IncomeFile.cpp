#include "IncomeFile.h"

bool IncomeFile::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(XML_FILE);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeID", income.getId());
    xml.AddElem( "UserID", income.getUserId());
    xml.AddElem( "Date", income.getStringDate());
    xml.AddElem( "Item", income.getItem());
    xml.AddElem( "Amount", AuxiliaryMethods::convertDoubleToString(income.getAmount()));

    xml.Save(XML_FILE);
    return true;
}

vector <Income> IncomeFile::getLastIncomeId(int ID_OF_LOGGED_USER)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    xml.Load(XML_FILE);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "IncomeID" );
        income.setId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "UserID" );
        income.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Date" );
        income.setStringDate(xml.GetData());
        income.setIntDate(AuxiliaryMethods::convertDateFromStringToIntWithoutDash(income.getStringDate()));
        xml.FindElem( "Item" );
        income.setItem(xml.GetData());
        xml.FindElem( "Amount" );
        income.setAmount(atof( MCD_2PCSZ(xml.GetData())));
        xml.OutOfElem();

        if (ID_OF_LOGGED_USER == income.getUserId())
            incomes.push_back(income);
    }
    return incomes;
}

int IncomeFile::getIdOfLastIncomeFromFile()
{
    Income income;
    CMarkup xml;
    int idOfLastIncome;

    bool fileExists = xml.Load(XML_FILE);

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") )
        {
            xml.IntoElem();
            xml.FindElem( "IncomeID" );
            idOfLastIncome = atoi( MCD_2PCSZ(xml.GetData()));
            xml.OutOfElem();
        }
    }
    else
        idOfLastIncome = 0;

    return idOfLastIncome;
}
