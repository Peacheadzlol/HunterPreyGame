#include "balancer.h"
#include "prey.h"
#include "hunter.h"

//Precondition: called by the caller, get row and col from it
//Postcondition: create the balancer object and its parent portion
Balancer::Balancer(int row, int col)
    : Creature(row, col, 'B')
{
    //transformed = false;
    balancer.setFillColor(sf::Color::Yellow);//set color
    balancer.setSize(sf::Vector2f(50,50));//set size
}
//Precondition: called by the caller, get grid from it
//Postcondition: move the balancer object to a open space around it randomly, if no open spot, doesnt move
void Balancer::move(Creature* grid[][MAX])
{
    int row = GetRow();
    int col = GetCol();
    int* temp = OpenSpots(grid);//get open spots
    int moveTo = RandomSpot(temp);//get random spot
    switch (moveTo)//move it there
    {
        case 0:
            MoveCreature(grid, row-1, col-1);
            balancer.setPosition((row-1)*50,(col-1)*50);
            break;
        case 1:
            MoveCreature(grid, row, col-1);
            balancer.setPosition(row*50,(col-1)*50);
            break;
        case 2:
            MoveCreature(grid, row+1, col-1);
            balancer.setPosition((row+1)*50,(col-1)*50);
            break;
        case 3:
            MoveCreature(grid, row-1, col);
            balancer.setPosition((row-1)*50,col*50);
            break;
        case 4:
            MoveCreature(grid, row+1, col);
            balancer.setPosition((row+1)*50,col*50);
            break;
        case 5:
            MoveCreature(grid, row-1, col+1);
            balancer.setPosition((row-1)*50,(col+1)*50);
            break;
        case 6:
            MoveCreature(grid, row, col+1);
            balancer.setPosition(row*50,(col+1)*50);
            break;
        case 7:
            MoveCreature(grid, row+1, col+1);
            balancer.setPosition((row+1)*50,(col+1)*50);
            break;
        default:
            break;
    }
    delete temp;
    transform(grid);//call transform
}
//Precondition: called by the caller, get grid
//Postcondition: balancer doesnt breed
void Balancer::breed(Creature* grid[][MAX])
{
    //EMPTY

}
//Precondition: called by the caller, get grid
//Postcondition: balancer doesnt die
void Balancer::die(Creature* grid[][MAX])
{
    //empty
}
//Precondition: called by the caller, get grid from it
//Postcondition: turns either an empty spot or none wall object around it into a prey or hunter if there is none left in the grid
void Balancer::transform(Creature* grid[][MAX])
{
    bool haveHunter = false, havePrey = false;
    int row = GetRow();
    int col = GetCol();
    for (int i = 0; i < MAX; i ++)//check if theres still hunter and prey left
    {
        for (int j = 0; j < MAX; j ++)
        {
            if (grid[i][j]->IsPrey())
                havePrey = true;
            if (grid[i][j]->IsHunter())
                haveHunter = true;
        }
    }
    if (!havePrey || !haveHunter)//no prey or hunter left on the grid
    {
        //transformed = true;
        int randomNum = rand() % 8;//get the random spot
        //cout << randomNum << endl;
        switch (randomNum)//transform creature
        {
            case 0:
                if (grid[row-1][col-1] == NULL || grid[row-1][col-1]->Getface() != 'W')
                {
                    cout << "case 0\n";
                    delete grid[row-1][col-1];
                    grid[row-1][col-1] = NULL;
                    if (!havePrey)
                        grid[row-1][col-1] = new Prey(row-1, col-1);
                    if (!haveHunter)
                        grid[row-1][col-1] = new Hunter(row-1, col-1);
                }
                break;
            case 1:
                if (grid[row][col-1] == NULL || grid[row][col-1]->Getface() != 'W')
                {
                    cout << "case 1\n";
                    delete grid[row][col-1];
                    grid[row][col-1] = NULL;
                    if (!havePrey)
                        grid[row][col-1] = new Prey(row, col-1);
                    if (!haveHunter)
                        grid[row][col-1] = new Hunter(row, col-1);
                }
                break;
            case 2:
                if (grid[row+1][col-1] == NULL || grid[row+1][col-1]->Getface() != 'W')
                {
                    delete grid[row+1][col-1];
                    grid[row+1][col-1] = NULL;
                    if (!havePrey)
                        grid[row+1][col-1] = new Prey(row+1, col-1);
                    if (!haveHunter)
                        grid[row+1][col-1] = new Hunter(row+1, col-1);
                }
                break;
            case 3:
                if (grid[row-1][col] == NULL || grid[row-1][col]->Getface() != 'W')
                {
                    delete grid[row-1][col];
                    grid[row-1][col] = NULL;
                    if (!havePrey)
                        grid[row-1][col] = new Prey(row-1, col);
                    if (!haveHunter)
                        grid[row-1][col] = new Hunter(row-1, col);
                }
                break;
            case 4:
                if (grid[row+1][col] == NULL || grid[row+1][col]->Getface() != 'W')
                {
                    delete grid[row+1][col];
                    grid[row+1][col] = NULL;
                    if (!havePrey)
                        grid[row+1][col] = new Prey(row+1, col);
                    if (!haveHunter)
                        grid[row+1][col] = new Hunter(row+1, col);
                }
                break;
            case 5:
                if (grid[row-1][col+1] == NULL || grid[row-1][col+1]->Getface() != 'W')
                {
                    delete grid[row-1][col+1];
                    grid[row-1][col+1] = NULL;
                    if (!havePrey)
                        grid[row-1][col+1] = new Prey(row-1, col+1);
                    if (!haveHunter)
                        grid[row-1][col+1] = new Hunter(row-1, col+1);
                }
                break;
            case 6:
                if (grid[row][col+1] == NULL || grid[row][col+1]->Getface() != 'W')
                {
                    delete grid[row][col+1];
                    grid[row][col+1] = NULL;
                    if (!havePrey)
                        grid[row][col+1] = new Prey(row, col+1);
                    if (!haveHunter)
                        grid[row][col+1] = new Hunter(row, col+1);
                }
                break;
            case 7:
                if (grid[row+1][col+1] == NULL || grid[row+1][col+1]->Getface() != 'W')
                {
                    delete grid[row+1][col+1];
                    grid[row+1][col+1] = NULL;
                    if (!havePrey)
                        grid[row+1][col+1] = new Prey(row+1, col+1);
                    if (!haveHunter)
                        grid[row+1][col+1] = new Hunter(row+1, col+1);
                }
                break;
            default:
                break;
        }
    }
    /*
    if (!havePrey)
    {
        delete grid[row][col];
        grid[row][col] = NULL;
        grid[row][col] = new Prey(row, col);
        transformed = true;
    }
    else if (!haveHunter)
    {
        delete grid[row][col];
        grid[row][col] = NULL;
        grid[row][col] = new Hunter(row, col);
        transformed = true;
    }
    */
}
//Precondition: called by the caller, get RenderWindow window from it
//Postcondition: prints the face of the object and draw it.
void Balancer::show(sf::RenderWindow& window)
{
    cout << face;
    window.draw(balancer);
}
void Balancer::setPosition(int row, int col)
{
    //empty
}
