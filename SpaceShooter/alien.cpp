#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "alien.h"


using namespace std;


Alien::Alien(float posX, float posY, bool h){
	positionX=posX;
	positionY=posY;
	hit=h;
}
Alien::~Alien(){}

void Alien::printImage(){
	 setcolor(GREEN);
     setfillstyle(SOLID_FILL,GREEN);
     int pointsAmount=6;
     int model[pointsAmount*2]={positionX,positionY,positionX+50,positionY,positionX+77,positionY+75,positionX+25,positionY+50,positionX-27,positionY+75,positionX,positionY};
     drawpoly(pointsAmount,model);
     floodfill((positionX+10),(positionY+50),GREEN);
     setcolor(BLUE);
     setfillstyle(SOLID_FILL,BLUE);
     rectangle(positionX+10,positionY+15,positionX+40,positionY+30);
     floodfill(positionX+20,positionY+20,BLUE);
}
void Alien::resetImage(){
	 setcolor(BLACK);
     setfillstyle(SOLID_FILL,BLACK);
     int pointsAmount=6;
     int model[pointsAmount*2]={positionX,positionY,positionX+50,positionY,positionX+77,positionY+75,positionX+25,positionY+50,positionX-27,positionY+75,positionX,positionY};
     drawpoly(pointsAmount,model);
     floodfill((positionX+10),(positionY+50),BLACK);
     setcolor(BLACK);
     setfillstyle(SOLID_FILL,BLACK);
     rectangle(positionX+10,positionY+15,positionX+40,positionY+30);
     floodfill(positionX+20,positionY+20,BLACK);
}
void Alien::animation(){
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    rectangle(positionX-27,positionY,positionX+85,positionY+76);
    floodfill(positionX+20,positionY+20,RED);
    delay(40);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(positionX-27,positionY,positionX+85,positionY+76);
    floodfill(positionX+20,positionY+20,YELLOW);
    delay(40);;
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    rectangle(positionX-27,positionY,positionX+85,positionY+76);
    floodfill(positionX+20,positionY+20,BLACK);
}
