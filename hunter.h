#ifndef HUNTER_H
#define HUNTER_H
#include "creature.h"
#include <SFML/Graphics.hpp>

//This creature is the hunter, will starve if not eaten prey in 3 steps, will breed every 8 steps
class Hunter : public Creature
{
public:
    Hunter(int row, int col);//constructor
    ~Hunter(){};
    void move(Creature* grid[][MAX]);
    void breed(Creature* grid[][MAX]);//breed for every 8 steps
    void die(Creature* grid[][MAX]);//starve if not eaten prey for 3 steps
    void kill(Creature* grid[][MAX], int moveTo);//kill the prey that is located in the randomly selected location
    void show(sf::RenderWindow& window);
    int* PreySpots(Creature* grid[][MAX]);//check for the prey spots around it, return the int pointer
    void setPosition(int row, int col);
    sf::RectangleShape hunter;
private:
    int stepStarve;
    char face = 'H';
    bool died;
};

#endif // HUNTER_H
