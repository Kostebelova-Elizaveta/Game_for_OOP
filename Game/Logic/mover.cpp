#include "Game/Logic/mover.h"

Mover::Mover(Field* fieldIn, LevelBuilder* builderIn, LevelPainter* painterIn, Interacter* interacterIn, LoggerFile* loggerFileIn, LoggerConsole* loggerConsoleIn, QGraphicsScene* sceneIn)
{
    field=fieldIn;
    builder=builderIn;
    painter=painterIn;
    interacter=interacterIn;
    loggerFile=loggerFileIn;
    loggerConsole=loggerConsoleIn;
    scene=sceneIn;
    player = field->Find(hero);
    player->SetCheck(0);
    FillVector(vecOfTrolls, troll);
    FillVector(vecOfBeagles, beagle);
    FillVector(vecOfSkeletons, skeleton);
    FillVector(vecOfBoots, boots);
    FillVector(vecOfPotions, potion);
    FillVector(vecOfSwords, sword);

    QTimer* timerTroll = new QTimer;
    connect(timerTroll, SIGNAL(timeout()), this, SLOT(OnTimerTroll()));
    timerTroll->start(2000);

    QTimer* timerBeagle = new QTimer;
    connect(timerBeagle, SIGNAL(timeout()), this, SLOT(OnTimerBeagle()));
    timerBeagle->start(1000);

    QTimer* timerSkeleton = new QTimer;
    connect(timerSkeleton, SIGNAL(timeout()), this, SLOT(OnTimerSkeleton()));
    timerSkeleton->start(1500);
}


void Mover::MoveTrollUp(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y-1, x)->GetPassable()!=0)
            && (field->GetBrick(y-1, x)->GetCondition()!=3)
            && (field->GetBrick(y-1, x)->GetCondition()!=2)
            && (!field->GetBrick(y-1, x)->IsKindnessInVector())
            && (!field->GetBrick(y-1, x)->IsSkeletonInVector())
            && (!field->GetBrick(y-1, x)->IsBeagleInVector())
            && (!field->GetBrick(y-1, x)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y-1, x)->AddToVector(enemy->GetName());
        field->GetBrick(y-1, x)->GetObj(enemy->GetName())->SetPositionX(x);
        field->GetBrick(y-1, x)->GetObj(enemy->GetName())->SetPositionY(y-1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y-1, x)->GetObj(nameOfObj);
        enemy->SetWay(3);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(4);
    }
}


void Mover::MoveTrollDown(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y+1, x)->GetPassable()!=0)
            && (field->GetBrick(y+1, x)->GetCondition()!=3)
            && (field->GetBrick(y+1, x)->GetCondition()!=2)
            && (!field->GetBrick(y+1, x)->IsKindnessInVector())
            && (!field->GetBrick(y+1, x)->IsSkeletonInVector())
            && (!field->GetBrick(y+1, x)->IsBeagleInVector())
            && (!field->GetBrick(y+1, x)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y+1, x)->AddToVector(enemy->GetName());
        field->GetBrick(y+1, x)->GetObj(enemy->GetName())->SetPositionX(x);
        field->GetBrick(y+1, x)->GetObj(enemy->GetName())->SetPositionY(y+1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y+1, x)->GetObj(nameOfObj);
        enemy->SetWay(1);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(2);
    }
}
void Mover::MoveTrollLeft(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y, x-1)->GetPassable()!=0)
            && (field->GetBrick(y, x-1)->GetCondition()!=3)
            && (field->GetBrick(y, x-1)->GetCondition()!=2)
            && (!field->GetBrick(y, x-1)->IsKindnessInVector())
            && (!field->GetBrick(y, x-1)->IsSkeletonInVector())
            && (!field->GetBrick(y, x-1)->IsBeagleInVector())
            && (!field->GetBrick(y, x-1)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y, x-1)->AddToVector(enemy->GetName());
        field->GetBrick(y, x-1)->GetObj(enemy->GetName())->SetPositionX(x-1);
        field->GetBrick(y, x-1)->GetObj(enemy->GetName())->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y, x-1)->GetObj(nameOfObj);
        enemy->SetWay(4);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(1);
    }
}
void Mover::MoveTrollRight(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y, x+1)->GetPassable()!=0)
            && (field->GetBrick(y, x+1)->GetCondition()!=3)
            && (field->GetBrick(y, x+1)->GetCondition()!=2)
            && (!field->GetBrick(y, x+1)->IsKindnessInVector())
            && (!field->GetBrick(y, x+1)->IsSkeletonInVector())
            && (!field->GetBrick(y, x+1)->IsBeagleInVector())
            && (!field->GetBrick(y, x+1)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y, x+1)->AddToVector(enemy->GetName());
        field->GetBrick(y, x+1)->GetObj(enemy->GetName())->SetPositionX(x+1);
        field->GetBrick(y, x+1)->GetObj(enemy->GetName())->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y, x+1)->GetObj(nameOfObj);
        enemy->SetWay(2);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(3);
    }
}


void Mover::MoveBeagleRight(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y, x+1)->GetPassable()!=0)
            && (field->GetBrick(y, x+1)->GetCondition()!=3)
            && (field->GetBrick(y, x+1)->GetCondition()!=2)
            && (!field->GetBrick(y, x+1)->IsKindnessInVector())
            && (!field->GetBrick(y, x+1)->IsSkeletonInVector())
            && (!field->GetBrick(y, x+1)->IsBeagleInVector())
            && (!field->GetBrick(y, x+1)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y, x+1)->AddToVector(enemy->GetName());
        field->GetBrick(y, x+1)->GetObj(enemy->GetName())->SetPositionX(x+1);
        field->GetBrick(y, x+1)->GetObj(enemy->GetName())->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y, x+1)->GetObj(nameOfObj);
        enemy->SetWay(1);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(2);
    }
}

void Mover::MoveBeagleLetf(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y, x-1)->GetPassable()!=0)
            && (field->GetBrick(y, x-1)->GetCondition()!=3)
            && (field->GetBrick(y, x-1)->GetCondition()!=2)
            && (!field->GetBrick(y, x-1)->IsKindnessInVector())
            && (!field->GetBrick(y, x-1)->IsSkeletonInVector())
            && (!field->GetBrick(y, x-1)->IsBeagleInVector())
            && (!field->GetBrick(y, x-1)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y, x-1)->AddToVector(enemy->GetName());
        field->GetBrick(y, x-1)->GetObj(enemy->GetName())->SetPositionX(x-1);
        field->GetBrick(y, x-1)->GetObj(enemy->GetName())->SetPositionY(y);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y, x-1)->GetObj(nameOfObj);
        enemy->SetWay(2);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(1);
    }
}


void Mover::MoveSkeletonUp(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y-1, x)->GetPassable()!=0)
            && (field->GetBrick(y-1, x)->GetCondition()!=3)
            && (field->GetBrick(y-1, x)->GetCondition()!=2)
            && (!field->GetBrick(y-1, x)->IsKindnessInVector())
            && (!field->GetBrick(y-1, x)->IsSkeletonInVector())
            && (!field->GetBrick(y-1, x)->IsBeagleInVector())
            && (!field->GetBrick(y-1, x)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y-1, x)->AddToVector(enemy->GetName());
        field->GetBrick(y-1, x)->GetObj(enemy->GetName())->SetPositionX(x);
        field->GetBrick(y-1, x)->GetObj(enemy->GetName())->SetPositionY(y-1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y-1, x)->GetObj(nameOfObj);
        enemy->SetWay(2);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(1);
    }
}

void Mover::MoveSkeletonDown(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement) {
    if ((field->GetBrick(y+1, x)->GetPassable()!=0)
            && (field->GetBrick(y+1, x)->GetCondition()!=3)
            && (field->GetBrick(y+1, x)->GetCondition()!=2)
            && (!field->GetBrick(y+1, x)->IsKindnessInVector())
            && (!field->GetBrick(y+1, x)->IsSkeletonInVector())
            && (!field->GetBrick(y+1, x)->IsBeagleInVector())
            && (!field->GetBrick(y+1, x)->IsTrollInVector())
            && (enemy->GetName()==nameOfObj) && (enemy!=nullptr)) {
        field->GetBrick(y+1, x)->AddToVector(enemy->GetName());
        field->GetBrick(y+1, x)->GetObj(enemy->GetName())->SetPositionX(x);
        field->GetBrick(y+1, x)->GetObj(enemy->GetName())->SetPositionY(y+1);
        field->GetBrick(y, x)->DelObjFromVector(field->GetBrick(y, x)->IsInVector(enemy->GetName()));
        enemy = field->GetBrick(y+1, x)->GetObj(nameOfObj);
        enemy->SetWay(1);
        approvement=1;
    }
    else {
        approvement=0;
        enemy->SetWay(2);
    }
}


void Mover::MoveTroll() {
    for (unsigned i=0; i<vecOfTrolls.size(); i++) {

        if ((vecOfTrolls[i]->GetWay()==1) && (vecOfTrolls[i]!=nullptr) && (vecOfTrolls[i]->GetAlive()==1)) {
            MoveTrollDown(vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i], troll, approvementForTroll);
            painter->ReDrawTrollDown(scene, vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY()-1, approvementForTroll);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfTrolls[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfTrolls[i]);
            FightTroll(i);
        }

        if ((vecOfTrolls[i]->GetWay()==2) && (vecOfTrolls[i]!=nullptr) && (vecOfTrolls[i]->GetAlive()==1)) {
            MoveTrollRight(vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i], troll, approvementForTroll);
            painter->ReDrawTrollRight(scene, vecOfTrolls[i]->GetPositionX()-1, vecOfTrolls[i]->GetPositionY(), approvementForTroll);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfTrolls[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfTrolls[i]);
            FightTroll(i);
        }

        if ((vecOfTrolls[i]->GetWay()==3) && (vecOfTrolls[i]!=nullptr) && (vecOfTrolls[i]->GetAlive()==1)) {
            MoveTrollUp(vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i], troll, approvementForTroll);
            painter->ReDrawTrollUp(scene, vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY()+1, approvementForTroll);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfTrolls[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfTrolls[i]);
            FightTroll(i);
        }

        if ((vecOfTrolls[i]->GetWay()==4) && (vecOfTrolls[i]!=nullptr) && (vecOfTrolls[i]->GetAlive()==1)) {
            MoveTrollLeft(vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i], troll, approvementForTroll);
            painter->ReDrawTrollLeft(scene, vecOfTrolls[i]->GetPositionX()+1, vecOfTrolls[i]->GetPositionY(), approvementForTroll);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfTrolls[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfTrolls[i]);
            FightTroll(i);
        }
    }
}

void Mover::MoveBeagle() {
    for (unsigned i=0; i<vecOfBeagles.size(); i++) {
        if (vecOfBeagles[i]->GetWay()==1) {
            MoveBeagleRight(vecOfBeagles[i]->GetPositionX(), vecOfBeagles[i]->GetPositionY(), vecOfBeagles[i], beagle, approvementForBeagle);
            painter->ReDrawBeagleRight(scene, vecOfBeagles[i]->GetPositionX()-1, vecOfBeagles[i]->GetPositionY(), approvementForBeagle);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfBeagles[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfBeagles[i]);
            FightBeagle(i);
        }
        if (vecOfBeagles[i]->GetWay()==2) {
            MoveBeagleLetf(vecOfBeagles[i]->GetPositionX(), vecOfBeagles[i]->GetPositionY(), vecOfBeagles[i], beagle, approvementForBeagle);
            painter->ReDrawBeagleLeft(scene, vecOfBeagles[i]->GetPositionX()+1, vecOfBeagles[i]->GetPositionY(), approvementForBeagle);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfBeagles[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfBeagles[i]);
            FightBeagle(i);

        }
    }
}


void Mover::MoveSkeleton() {
    for (unsigned i=0; i<vecOfSkeletons.size(); i++) {
        if (vecOfSkeletons[i]->GetWay()==1) {
            MoveSkeletonDown(vecOfSkeletons[i]->GetPositionX(), vecOfSkeletons[i]->GetPositionY(), vecOfSkeletons[i], skeleton, approvementForSkeleton);
            painter->ReDrawSkeletonDown(scene, vecOfSkeletons[i]->GetPositionX(), vecOfSkeletons[i]->GetPositionY()-1, approvementForSkeleton);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfSkeletons[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfSkeletons[i]);
            FightSkeleton(i);
        }
        if (vecOfSkeletons[i]->GetWay()==2) {
            MoveSkeletonUp(vecOfSkeletons[i]->GetPositionX(), vecOfSkeletons[i]->GetPositionY(), vecOfSkeletons[i], skeleton, approvementForSkeleton);
            painter->ReDrawSkeletonUp(scene, vecOfSkeletons[i]->GetPositionX(), vecOfSkeletons[i]->GetPositionY()+1, approvementForSkeleton);
            if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfSkeletons[i]);
            if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfSkeletons[i]);
            FightSkeleton(i);
        }
    }
}

void Mover::OnTimerTroll() {
    MoveTroll();
}

void Mover::OnTimerBeagle() {
    MoveBeagle();
}

void Mover::OnTimerSkeleton() {
    MoveSkeleton();
}


void Mover::FightTroll(int i) {
    interacter->InteractFight(vecOfTrolls[i], player);
    if (vecOfTrolls[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfTrolls[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfTrolls[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfTrolls[i]->GetPositionY(), vecOfTrolls[i]->GetPositionX())->IsInVector(troll));
        vecOfTrolls.erase(vecOfTrolls.begin()+i);
    }
    if (player->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, vecOfTrolls[i]->GetPositionX(), vecOfTrolls[i]->GetPositionY(), troll);
        builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->DelObjFromVector(builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->IsInVector(hero));
        qApp->quit();
    }
}

void Mover::FightBeagle(int i) {
    interacter->InteractFight(vecOfBeagles[i], player);
    if (vecOfBeagles[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfBeagles[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfBeagles[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfBeagles[i]->GetPositionY(), vecOfBeagles[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfBeagles[i]->GetPositionY(), vecOfBeagles[i]->GetPositionX())->IsInVector(beagle));
        vecOfBeagles.erase(vecOfBeagles.begin()+i);
    }
    if (player->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, vecOfBeagles[i]->GetPositionX(), vecOfBeagles[i]->GetPositionY(), beagle);
        builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->DelObjFromVector(builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->IsInVector(hero));
        qApp->quit();
    }
}

void Mover::FightSkeleton(int i) {
    interacter->InteractFight(vecOfSkeletons[i], player);
    if (vecOfSkeletons[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfSkeletons[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfSkeletons[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfSkeletons[i]->GetPositionY(), vecOfSkeletons[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfSkeletons[i]->GetPositionY(), vecOfSkeletons[i]->GetPositionX())->IsInVector(skeleton));
        vecOfSkeletons.erase(vecOfSkeletons.begin()+i);
    }
    if (player->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, vecOfSkeletons[i]->GetPositionX(), vecOfSkeletons[i]->GetPositionY(), skeleton);
        builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->DelObjFromVector(builder->GetField()->GetBrick(player->GetPositionY(), player->GetPositionY())->IsInVector(hero));
        qApp->quit();
    }
}

void Mover::FillVector(std::vector<InterfaceForPoint *> &vec, NameOfObjects name) {
    InterfaceForPoint* obj = builder->GetField()->Find(name);
    while (obj!=nullptr) {
        if ((vec.empty()) || !(builder->IsInVectorObj(obj, vec))) {
            vec.push_back(obj);
        }
        obj = builder->GetField()->Find(name);
    }
}


void Mover::PickPotion(int i) {
    interacter->InteractPick(vecOfPotions[i], player);
    if (vecOfPotions[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfPotions[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfPotions[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfPotions[i]->GetPositionY(), vecOfPotions[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfPotions[i]->GetPositionY(), vecOfPotions[i]->GetPositionX())->IsInVector(potion));
        vecOfPotions.erase(vecOfPotions.begin()+i);
    }
}

void Mover::PickSword(int i) {
    interacter->InteractPick(vecOfSwords[i], player);
    if (vecOfSwords[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfSwords[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfSwords[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfSwords[i]->GetPositionY(), vecOfSwords[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfSwords[i]->GetPositionY(), vecOfSwords[i]->GetPositionX())->IsInVector(sword));
        vecOfSwords.erase(vecOfSwords.begin()+i);
    }
}

void Mover::PickBoots(int i) {
    interacter->InteractPick(vecOfBoots[i], player);
    if (vecOfBoots[i]->GetAlive()==0) {
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(vecOfBoots[i]);
        if (loggerConsole->GetUsable()) loggerConsole->WriteDown(player);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(vecOfBoots[i]);
        if (loggerFile->GetUsable()) loggerFile->WriteDown(player);
        painter->ReDrawAfterInteraction(scene, player->GetPositionX(), player->GetPositionY(), hero);
        builder->GetField()->GetBrick(vecOfBoots[i]->GetPositionY(), vecOfBoots[i]->GetPositionX())->DelObjFromVector(builder->GetField()->GetBrick(vecOfBoots[i]->GetPositionY(), vecOfBoots[i]->GetPositionX())->IsInVector(boots));
        vecOfBoots.erase(vecOfBoots.begin()+i);
    }
}

int Mover::GetVecSize(NameOfObjects name)
{
    if (name == troll) {
        return vecOfTrolls.size();
    }
    if (name == beagle) {
        return vecOfBeagles.size();
    }
    if (name == skeleton) {
        return vecOfSkeletons.size();
    }
    if (name == potion) {
        return vecOfPotions.size();
    }
    if (name == sword) {
        return vecOfSwords.size();
    }
    if (name == boots) {
        return vecOfBoots.size();
    }
    return 0;
}

InterfaceForPoint *Mover::GetHero()
{
    return player;
}

void Mover::SetHero(InterfaceForPoint *heroIn)
{
    player = heroIn;
}

Interacter *Mover::GetInteracter()
{
    return interacter;
}

void Mover::SetField(Field *fieldIn)
{
    field = fieldIn;
}

Mover::~Mover() {

}
