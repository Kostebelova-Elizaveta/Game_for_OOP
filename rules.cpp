#include "rules.h"
template <typename T>
Rules<T>::Rules()
{
    h=25;
    w=40;
    enemy=5;
    item=3;
    countEnemy=4;
    countItem=4;
}

template <typename T>
int Rules<T>::GetH()
{
    return h;

}

template <typename T>
int Rules<T>::GetW()
{
    return w;

}

template <typename T>
int Rules<T>::GetEnemy()
{
    return enemy;

}

template <typename T>
int Rules<T>::GetItem()
{
    return item;

}

template <typename T>
int Rules<T>::GetCountEnemy()
{
    return countEnemy;

}

template <typename T>
int Rules<T>::GetCountItem()
{
    return countItem;

}

template<typename T>
Rules<T>::~Rules()
{

}
