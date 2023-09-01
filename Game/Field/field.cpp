#include "Game/Field/field.h"
#include <QGraphicsScene>
#include <QPen>

Field::Field(int width_input, int height_input, int countEnemyIn, int countItemIn)
{
   width=width_input;
   height=height_input;
   bricks = new Point* [height_input];
    for (int i=0; i<height_input; i++) {
        bricks[i] = new Point [width_input] ;
    }
    countEnemy=countEnemyIn;
    countItem=countItemIn;
}

Field::Field(const Field &poleForCopy) // копирование
{
    width=poleForCopy.width;
    height=poleForCopy.height;
    bricks = new Point* [height];
    playerReminder = poleForCopy.playerReminder;
    for (int i=0; i<height; i++) {
        bricks[i] = new Point [width] ;
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            bricks[i][j]=poleForCopy.bricks[i][j];
        }
    }
}

Field::Field(Field &&poleForMoving) // перемещение
{
    std::swap(height, poleForMoving.height);
    std::swap(width, poleForMoving.width);
    std::swap(bricks, poleForMoving.bricks);
    std::swap(playerReminder, poleForMoving.playerReminder);
}

Field Field::operator = (const Field &poleForCopy) // копирование оператор
{
    if (this != &poleForCopy) {
        for (int i=0; i<height; i++) {
             delete[] bricks[i];
        }
        delete[] bricks;
        width=poleForCopy.width;
        height=poleForCopy.height;
        bricks = new Point* [height];
        playerReminder = poleForCopy.playerReminder;
        for (int i=0; i<height; i++) {
            bricks[i] = new Point [width] ;
        }
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                bricks[i][j]=poleForCopy.bricks[i][j];
            }
        }
    }
    return *this;
}

Field Field::operator = (Field &&poleForMoving) // перемещение оператор
{
    if (this != &poleForMoving) {
        std::swap(height, poleForMoving.height);
        std::swap(width, poleForMoving.width);
        std::swap(bricks, poleForMoving.bricks);
        std::swap(playerReminder, poleForMoving.playerReminder);
    }
    return *this;
}


Point* Field::GetBrick(int height, int widht) {
    return &bricks[height][widht];
}


Point* Field::FindExit() {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (bricks[i][j].GetCondition()==3) {
                return &bricks[i][j];
            }
        }
    }
    return nullptr;
}


int Field::GetWidth() {
    return width;
}
int Field::GetHeight() {
    return height;
}

int Field::GetCountEnemy()
{
    return countEnemy;
}

int Field::GetCountItem()
{
    return countItem;
}

void Field::SetCountEnemy(int num)
{
    countEnemy=num;
}

void Field::SetCountItem(int num)
{
    countItem=num;
}

void Field::SetHeight(int num)
{
    height=num;
}

void Field::SetWidth(int num)
{
    width=num;
}

InterfaceForPoint* Field::Find (NameOfObjects name) {
    for (int i=1; i<height-1; i++) {
        for (int j=1; j<width-1; j++) {
            if ((bricks[i][j].IsInVector(name)!=-1) && (bricks[i][j].GetObj(name)->GetCheck()==0)) {
                if (name != hero) bricks[i][j].GetObj(name)->SetCheck(1);
                return bricks[i][j].GetObj(name);
            }
        }
    }
    return nullptr;
}


Field::~Field() {
    for (int i=0; i<height; i++) {
         delete[] bricks[i];
    }
    delete[] bricks;
}
