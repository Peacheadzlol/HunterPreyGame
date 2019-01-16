#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "creature.h"
#include "constant.h"
#include "wall.h"
#include "hunter.h"
#include "prey.h"
#include "balancer.h"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Grid
{
public:
    Grid();//default constructor
    Grid(int hunter, int prey, int balancer);//constructor with 3 arguments, takes in the numbers of each creatures
    void Add(int hunter, int prey, int balancer);//add the number of each creatures
    void Init();
    void Show();
    void Step();//step function
    ~Grid();//destructor
    void processEvents();
    void update();
    void Draw();
    void render();
    void run();
    //sf::RectangleShape hunter;
    //sf::RectangleShape prey;
    //sf::RectangleShape wall;
private:
    Creature* grid[MAX][MAX];
    sf::RenderWindow window;

};

#endif // GRID_H
