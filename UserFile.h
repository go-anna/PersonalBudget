#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class UserFile : public XmlFile
{

public:
    UserFile(string fileName) : XmlFile(fileName){};
    void saveAllUsersToTheFile(User user);
    vector <User> loadUsersFromTheFile();
     void addAllUsersToFile(vector <User> &users);
};

#endif
