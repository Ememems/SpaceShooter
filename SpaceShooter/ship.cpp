#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "ship.h"

using namespace std;
Ship::Ship(int startPosX, int startPosY, int liv, int p){//startPos/startPos-pozycja pocz.x/y
positionX=startPosX;
positionY=startPosY;
lives=liv;
points=p;
}
Ship::~Ship(){
}

void Ship::printImage(){
    if(positionX>110&&positionX<1812){//right-left colision
        if(positionY>50&&positionY<919){//up-down colision.
            int shipBody=16, shipWindow=5;
            int model[shipBody*2]={positionX,positionY,positionX+15,positionY+26,positionX+15,positionY+46,positionX+60,positionY+67,positionX+60,positionY+87,positionX+15,positionY+66,positionX+15,positionY+82,positionX+26,positionY+103,positionX-26,positionY+103,positionX-14,positionY+82,positionX-14,positionY+66,positionX-60,positionY+87,positionX-60,positionY+66,positionX-14,positionY+46,positionX-14,positionY+26,positionX,positionY};
            int okno[shipWindow*2]={positionX-4,positionY+11,positionX+4,positionY+11,positionX+7,positionY+18,positionX-7,positionY+18,positionX-4,positionY+11};
            setcolor(RED);
            drawpoly(shipBody,model);
            setfillstyle(SOLID_FILL,RED);
            floodfill(positionX,(positionY+4),RED);
            setcolor(BLUE);
            drawpoly(shipWindow,okno);
            setfillstyle(SOLID_FILL,BLUE);
            floodfill(positionX,(positionY+12),BLUE);
        }
    }
}

void Ship::resetImage(){
    if(positionX>110&&positionX<1812){//right-left colision
        if(positionY>50&&positionY<919){//up-down colision
            int shipBody=16, shipWindow=5;
            int model[shipBody*2]={positionX,positionY,positionX+15,positionY+26,positionX+15,positionY+46,positionX+60,positionY+67,positionX+60,positionY+87,positionX+15,positionY+66,positionX+15,positionY+82,positionX+26,positionY+103,positionX-26,positionY+103,positionX-14,positionY+82,positionX-14,positionY+66,positionX-60,positionY+87,positionX-60,positionY+66,positionX-14,positionY+46,positionX-14,positionY+26,positionX,positionY};
            int okno[shipWindow*2]={positionX-4,positionY+11,positionX+4,positionY+11,positionX+7,positionY+18,positionX-7,positionY+18,positionX-4,positionY+11};
            setcolor(BLACK);
            drawpoly(shipBody,model);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(positionX,(positionY+4),BLACK);
            setcolor(BLACK);
            drawpoly(shipWindow,okno);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(positionX,(positionY+12),BLACK);
        }
    }
}

void Ship::animation(){
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    rectangle(positionX-70,positionY+1,positionX+70,positionY+104);
    floodfill(positionX+20,positionY+20,RED);
    delay(40);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(positionX-70,positionY+1,positionX+70,positionY+104);
    floodfill(positionX+20,positionY+20,YELLOW);
    delay(40);;
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    rectangle(positionX-70,positionY+1,positionX+70,positionY+104);
    floodfill(positionX+20,positionY+20,BLACK);

}

