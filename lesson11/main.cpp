#include <iostream>

#include "tree.h"
#include "rec.h"
#include "circle.h"

using std::cin;

int main(){
    TreeAng tr;
    ReactAng ra;
    Circle c;
    int sides[6]{};
    int sidesR[4]{};
    int sidesC[4]{};
    cout << "Setup Treeangle" << endl;
    for(int i = 0; i < 6; i++)
        cin >> sides[i];
    tr.setupTree(sides[0], sides[1], sides[2], sides[3], sides[4], sides[5]);
    tr.getInfo();
    cout << "Setup Rectangle " << endl;
    for(int i = 0; i < 4; i++)
        cin >> sidesR[i];
    ra.setupRectangle(sidesR[0], sidesR[1], sidesR[2], sidesR[3]);
    ra.getInfo();
    cout << "Setup Circle " << endl; 
    for(int i = 0; i < 4; i++)
        cin >> sidesC[i];
    c.setupCircle(sidesC[0], sidesC[1], sidesC[2], sidesC[3]);
    c.getInfo();

}