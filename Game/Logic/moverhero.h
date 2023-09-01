#ifndef MOVERHERO_H
#define MOVERHERO_H
#include "Game/Field/field.h"
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Logic/mover.h"

class MoverHero
{
private:
    Field* field;
    InterfaceForPoint* player;
    Mover* mover;
public:
    MoverHero(Field* fieldIn, InterfaceForPoint* playerIn, Mover* moverIn);
    void MoveHeroUp();
    void MoveHeroDown();
    void MoveHeroLeft();
    void MoveHeroRight();
    InterfaceForPoint* GetHero();
    Field* GetField();
    void SetField(Field* fieldIn);
};

#endif // MOVERHERO_H
