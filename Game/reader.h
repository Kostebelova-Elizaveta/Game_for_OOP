#ifndef READER_H
#define READER_H

#include <conio.h>
#include "Game/KeysName.h"
#include "Game/Logic/moverhero.h"
#include "Game/Paint/levelpainter.h"
#include "Game/saver.h"
#include "Game/loader.h"
#include "Game/Logic/levelbuilder.h"
#include <QLabel>

class Reader {
private:
    MoverHero* m;
    LevelPainter* painter;
    QGraphicsScene* scene;
    Saver* saver;
    Loader* loader;
    LevelBuilder* builder;
    Interacter* interacter;
    Mover* mover;
    LoggerConsole* loggerConsole;
    LoggerFile* loggerFile;
    QLabel *labelHealth;
    QLabel *labelAtack;
    QLabel *labelCountEnemy;
    QLabel *labelCountItem;

public:
    Reader(MoverHero* mIn, LevelPainter* painterIn, QGraphicsScene* sceneIn, Saver* saverIn, Loader* loaderIn, LevelBuilder* builderIn, Mover* moveIn, Interacter* iIn, LoggerFile* loggerFileIn, LoggerConsole* loggerConsoleIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI);
    void ReadButton(int key);
};

#endif // READER_H
