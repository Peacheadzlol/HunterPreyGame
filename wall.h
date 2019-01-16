#ifndef WALL_H
#define WALL_H
#include "creature.h"
#include <SFML/Graphics.hpp>

//This creature is the wall
class Wall : public Creature
{
public:
    Wall(int row, int col);//constructor with 2 arguments
    ~Wall(){};
    void move(Creature* grid[][MAX]);//empty
    void breed(Creature* grid[][MAX]);//empty
    void die(Creature* grid[][MAX]);//empty
    void show(sf::RenderWindow& window);
    void setPosition(int row, int col);
    sf::RectangleShape wall;
private:
    char face = 'W';
};

#endif // WALL_H
