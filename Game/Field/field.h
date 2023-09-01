#ifndef FIELD_H
#define FIELD_H
#include "Game/Field/point.h"
#include "Game/Paint/palette.h"
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Hero/hero.h"
#include <QGraphicsScene>

class Field
{
private:
    int width, height;
    Point** bricks;
    Hero* playerReminder;
    int countEnemy;
    int countItem;
public:
    Field(int width, int heigh, int countEnemyIn, int countItemIn);
    Field(const Field &poleForCopy);
    Field(Field &&poleForMoving);
    Field operator = (const Field &poleForCopy);
    Field operator = (Field &&poleForMoving);
    Point* GetBrick(int height, int widht);
    Point* FindExit();
    InterfaceForPoint* Find (NameOfObjects name);
    int GetWidth();
    int GetHeight();
    int GetCountEnemy();
    int GetCountItem();
    void SetCountEnemy(int num);
    void SetCountItem(int num);
    void SetHeight(int num);
    void SetWidth(int num);
    ~Field();
};

#endif // FIELD_H
