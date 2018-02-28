/*
 * By giahuy2201
 * Date: Feb 26, 2018
 */

#include <iostream>

int match(int *icoor, int *coor);

int main()
{
    int *icoor = new int[6]; // to store 2 inital point
    std::cout << "Enter intial points: ";
    for(int i=0; i< 6;i++) // read 6 numbers one by one
    {
        std::cin >> icoor[i];
    }

    while(true) // let user enter the third number to check (for multiple-choice test :D)
    {
        int *coor = new int[3]; // to store the point
        std::cout << "\n\nType a point: ";
        for(int i=0; i< 3;i++)
        {
            std::cin >> coor[i];
        }
        if(match(icoor, coor)) // if it fit two initial points -> DONE
        {
            std::cout << "-> TRUE";
        }
    }

    return 0;
}

int match(int *icoor, int *coor)
{
    /*
     * to check if the third point with coordinates in coor array is fit the inital points.
     */
    float y = (float)(icoor[1]*coor[0] - coor[1]*icoor[0]) / (icoor[1]*icoor[3] - icoor[0]*icoor[4]); // solve the 2-unknown equation to get x and y
    float x = (coor[0] - icoor[3]*y) / icoor[0];

    std::cout << "\nx: " << x << " y: " << y; // let user know the unknowns' value
    int c = icoor[2]*x + icoor[5]*y; // calculate the expected result

    if(c == coor[2]) // compare and DONE
    {
        return true;
    }
    return false;
}