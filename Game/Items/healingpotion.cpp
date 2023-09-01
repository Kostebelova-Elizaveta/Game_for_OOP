#include "Game/Items/healingpotion.h"

HealingPotion::HealingPotion()
{
    bufHp=50;
    bufAt=0;
    bufSp=0;
    alive=1;
    check=0;
    name = potion;
}

void HealingPotion::PickItem(InterfaceForPoint *&item)
{

}

void HealingPotion::Fight(InterfaceForPoint *&enemy)
{

}

void HealingPotion::SetHealth(int num)
{

}

void HealingPotion::SetAtack(int num)
{

}

void HealingPotion::SetSpeed(int num)
{

}

int HealingPotion::GetAlive() {
    return alive;
}

int HealingPotion::GetWay() {
    return 0;
}

void HealingPotion::SetAlive(int num) {
    alive=num;
}

void HealingPotion::SetWay(int num) {

}

int HealingPotion::GetBuf() {
    return bufHp;
}

int HealingPotion::GetPositionX() {
    return x;
}
int HealingPotion::GetPositionY() {
    return y;
}
void HealingPotion::SetPositionX(int num) {
    x = num;
}
void HealingPotion::SetPositionY(int num) {
    y = num;
}
int HealingPotion::GetCheck() {
    return check;
}
void HealingPotion::SetCheck(int num) {
    check=num;;
}


int HealingPotion::GetHealth() {
    return 0;
}
int HealingPotion::GetAtack() {
    return 0;
}
int HealingPotion::GetSpeed() {
    return 0;
}

NameOfObjects  HealingPotion::GetName() {
    return name;
}
