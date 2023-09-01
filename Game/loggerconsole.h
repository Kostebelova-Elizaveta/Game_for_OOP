#ifndef LOGGERCONSOLE_H
#define LOGGERCONSOLE_H
#include "Game/logger.h"
#include <iostream>
using namespace std;


class LoggerConsole : public Logger
{
private:
    bool usable;
public:
    friend std::ostream& operator<< (std::ostream &out, InterfaceForPoint &smtf);
    friend std::ostream& operator<< (std::ostream &out, Field &smtf);
    friend std::ostream& operator<< (std::ostream &out, Point &smtf);
    LoggerConsole(bool num);
    void WriteDown(InterfaceForPoint* smtf);
    void WriteDown(Field* smtf);
    void WriteDown(Point* smtf);
    bool GetUsable();
    ~LoggerConsole();

};

#endif // LOGGERCONSOLE_H
