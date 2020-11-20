#include <iostream>
#include <cmath>

using std::sqrt;
using std::cout;
using std::cin;
using std::endl;

struct treeAngle{
    int a;
    int b;
    int c;
};

struct rectAng{
    int width;
    int height;
};

struct  circle{
    int r;
};

float * findAreas(treeAngle* treeAngle, rectAng* rectAng, circle* circle){
    float * areas = new float[3];
    float p = ((treeAngle->a + treeAngle->b + treeAngle->c) / 2);
    float treeArea = sqrt(p * (p - treeAngle->a) * (p - treeAngle->b) * (p - treeAngle->c));
    areas[0] = treeArea;
    areas[1] = rectAng->height * rectAng->width;
    areas[2] = circle->r * circle->r; 
    return areas;
}

bool checkTreeAngle(int a, int b, int c){
    return (a + b > c && b + c > a && a + c > b);
}

void setupTreeAngle(treeAngle* treeAng, int a, int b, int c){
    treeAng->a = a;
    treeAng->b = b;
    treeAng->c = c;
}

void setupRectAng(rectAng* rectA, int height, int width){
    rectA->height = height;
    rectA->width = width;
}

void setupCircle(circle* Circ, int r){
    Circ->r = r;
}

int main(){

    treeAngle treeAngle1;
    rectAng rectAng1;
    circle circle1;
    int sides[6]{};
    
    for(int i = 0; i < 6; i++){
        cout << "Write the side " << ((i < 3) ? i + 1 : (i < 5) ? i - 2 : 1) << " Of " <<  ((i < 3) ? "Treeangle: " : (i < 5) ? "Rectangle: " : "Circle: ");
        cin >> sides[i];
        if(i == 2 && !checkTreeAngle(sides[0], sides[1], sides[2])){
            cout << "The treeangle does not exists" << endl;
            return 0;
        }
    }
    
    setupTreeAngle(&treeAngle1, sides[0], sides[1], sides[2]);
    setupRectAng(&rectAng1, sides[3], sides[4]);
    setupCircle(&circle1, sides[5]);
    float * adrArea = findAreas(&treeAngle1, &rectAng1, &circle1);
    for(int i = 0; i < 3; i++)
        cout << "The are of " << ((!i) ? "treeangle " : (i == 1) ? "rectangle " : "circle ")  << " is " << adrArea[i] << endl;
    return 0;

}