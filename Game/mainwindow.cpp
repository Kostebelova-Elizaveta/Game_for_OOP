#include "Game/mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QApplication>
#include <QTimer>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    std::srand(time(0) ^ getpid()); // для отладки rand()
    this->setFixedSize(1500, 800);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);
    QLabel *labelHealth = new QLabel(this);
    QLabel *labelAtack = new QLabel(this);
    QLabel *labelCountEnemy = new QLabel(this);
    QLabel *labelCountItem = new QLabel(this);

    game = new Game<Rules<int>>(scene, labelHealth, labelAtack, labelCountEnemy, labelCountItem);
    game->Start();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    game->GetReader()->ReadButton(e->key());

}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

