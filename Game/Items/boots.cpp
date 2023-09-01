#include "Game/Items/boots.h"

Boots::Boots()
{
    bufSp=20;
    bufHp=0;
    bufAt=0;
    alive=1;
    check=0;
    name = boots;
}

void Boots::PickItem(InterfaceForPoint *&item)
{

}

void Boots::Fight(InterfaceForPoint *&enemy)
{

}

void Boots::SetHealth(int num)
{

}

void Boots::SetAtack(int num)
{

}

void Boots::SetSpeed(int num)
{

}

int Boots::GetAlive() {
    return alive;
}

int Boots::GetWay() {
    return 0;
}

void Boots::SetAlive(int num) {
    alive=num;
}

void Boots::SetWay(int num) {

}

int Boots::GetBuf() {
    return bufSp;
}

int Boots::GetPositionX() {
    return x;
}
int Boots::GetPositionY() {
    return y;
}
void Boots::SetPositionX(int num) {
    x = num;
}
void Boots::SetPositionY(int num) {
    y = num;
}
int Boots::GetCheck() {
    return check;
}
void Boots::SetCheck(int num) {
    check=num;;
}


int Boots::GetHealth() {
    return 0;
}
int Boots::GetAtack() {
    return 0;
}
int Boots::GetSpeed() {
    return 0;
}

NameOfObjects Boots::GetName() {
    return name;
}
