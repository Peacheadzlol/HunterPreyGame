#include "prey.h"
//Precondition: called by the caller
//Postcondition: create the prey object and also its parent portion
Prey::Prey(int row, int col)
    : Creature(row, col, 'P')
{
    prey.setFillColor(sf::Color::Green);//set color
    prey.setSize(sf::Vector2f(50,50));//set size
    prey.setPosition(row*50, col*50);
}
//Precondition: called by the caller
//Postcondition: move the prey object to a random empty spot around it, if there is no empty spot, it doesnt move
void Prey::move(Creature* grid[][MAX])
{
    //cout << "Prey move function reached\n";
    int row = GetRow();
    int col = GetCol();
    int* temp = OpenSpots(grid);//find empty spots
    int moveTo = RandomSpot(temp);//get random spot
    switch (moveTo)//move to that spot
    {
        case 0:
            MoveCreature(grid, row-1, col-1);
            prey.setPosition((row-1)*50,(col-1)*50);
            break;
        case 1:
            MoveCreature(grid, row, col-1);
            prey.setPosition(row*50,(col-1)*50);
            break;
        case 2:
            MoveCreature(grid, row+1, col-1);
            prey.setPosition((row+1)*50,(col-1)*50);
            break;
        case 3:
            MoveCreature(grid, row-1, col);
            prey.setPosition((row-1)*50,col*50);
            break;
        case 4:
            MoveCreature(grid, row+1, col);
            prey.setPosition((row+1)*50,col*50);
            break;
        case 5:
            MoveCreature(grid, row-1, col+1);
            prey.setPosition((row-1)*50,(col+1)*50);
            break;
        case 6:
            MoveCreature(grid, row, col+1);
            prey.setPosition(row*50,(col+1)*50);
            break;
        case 7:
            MoveCreature(grid, row+1, col+1);
            prey.setPosition((row+1)*50,(col+1)*50);
            break;
        default:
            break;
    }
    delete temp;
    breed(grid);//call breed function
}
//Precondition: called by the caller
//Postcondition: breed one prey for every 3 steps and place the new prey randomly around the breeder prey
void Prey::breed(Creature* grid[][MAX])
{
    //cout << "Prey breed function reached\n";
    if (GetBreedStep() >= 3)
    {
        int row = GetRow();
        int col = GetCol();
        int* temp = OpenSpots(grid);//get the empty spots
        int moveTo = RandomSpot(temp);//get the random spot
        switch(moveTo)//breed the prey at the random spot
        {
            case 0:
                grid[row-1][col-1] = new Prey(row-1, col-1);
                grid[row-1][col-1]->setPosition((row-1)*50,(col-1)*50);
                //prey.setPosition((row-1)*50,(col-1)*50);
                Creature::breed(grid);
                break;
            case 1:
                grid[row][col-1] = new Prey(row, col-1);
                grid[row][col-1]->setPosition(row*50,(col-1)*50);
                Creature::breed(grid);
                //prey.setPosition(row*50,(col-1)*50);
                break;
            case 2:
                grid[row+1][col-1] = new Prey(row+1, col-1);
                grid[row+1][col-1]->setPosition((row+1)*50,(col-1)*50);
                Creature::breed(grid);
                //prey.setPosition((row+1)*50,(col-1)*50);
                break;
            case 3:
                grid[row-1][col] = new Prey(row-1, col);
                grid[row-1][col]->setPosition((row-1)*50,col*50);
                Creature::breed(grid);
                //prey.setPosition((row-1)*50,col*50);
                break;
            case 4:
                grid[row+1][col] = new Prey(row+1, col);
                grid[row+1][col]->setPosition((row+1)*50,col*50);
                Creature::breed(grid);
                //prey.setPosition((row+1)*50,col*50);
                break;
            case 5:
                grid[row-1][col+1] = new Prey(row-1, col+1);
                grid[row-1][col+1]->setPosition((row-1)*50,(col+1)*50);
                Creature::breed(grid);
                //prey.setPosition((row-1)*50,(col+1)*50);
                break;
            case 6:
                grid[row][col+1] = new Prey(row, col+1);
                grid[row][col+1]->setPosition(row*50,(col+1)*50);
                Creature::breed(grid);
                //prey.setPosition(row*50,(col+1)*50);
                break;
            case 7:
                grid[row+1][col+1] = new Prey(row+1, col+1);
                grid[row+1][col+1]->setPosition((row+1)*50,(col+1)*50);
                Creature::breed(grid);
                //prey.setPosition((row+1)*50,(col+1)*50);
                break;
            default:
                break;
        }
    }
}
//Precondition: called by the caller
//Postcondition: prey doesnt die
void Prey::die(Creature* grid[][MAX])
{
    //cout << "Prey die function reached\n";
    //empty
}
//Precondition: called by the caller
//Postcondition: print the prey face and draw it
void Prey::show(sf::RenderWindow &window)
{
    cout << face;
    //window.clear();
    window.draw(prey);
}
void Prey::setPosition(int row, int col)
{
    prey.setPosition(row, col);
}
