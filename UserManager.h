#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "UserFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UserFile userFile;

    User insertNewUserData();


public:
    UserManager(string nameFile) : userFile(nameFile){
        loggedInUserId = 0;
        users = userFile.loadUsersFromTheFile();
    };
    void userRegistration();
    void userLogin();
    int getNewId();
    int userLoggingIn();
    bool isThereLogin(string login);
    void changeThePasswordOfLoggedInUser();
    void userLogout();
    int getUserLogin();
    bool isUserLoggedIn();
     char userMenu();
};

#endif
