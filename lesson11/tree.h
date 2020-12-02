#pragma once

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::pow;

class TreeAng{
    private:
        int aX;
        int aY;
        int bX;
        int bY;
        int cX;
        int cY;
        int a = 0;
        int b = 0;
        int c = 0;
    
    public:
        void setupTree(int aX1, int aY1, int bX1, int bY1, int cX1, int cY1){
            int aT = pow(pow(aX1 - bX1, 2) + pow(aY1 - bY1, 2), 0.5);
            int bT = pow(pow(bX1 - cX1, 2) + pow(bY1 - cY1, 2), 0.5);
            int cT = pow(pow(aX1 - cX1, 2) + pow(aY1 - cY1, 2), 0.5);
            if (aT > bT && bT > cT && cT > aT){
                a = aT;
                b = bT;
                c = cT;
            }
            else
                cout << "Error" << endl;
        }
        void getInfo(){
            if(a && b && c)
                cout << "A: " << a << " B: " << b << " C: " << c << endl;
            else
                cout << "First setup treeangle" << endl;
        }
};