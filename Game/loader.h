#ifndef LOADER_H
#define LOADER_H
#include "Game/Field/field.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

class Loader
{
private:
    Field* result;
public:
    Loader();
    Field* Load();
};

#endif // LOADER_H
