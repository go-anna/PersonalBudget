#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile
{
protected:
    const string XML_FILE;

public:
    XmlFile(string xmlFileName) : XML_FILE(xmlFileName) {};
};

#endif
