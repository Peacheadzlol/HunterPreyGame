#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    cout << "About to create the Grid object\n";
    Grid g(1,1,1);//one hunter, one prey, one balancer
    cout << "About to go into run function\n";
    g.run();
    //morshed
    return 0;
}
