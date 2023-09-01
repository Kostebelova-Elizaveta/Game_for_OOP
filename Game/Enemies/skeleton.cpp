#include "skeleton.h"

Skeleton::Skeleton()
{
    health = 25;
    atack = 5;
    speed = 1500;
    type = 3;
    check=0;
    way = 1;
    alive = 1;
    name = skeleton;
}

void Skeleton::PickItem(InterfaceForPoint *&item)
{

}

void Skeleton::Fight(InterfaceForPoint *&enemy)
{

}

void Skeleton::SetHealth(int num)
{
    health = num;
}

void Skeleton::SetAtack(int num)
{
    atack = num;
}

void Skeleton::SetSpeed(int num)
{
    speed = num;
}

int Skeleton::GetBuf() {
    return 0;
}

int Skeleton::GetAlive() {
    return alive;
}

int Skeleton::GetWay() {
    return way;
}

void Skeleton::SetAlive(int num) {
    alive=num;
}

void Skeleton::SetWay(int num) {
    way=num;
}

int Skeleton::GetHealth() {
    return health;
}
int Skeleton::GetAtack() {
    return atack;
}
int Skeleton::GetSpeed() {
    return speed;
}
int Skeleton::GetType() {
    return type;
}
int Skeleton::GetCheck() {
    return check;
}
void Skeleton::SetCheck(int num) {
    check=num;;
}
int Skeleton::GetPositionX() {
    return x;
}
int Skeleton::GetPositionY() {
    return y;
}
void Skeleton::SetPositionX(int num) {
    x = num;
}
void Skeleton::SetPositionY(int num) {
    y = num;
}


NameOfObjects Skeleton::GetName() {
    return name;
}

