#ifndef INTERFACEFORPOINT_H
#define INTERFACEFORPOINT_H
#include <QGraphicsScene>



enum NameOfObjects {hero, troll, beagle, skeleton, potion, sword, boots};

class InterfaceForPoint
{
public:
    virtual ~InterfaceForPoint();
    virtual int GetAlive() = 0;
    virtual int GetBuf() = 0;
    virtual void SetAlive(int num) = 0;
    virtual void SetWay(int num) = 0;
    virtual int GetWay() = 0;
    virtual int GetPositionX() = 0;
    virtual int GetPositionY() = 0;
    virtual void SetPositionX(int num) = 0;
    virtual void SetPositionY(int num) = 0;
    virtual int GetCheck() = 0;
    virtual void SetCheck(int num) = 0;
    virtual NameOfObjects GetName() = 0;
    virtual int GetHealth() = 0;
    virtual int GetAtack() = 0;
    virtual int GetSpeed() = 0;
    virtual void SetHealth(int num) = 0;
    virtual void SetAtack(int num) = 0;
    virtual void SetSpeed(int num) = 0;

    virtual void PickItem(InterfaceForPoint* &item) = 0;
    virtual void Fight(InterfaceForPoint* &enemy) = 0;

};

#endif // INTERFACEFORPOINT_H
