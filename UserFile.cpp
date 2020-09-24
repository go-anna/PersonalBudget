#include "userFile.h"

void UserFile::saveAllUsersToTheFile(User user)
{
 CMarkup xml;

  bool fileExists = xml.Load(XML_FILE);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "UserID", user.getId());
    xml.AddElem( "Name", user.getName());
    xml.AddElem( "Surname", user.getSurname());
    xml.AddElem( "Login", user.getLogin());
    xml.AddElem( "Password", user.getPassword());

    xml.Save(XML_FILE);
}

vector <User> UserFile::loadUsersFromTheFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    xml.Load(XML_FILE);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "UserID" );
        user.setId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
        xml.FindElem( "Name" );
        user.setName(xml.GetData());
        xml.FindElem( "Surname" );
        user.setSurname(xml.GetData());
        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());
        xml.FindElem( "Password" );
        user.setPassword(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}
