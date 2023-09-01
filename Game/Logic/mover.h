#ifndef MOVER_H
#define MOVER_H
#include "Game/Field/field.h"
#include "Game/Interfaces/interfaceforpoint.h"
#include "Game/Logic/interacter.h"
#include "Game/Paint/levelpainter.h"
#include "Game/Logic/levelbuilder.h"
#include "Game/loggerconsole.h"
#include "Game/loggerfile.h"
#include <QTimer>

class Mover : public QObject
{
    Q_OBJECT
private:
    Field* field;
    int approvementForTroll, approvementForBeagle, approvementForSkeleton;
    QGraphicsScene* scene;
    LevelBuilder* builder;
    LevelPainter* painter;
    Interacter* interacter;
    LoggerFile* loggerFile;
    LoggerConsole* loggerConsole;
    InterfaceForPoint* player;
    std::vector<InterfaceForPoint*> vecOfTrolls;
    std::vector<InterfaceForPoint*> vecOfBeagles;
    std::vector<InterfaceForPoint*> vecOfSkeletons;
    std::vector<InterfaceForPoint*> vecOfPotions;
    std::vector<InterfaceForPoint*> vecOfBoots;
    std::vector<InterfaceForPoint*> vecOfSwords;
public:
    void FillVector(std::vector<InterfaceForPoint*> &vec, NameOfObjects name);
    Mover(Field* fieldIn, LevelBuilder* builderIn, LevelPainter* painterIn, Interacter* interacterIn, LoggerFile* loggerFileIn, LoggerConsole* loggerConsoleIn, QGraphicsScene* sceneIn);
    ~Mover();
    void MoveTrollUp(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveTrollDown(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveTrollLeft(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveTrollRight(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveBeagleRight(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveBeagleLetf(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveSkeletonUp(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveSkeletonDown(int x, int y, InterfaceForPoint* &enemy, NameOfObjects nameOfObj, int & approvement);
    void MoveTroll();
    void MoveBeagle();
    void MoveSkeleton();
    void FightTroll(int i);
    void FightBeagle(int i);
    void FightSkeleton(int i);
    void PickPotion(int i);
    void PickSword(int i);
    void PickBoots(int i);
    int GetVecSize(NameOfObjects name);
    InterfaceForPoint* GetHero();
    void SetHero(InterfaceForPoint* heroIn);
    Interacter* GetInteracter();
    void SetField(Field* fieldIn);
public slots:
    void OnTimerTroll();
    void OnTimerBeagle();
    void OnTimerSkeleton();
};

#endif // MOVER_H
