#include <iostream>

int match(int *icoor, int *coor);


int main()
{
    int *icoor = new int[6];
    std::cout << "Enter intial points: ";
    for(int i=0; i< 6;i++)
    {
        std::cin >> icoor[i];
    }

    while(true)
    {
        int *coor = new int[3];
        std::cout << "\n\nType a point: ";
        for(int i=0; i< 3;i++)
        {
            std::cin >> coor[i];
        }
        if(match(icoor, coor))
        {
            std::cout << "-> TRUE";
        }
    }

    return 0;
}

int match(int *icoor, int *coor)
{
    int y = (icoor[1]*coor[0] - coor[1]*icoor[0]) / (icoor[1]*icoor[3] - icoor[0]*icoor[4]);
    int x = (coor[0] - icoor[3]*y) / icoor[0];
    std::cout << "\nx: " << x << " y: " << y;
    int c = icoor[2]*x + icoor[5]*y;

    if(c == coor[2])
    {
        return true;
    }
    return false;
}