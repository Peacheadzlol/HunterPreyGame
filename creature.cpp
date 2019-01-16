#include "creature.h"
#include <iostream>
#include "constant.h"
using namespace std;

//Precondition: called by the caller
//Postcondition: returns the face
char Creature::Getface()
{
    return face;
}
//Precondition: called by the caller
//Postcondition: constructor of the creature class
Creature::Creature(int i, int j, char f)
{
    row = i;
    col = j;
    face = f;
    stepBreed = 0;
    moved = true;
}
//Precondition: called by the caller, get grid from it
//Postcondition: virtual move function that calls its children's move function
void Creature::move(Creature* grid[][MAX])
{
    //cout << "Creature move function reached\n";
    moved = true;
    //empty
}
//Precondition: called by the caller, get grid from it
//Postcondition: virtual breed function that calls its children's breed function
void Creature::breed(Creature* grid[][MAX])
{
    //cout << "Creature breed function reached\n";
    stepBreed = 0;
}
//Precondition: called by the caller, get grid from it
//Postcondition: virtual die function that calls its children's die function
void Creature::die(Creature* grid[][MAX])
{
    //cout << "Creature die function reached\n";
    grid[row][col] = NULL;
}
//Precondition: called by the caller
//Postcondition: returns row
int Creature::GetRow()
{
    return row;
}
//Precondition: called by the caller
//Postcondition: returns col
int Creature::GetCol()
{
    return col;
}
//Precondition: called by the caller
//Postcondition: check if the face is a prey
bool Creature::IsPrey()
{
    //cout << "Creature IsPrey function reached\n";
    if (this == NULL)
    {
        //cout <<"this == NULL\n";
        return false;
    }
    else if (face == 'P')
    {
        //cout << "It is Prey\n";
        return true;
    }
    else
    {
        //cout << "It is not Prey\n";
        return false;
    }
}
//Precondition: called by the caller
//Postcondition: check if the face is hunter
bool Creature::IsHunter()
{
    //cout << "Creature IsHunter function reached\n";
    if (this == NULL)
    {
        //cout <<"this == NULL\n";
        return false;
    }
    else if (face == 'H')
    {
        //cout << "It is Hunter\n";
        return true;
    }
    else
    {
        //cout << "It is not Hunter\n";
        return false;
    }
}
//Precondition: called by the caller, get grid from it
//Postcondition: find the empty spots around the object and numbered their locations inside of the int array, return the int pointer of the array back
int* Creature::OpenSpots(Creature* grid[][MAX])
{
    //cout << "Creature OpenSpots function reached\n";
    int* temp = new int[9];//save the last spot for -1, end of the array
    int row = GetRow();
    int col = GetCol();
    int index = 0;
    if (grid[row-1][col-1] == NULL)
    {
        temp[index] = 0;
        index ++;
    }
    if (grid[row][col-1] == NULL)
    {
        temp[index] = 1;
        index ++;
    }
    if (grid[row+1][col-1] == NULL)
    {
        temp[index] = 2;
        index ++;
    }
    if (grid[row-1][col] == NULL)
    {
        temp[index] = 3;
        index ++;
    }
    if (grid[row+1][col] == NULL)
    {
        temp[index] = 4;
        index ++;
    }
    if (grid[row-1][col+1] == NULL)
    {
        temp[index] = 5;
        index ++;
    }
    if (grid[row][col+1] == NULL)
    {
        temp[index] = 6;
        index ++;
    }
    if(grid[row+1][col+1] == NULL)
    {
        temp[index] = 7;
        index ++;
    }
    temp[index] = -1;
    return temp;
}
//Precondition: called by the caller get int* array
//Postcondition: returns the random number selected
int Creature::RandomSpot(int* array)
{
    //cout << "Creature RandomSpots function reached\n";
    int size = 0;
    while (array[size] != -1)
    {
        size ++;//find size of the array
    }
    if (size == 0)
    {
        return -1;
    }
    else
    {
        int randomNum = rand() % size;
        int temp = array[randomNum];
        //delete [] array;
        return temp;
    }
}
//Precondition: called by the caller, get grid, and row and col from it
//Postcondition: move the creature to the location given on the grid
void Creature::MoveCreature(Creature* grid[][MAX], int r, int c)
{
    //cout << "Creature MoveCreature function reached\n";
    if (!moved && grid[r][c] == NULL)
    {
        grid[r][c] = grid[row][col];
        grid[row][col] = NULL;
        row = r;
        col = c;
        stepBreed ++;
    }
    moved = true;
}
//Precondition: called by the caller
//Postcondition: returns stepBreed
int Creature::GetBreedStep()
{
    return stepBreed;
}
//Precondition: called by the caller
//Postcondition: resets moved to false
void Creature::ResetMoved()
{
   moved = false;
}
//Precondition: called by the caller
//Postcondition: returns moved
bool Creature::ItMoved()
{
    return moved;
}
//Precondition: called by the caller, get RenderWindow window from it
//Postcondition: virtual show fuction that calls its children's show functions
void Creature::show(sf::RenderWindow &window)
{
    //virtual function
}
void Creature::setPosition(int r, int c)
{

}
