#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H
#include "Game/Items/item.h"

class HealingPotion : public Item
{
private:
    int bufAt, bufSp, bufHp;
    int x, y;
    int check;
    int alive;
    NameOfObjects name;
public:
    HealingPotion();
    int GetAlive();
    int GetWay();
    void SetAlive(int num);
    void SetWay(int num);
    int GetBuf();
    int GetPositionX();
    int GetPositionY();
    int GetCheck();
    void SetCheck(int num);
    void SetPositionX(int num);
    void SetPositionY(int num);
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

#endif // HEALINGPOTION_H
