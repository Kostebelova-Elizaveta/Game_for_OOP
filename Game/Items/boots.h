#ifndef BOOTS_H
#define BOOTS_H
#include "Game/Items/item.h"

class Boots : public Item
{
private:
    int bufAt, bufSp, bufHp;
    int x, y;
    int check;
    int alive;
    NameOfObjects name;
public:
    Boots();
    int GetAlive();
    int GetWay();
    void SetAlive(int num);
    void SetWay(int num);
    int GetBuf();
    int GetPositionX();
    int GetPositionY();
    void SetPositionX(int num);
    void SetPositionY(int num);
    int GetCheck();
    void SetCheck(int num);
    NameOfObjects GetName();
    int GetHealth();
    int GetAtack();
    int GetSpeed();
    void SetHealth(int num);
    void SetAtack(int num);
    void SetSpeed(int num);

    void PickItem(InterfaceForPoint* &item);
    void Fight(InterfaceForPoint* &enemy);
};

#endif // BOOTS_H
