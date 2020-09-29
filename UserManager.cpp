#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = insertNewUserData();

    users.push_back(user);
    userFile.saveAllUsersToTheFile(user);

    cout << endl << "The account has been successfully created" << endl << endl;
    system("pause");
}

char UserManager::userMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from the current month" << endl;
    cout << "4. Balance from the previous month" << endl;
    cout << "5. Balance from the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. change password" << endl;
    cout << "7. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

User UserManager::insertNewUserData()
{
    User user;
    string tekst;
    user.setId(getNewId());

    cout << "Enter Name: ";
    user.setName(AuxiliaryMethods::loadLine());
    user.setName(AuxiliaryMethods::replaceFirstLetterToUppercaseAndRemainderLowercase(user.getName()));

    cout << "Enter Surname: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    user.setName(AuxiliaryMethods::replaceFirstLetterToUppercaseAndRemainderLowercase(user.getName()));

    do
    {
        cout << "Enter Login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (isThereLogin(user.getLogin()) == true);

    cout << "Enter Password: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

void UserManager::userLogin()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
         {
                cout << "Enter password. : Attempts left " << attempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Succesful login" << endl << endl;
                    loggedInUserId = itr -> getId();
                    system("pause");
                    return;
                }
            }
            cout << "The password was entered incorrectly for 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return;
}

int UserManager::getNewId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isThereLogin(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login has already exist." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::changeThePasswordOfLoggedInUser()
{
    string newPassword = "";
    if(loggedInUserId==0){
        cout<<"Please log in to change your password"<<endl;
        userLogin();
    }
    cout << "Type new password: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getId() == loggedInUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been successfully changed." << endl << endl;
        }
    }

}

void UserManager::userLogout()
{
    cout<<"You are logged out"<<endl;
    loggedInUserId=0;

}

int UserManager::getUserLogin()
{
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn()
{
    if(loggedInUserId!=0){
        return true;
    }
    else
        {
        return false;
    }
}
