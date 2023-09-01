#ifndef LOGGERFILE_H
#define LOGGERFILE_H
#include "Game/logger.h"
#include <iostream>
using namespace std;

class LoggerFile : public Logger
{
private:
    bool usable;
    ofstream myfile;
    string name;
public:
    friend std::ostream& operator<< (std::ostream &out, InterfaceForPoint &smtf);
    friend std::ostream& operator<< (std::ostream &out, Field &smtf);
    friend std::ostream& operator<< (std::ostream &out, Point &smtf);
    LoggerFile(bool num, string filename);
    void WriteDown(InterfaceForPoint* smtf);
    void WriteDown(Field* smtf);
    void WriteDown(Point* smtf);
    bool GetUsable();
    ~LoggerFile();
};

#endif // LOGGERFILE_H
