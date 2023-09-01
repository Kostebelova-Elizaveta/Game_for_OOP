#include "troll.h"

Troll::Troll()
{
    health = 50;
    atack = 15;
    speed = 2000;
    type = 1;
    check=0;
    way = 1;
    alive = 1;
    name = troll;
}

void Troll::PickItem(InterfaceForPoint *&item)
{

}

void Troll::Fight(InterfaceForPoint *&enemy)
{

}

void Troll::SetHealth(int num)
{
    health = num;
}

void Troll::SetAtack(int num)
{
    atack = num;
}

void Troll::SetSpeed(int num)
{
    speed = num;
}

int Troll::GetBuf() {
    return 0;
}

int Troll::GetAlive() {
    return alive;
}

int Troll::GetWay() {
    return way;
}

void Troll::SetAlive(int num) {
    alive=num;
}

void Troll::SetWay(int num) {
    way=num;
}

int Troll::GetHealth() {
    return health;
}
int Troll::GetAtack() {
    return atack;
}
int Troll::GetSpeed() {
    return speed;
}
int Troll::GetType() {
    return type;
}
int Troll::GetCheck() {
    return check;
}
void Troll::SetCheck(int num) {
    check=num;;
}
int Troll::GetPositionX() {
    return x;
}
int Troll::GetPositionY() {
    return y;
}
void Troll::SetPositionX(int num) {
    x = num;
}
void Troll::SetPositionY(int num) {
    y = num;
}
NameOfObjects Troll::GetName() {
    return name;
}
