#include "grid.h"
#include "constant.h"
#include <iostream>
using namespace std;

void Grid::Init()//init function, initialize all Creature ptrs to NULL
{
    for(int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i = 0; i < MAX; i ++)//create wall objects
    {
        grid[0][i] = new Wall(0, i);
        grid[MAX - 1][i] = new Wall(MAX - 1, i);
        grid[i][0] = new Wall(i, 0);
        grid[i][MAX - 1] = new Wall(i, MAX - 1);
    }

}
Grid::Grid()//default constructor
{
    cout << "Entered the Grid default constructor\n";
    window.create(sf::VideoMode(1000, 1000), "Test Window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    cout << "About to set the framerate limit\n";
    window.setFramerateLimit(60);
    /*
    wall.setFillColor(sf::Color::Blue);
    wall.setSize(sf::Vector2f(10,10));
    hunter.setFillColor(sf::Color::Red);
    hunter.setSize(sf::Vector2f(10,10));
    prey.setFillColor(sf::Color::Green);
    prey.setSize(sf::Vector2f(10,10));
    */
    for(int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i = 0; i < MAX; i ++)
    {
        grid[0][i] = new Wall(0, i);
        grid[MAX - 1][i] = new Wall(MAX - 1, i);
        grid[i][0] = new Wall(i, 0);
        grid[i][MAX - 1] = new Wall(i, MAX - 1);
    }
}
Grid::Grid(int hunter, int prey, int balancer)
{
    window.create(sf::VideoMode(1000, 1000), "Sample Window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    window.setFramerateLimit(60);
    for(int i = 0; i < MAX; i ++)//first set every creature* to NULL
    {
        for (int j = 0; j < MAX; j ++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i = 0; i < MAX; i ++)//create wall object
    {
        grid[0][i] = new Wall(0, i);
        grid[MAX - 1][i] = new Wall(MAX - 1, i);
        grid[i][0] = new Wall(i, 0);
        grid[i][MAX - 1] = new Wall(i, MAX - 1);
    }
    srand(time(NULL));
    for (int i = 0; i < hunter; i ++)//create hunter object and put them randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Hunter(row, col);
    }
    for (int i = 0; i < prey; i ++)//create prey object and put them randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Prey(row, col);
    }
    for (int i = 0; i < balancer; i ++)//create balancer object and put them randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Balancer(row, col);
    }
}
Grid::~Grid()//destructor
{
    cout << "destructor fired\n";
    for(int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            delete grid[i][j];
        }
    }
}
void Grid::Add(int hunter, int prey, int balancer)//add the numbers of creatures into the grid
{
    for (int i = 0; i < hunter; i ++)//create the hunter object and place it randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Hunter(row, col);
    }
    for (int i = 0; i < prey; i ++)//create the prey object and place it randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Prey(row, col);
    }
    for (int i = 0; i < balancer; i ++)//create the balancer object and place it randomly into the grid
    {
        int row = rand() % MAX;
        int col = rand() % MAX;
        while (grid[row][col] != NULL)
        {
            row = rand() % MAX;
            col = rand() % MAX;
        }
        grid[row][col] = new Balancer(row, col);
    }
}
void Grid::Show()//show function, prints the grid to the screen and sfml window
{
    //cout << "Show function entered\n";

    window.clear();
    for (int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            if (grid[i][j] == NULL)
                cout << " ";
            else
                grid[i][j]->show(window);//call virtual function
        }
        cout << endl;
    }

    /*
    char face;
    for (int i = 0; i < MAX; i ++)
    {
        cout << "1st for loop entered\n";
        for (int j = 0; j < MAX; j ++)
        {
            cout <<"2nd for loop entered\n";
            if (grid[i][j] != NULL)
                face = grid[i][j]->Getface();
            else
                face = 'a';
            cout << face << endl;
            switch (face)
            {
                case 'W':
                    shape.setFillColor(sf::Color::Blue);
                    shape.setSize(sf::Vector2f(10,10));
                    shape.setPosition(i,j);
                    cout << "wall entered\n";
                    //window.draw(wall);
                    break;
                case 'H':
                    shape.setFillColor(sf::Color::Red);
                    shape.setSize(sf::Vector2f(10,10));
                    shape.setPosition(i,j);
                    cout << "hunter entered\n";
                    //window.draw(hunter);
                    break;
                case 'P':
                    shape.setFillColor(sf::Color::Green);
                    shape.setSize(sf::Vector2f(10,10));
                    shape.setPosition(i,j);
                    cout << "prey entered\n";
                    //window.draw(prey);
                    break;
                default:
                    cout << "default ";
                    break;
            }
        }
    }
    */
}
void Grid::Step()//step function
{
    //cout << "Step function entered\n";
    for (int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            if (grid[i][j] != NULL)
                grid[i][j]->ResetMoved();//reset move
        }
    }
    for (int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j ++)
        {
            if (grid[i][j] != NULL && !grid[i][j]->ItMoved())
                grid[i][j]->move(grid);//call virtual move function to move creatures
        }
    }
}
void Grid::processEvents()
{
   //cout << "processEvents function entered\n";
   sf::Event event;
   while (window.pollEvent(event))//or waitEvent
   {
   // check the type of the event...
       switch (event.type)
       {
           // window closed
           // "close requested" event: we close the window
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //close window when esc is pressed
                   window.close();
               }
               break;
           /*case sf::Event::MouseButtonReleased:
               if (event.mouseButton.button == sf::Mouse::Right){
                   std::cout << "the right button was pressed" << std::endl;
                   std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                   std::cout << "mouse y: " << event.mouseButton.y << std::endl;
               }else{
                   std::cout<<"left button?"<<std::endl;
                   mybox.setPosition(event.mouseButton.x,event.mouseButton.y);
               }
               break;
           */
           default:
               break;
       }
   }
}
void Grid::update()//not used here
{
    Step();
}
void Grid::render()
{
    //cout << "render function entere\n";
    //window.clear();
    Show();
    //Draw();
    window.display();
}
void Grid::Draw()
{
    cout << "Draw function entered\n";
}
void Grid::run()//run function
{
   int i = 1;
    while (window.isOpen())
   {
       //cout << "run function entered\n";
       //Show();
       processEvents();
       Step();
       render(); //clear/draw/display
       cout << i << endl;//display the numbers
       i ++;
   }
}
