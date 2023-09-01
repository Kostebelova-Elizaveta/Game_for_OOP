#include "loader.h"

using namespace std;
Loader::Loader()
{

}

Field* Loader::Load()
{
    std::ifstream fin;
    string s;
    int h = 0, w = 0, ce = 0, ci = 0;
    int num = 0;
    fin.open("C:/Users/liza/Desktop/OOP_Lab3/save.txt");
    if (!fin.is_open()) {
            throw "File open error!";
        }
    else {

        try {
            getline(fin, s);
            h = stoi(s);
            getline(fin, s);
            w = stoi(s);
            getline(fin, s);
            ce = stoi(s);
            getline(fin, s);
            ci = stoi(s);

            result = new Field(w, h, ce, ci);
            for (int i=0; i<h; i++) {
                for (int j=0; j<w; j++) {
                    getline(fin, s);
                    num = stoi(s);
                    if (num==i)  {
                        getline(fin, s);
                        num = stoi(s);
                        if (num==j) {
                            getline(fin, s);
                            num = stoi(s);
                            result->GetBrick(i, j)->SetPassable(num);

                            getline(fin, s);
                            num = stoi(s);
                            result->GetBrick(i, j)->SetCondition(num);

                            getline(fin, s);
                            num = stoi(s);
                            switch (num) {
                                case 1:
                                    result->GetBrick(i, j)->AddToVector(potion);
                                    result->GetBrick(i, j)->GetObj(potion)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(potion)->SetPositionY(i);
                                    break;
                                case 2:
                                    result->GetBrick(i, j)->AddToVector(sword);
                                    result->GetBrick(i, j)->GetObj(sword)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(sword)->SetPositionY(i);
                                    break;
                                case 3:
                                    result->GetBrick(i, j)->AddToVector(boots);
                                    result->GetBrick(i, j)->GetObj(boots)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(boots)->SetPositionY(i);
                                    break;
                                case 4:
                                    result->GetBrick(i, j)->AddToVector(troll);
                                    result->GetBrick(i, j)->GetObj(troll)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(troll)->SetPositionY(i);
                                    break;
                                case 5:
                                    result->GetBrick(i, j)->AddToVector(beagle);
                                    result->GetBrick(i, j)->GetObj(beagle)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(beagle)->SetPositionY(i);
                                    break;
                                case 6:
                                    result->GetBrick(i, j)->AddToVector(skeleton);
                                    result->GetBrick(i, j)->GetObj(skeleton)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(skeleton)->SetPositionY(i);
                                    break;
                                case 7:
                                    result->GetBrick(i, j)->AddToVector(hero);
                                    result->GetBrick(i, j)->GetObj(hero)->SetPositionX(j);
                                    result->GetBrick(i, j)->GetObj(hero)->SetPositionY(i);
                                    getline(fin, s);
                                    num = stoi(s);
                                    result->GetBrick(i, j)->GetObj(hero)->SetHealth(num);
                                    getline(fin, s);
                                    num = stoi(s);
                                    result->GetBrick(i, j)->GetObj(hero)->SetAtack(num);
                                    getline(fin, s);
                                    num = stoi(s);
                                    result->GetBrick(i, j)->GetObj(hero)->SetSpeed(num);
                                    break;
                                case 0:
                                    break;
                                default:
                                    return nullptr;
                                    break;
                            }
                        }
                        else {
                            return nullptr;
                        }
                    }
                    else {
                        return nullptr;
                    }
                }
            }
        } catch (...) {
            return nullptr;
        }


        return result;
    }
    fin.close();
}
