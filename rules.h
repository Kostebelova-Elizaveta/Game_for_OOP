#ifndef RULES_H
#define RULES_H

template <typename T>
class Rules
{
private:
    int h, w;
    int enemy, item;
    int countItem, countEnemy;
public:
    Rules();
    int GetH();
    int GetW();
    int GetEnemy();
    int GetItem();
    int GetCountEnemy();
    int GetCountItem();
    ~Rules();
};


#endif // RULES_H
