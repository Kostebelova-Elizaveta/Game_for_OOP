#ifndef TROLL_H
#define TROLL_H
#include "Game/Enemies/enemy.h"

class Troll : public Enemy
{
private:
    int health, atack, speed;
    int type, check;
    int alive, way;
    int x, y;
    NameOfObjects name;
public:
    Troll();
    int GetBuf();
    int GetAlive();
    int GetWay();
    void SetAlive(int num);
    void SetWay(int num);
    int GetHealth();
    int GetAtack();
    int GetSpeed();
    int GetType();
    int GetCheck();
    void SetCheck(int num);
    int GetPositionX();
    int GetPositionY();
    void SetPositionX(int num);
    void SetPositionY(int num);
    NameOfObjects GetName();
    void SetHealth(int num);
    void SetAtack(int num);
    void SetSpeed(int num);

    void PickItem(InterfaceForPoint* &item);
    void Fight(InterfaceForPoint* &enemy);
};

#endif // TROLL_H
