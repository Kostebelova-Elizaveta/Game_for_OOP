#include "loggerfile.h"

std::ostream& operator<< (std::ostream &out, InterfaceForPoint &smtf);
std::ostream& operator<< (std::ostream &out, Field &smtf);
std::ostream& operator<< (std::ostream &out, Point &smtf);

LoggerFile::LoggerFile(bool num, string filename)
{
    usable=num;
    name = "C:/Users/liza/Desktop/OOP_Lab3/" + filename;
    myfile.open(name);
}

void LoggerFile::WriteDown(InterfaceForPoint* smtf) {
    myfile << *smtf;
}
void LoggerFile::WriteDown(Point* smtf) {
    myfile << *smtf;
}
void LoggerFile::WriteDown(Field* smtf) {
    myfile << *smtf;
}

bool LoggerFile::GetUsable() {
    return usable;
}

LoggerFile::~LoggerFile()
{
    myfile.close();
}
