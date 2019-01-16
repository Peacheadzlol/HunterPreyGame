#include "wall.h"
#include "creature.h"
#include <iostream>
using namespace std;

//Precondition: called by the caller
//Postcondition: create wall object along with its parent portion
Wall::Wall(int row, int col)
    : Creature(row, col, 'W')//call parent constructor
{
    wall.setFillColor(sf::Color::Blue);//set color
    wall.setSize(sf::Vector2f(50,50));//set size
    wall.setPosition(row*50, col*50);//size position
}
//Precondition: called by the caller
//Postcondition: it's a wall, doesnt move
void Wall::move(Creature* grid[][MAX])
{
    //empty
}
//Precondition: called by the caller
//Postcondition: wall doesnt breed
void Wall::breed(Creature* grid[][MAX])
{
    //empty
}
//Precondition: called by the caller
//Postcondition: wall does not die
void Wall::die(Creature* grid[][MAX])
{
    //empty
}
//Precondition: called by the caller
//Postcondition: print Wall face and draw it
void Wall::show(sf::RenderWindow &window)
{
    cout << face;
    //window.clear();
    window.draw(wall);//draw
}
void Wall::setPosition(int row, int col)
{
    //empty
}
