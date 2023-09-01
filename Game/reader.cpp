#include "reader.h"
#include <iostream>

Reader::Reader(MoverHero* mIn, LevelPainter* painterIn, QGraphicsScene* sceneIn, Saver* saverIn, Loader* loaderIn, LevelBuilder* builderIn, Mover* moveIn, Interacter* iIn, LoggerFile* loggerFileIn, LoggerConsole* loggerConsoleIn, QLabel *labelH, QLabel *labelA, QLabel *labelCE, QLabel *labelCI)
{
    m = mIn;
    painter = painterIn;
    scene = sceneIn;
    saver = saverIn;
    loader = loaderIn;
    builder = builderIn;
    mover = moveIn;
    interacter = iIn;
    loggerConsole = loggerConsoleIn;
    loggerFile = loggerFileIn;
    labelHealth=labelH;
    labelAtack=labelA;
    labelCountEnemy=labelCE;
    labelCountItem=labelCI;
}

void Reader::ReadButton(int key)
{

    switch (key) {
        case QtKeys::UpKey: {
            m->MoveHeroUp();
            painter->ReDrawHeroUp(scene, m->GetHero()->GetPositionX(), m->GetHero()->GetPositionY()+1);
            break;
        }
        case QtKeys::DownKey: {
            m->MoveHeroDown();
            painter->ReDrawHeroDown(scene, m->GetHero()->GetPositionX(), m->GetHero()->GetPositionY()-1);
            break;
        }
        case QtKeys::LeftKey: {
            m->MoveHeroLeft();
            painter->ReDrawHeroLeft(scene, m->GetHero()->GetPositionX()+1, m->GetHero()->GetPositionY());
            break;
        }
        case QtKeys::RightKey: {
            m->MoveHeroRight();
            painter->ReDrawHeroRight(scene, m->GetHero()->GetPositionX()-1, m->GetHero()->GetPositionY());
            break;
        }
        case QtKeys::SB: {
            saver->Save(m->GetField());
            break;
        }
        case QtKeys::LB: {
            if (loader->Load()!=nullptr) {
                scene->clear();
                Field* smtf = loader->Load();
                delete builder;
                builder = new LevelBuilder();
                builder->SetSavedField(smtf);
                delete painter;
                painter = new LevelPainter(smtf, labelHealth, labelAtack, labelCountEnemy, labelCountItem);
                painter->Draw(scene);
                delete interacter;
                interacter = new Interacter(smtf);
                delete mover;
                mover = new Mover(smtf, builder, painter, interacter, loggerFile, loggerConsole, scene);
                delete m;
                m = new MoverHero(builder->GetField(), builder->GetField()->Find(hero), mover);
            }
            break;
        }
    }
}
