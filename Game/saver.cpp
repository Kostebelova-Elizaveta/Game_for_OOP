#include "saver.h"

std::ostream& operator<< (std::ostream &out, Field &smtf);


Saver::Saver()
{
    name = "C:/Users/liza/Desktop/OOP_Lab3/save.txt";
}

void Saver::Save(Field *fieldForSafe)
{
    myfile.open(name);
    myfile << *fieldForSafe;
    myfile.close();

}

Saver::~Saver()
{

}

