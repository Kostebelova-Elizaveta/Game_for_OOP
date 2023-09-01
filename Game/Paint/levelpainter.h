#ifndef LEVELPAINTER_H
#define LEVELPAINTER_H
#include "Game/Paint/painter.h"
#include "Game/Field/field.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class LevelPainter : public Painter
{
private:
   Field* field;
   QLabel *labelHealth;
   QLabel *labelAtack;
   QLabel *labelCountEnemy;
   QLabel *labelCountItem;
   int ex_x, ex_y;
public:
    LevelPainter(Field* fieldIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI);
    ~LevelPainter();
    void SetField(Field* fIn);
    void Draw(QGraphicsScene* scene);
    void ReDrawEnter(QGraphicsScene* scene, int x, int y);
    void ReDrawAfterInteraction(QGraphicsScene* scene, int x, int y, NameOfObjects name);
    void ReDrawTrollUp(QGraphicsScene* scene, int x, int y, int approvement);
    void ReDrawTrollDown(QGraphicsScene* scene, int x, int y, int approvement);
    void ReDrawTrollLeft(QGraphicsScene* scene, int x, int y, int approvement);
    void ReDrawTrollRight(QGraphicsScene* scene, int x, int y, int approvement);

    void ReDrawHeroUp(QGraphicsScene* scene, int x, int y);
    void ReDrawHeroDown(QGraphicsScene* scene, int x, int y);
    void ReDrawHeroLeft(QGraphicsScene* scene, int x, int y);
    void ReDrawHeroRight(QGraphicsScene* scene, int x, int y);

    void ReDrawSkeletonUp(QGraphicsScene* scene, int x, int y, int approvement);
    void ReDrawSkeletonDown(QGraphicsScene* scene, int x, int y, int approvement);

    void ReDrawBeagleLeft(QGraphicsScene* scene, int x, int y, int approvement);
    void ReDrawBeagleRight(QGraphicsScene* scene, int x, int y, int approvement);
};

#endif // LEVELPAINTER_H
