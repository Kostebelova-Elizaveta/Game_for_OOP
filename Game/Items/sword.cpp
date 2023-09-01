#include "Game/Items/sword.h"

Sword::Sword()
{
    bufAt=20;
    bufHp=0;
    bufSp=0;
    alive=1;
    check=0;
    name = sword;
}

void Sword::SetHealth(int num)
{

}

void Sword::SetAtack(int num)
{

}

void Sword::SetSpeed(int num)
{

}

void Sword::PickItem(InterfaceForPoint *&item)
{

}

void Sword::Fight(InterfaceForPoint *&enemy)
{

}

int Sword::GetBuf() {
    return bufAt;
}

int Sword::GetPositionX() {
    return x;
}
int Sword::GetPositionY() {
    return y;
}
void Sword::SetPositionX(int num) {
    x = num;
}
void Sword::SetPositionY(int num) {
    y = num;
}
int Sword::GetCheck() {
    return check;
}
void Sword::SetCheck(int num) {
    check=num;;
}

int Sword::GetAlive() {
    return alive;
}

int Sword::GetWay() {
    return 0;
}

void Sword::SetAlive(int num) {
    alive=num;
}

void Sword::SetWay(int num) {

}

int Sword::GetHealth() {
    return 0;
}
int Sword::GetAtack() {
    return 0;
}
int Sword::GetSpeed() {
    return 0;
}

NameOfObjects Sword::GetName() {
    return name;
}
