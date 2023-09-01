#include "Game/Logic/interacter.h"

Interacter::~Interacter()
{

}

Interacter::Interacter(Field *fieldIn)
{
    field = fieldIn;
}

void Interacter::InteractFight(InterfaceForPoint* enemy, InterfaceForPoint* player) {
    if ((enemy->GetPositionX()==player->GetPositionX()) && (enemy->GetPositionY()==player->GetPositionY())
            && ((enemy->GetName()==skeleton) || (enemy->GetName()==beagle) || (enemy->GetName()==troll))) {
        player->Fight(enemy);
        if (player->GetHealth()>0) {
            player->SetAlive(1);
            enemy->SetAlive(0);
            field->SetCountEnemy(field->GetCountEnemy()-1);
            if (field->GetCountEnemy()==0) {
                field->FindExit()->SetPassable(1);
            }
        }
        else {
            enemy->SetAlive(1);
             player->SetAlive(0);
        }
    }

}

void Interacter::InteractPick(InterfaceForPoint *item, InterfaceForPoint* player) {
    if ((item->GetPositionX()==player->GetPositionX()) && (item->GetPositionY()==player->GetPositionY())
            && ((item->GetName()==potion) || (item->GetName()==sword) || (item->GetName()==boots))) {
        player->PickItem(item);
        item->SetAlive(0);
        field->SetCountItem(field->GetCountItem()-1);
        if (field->GetCountItem()==0) {
            field->FindExit()->SetPassable(1);
        }
    }
}

void Interacter::InteractExit(Point *exit, InterfaceForPoint* player) {
    if (exit->GetObj(hero)==player) {
        if (exit->GetCondition()==3) {
                qApp->quit();
            }
    }
}

void Interacter::SetField(Field *fieldIn)
{
    field = fieldIn;
}
