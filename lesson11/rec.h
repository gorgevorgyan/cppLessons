#pragma once

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::pow;

class ReactAng{
    private:
        int aX;
        int aY;
        int bX;
        int bY;
        int cX;
        int cY;
        int a = 0;
        int b = 0;
    public:
        void setupRectangle(int aX1, int aY1, int cX1, int cY1){
            bY = cY1;
            bX = aX1;
            a = pow(pow(aX1 - bX, 2) + pow(aY1 - bY, 2), 0.5);
            b = pow(pow(bX - cX1, 2) + pow(bY - cY1, 2), 0.5);

        }
        void getInfo(){
            cout << "Width is " << a << " Height is " << b << endl;
        }
};