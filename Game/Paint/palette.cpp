#include "Game/Paint/palette.h"
#include <QPen>
#include <QColor>
Palette::Palette()
{
    green = QColor::fromRgb (0, 250, 0);
    red = QColor::fromRgb (250, 0, 0);
    blue = QColor::fromRgb (0, 0, 250);
    DarkOrange = QColor::fromRgb (255, 140, 0);
    OrangeRed = QColor::fromRgb (255, 69, 0);
    Fuchsia = QColor::fromRgb (255, 0, 255);
    pencil = QColor::fromRgb(0, 0, 0);
    Khaki = QColor::fromRgb(240, 230, 140);
    QPixmap pixHero("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Hero.png");
    QPixmap pixTroll("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Troll.png");
    QPixmap pixPotion("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Heal.png");
    QPixmap pixBeagle("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Beagle.png");
    QPixmap pixBoots("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Boots.png");
    QPixmap pixSkeleton("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Skeleton.png");
    QPixmap pixSword("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_Sword.png");
    QPixmap pixExit("C:/Users/liza/Desktop/OOP_Lab3/Textures/OOP_exit.png");
    tectureForHero.setTexture(pixHero);
    tectureForTroll.setTexture(pixTroll);
    tectureForPotion.setTexture(pixPotion);
    tectureForBeagle.setTexture(pixBeagle);
    tectureForBoots.setTexture(pixBoots);
    tectureForSkeleton.setTexture(pixSkeleton);
    tectureForSword.setTexture(pixSword);
    tectureForExit.setTexture(pixExit);
}

QBrush Palette::GetColor(Colors name) {
    if (name == RED) {
        return red;
    }
    if (name == BLUE) {
        return blue;
    }
    if (name == GREEN) {
        return green;
    }
    if (name == DARKORANGE) {
        return DarkOrange;
    }
    if (name == ORANGERED) {
        return OrangeRed;
    }
    if (name == FUCHSIA) {
        return Fuchsia;
    }
    if (name == KHAKI) {
        return Khaki;
    }
    return red;
}

QBrush Palette::GetTexture(NameOfObjects name) {
    if (name == troll) {
        return tectureForTroll;
    }
    if (name == skeleton) {
        return tectureForSkeleton;
    }
    if (name == beagle) {
        return tectureForBeagle;
    }
    if (name == potion) {
        return tectureForPotion;
    }
    if (name == boots) {
        return tectureForBoots;
    }
    if (name == sword) {
        return tectureForSword;
    }
    if (name == hero) {
        return tectureForHero;
    }
    return tectureForHero;
}

QBrush Palette::GetTextureExit()
{
    return tectureForExit;
}

QPen Palette::GetPen() {
    return pencil;
}

QBrush Palette::SetYourOwnColor(int r, int g, int b) {
    QBrush color;
    return color = QColor::fromRgb (r, g, b);
}
