#ifndef SAVER_H
#define SAVER_H
#include "Game/Field/field.h"
#include "loggerconsole.h"
#include "loggerfile.h"
#include <iostream>
#include <fstream>
using namespace std;

class Saver
{
private:
    ofstream myfile;
    string name;
public:
    Saver();
    void Save(Field* fieldForSafe);
    friend std::ostream& operator<< (std::ostream &out, Field &smtf);
    ~Saver();
};

#endif // SAVER_H
