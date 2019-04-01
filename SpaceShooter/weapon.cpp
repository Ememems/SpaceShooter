#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "weapon.h"

using namespace std;

Weapon::Weapon(int posX, int posY,int lastYpos,int randLoc, float shipWeaponV,float alienWeaponV){
    positionX=posX;
    positionY=posY;
    lastYposition=lastYpos;
    shipWeaponSpeed=shipWeaponV;
    alienWeaponSpeed=alienWeaponV;
    randomLocation=randLoc;

}
Weapon::~Weapon(){}

void Weapon::printImage(){
    setcolor(MAGENTA);
    rectangle(positionX-3,positionY-50,positionX+3,positionY);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(positionX,(positionY-5),MAGENTA);
}
void Weapon::resetImage(){
    setcolor(BLACK);
    rectangle(positionX-3,positionY-50,positionX+3,positionY);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(positionX,(positionY-5),BLACK);
}
void Weapon::randomize(){
    srand(time(NULL));
    randomLocation=rand()%13;
}



