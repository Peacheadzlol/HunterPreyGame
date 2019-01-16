#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include "constant.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Creature
{
public:
    char Getface();
    int GetRow();
    int GetCol();
    bool IsPrey();
    bool IsHunter();
    bool ItMoved();//returns the moved boolean value
    void ResetMoved();
    int* OpenSpots(Creature* grid[][MAX]);
    int GetBreedStep();
    int RandomSpot(int* array);
    void MoveCreature(Creature* grid[][MAX], int r, int c);
    virtual void setPosition(int r, int c);
    virtual void move(Creature* grid[][MAX]);//virtual move function
    virtual void breed(Creature* grid[][MAX]);//virtual breed function
    virtual void die(Creature* grid[][MAX]);//virtual die function
    virtual void show(sf::RenderWindow& window);//virtual show function
    Creature(int i, int j, char f);
    virtual ~Creature(){};//virtual destructor
private:
    int row;
    int col;
    char face;
    int stepBreed;
    bool moved;
};

#endif // CREATURE_H
