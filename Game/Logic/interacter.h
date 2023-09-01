#ifndef INTERACTER_H
#define INTERACTER_H
#include "Game/Field/field.h"

class Interacter
{
private:
    Field* field;
public:
    Interacter(Field* fieldIn);
    ~Interacter();
    void InteractFight(InterfaceForPoint* enemy, InterfaceForPoint* player);
    void InteractPick(InterfaceForPoint* item, InterfaceForPoint* player);
    void InteractExit(Point* exit, InterfaceForPoint* player);
    void SetField(Field* fieldIn);
};

#endif // INTERACTER_H
