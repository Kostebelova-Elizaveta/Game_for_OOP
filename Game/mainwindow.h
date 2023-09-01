#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QGraphicsTextItem>
#include <QLabel>
#include "Game/Logic/levelbuilder.h"
#include "Game/Paint/levelpainter.h"
#include "Game/Logic/mover.h"
#include "Game/game.h"
#include "rules.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Game<Rules<int>>* game;
protected:
    void keyPressEvent(QKeyEvent* e);
};
#include "Game/game.cpp"
#include "rules.cpp"
#endif // MAINWINDOW_H
