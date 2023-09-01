#include "moverhero.h"

MoverHero::MoverHero(Field* fieldIn, InterfaceForPoint* playerIn, Mover* moverIn)
{
    field = fieldIn;
    player = playerIn;
    player->SetCheck(0);
    mover = moverIn;
}

void MoverHero::MoveHeroUp()
{
    int x = player->GetPositionX();
    int y = player->GetPositionY();
    int h = player->GetHealth();
    int a = player->GetAtack();

    if ((field->GetBrick(y-1, x)->GetPassable()!=0) && (player!=nullptr)) {

        field->GetBrick(y-1, x)->AddToVector(hero);
        field->GetBrick(y-1, x)->GetObj(hero)->SetPositionX(x);
        field->GetBrick(y-1, x)->GetObj(hero)->SetPositionY(y-1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(hero));
        player = field->GetBrick(y-1, x)->GetObj(hero);
        player->SetHealth(h);
        player->SetAtack(a);
        x = player->GetPositionX();
        y = player->GetPositionY();
        mover->SetHero(player);

        if (field->GetBrick(y, x)->IsTrollInVector()) {
            for (int i=0; i<mover->GetVecSize(troll); i++) {
                mover->FightTroll(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSkeletonInVector()) {
            for (int i=0; i<mover->GetVecSize(skeleton); i++) {
                mover->FightSkeleton(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBeagleInVector()) {
            for (int i=0; i<mover->GetVecSize(beagle); i++) {
                mover->FightBeagle(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSwordInVector()) {
            for (int i=0; i<mover->GetVecSize(sword); i++) {
                mover->PickSword(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBootsInVector()) {
            for (int i=0; i<mover->GetVecSize(boots); i++) {
                mover->PickBoots(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsPotionInVector()) {
            for (int i=0; i<mover->GetVecSize(potion); i++) {
                mover->PickPotion(i);
                player = mover->GetHero();
            }
        }

        if ((field->GetBrick(y, x)->GetCondition()==3) && (field->GetBrick(y, x)->GetPassable()==1)) {
            mover->GetInteracter()->InteractExit(field->GetBrick(y, x), player);
        }
    }
}

void MoverHero::MoveHeroDown()
{
    int x = player->GetPositionX();
    int y = player->GetPositionY();
    int h = player->GetHealth();
    int a = player->GetAtack();
    if (field->GetBrick(y+1, x)->GetPassable()!=0) {

        field->GetBrick(y+1, x)->AddToVector(hero);
        field->GetBrick(y+1, x)->GetObj(hero)->SetPositionX(x);
        field->GetBrick(y+1, x)->GetObj(hero)->SetPositionY(y+1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(hero));
        player = field->GetBrick(y+1, x)->GetObj(hero);
        player->SetHealth(h);
        player->SetAtack(a);
        x = player->GetPositionX();
        y = player->GetPositionY();
        mover->SetHero(player);

        if (field->GetBrick(y, x)->IsTrollInVector()) {
            for (int i=0; i<mover->GetVecSize(troll); i++) {
                mover->FightTroll(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSkeletonInVector()) {
            for (int i=0; i<mover->GetVecSize(skeleton); i++) {
                mover->FightSkeleton(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBeagleInVector()) {
            for (int i=0; i<mover->GetVecSize(beagle); i++) {
                mover->FightBeagle(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSwordInVector()) {
            for (int i=0; i<mover->GetVecSize(sword); i++) {
                mover->PickSword(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBootsInVector()) {
            for (int i=0; i<mover->GetVecSize(boots); i++) {
                mover->PickBoots(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsPotionInVector()) {
            for (int i=0; i<mover->GetVecSize(potion); i++) {
                mover->PickPotion(i);
                player = mover->GetHero();
            }
        }

        if ((field->GetBrick(y, x)->GetCondition()==3) && (field->GetBrick(y, x)->GetPassable()==1)) {
            mover->GetInteracter()->InteractExit(field->GetBrick(y, x), player);
        }
    }
}

void MoverHero::MoveHeroRight()
{
    int x = player->GetPositionX();
    int y = player->GetPositionY();
    int h = player->GetHealth();
    int a = player->GetAtack();
    if (field->GetBrick(y, x+1)->GetPassable()!=0) {

        field->GetBrick(y, x+1)->AddToVector(hero);
        field->GetBrick(y, x+1)->GetObj(hero)->SetPositionX(x+1);
        field->GetBrick(y, x+1)->GetObj(hero)->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(hero));
        player = field->GetBrick(y, x+1)->GetObj(hero);
        player->SetHealth(h);
        player->SetAtack(a);
        x = player->GetPositionX();
        y = player->GetPositionY();
        mover->SetHero(player);

        if (field->GetBrick(y, x)->IsTrollInVector()) {
            for (int i=0; i<mover->GetVecSize(troll); i++) {
                mover->FightTroll(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSkeletonInVector()) {
            for (int i=0; i<mover->GetVecSize(skeleton); i++) {
                mover->FightSkeleton(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBeagleInVector()) {
            for (int i=0; i<mover->GetVecSize(beagle); i++) {
                mover->FightBeagle(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSwordInVector()) {
            for (int i=0; i<mover->GetVecSize(sword); i++) {
                mover->PickSword(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBootsInVector()) {
            for (int i=0; i<mover->GetVecSize(boots); i++) {
                mover->PickBoots(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsPotionInVector()) {
            for (int i=0; i<mover->GetVecSize(potion); i++) {
                mover->PickPotion(i);
                player = mover->GetHero();
            }
        }

        if ((field->GetBrick(y, x)->GetCondition()==3) && (field->GetBrick(y, x)->GetPassable()==1)) {
            mover->GetInteracter()->InteractExit(field->GetBrick(y, x), player);
        }
    }
}

InterfaceForPoint *MoverHero::GetHero()
{
    return player;
}

Field *MoverHero::GetField()
{
    return field;
}

void MoverHero::SetField(Field *fieldIn)
{
    field = fieldIn;
}

void MoverHero::MoveHeroLeft()
{
    int x = player->GetPositionX();
    int y = player->GetPositionY();
    int h = player->GetHealth();
    int a = player->GetAtack();
    if (field->GetBrick(y, x-1)->GetPassable()!=0) {

        field->GetBrick(y, x-1)->AddToVector(hero);
        field->GetBrick(y, x-1)->GetObj(hero)->SetPositionX(x-1);
        field->GetBrick(y, x-1)->GetObj(hero)->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(hero));
        player = field->GetBrick(y, x-1)->GetObj(hero);
        player->SetHealth(h);
        player->SetAtack(a);
        x = player->GetPositionX();
        y = player->GetPositionY();
        mover->SetHero(player);

        if (field->GetBrick(y, x)->IsTrollInVector()) {
            for (int i=0; i<mover->GetVecSize(troll); i++) {
                mover->FightTroll(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSkeletonInVector()) {
            for (int i=0; i<mover->GetVecSize(skeleton); i++) {
                mover->FightSkeleton(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBeagleInVector()) {
            for (int i=0; i<mover->GetVecSize(beagle); i++) {
                mover->FightBeagle(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsSwordInVector()) {
            for (int i=0; i<mover->GetVecSize(sword); i++) {
                mover->PickSword(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsBootsInVector()) {
            for (int i=0; i<mover->GetVecSize(boots); i++) {
                mover->PickBoots(i);
                player = mover->GetHero();
            }
        }

        if (field->GetBrick(y, x)->IsPotionInVector()) {
            for (int i=0; i<mover->GetVecSize(potion); i++) {
                mover->PickPotion(i);
                player = mover->GetHero();
            }
        }

        if ((field->GetBrick(y, x)->GetCondition()==3) && (field->GetBrick(y, x)->GetPassable()==1)) {
            mover->GetInteracter()->InteractExit(field->GetBrick(y, x), player);
        }
    }
}
