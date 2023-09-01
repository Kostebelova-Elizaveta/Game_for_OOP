#include "beagle.h"

Beagle::Beagle()
{
    health = 30;
    atack = 20;
    speed = 1000;
    type = 2;
    check = 0;
    way = 1;
    alive = 1;
    name = beagle;
}

void Beagle::PickItem(InterfaceForPoint *&item)
{

}

void Beagle::Fight(InterfaceForPoint *&enemy)
{

}

void Beagle::SetHealth(int num)
{
    health = num;
}

void Beagle::SetAtack(int num)
{
    atack = num;
}

void Beagle::SetSpeed(int num)
{
    speed = num;
}

int Beagle::GetBuf() {
    return 0;
}

int Beagle::GetHealth() {
    return health;
}
int Beagle::GetAtack() {
    return atack;
}
int Beagle::GetSpeed() {
    return speed;
}
int Beagle::GetType() {
    return type;
}

int Beagle::GetCheck() {
    return check;
}
void Beagle::SetCheck(int num) {
    check=num;;
}

int Beagle::GetPositionX() {
    return x;
}
int Beagle::GetPositionY() {
    return y;
}
void Beagle::SetPositionX(int num) {
    x = num;
}
void Beagle::SetPositionY(int num) {
    y = num;
}

int Beagle::GetAlive() {
    return alive;
}

int Beagle::GetWay() {
    return way;
}

void Beagle::SetAlive(int num) {
    alive=num;
}

void Beagle::SetWay(int num) {
    way=num;
}

NameOfObjects Beagle::GetName() {
    return name;
}

