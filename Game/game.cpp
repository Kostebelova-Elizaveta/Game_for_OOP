#include "Game/game.h"
#include <iostream>
template <typename T>
Game<T>::Game(QGraphicsScene* sceneIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI)
{
    scene=sceneIn;
    labelHealth=labelH;
    labelAtack=labelA;
    labelCountEnemy=labelCE;
    labelCountItem=labelCI;
}

template <typename T>
void Game<T>::Start() {
    builder = new LevelBuilder();
    rules = new T;
    loader = new Loader();
    builder->SetField(rules->GetW(), rules->GetH(), rules->GetEnemy(), rules->GetItem(), rules->GetCountEnemy(), rules->GetCountItem());
    painter = new LevelPainter(builder->GetField(), labelHealth, labelAtack, labelCountEnemy, labelCountItem);
    painter->Draw(scene);
    interacter = new Interacter(builder->GetField());
    loggerConsole = new LoggerConsole(0);
    loggerFile = new LoggerFile(1, "loggs.txt");
    mover = new Mover(builder->GetField(), builder, painter, interacter, loggerFile, loggerConsole, scene);
    moverHero = new MoverHero(builder->GetField(), builder->GetField()->Find(hero), mover);
    saver = new Saver();
    reader = new Reader(moverHero, painter, scene, saver, loader, builder, mover, interacter, loggerFile, loggerConsole, labelHealth, labelAtack, labelCountEnemy, labelCountItem);



}


template <typename T>
Game<T>::~Game() {

}

template<typename T>
Reader *Game<T>::GetReader()
{
    return reader;

}
