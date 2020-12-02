#pragma once

#include <iostream>
#include <cmath>

using std::pow;
using std::cout;
using std::endl;

class Circle{
    private:
        int rX;
        int rY;
        int dX;
        int dY;
        int R = 0;
    public:
        void setupCircle(int rX1, int rY1, int dX1, int dY1){
            R = pow(pow(rX - dX, 2) + pow(rY + dY, 2), 0.5);
        }
        void getInfo(){
            if(R)
                cout << "R is " << R << endl;
            else
                cout << "Error" << endl;
        }
};