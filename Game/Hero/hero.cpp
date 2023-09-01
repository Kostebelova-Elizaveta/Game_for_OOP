#include "Game/Hero/hero.h"

Hero::Hero()
{
    health = 100;
    atack = 25;
    speed = 500;
    name = hero;
    alive = 1;
    check = 0;
}

int Hero::GetBuf() {
    return 0;
}

int Hero::GetHealth() {
    return health;
}
int Hero::GetAtack() {
    return atack;
}
int Hero::GetSpeed() {
    return speed;
}
void Hero::AddHealth(int num) {
    health+=num;
}
void Hero::AddAtack(int num) {
    atack+=num;
}
void Hero::AddSpeed(int num) {
    speed+=num;
}

int Hero::GetPositionX() {
    return x;
}
int Hero::GetPositionY() {
    return y;
}
void Hero::SetPositionX(int num) {
    x = num;
}
void Hero::SetPositionY(int num) {
    y = num;
}
int Hero::GetCheck() {
    return check;
}
void Hero::SetCheck(int num) {
    check=num;;
}

NameOfObjects Hero::GetName() {
    return name;
}

int Hero::GetAlive() {
    return alive;
}

int Hero::GetWay() {
    return 0;
}

void Hero::SetAlive(int num) {
    alive=num;
}

void Hero::SetWay(int num) {

}

void Hero::PickItem(InterfaceForPoint* &item) {
    if (item->GetName()==potion) {
        health+=item->GetBuf();
    }
    if (item->GetName()==sword) {
        atack+=item->GetBuf();
    }
    if (item->GetName()==boots) {
        speed+=item->GetBuf();
    }

}


//void Hero::Win(Point* cell) {
//    if (cell->GetCondition()==3) {
//        qApp->quit();
//    }
//}

void Hero::Fight(InterfaceForPoint* &enemy) {
    health-=enemy->GetAtack()*(enemy->GetHealth()/atack);

}

void Hero::SetHealth(int num)
{
    health = num;
}

void Hero::SetAtack(int num)
{
    atack = num;
}

void Hero::SetSpeed(int num)
{
    speed = num;
}

Hero::~Hero() {

}


