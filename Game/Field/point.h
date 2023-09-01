#ifndef POINT_H
#define POINT_H
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Paint/palette.h"
#include <vector>
#include <QGraphicsScene>
#include "Game/Items/healingpotion.h"
#include "Game/Items/sword.h"
#include "Game/Items/boots.h"
#include "Game/Enemies/troll.h"
#include "Game/Enemies/beagle.h"
#include "Game/Enemies/skeleton.h"

class Point
{
private:
    int passable; //проходимость 1 - проходит, 0 - иначе
    int condition; //вид блока, 1 - часть поля, 2 - вход, 3 - выход, 0 - стена
    std::vector<InterfaceForPoint*> elements; // для хранения игрока, врагов и предметов
public:
    int GetPassable();
    void SetPassable(int num);
    int GetCondition();
    void SetCondition(int num);
    std::vector<InterfaceForPoint*> GetVector();
    Point();
    ~Point();
    Point operator = (const Point &brickForCopy);
    void AddToVector(NameOfObjects nameOfObj);
    void AddObjToVector(InterfaceForPoint* smtf);
    void AddHero(InterfaceForPoint* smtf);
    int IsInVector(NameOfObjects nameOfObj);
    void DelObjFromVector(int pos);
    bool IsSmtfInVector();
    bool IsKindnessInVector();
    bool IsTrollInVector();
    bool IsBeagleInVector();
    bool IsSkeletonInVector();
    bool IsEnemyInVector();
    bool IsSwordInVector();
    bool IsPotionInVector();
    bool IsBootsInVector();
    void ClearVector();
    void DelObjFromMemory(InterfaceForPoint* smtf);
    InterfaceForPoint* GetObj(NameOfObjects nameOfObj);
};

#endif // POINT_H
