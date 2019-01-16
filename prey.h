#ifndef PREY_H
#define PREY_H
#include "creature.h"
#include <SFML/Graphics.hpp>

//this creature is the prey, never dies unless eaten by hunter, will breed every 3 steps
class Prey : public Creature
{
public:
    Prey(int row, int col);//constructor
    ~Prey(){};
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);//breed every 3 steps
    void die(Creature* grid[][MAX]);//empty
    void show(sf::RenderWindow& window);
    void setPosition(int row, int col);
    sf::RectangleShape prey;
private:
    char face = 'P';
};

#endif // PREY_H
