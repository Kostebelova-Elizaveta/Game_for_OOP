#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include "Game/Logic/levelbuilder.h"
#include "Game/Paint/levelpainter.h"
#include "Game/Logic/mover.h"
#include "Game/Logic/interacter.h"
#include "Game/Field/field.h"
#include "Game/loggerconsole.h"
#include "Game/loggerfile.h"
#include "Game/Logic/moverhero.h"
#include "Game/reader.h"
#include "Game/saver.h"
#include "Game/loader.h"
#include <QLabel>
#include <QKeyEvent>
template <typename T>
class Game
{
private:
    QGraphicsScene* scene;
    LevelBuilder* builder;
    LevelPainter* painter;
    Interacter* interacter;
    Mover* mover;
    MoverHero* moverHero;
    Reader* reader;
    LoggerFile* loggerFile;
    LoggerConsole* loggerConsole;
    T* rules;
    QLabel *labelHealth;
    QLabel *labelAtack;
    QLabel *labelCountEnemy;
    QLabel *labelCountItem;
    Saver* saver;
    Loader* loader;
public:
    void Start();
    Game(QGraphicsScene* sceneIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI);
    ~Game();
    Reader* GetReader();
};

#endif // GAME_H
