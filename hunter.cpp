#include "hunter.h"

//Precondition: called by the caller
//Postcondition: create the hunter object and also create its parent portion
Hunter::Hunter(int row, int col)
    : Creature(row, col, 'H')
{
    died = false;//I was just BORN, STILL ALIVE
    stepStarve = 0;
    hunter.setFillColor(sf::Color::Red);//set color
    hunter.setSize(sf::Vector2f(50,50));//set size
    hunter.setPosition(row*50, col*50);
}
//Precondition: called by the caller
//Postcondition: print the hunter face and if it's still alive, draw it
void Hunter::show(sf::RenderWindow &window)
{
    //window.clear();
    cout << face;
    if (!died)
        window.draw(hunter);
}
//Precondition: called by the caller, get grid from it
//Postcondition: move the hunter object to location around it, if there are preys around it, eats a prey randomly, if no prey, move to an random empty spot around it, if no empty spot, doesnt move
void Hunter::move(Creature* grid[][MAX])
{
    //cout << "Hunter move function reached\n";
    stepStarve ++;
    int* temp = PreySpots(grid);//find prey spots
    if (*temp == -1)//no prey
        temp = OpenSpots(grid);//find empty spots
    int moveTo = RandomSpot(temp);//get random spot
    switch (moveTo)//move to that spot
    {
        case 0:
            kill(grid, 0);
            break;
        case 1:
            kill(grid, 1);
            break;
        case 2:
            kill(grid, 2);
            break;
        case 3:
            kill(grid, 3);
            break;
        case 4:
            kill(grid, 4);
            break;
        case 5:
            kill(grid, 5);
            break;
        case 6:
            kill(grid, 6);
            break;
        case 7:
            kill(grid, 7);
            break;
        default:
            break;
    }
    delete temp;
    breed(grid);//call breed function
    die(grid);//see if it's time to die
}
//Precondition: called by the caller, get grid from it
//Postcondition: if the object has been moving for least 8 steps, breed another hunter object, and place it around the breeder randomly
void Hunter::breed(Creature* grid[][MAX])
{
    //cout << "Hunter breed function reached\n";
    if (GetBreedStep() >= 8)
    {
        int row = GetRow();
        int col = GetCol();
        int* temp = OpenSpots(grid);//find empty spots
        int moveTo = RandomSpot(temp);//get random spot
        switch (moveTo)//create the new hunter there
        {
            case 0:
                grid[row-1][col-1] = new Hunter(row-1, col-1);
                grid[row-1][col-1]->setPosition((row-1)*50,(col-1)*50);
                Creature::breed(grid);
                //grid[row-1][col-1]->setPosition((row-1)*50,(col-1)*50);
                //hunter.setPosition((row-1)*50,(col-1)*50);
                break;
            case 1:
                grid[row][col-1] = new Hunter(row, col-1);
                grid[row][col-1]->setPosition(row*50,(col-1)*50);
                Creature::breed(grid);
                //grid[row][col-1]->setPosition(row*50,(col-1)*50);
                //hunter.setPosition(row*50,(col-1)*50);
                break;
            case 2:
                grid[row+1][col-1] = new Hunter(row+1, col-1);
                grid[row+1][col-1]->setPosition((row+1)*50,(col-1)*50);
                Creature::breed(grid);
                //grid[row+1][col-1]->setPosition((row+1)*50,(col-1)*50);
                //hunter.setPosition((row+1)*50,(col-1)*50);
                break;
            case 3:
                grid[row-1][col] = new Hunter(row-1, col);
                grid[row-1][col]->setPosition((row-1)*50,col*50);
                Creature::breed(grid);
                //grid[row-1][col]->setPosition((row-1)*50,col*50);
                //hunter.setPosition((row-1)*50,col*50);
                break;
            case 4:
                grid[row+1][col] = new Hunter(row+1, col);
                grid[row+1][col]->setPosition((row+1)*50,col*50);
                Creature::breed(grid);
                //grid[row+1][col]->setPosition((row+1)*50,col*50);
                //hunter.setPosition((row+1)*50,col*50);
                break;
            case 5:
                grid[row-1][col+1] = new Hunter(row-1, col+1);
                grid[row-1][col+1]->setPosition((row-1)*50,(col+1)*50);
                Creature::breed(grid);
                //grid[row-1][col+1]->setPosition((row-1)*50,(col+1)*50);
                //hunter.setPosition((row-1)*50,(col+1)*50);
                break;
            case 6:
                grid[row][col+1] = new Hunter(row, col+1);
                grid[row][col+1]->setPosition(row*50,(col+1)*50);
                Creature::breed(grid);
                //grid[row][col+1]->setPosition(row*50,(col+1)*50);
                //hunter.setPosition(row*50,(col+1)*50);
                break;
            case 7:
                grid[row+1][col+1] = new Hunter(row+1, col+1);
                grid[row+1][col+1]->setPosition((row+1)*50,(col+1)*50);
                Creature::breed(grid);
                //grid[row+1][col+1]->setPosition((row+1)*50,(col+1)*50);
                //hunter.setPosition((row+1)*50,(col+1)*50);
                break;
            default:
                break;
        }
    }
}
//Precondition: called by the caller, get grid from it
//Postcondition: if the hunter moved for 3 steps without eating a prey, it dies, free the space
void Hunter::die(Creature* grid[][MAX])
{
    //cout << "Hunter die function reached\n";
    if (stepStarve >= 3)
    {
        int row = GetRow();
        int col = GetCol();
        delete grid[row][col];
        grid[row][col] = NULL;
        died = true;
    }
}
//Precondition: called by the caller, get grid and int moveTo from it
//Postcondition: kill the prey located in move to location, and move the hunter there
void Hunter::kill(Creature* grid[][MAX], int moveTo)
{
    //cout << "Hunter kill function reached\n";
    int row = GetRow();
    int col = GetCol();
    switch (moveTo)//kill the prey
    {
        case 0:
            if (grid[row-1][col-1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row-1][col-1];
                grid[row-1][col-1] = NULL;
            }
            MoveCreature(grid, row-1, col-1);
            hunter.setPosition((row-1)*50,(col-1)*50);
            break;
        case 1:
            if (grid[row][col-1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row][col-1];
                grid[row][col-1] = NULL;
            }
            MoveCreature(grid, row, col-1);
            hunter.setPosition(row*50,(col-1)*50);
            break;
        case 2:
            if (grid[row+1][col-1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row+1][col-1];
                grid[row+1][col-1] = NULL;
            }
            MoveCreature(grid, row+1, col-1);
            hunter.setPosition((row+1)*50,(col-1)*50);
            break;
        case 3:
            if (grid[row-1][col]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row-1][col];
                grid[row-1][col] = NULL;
            }
            MoveCreature(grid, row-1, col);
            hunter.setPosition((row-1)*50,col*50);
            break;
        case 4:
            if (grid[row+1][col]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row+1][col];
                grid[row+1][col] = NULL;
            }
            MoveCreature(grid, row+1, col);
            hunter.setPosition((row+1)*50,col*50);
            break;
        case 5:
            if (grid[row-1][col+1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row-1][col+1];
                grid[row-1][col+1] = NULL;
            }
            MoveCreature(grid, row-1, col+1);
            hunter.setPosition((row-1)*50, (col+1)*50);
            break;
        case 6:
            if (grid[row][col+1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row][col+1];
                grid[row][col+1] = NULL;
            }
            MoveCreature(grid, row, col+1);
            hunter.setPosition(row*50,(col+1)*50);
            break;
        case 7:
            if (grid[row+1][col+1]->IsPrey())
            {
                stepStarve = 0;
                delete grid[row+1][col+1];
                grid[row+1][col+1] = NULL;
            }
            MoveCreature(grid, row+1, col+1);
            hunter.setPosition((row+1)*50,(col+1)*50);
            break;
        default:
            break;
    }
}
//Precondition: called by the caller, get grid from it
//Postcondition: returns the int point that points to an int array that has the location of prey numbered in itself
int* Hunter::PreySpots(Creature* grid[][MAX])
{
    //cout << "Hunter PreySpots function reached\n";
    int* temp = new int[8 + 1];//save the last spot for -1, end of the array
    int row = GetRow();
    int col = GetCol();
    int index = 0;
    if (grid[row-1][col-1]->IsPrey())
    {
        //cout << "0\n";
        temp[index] = 0;
        index ++;
    }
    if (grid[row][col-1]->IsPrey())
    {
        //cout << "1\n";
        temp[index] = 1;
        index ++;
    }
    if (grid[row+1][col-1]->IsPrey())
    {
        //cout << "2\n";
        temp[index] = 2;
        index ++;
    }
    if (grid[row-1][col]->IsPrey())
    {
        //cout << "3\n";
        temp[index] = 3;
        index ++;
    }
    if (grid[row+1][col]->IsPrey())
    {
        //cout << "4\n";
        temp[index] = 4;
        index ++;
    }
    if (grid[row-1][col+1]->IsPrey())
    {
        //cout << "5\n";
        temp[index] = 5;
        index ++;
    }
    if (grid[row][col+1]->IsPrey())
    {
        //cout << "6\n";
        temp[index] = 6;
        index ++;
    }
    if (grid[row+1][col+1]->IsPrey())
    {
        //cout << "7\n";
        temp[index] = 7;
        index ++;
    }
    temp[index] = -1;//end of the array, end of num_used
    //cout << "end of Hunter PreySpot\n";
    return temp;
}
void Hunter::setPosition(int row, int col)
{
    hunter.setPosition(row ,col);
}
