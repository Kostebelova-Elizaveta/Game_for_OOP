#ifndef LOGGER_H
#define LOGGER_H
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Field/field.h"
#include <fstream>

class Logger
{
public:
    virtual ~Logger();
    virtual void WriteDown(InterfaceForPoint* smtf) = 0;
    virtual void WriteDown(Field* smtf) = 0;
    virtual void WriteDown(Point* smtf) = 0;
    virtual bool GetUsable() = 0;
};

#endif // LOGGER_H
