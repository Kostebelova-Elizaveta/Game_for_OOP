#ifndef PALETTE_H
#define PALETTE_H
#include <QPen>
#include <QColor>
#include <string>
#include "Game/Interfaces/interfaceforpoint.h"

enum Colors {GREEN, RED, BLUE, DARKORANGE, ORANGERED, FUCHSIA, KHAKI};

class Palette
{
private:
    QPen pencil; QBrush green;
    QBrush red; QBrush blue;
    QBrush DarkOrange; QBrush OrangeRed;
    QBrush Fuchsia; QBrush Khaki;
    QBrush tectureForHero; QBrush tectureForTroll;
    QBrush tectureForPotion; QBrush tectureForSkeleton;
    QBrush tectureForSword; QBrush tectureForBeagle;
    QBrush tectureForBoots;
    QBrush tectureForExit;
public:
    Palette();
    QBrush GetColor(Colors name);
    QBrush GetTexture(NameOfObjects name);
    QBrush GetTextureExit();
    QPen GetPen();
    QBrush SetYourOwnColor(int r, int g, int b);
};

#endif // PALETTE_H
