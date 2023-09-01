#ifndef PAINTER_H
#define PAINTER_H
#include <QGraphicsScene>
#include <QLabel>
class Painter
{
public:
    virtual ~Painter();
    virtual void Draw(QGraphicsScene* scene) = 0;
};

#endif // PAINTER_H
