#include "Game/Paint/levelpainter.h"
LevelPainter::LevelPainter(Field* fieldIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI)
{
    field=fieldIn;
    labelHealth=labelH;
    labelAtack=labelA;
    labelCountEnemy=labelCE;
    labelCountItem=labelCI;
}

void LevelPainter::Draw(QGraphicsScene* scene) {
    Palette Colors;

    for (int i=0; i<field->GetHeight(); i++) {
        for (int j=0; j<field->GetWidth(); j++) {

               switch (field->GetBrick(i,j)->GetCondition()) {
                case 0:
                   scene->addRect(j*25, i*25, 10, 10, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   scene->addRect(j*25+10, i*25, 15, 10, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   scene->addRect(j*25, i*25+10, 15, 10, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   scene->addRect(j*25+15, i*25+10, 10, 10, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   scene->addRect(j*25, i*25+20, 10, 5, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   scene->addRect(j*25+10, i*25+20, 15, 5, Colors.GetPen(), Colors.GetColor(ORANGERED));
                   break;
                case 1:
                   scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
                   break;
                case 2:
                   scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetColor(BLUE));
                   break;
                case 3:
                   ex_x=j; ex_y=i;
                   if ((field->GetCountEnemy()<=0) || (field->GetCountItem()<=0)) {
                       scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetColor(FUCHSIA));
                   }
                   else {
                       scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTextureExit());
                   }

                   break;
                default:
                    scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
                }
        }
    }

    for (int i=0; i<field->GetHeight(); i++) {
        for (int j=0; j<field->GetWidth(); j++) {
            if (field->GetBrick(i, j)->IsInVector(hero)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
                string strH = to_string(field->GetBrick(i, j)->GetObj(hero)->GetHealth());
                string strT = "Player Health: ";
                strH = strT + strH;
                QString s = QString::fromStdString(strH);
                labelHealth->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                labelHealth->setText(s);
                labelHealth->setAlignment(Qt::AlignBottom | Qt::AlignRight);
                labelHealth->setGeometry(5, 1, 105, 35);

                string strA = to_string(field->GetBrick(i, j)->GetObj(hero)->GetAtack());
                string strTx = "Player Atack: ";
                strA = strTx + strA;
                QString st = QString::fromStdString(strA);
                labelAtack->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                labelAtack->setText(st);
                labelAtack->setAlignment(Qt::AlignBottom | Qt::AlignRight);
                labelAtack->setGeometry(5, 1, 90, 35*2);

                string strCE = to_string(field->GetCountEnemy());
                string strTxe = "Enemies remained: ";
                strCE= strTxe + strCE;
                QString str = QString::fromStdString(strCE);
                labelCountEnemy->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                labelCountEnemy->setText(str);
                labelCountEnemy->setAlignment(Qt::AlignBottom | Qt::AlignRight);
                labelCountEnemy->setGeometry(5, 1, 115, 35*3);

                string strCI = to_string(field->GetCountItem());
                string strTxi = "Items remained: ";
                strCI = strTxi + strCI;
                QString stra = QString::fromStdString(strCI);
                labelCountItem->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                labelCountItem->setText(stra);
                labelCountItem->setAlignment(Qt::AlignBottom | Qt::AlignRight);
                labelCountItem->setGeometry(5, 1, 100, 35*4);

            }
            if (field->GetBrick(i, j)->IsInVector(potion)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(potion));
            }
            if (field->GetBrick(i, j)->IsInVector(boots)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(boots));
            }
            if (field->GetBrick(i, j)->IsInVector(sword)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(sword));
            }
            if (field->GetBrick(i, j)->IsInVector(troll)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
            }

            if (field->GetBrick(i, j)->IsInVector(beagle)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(beagle));
            }

            if (field->GetBrick(i, j)->IsInVector(skeleton)!=-1) {
                scene->addRect(j*25, i*25, 25, 25, Colors.GetPen(), Colors.GetTexture(skeleton));
            }

        }
    }
}

void LevelPainter::ReDrawEnter(QGraphicsScene *scene, int x, int y)
{
    Palette Colors;
    scene->addRect(y*25, x*25, 25, 25, Colors.GetPen(), Colors.GetColor(BLUE));
}

void LevelPainter::ReDrawAfterInteraction(QGraphicsScene* scene, int x, int y, NameOfObjects name) {
    Palette Colors;
    if (name==troll) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
    }
    if (name==skeleton) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(skeleton));
    }
    if (name==beagle) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(beagle));
    }
    if (name==hero) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
        string strH = to_string(field->Find(hero)->GetHealth());
        string strT = "Player Health: ";
        strH = strT + strH;
        QString s = QString::fromStdString(strH);
        labelHealth->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        labelHealth->setText(s);
        labelHealth->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        labelHealth->setGeometry(5, 1, 105, 35);

        string strA = to_string(field->Find(hero)->GetAtack());
        string strTx = "Player Atack: ";
        strA = strTx + strA;
        QString st = QString::fromStdString(strA);
        labelAtack->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        labelAtack->setText(st);
        labelAtack->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        labelAtack->setGeometry(5, 1, 90, 35*2);

        string strCE = to_string(field->GetCountEnemy());
        string strTxe = "Enemies remained: ";
        strCE= strTxe + strCE;
        QString str = QString::fromStdString(strCE);
        labelCountEnemy->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        labelCountEnemy->setText(str);
        labelCountEnemy->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        labelCountEnemy->setGeometry(5, 1, 115, 35*3);

        string strCI = to_string(field->GetCountItem());
        string strTxi = "Items remained: ";
        strCI = strTxi + strCI;
        QString stra = QString::fromStdString(strCI);
        labelCountItem->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        labelCountItem->setText(stra);
        labelCountItem->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        labelCountItem->setGeometry(5, 1, 100, 35*4);
        if ((field->GetCountEnemy()<=0) || (field->GetCountItem()<=0)) {
            scene->addRect(ex_x*25, ex_y*25, 25, 25, Colors.GetPen(), Colors.GetColor(FUCHSIA));
        }
        else {
            scene->addRect(ex_x*25, ex_y*25, 25, 25, Colors.GetPen(), Colors.GetTextureExit());
        }
    }
    if ((name==sword) || (name==potion) || (name==boots)) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
    }
}

void LevelPainter::ReDrawTrollUp(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, (y-1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
    }

}
void LevelPainter::ReDrawTrollDown(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, (y+1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
    }

}
void LevelPainter::ReDrawTrollLeft(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect((x-1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
    }

}
void LevelPainter::ReDrawTrollRight(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect((x+1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(troll));
    }

}

void LevelPainter::ReDrawHeroUp(QGraphicsScene *scene, int x, int y)
{
    Palette Colors;
    scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
    scene->addRect(x*25, (y-1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
}

void LevelPainter::ReDrawHeroDown(QGraphicsScene *scene, int x, int y)
{
    Palette Colors;
    scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
    scene->addRect(x*25, (y+1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
}

void LevelPainter::ReDrawHeroLeft(QGraphicsScene *scene, int x, int y)
{
    Palette Colors;
    scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
    scene->addRect((x-1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
}

void LevelPainter::ReDrawHeroRight(QGraphicsScene *scene, int x, int y)
{
    Palette Colors;
    scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
    scene->addRect((x+1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(hero));
}


void LevelPainter::ReDrawBeagleLeft(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect((x-1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(beagle));
    }

}
void LevelPainter::ReDrawBeagleRight(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect((x+1)*25, y*25, 25, 25, Colors.GetPen(), Colors.GetTexture(beagle));
    }

}

void LevelPainter::ReDrawSkeletonUp(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, (y-1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(skeleton));
    }

}
void LevelPainter::ReDrawSkeletonDown(QGraphicsScene* scene, int x, int y, int approvement) {
    Palette Colors;
    if (approvement==1) {
        scene->addRect(x*25, y*25, 25, 25, Colors.GetPen(), Colors.GetColor(KHAKI));
        scene->addRect(x*25, (y+1)*25, 25, 25, Colors.GetPen(), Colors.GetTexture(skeleton));
    }

}


LevelPainter::~LevelPainter()
{
    //delete field;
}

void LevelPainter::SetField(Field *fIn)
{
    field = fIn;
}
