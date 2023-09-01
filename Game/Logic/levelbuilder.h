#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H
#include "Game/Field/field.h"
#include "Game/Logic/builder.h"
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Hero/hero.h"


class LevelBuilder : public Builder
{
private:
   Field* field;
public:
    LevelBuilder();
    ~LevelBuilder();
    void SetField(int widht, int height, int numberOfEnemy, int numberOfItem, int countEnemy, int countItem);
    void SetSavedField(Field* fieldIn);
    Field* GetField();
    bool IsInVectorObj(InterfaceForPoint* smtf, std::vector<InterfaceForPoint*> vec);
};

#endif // LEVELBUILDER_H
