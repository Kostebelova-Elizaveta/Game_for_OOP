#include "loggerconsole.h"

std::ostream& operator<< (std::ostream &out, InterfaceForPoint &smtf) {
    if ((smtf.GetName()==troll) || (smtf.GetName()==beagle) || (smtf.GetName()==skeleton)) {
        if (smtf.GetName()==troll) out << "Object:troll" << endl;
        if (smtf.GetName()==beagle) out <<"Object:beagle" << endl;
        if (smtf.GetName()==skeleton) out <<"Object:skeleton" << endl;
        out << "Object's Health:" << smtf.GetHealth() << endl;
        out << "Object's Atack:" << smtf.GetAtack() << endl;
        out << "Object's Speed:" << smtf.GetSpeed() << endl;
        out << "Object's Position X:" << smtf.GetPositionX() << endl;
        out << "Object's Position Y:" << smtf.GetPositionY() << endl;
        out << "Object's Way for moving:" << smtf.GetWay() << endl;
        out << "Object's Check:" << smtf.GetCheck() << endl;
        out << "Object's Alive:" << smtf.GetAlive() << endl;
        out << endl;
    }
    if ((smtf.GetName()==potion) || (smtf.GetName()==sword) || (smtf.GetName()==boots)) {
        if (smtf.GetName()==potion) out << "Object:potion" << endl;
        if (smtf.GetName()==sword) out << "Object:sword" << endl;
        if (smtf.GetName()==boots) out << "Object:boots" << endl;
        out << "Object's Buf:" << smtf.GetBuf() << endl;
        out << "Object's Position X:" << smtf.GetPositionX() << endl;
        out << "Object's Position Y:" << smtf.GetPositionY() << endl;
        out << "Object's Check:" << smtf.GetCheck() << endl;
        out << "Object's Alive:" << smtf.GetAlive() << endl;
        out << endl;
    }
    if (smtf.GetName()==hero) {
        out << "Object:hero" << endl;
        out << "Object's Health:" << smtf.GetHealth() << endl;
        out << "Object's Atack:" << smtf.GetAtack() << endl;
        out << "Object's Speed:" << smtf.GetSpeed() << endl;
        out << "Object's Position X:" << smtf.GetPositionX() << endl;
        out << "Object's Position Y:" << smtf.GetPositionY() << endl;
        out << "Object's Check:" << smtf.GetCheck() << endl;
        out << "Object's Alive:" << smtf.GetAlive() << endl;
        out << endl;
    }
    return out;
}


std::ostream& operator<< (std::ostream &out, Point &smtf)  {
    out <<"Object:Point" << endl;
    out <<"Object's Passable:" << smtf.GetPassable() << endl;
    out <<"Object's Condition:" << smtf.GetCondition() << endl;
    if (smtf.IsSmtfInVector()) {
        out <<"Object's Elements:" << endl;
        for (unsigned i=0; i<smtf.GetVector().size(); i++) {
            if (smtf.GetVector()[i]->GetName()==potion) out << "potion ";
            if (smtf.GetVector()[i]->GetName()==sword) out << "sword ";
            if (smtf.GetVector()[i]->GetName()==boots) out << "boots ";
            if (smtf.GetVector()[i]->GetName()==troll) out << "troll ";
            if (smtf.GetVector()[i]->GetName()==beagle) out << "beagle ";
            if (smtf.GetVector()[i]->GetName()==skeleton) out << "skeleton ";
            if (smtf.GetVector()[i]->GetName()==hero) out << "hero ";
        }
        out  << endl;
    }
    else {
        out << "Object's Elements:NULL" << endl;
    }
    out  << endl;
    return out;
}

std::ostream& operator<< (std::ostream &out, Field &smtf) {
    out << smtf.GetHeight() << endl;
    out << smtf.GetWidth() << endl;
    out << smtf.GetCountEnemy() << endl;
    out << smtf.GetCountItem() << endl;
    for (int i=0; i<smtf.GetHeight(); i++) {
        for (int j=0; j<smtf.GetWidth(); j++) {
            out << i << endl;
            out << j << endl;
            out << smtf.GetBrick(i,j)->GetPassable() << endl;
            out << smtf.GetBrick(i,j)->GetCondition() << endl;
            if (smtf.GetBrick(i,j)->IsSmtfInVector()) {
                for (unsigned k=0; k<smtf.GetBrick(i,j)->GetVector().size(); k++) {
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==potion) out << 1; // potion == 1
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==sword) out << 2; // sword == 2
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==boots) out << 3; // boots == 3
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==troll) out << 4; // troll == 4
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==beagle) out << 5; // beagle == 5
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==skeleton) out << 6; // skeleton == 6
                    if (smtf.GetBrick(i,j)->GetVector()[k]->GetName()==hero) {
                        out << 7 << endl; // hero == 7
                        out << smtf.GetBrick(i,j)->GetVector()[k]->GetHealth() << endl;
                        out << smtf.GetBrick(i,j)->GetVector()[k]->GetAtack() << endl;
                        out << smtf.GetBrick(i,j)->GetVector()[k]->GetSpeed();
                    }
                }
                out  << endl;
            }
            else {
                out << 0 << endl; // NULL == 0
            }
        }
    }
    return out;
}

LoggerConsole::LoggerConsole(bool num)
{
    usable=num;
}

void LoggerConsole::WriteDown(InterfaceForPoint* smtf) {
    cout << *smtf;
}
void LoggerConsole::WriteDown(Point* smtf) {
    cout << *smtf;
}
void LoggerConsole::WriteDown(Field* smtf) {
    cout << *smtf;
}

bool LoggerConsole::GetUsable() {
    return usable;
}

LoggerConsole::~LoggerConsole()
{

}

