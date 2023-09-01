#ifndef HERO_H
#define HERO_H
#include <QApplication>
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Items/item.h"
#include "Game/Enemies/enemy.h"
#include "Game/Field/point.h"

class Hero : public InterfaceForPoint
{
private:
    int health, atack, speed;
    int x, y;
    int alive;
    int check;
    NameOfObjects name;
public:
    Hero();
    int GetBuf();
    int GetAlive();
    int GetWay();
    void SetAlive(int num);
    void SetWay(int num);
    int GetHealth();
    int GetAtack();
    int GetSpeed();
    void AddHealth(int num);
    void AddAtack(int num);
    void AddSpeed(int num);
    int GetPositionX();
    int GetPositionY();
    void SetPositionX(int num);
    void SetPositionY(int num);
    int GetCheck();
    void SetCheck(int num);
    NameOfObjects GetName();
    ~Hero();
    void PickItem(InterfaceForPoint* &item);
    //void Win(Point* cell);
    void Fight(InterfaceForPoint* &enemy);
    void SetHealth(int num);
    void SetAtack(int num);
    void SetSpeed(int num);
};

#endif // HERO_H
