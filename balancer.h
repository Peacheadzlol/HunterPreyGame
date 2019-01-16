#ifndef BALANCER_H
#define BALANCER_H
#include <SFML/Graphics.hpp>
#include "creature.h"

//This creature is the balancer, never dies, never breeds, but it will create a hunter or prey if there is none left in the grid
class Balancer : public Creature
{
public:
    Balancer(int row, int col);//constructor
    ~Balancer(){};
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);//empty
    void die(Creature* grid[][MAX]);//empty
    void transform(Creature* grid[][MAX]);//turns either an empty spot or none wall object around it into a prey or hunter if there is none left in the grid
    void show(sf::RenderWindow& window);
    void setPosition(int row, int col);
    sf::RectangleShape balancer;
private:
    char face = 'B';
};

#endif // BALANCER_H
