#ifndef BUILDER_H
#define BUILDER_H
#include "Game/Field/field.h"
#include <QGraphicsScene>

class Builder
{
public:
    virtual ~Builder();
    virtual void SetField(int widht, int height, int numberOfEnemy, int numberOfItem, int countEnemy, int countItem) = 0;
    virtual void SetSavedField(Field* fieldIn) = 0;
};

#endif // BUILDER_H
