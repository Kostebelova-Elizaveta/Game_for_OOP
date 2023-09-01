#include "Game/Logic/levelbuilder.h"

LevelBuilder::LevelBuilder(){


}

void LevelBuilder::SetField(int widht, int height, int numberOfEnemy, int numberOfItem, int countEnemy, int countItem) {
   field = new Field(widht, height, countEnemy, countItem);
   for (int i=0; i<height; i++) {
       for (int j=0; j<widht; j++) {
           if ( (i==0) || (j==0) || (i==height-1) || (j==widht-1) ) {
               field->GetBrick(i,j)->SetCondition(0); // стена
               field->GetBrick(i,j)->SetPassable(0);
           }
           else {
               field->GetBrick(i,j)->SetCondition(1); // поле
               field->GetBrick(i,j)->SetPassable(1);
           }
        }
   }
   int enter_x = rand()%(widht-2) +1;
   int enter_y = rand()%(height-2) +1;
   int exit_x = rand()%(widht-2) +1;
   int exit_y = rand()%(height-2) +1;

   field->GetBrick(enter_y, enter_x)->SetCondition(2); // вход
    field->GetBrick(enter_y, enter_x)->SetPassable(1);

   while ((abs(enter_x-exit_x)<=3) && (abs(enter_y-exit_y)<=3)) {
       exit_x = rand()%(widht-2) +1;
       exit_y = rand()%(height-2) +1;
   }
   field->GetBrick(exit_y, exit_x)->SetCondition(3); // выход
   if ((countEnemy==0) && (countItem==0)) {
       field->GetBrick(exit_y, exit_x)->SetPassable(1);
   }
   else {
       field->GetBrick(exit_y, exit_x)->SetPassable(0);
   }

   int countWalls = 3;
   for (int i=1; i<height-1; i++) {
       for (int j=0; j<countWalls; j++) {
           int num = rand()%(widht-2) +1;
       if ((field->GetBrick(i, num)->GetCondition()!=2)
               && (field->GetBrick(i, num)->GetCondition()!=3)
               && (field->GetBrick(i+1, num)->GetCondition()!=2)
               && (field->GetBrick(i-1, num)->GetCondition()!=2)
               && (field->GetBrick(i, num+1)->GetCondition()!=2)
               && (field->GetBrick(i, num-1)->GetCondition()!=2)
               && (field->GetBrick(i+1, num)->GetCondition()!=3)
               && (field->GetBrick(i-1, num)->GetCondition()!=3)
               && (field->GetBrick(i, num+1)->GetCondition()!=3)
               && (field->GetBrick(i, num-1)->GetCondition()!=3)) {
           field->GetBrick(i, num)->SetCondition(0);
           field->GetBrick(i, num)->SetPassable(0);
            }
        }
    }
   Hero* player = new Hero();

   for (int i=0; i<numberOfItem; i++) {
       int potion_x = rand()%(widht-2) +1;
       int potion_y = rand()%(height-2) +1;
       while (field->GetBrick(potion_y, potion_x)->GetCondition()==0) {
               potion_x = rand()%(widht-2) +1;
               potion_y = rand()%(height-2) +1;
       }
       field->GetBrick(potion_y, potion_x)->AddToVector(potion);
       field->GetBrick(potion_y, potion_x)->GetObj(potion)->SetPositionX(potion_x);
       field->GetBrick(potion_y, potion_x)->GetObj(potion)->SetPositionY(potion_y);
   }

   for (int i=0; i<numberOfItem; i++) {
       int sword_x = rand()%(widht-2) +1;
       int sword_y = rand()%(height-2) +1;
       while (field->GetBrick(sword_y, sword_x)->GetCondition()==0) {
               sword_x = rand()%(widht-2) +1;
               sword_y = rand()%(height-2) +1;
       }
       field->GetBrick(sword_y, sword_x)->AddToVector(sword);
       field->GetBrick(sword_y, sword_x)->GetObj(sword)->SetPositionX(sword_x);
       field->GetBrick(sword_y, sword_x)->GetObj(sword)->SetPositionY(sword_y);
   }

   for (int i=0; i<numberOfItem; i++) {
       int boots_x = rand()%(widht-2) +1;
       int boots_y = rand()%(height-2) +1;
       while (field->GetBrick(boots_y, boots_x)->GetCondition()==0) {
               boots_x = rand()%(widht-2) +1;
               boots_y = rand()%(height-2) +1;
       }
       field->GetBrick(boots_y, boots_x)->AddToVector(boots);
       field->GetBrick(boots_y, boots_x)->GetObj(boots)->SetPositionX(boots_x);
       field->GetBrick(boots_y, boots_x)->GetObj(boots)->SetPositionY(boots_y);
   }

   for (int i=0; i<numberOfEnemy; i++) {
       int troll_x = rand()%(widht-2) +1;
       int troll_y = rand()%(height-2) +1;
       while (field->GetBrick(troll_y, troll_x)->GetCondition()==0) {
               troll_x = rand()%(widht-2) +1;
               troll_y = rand()%(height-2) +1;
       }
       field->GetBrick(troll_y, troll_x)->AddToVector(troll);
       field->GetBrick(troll_y, troll_x)->GetObj(troll)->SetPositionX(troll_x);
       field->GetBrick(troll_y, troll_x)->GetObj(troll)->SetPositionY(troll_y);
   }

   for (int i=0; i<numberOfEnemy; i++) {
       int skeleton_x = rand()%(widht-2) +1;
       int skeleton_y = rand()%(height-2) +1;
       while ((field->GetBrick(skeleton_y, skeleton_x)->GetCondition()==0 || (field->GetBrick(skeleton_y, skeleton_x)->IsSmtfInVector()))) {
               skeleton_x = rand()%(widht-2) +1;
               skeleton_y = rand()%(height-2) +1;
       }
       field->GetBrick(skeleton_y, skeleton_x)->AddToVector(skeleton);
       field->GetBrick(skeleton_y, skeleton_x)->GetObj(skeleton)->SetPositionX(skeleton_x);
       field->GetBrick(skeleton_y, skeleton_x)->GetObj(skeleton)->SetPositionY(skeleton_y);
   }

   for (int i=0; i<numberOfEnemy; i++) {
       int beagle_x = rand()%(widht-2) +1;
       int beagle_y = rand()%(height-2) +1;
       while (field->GetBrick(beagle_y, beagle_x)->GetCondition()==0) {
               beagle_x = rand()%(widht-2) +1;
               beagle_y = rand()%(height-2) +1;
       }
       field->GetBrick(beagle_y, beagle_x)->AddToVector(beagle);
       field->GetBrick(beagle_y, beagle_x)->GetObj(beagle)->SetPositionX(beagle_x);
       field->GetBrick(beagle_y, beagle_x)->GetObj(beagle)->SetPositionY(beagle_y);
   }

//   int pl_x = troll_x, pl_y = troll_y+2; // для теста сражения

//   field->GetBrick(troll_y-2, troll_x)->AddToVector(troll);
//   field->GetBrick(troll_y-2, troll_x)->GetObj(troll)->SetPositionX(troll_x);
//   field->GetBrick(troll_y-2, troll_x)->GetObj(troll)->SetPositionY(troll_y-2); // для теста сражения


   field->GetBrick(enter_y, enter_x)->AddHero(player);
   field->GetBrick(enter_y, enter_x)->GetObj(hero)->SetPositionX(enter_x);
   field->GetBrick(enter_y, enter_x)->GetObj(hero)->SetPositionY(enter_y); // для создания героя
//   field->GetBrick(pl_y, pl_x)->AddHero(player);
//   field->GetBrick(pl_y, pl_x)->GetObj(hero)->SetPositionX(pl_x);
//   field->GetBrick(pl_y, pl_x)->GetObj(hero)->SetPositionY(pl_y);  // для теста сражения

}

void LevelBuilder::SetSavedField(Field *fieldIn)
{
    field = fieldIn;
}

bool LevelBuilder::IsInVectorObj(InterfaceForPoint* smtf, std::vector<InterfaceForPoint*> vec) {
    for (unsigned i=0; i<vec.size(); i++) {
        if (vec[i]==smtf) {
            return 1;
        }
    }
    return 0;
}

Field* LevelBuilder::GetField() {
    return field;
}

LevelBuilder::~LevelBuilder(){
    delete field;
}



