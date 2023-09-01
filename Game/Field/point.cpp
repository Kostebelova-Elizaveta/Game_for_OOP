#include "Game/Field/point.h"
#include "Game/Hero/hero.h"
#include <vector>

Point::Point()
{
    passable=0;
    condition=0;
}

Point::~Point()
{
    ClearVector();
}

Point Point::operator = (const Point &brickForCopy) { // копирование
    this->passable=brickForCopy.passable;
    this->condition=brickForCopy.condition;
    for (unsigned i=0; i<brickForCopy.elements.size(); i++) {
        this->elements[i]=brickForCopy.elements[i];
    }
    return *this;
}


int Point::GetPassable() {
    return passable;
}

void Point::SetPassable(int num) {
    passable=num;
}

int Point::GetCondition() {
    return condition;
}

void Point::SetCondition(int num) {
    condition=num;
}

std::vector<InterfaceForPoint*> Point::GetVector() {
    return elements;
}

void Point::AddObjToVector(InterfaceForPoint* smtf) {
    elements.push_back(smtf);
}

bool Point::IsSmtfInVector() {
    if (elements.empty()) {
        return 0;
    }
    else {
        return 1;
    }
}

bool Point::IsKindnessInVector() {
    for (unsigned i=0; i<elements.size(); i++) {
        if ((elements[i]->GetName()==potion)
                || (elements[i]->GetName()==boots)
                || (elements[i]->GetName()==sword)) {
            return 1;
            break;
        }
    }
    return 0;
}

bool Point::IsTrollInVector() {
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==troll) {
            return 1;
            break;
        }
    }
    return 0;
}
bool Point::IsSkeletonInVector() {
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==skeleton) {
            return 1;
            break;
        }
    }
    return 0;
}

bool Point::IsEnemyInVector()
{
    for (unsigned i=0; i<elements.size(); i++) {
        if ((elements[i]->GetName()==skeleton) || (elements[i]->GetName()==troll) || (elements[i]->GetName()==beagle)) {
            return 1;
            break;
        }
    }
    return 0;
}

bool Point::IsSwordInVector()
{
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==sword) {
            return 1;
            break;
        }
    }
    return 0;
}

bool Point::IsPotionInVector()
{
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==potion) {
            return 1;
            break;
        }
    }
    return 0;
}

bool Point::IsBootsInVector()
{
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==boots) {
            return 1;
            break;
        }
    }
    return 0;
}

void Point::ClearVector()
{
    for (unsigned i=0; i<elements.size(); i++) {
        delete elements[i];
    }
    elements.clear();
}

void Point::DelObjFromMemory(InterfaceForPoint* smtf)
{
    delete smtf;
}
bool Point::IsBeagleInVector() {
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==beagle) {
            return 1;
            break;
        }
    }
    return 0;
}

void Point::AddToVector(NameOfObjects nameOfObj) {
    if (nameOfObj == troll) {
        Troll* enemy_troll = new Troll();
        elements.push_back(enemy_troll);
     }
    if (nameOfObj == hero) {
        Hero* new_hero = new Hero();
        elements.push_back(new_hero);
     }
    if (nameOfObj == beagle) {
        Beagle* enemy_Beagle = new Beagle();
        elements.push_back(enemy_Beagle);
    }
    if (nameOfObj == skeleton) {
        Skeleton* enemy_Skeleton = new Skeleton();
        elements.push_back(enemy_Skeleton);
    }
    if (nameOfObj == potion) {
        HealingPotion* item_HealingPotion = new HealingPotion();
        elements.push_back(item_HealingPotion);
    }
    if (nameOfObj == boots) {
        Boots* item_Boots = new Boots();
        elements.push_back(item_Boots);
    }
    if (nameOfObj == sword) {
        Sword* item_Sword = new Sword();
        elements.push_back(item_Sword);
    }
}

void Point::AddHero(InterfaceForPoint* smtf) {
    if (smtf->GetName()==hero) {
        elements.push_back(smtf);
    }
}

int Point::IsInVector(NameOfObjects nameOfObj) {
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]!=0) {
            if (elements[i]->GetName()==nameOfObj) {
                return i;
            }
        }
    }
    return -1;
}

void Point::DelObjFromVector(int pos) {
    if (pos!=-1) {
        elements.erase(elements.begin() + pos);
    }
}

InterfaceForPoint* Point::GetObj(NameOfObjects nameOfObj) {
    for (unsigned i=0; i<elements.size(); i++) {
        if (elements[i]->GetName()==nameOfObj) {
            return elements[i];
        }
    }
    return nullptr;
}



