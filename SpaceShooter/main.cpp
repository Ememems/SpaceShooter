#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <sstream>
#include "ship.h"
#include "weapon.h"
#include "alien.h"

using namespace std;

void errorCheck(){
    int screenWidth=1912;
    int screenHeight=1072;
    int errorcode;
    initwindow(screenWidth,screenHeight);
    errorcode=graphresult();
    if(errorcode!=grOk){
        printf("Error %d BGI while window openning (%d,%d): %s\n",errorcode,screenWidth,screenHeight,grapherrormsg(errorcode));
        printf("Press any key to end program");
        getch();
    }
}

int catchKey(){
    int key;
    if(kbhit()!=0){
            key=getch();
            printf("\n%d\n%c\n",key,key);
}
return key;
}

void frame(int frameWidth, int frameHeight){
    setcolor(YELLOW);
    rectangle(0,0,frameWidth,frameHeight);
    setfillstyle(SLASH_FILL,YELLOW);
    floodfill(frameWidth/2,frameHeight/2,YELLOW);
    setcolor(DARKGRAY);
    rectangle(50,50,frameWidth-50,frameHeight-50);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(frameWidth/2,frameHeight/2,DARKGRAY);
}

void resetScreen(){
    setcolor(DARKGRAY);
    rectangle(51,51,1861,1021);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(851,416,DARKGRAY);
    setcolor(BLACK);
    rectangle(51,51,1861,1021);
}

int menu(int frameWidth, int frameHeight){
    resetScreen();
    frameWidth=frameHeight/2-100;
    frameHeight=frameHeight/2-100;
    int upDown=0;//Up-down arrows
    int control=5;//control variable
    int xChoiceFramePosition=851,yChoiceFramePosition=437;//menu choice frame position
    int key=0;
    setcolor(YELLOW);
    outtextxy(frameWidth,frameHeight,"New Game");
    outtextxy(frameWidth,frameHeight+40,"Difficulty level");
    outtextxy(frameWidth,frameHeight+80,"Load gam");
    outtextxy(frameWidth,frameHeight+120,"Help");
    outtextxy(frameWidth,frameHeight+160,"Exit");
    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
	do{
        if(kbhit()!=0){
            key=catchKey();
            if(key==80){
                if(yChoiceFramePosition-4+upDown<576){
                    setcolor(BLACK);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                    control--;
                    upDown+=40;
                    setcolor(YELLOW);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                }
            }
            if(key==72){
                if(yChoiceFramePosition-4+upDown>456){
                    setcolor(BLACK);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                    control++;
                    upDown-=40;
                    setcolor(YELLOW);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                }
            }
        }
	}while(key!=13);
return control;
}

int difficultyLevelsMenu(int frameWidth, int frameHeight){
frameWidth=frameWidth/2-100;
    frameHeight=frameHeight/2-100;
    int upDown=0;//up-down arrow
    int control=3;//control variable
    int xChoiceFramePosition=851,yChoiceFramePosition=437;
    int key=0;
    setcolor(YELLOW);
    outtextxy(frameWidth,frameHeight,"Easy");
    outtextxy(frameWidth,frameHeight+40,"Hard");
    outtextxy(frameWidth,frameHeight+80,"IMPOSSIBRU");
    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
	do{
        if(kbhit()!=0){
            key=catchKey();
            if(key==80){
                if(yChoiceFramePosition-4+upDown<496){
                    setcolor(BLACK);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                    control--;
                    upDown+=40;
                    setcolor(YELLOW);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                }
            }
            if(key==72){
                if(yChoiceFramePosition-4+upDown>456){
                    setcolor(BLACK);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                    control++;
                    upDown-=40;
                    setcolor(YELLOW);
                    rectangle(xChoiceFramePosition,yChoiceFramePosition-4+upDown,xChoiceFramePosition+200,yChoiceFramePosition+19+upDown);
                }
            }
        }
	}while(key!=13);
return control;
}

float level(int control){
    float speed;
    if(control==3) speed=1;
    if(control==2) speed=2;
    if(control==1) speed=18;
return speed;
}

void helpMenu(int xChoiceFramePosition, int yChoiceFramePosition,int helpMenuControl){
    setcolor(YELLOW);
    outtextxy(xChoiceFramePosition/2-650,yChoiceFramePosition/2-100,"Welcome in my game! Rules are simple. You control your ship with arrows on the keyboard, press space if you want to shoot, press z if you want to save game, if you let alien to hit you, ");
    if(helpMenuControl==0)
    outtextxy(xChoiceFramePosition/2-550,yChoiceFramePosition/2-75,"you loose one live, if you destroy alien vessel you get point. Remember, do not try to batter enemy vessels. That will destroy your ship!!! You can leave this game in any moment pressing 'esc'. To return to the menu press enter.");
    if(helpMenuControl==1)
    outtextxy(xChoiceFramePosition/2-550,yChoiceFramePosition/2-75,"you loose one live, if you destroy alien vessel you get point. Remember, do not try to batter enemy vessels. That will destroy your ship!!! You can leave this game in any moment pressing 'esc'. To return to game press enter.");
}

float alienPosition(int k, int alienNumber){
    int xPosition,i;
	if(alienNumber==0) xPosition=120+150*alienNumber;
	if(alienNumber==1) xPosition=120+150*alienNumber;
    if(alienNumber==2) xPosition=120+150*alienNumber;
    if(alienNumber==3) xPosition=120+150*alienNumber;
    if(alienNumber==4) xPosition=120+150*alienNumber;
    if(alienNumber==5) xPosition=120+150*alienNumber;
    if(alienNumber==6) xPosition=120+150*alienNumber;
    if(alienNumber==7) xPosition=120+150*alienNumber;
    if(alienNumber==8) xPosition=120+150*alienNumber;
    if(alienNumber==9) xPosition=120+150*alienNumber;
    if(alienNumber==10) xPosition=120+150*alienNumber;
    if(alienNumber==11) xPosition=120+150*alienNumber;
    if(alienNumber==12) xPosition=120+150*alienNumber;
return xPosition;
}

void saveGame(int shipXPosition,int shipYPosition, int points, int lives, float level, int hit[12]){
    struct structure{
        int shipXPosition;
        int shipYPosition;
		int points;
		int lives;
		float level;
        int hit[12];//hit
    } save;
    save.lives=lives;
	save.shipXPosition=shipXPosition;
	save.shipYPosition=shipYPosition;
	save.points=points;
	save.lives=lives;
	save.level=level;
    for(int i=0;i<12;i++){
            save.hit[i]=hit[i];
    }
    //for(int t=0;t<12;t++) printf("\nelement %d tablicy to: %d",t,save.hit[t]);
    FILE *file;
    file=fopen("save.dat","w");
    fwrite(&save,sizeof(structure),1,file);
    fclose(file);
}

void load(int *shipXPosition,int *shipYPosition, int *points, int *lives, float *level, int hit[12],int frameWidth,int frameHeight){
    int x=frameWidth/2-100;
    int y=frameHeight/2-100;
    struct structure{
        int shipXPosition;
        int shipYPosition;
		int points;
		int lives;
		float level;
        int hit[12];//hit
    } save;
    FILE *file;
    file=fopen("save.dat","r");
    if(file){
        fread(&save,sizeof(structure),1,file);
        fclose(file);
        *shipXPosition=save.shipXPosition;
		*shipYPosition=save.shipYPosition;
		*points=save.points;
		*lives=save.lives;
		*level=save.level;
         for(int i=0;i<12;i++){
			hit[i]=save.hit[i];
         }
         for(int q=0;q<12;q++) printf("\nelement %d tablicy to: %d",q,hit[q]);
        resetScreen();
        setcolor(YELLOW);
        outtextxy(x,y,"Game loaded succesly");
        delay(500);
    }else{
        resetScreen();
        setcolor(YELLOW);
        outtextxy(x,y,"There are no saves");
        delay(500);
    }
}

void showLives(int lives,int xChoiceFramePosition, int yChoiceFramePosition){
    int livesXPosition,livesYPosition;
    int pointsAmount=7;
    livesXPosition=xChoiceFramePosition-212;
    livesYPosition=yChoiceFramePosition-992;
    setcolor(YELLOW);
    outtextxy(livesXPosition,livesYPosition,"lives: ");
    livesXPosition+=25;
        for(int i=0;i<lives;i++){
            livesXPosition+=20;
            int model[pointsAmount*2]={livesXPosition,livesYPosition,livesXPosition+6,livesYPosition+6,livesXPosition+12,livesYPosition,livesXPosition+15,livesYPosition+3,livesXPosition+6,livesYPosition+11,livesXPosition-3,livesYPosition+3,livesXPosition,livesYPosition};
            setcolor(YELLOW);
            drawpoly(pointsAmount,model);
            setfillstyle(SOLID_FILL,YELLOW);
            //floodfill(x+6,(y+10),YELLOW);
        }
}

void hideLives(int lives,int xChoiceFramePosition, int yChoiceFramePosition){
    int livesXPosition,livesYPosition;
    int pointsAmount=7;
    livesXPosition=xChoiceFramePosition-212;
    livesYPosition=yChoiceFramePosition-992;
    setcolor(YELLOW);
    outtextxy(livesXPosition,livesYPosition,"lives: ");
    livesXPosition+=25;
        for(int i=0;i<lives;i++){
            livesXPosition+=20;
            int model[pointsAmount*2]={livesXPosition,livesYPosition,livesXPosition+6,livesYPosition+6,livesXPosition+12,livesYPosition,livesXPosition+15,livesYPosition+3,livesXPosition+6,livesYPosition+11,livesXPosition-3,livesYPosition+3,livesXPosition,livesYPosition};
            setcolor(BLACK);
            drawpoly(pointsAmount,model);
            setfillstyle(SOLID_FILL,BLACK);
            //floodfill(x+6,(y+10),BLACK);
        }
}

int winCheck(int winControl, int winControlResult){
    if(winControl==0) winControlResult-=1;
    if(winControl!=0) winControlResult+=0;
return winControlResult;
}

void endGameWin(int xChoiceFramePosition, int yChoiceFramePosition, int flag){
    if(flag==0){
    int key;
    resetScreen();
    setcolor(YELLOW);
    outtextxy(xChoiceFramePosition/2-75,yChoiceFramePosition/2-100,"Victory!!!");
    outtextxy(xChoiceFramePosition/2-150,yChoiceFramePosition/2-75,"If you want to exit press 'esc'");
    do{
        if(kbhit()!=0){
            key=catchKey();
            switch(key){
            case 27:
            exit(0);
            }
        }
	}while(kbhit()==0);
}
}

void endGameLoss(int xChoiceFramePosition, int yChoiceFramePosition, int flag){
    int key;
    if(flag==0){
    resetScreen();
    setcolor(YELLOW);
    outtextxy(xChoiceFramePosition/2-100,yChoiceFramePosition/2-100,"You Lose!!!");
    outtextxy(xChoiceFramePosition/2-150,yChoiceFramePosition/2-75,"If you want to exit press 'esc'");
    do{
        if(kbhit()!=0){
            key=catchKey();
            switch(key){
            case 27:
            exit(0);
            }
        }
	}while(kbhit()==0);
}
}

int main(){
	int key,menuControl,levelControl, screenWidth=1912, screenHeight=1072,i,j,k,l,f,h,g,weaponControl1=0,weaponControl2=0,weaponControl3=0,weaponControl4=0,winControl1=1,winControl2=0,menuControl2=0,points=0;;// st zmienna sterujaca menu V-zmienna odpowiedzialna za aktualizacje shipYPositioncji potworkow i level trudosci. i-steruje bronia.weaponControl1-zmienna sterujaca bronia,winControl1/winControl2-sterujaca wygrana;
	int saveTab[13];
	char pointsTab[20];
	errorCheck();
	frame(screenWidth,screenHeight);
	Ship ncc1701; //Krotka ktora zapamietam
    Weapon shipWeapon,alienWeapon;//
    Alien *alien=new Alien[20];
    ident1:
    menuControl=menu(screenWidth,screenHeight);
    if(menuControl==5){
        ident3:
        menuControl=5;
        resetScreen();
        showLives(ncc1701.lives,screenWidth,screenHeight);
        ncc1701.printImage();
            for(i=0;i<12;i++){
                if(alien[i].hit==1){
                alien[i].printImage();
                }
                alien[i+1].positionX=alien[i].positionX+150;
            }
        alienWeapon.positionX=120;
        alienWeapon.positionY=246;
    }
    if(menuControl==4){
        resetScreen();
        levelControl=difficultyLevelsMenu(screenWidth,screenHeight);
        alienWeapon.alienWeaponSpeed=level(levelControl);
        goto ident1;
    }
    if(menuControl==3){
        resetScreen();
        load(&ncc1701.positionX,&ncc1701.positionY,&ncc1701.points,&ncc1701.lives,&alienWeapon.alienWeaponSpeed,saveTab,screenWidth,screenHeight);
        for(h=0;h<12;h++) alien[h].hit=saveTab[h];
        //for(int a=0;a<12;a++) printf("\nelement %d tablicy to: %d",a,p[a].hit);
        goto ident3;

    }
    if(menuControl==2){
        menuControl2=0;
        ident2:
        resetScreen();
        do{
        helpMenu(screenWidth,screenHeight,menuControl2);
        if(kbhit()!=0){
            key=catchKey();
            if(key==13){
                menuControl=0;
                resetScreen();
                goto ident1;
            }
            if(key==113){
                menuControl=0;
                resetScreen();
                goto ident3;
        }
        }
        }while(key!=13);
    }
while(menuControl==5&&key!=27){
        if(kbhit()!=0){
            key=catchKey();
                 switch(key){
                    case 77:
                        if(ncc1701.positionX<1800){
                            ncc1701.resetImage();
                            ncc1701.positionX+=5;
                        }
                        break;
                    case 75:
                        if(ncc1701.positionX>115){
                            ncc1701.resetImage();
                            ncc1701.positionX-=5;
                        }
                        break;
                    case 72:
                        if(ncc1701.positionY>55){
                            ncc1701.resetImage();
                            ncc1701.positionY-=5;
                        }
                        break;
                    case 80:
                        if(ncc1701.positionY<914){
                            ncc1701.resetImage();
                            ncc1701.positionY+=5;
                        }
                        break;
                    case 32:
                        weaponControl1=1;
                        shipWeapon.positionX=ncc1701.positionX;
                        shipWeapon.positionY=ncc1701.positionY;
                        weaponControl3=101;
                        weaponControl4=102;
                        break;
                    case 59:
                        menuControl2=1;
                        goto ident2;
                        break;
                    case 122:
                        setcolor(YELLOW);
                        outtextxy(screenWidth/2-100,screenHeight/2-100,"save...");
                        delay(500);
                        setcolor(BLACK);
                        outtextxy(screenWidth/2-100,screenHeight/2-100,"save...");
                        for(f=0;f<12;f++) saveTab[f]=alien[f].hit;
                        saveGame(ncc1701.positionX,ncc1701.positionY,ncc1701.points,ncc1701.lives,alienWeapon.alienWeaponSpeed,saveTab);
                }
                ncc1701.printImage();
        }
     for(l=0;l<12;l++){
     if((shipWeapon.positionX-3>alien[l].positionX-35&&shipWeapon.positionX+3<alien[l].positionX+82)&&(alien[l].hit==1)){
        weaponControl3=246;
        weaponControl4=247;
     }
     }
     if(shipWeapon.positionY>weaponControl3){
        if(weaponControl1==1){
            shipWeapon.resetImage();
            shipWeapon.positionY-=shipWeapon.shipWeaponSpeed;
            shipWeapon.printImage();
        for(k=0;k<12;k++){
        if((shipWeapon.positionX-3>alien[k].positionX-35&&shipWeapon.positionX+3<alien[k].positionX+82)&&((shipWeapon.positionY>=alien[k].positionY+120)&&(shipWeapon.positionY<=alien[k].positionY+130))&&(alien[k].hit==1)){
            alien[k].resetImage();
            alien[k].animation();
            alien[k].hit=0;
            ncc1701.points+=1;
        }
    }
        }
    }
    if(shipWeapon.positionY<=weaponControl4) shipWeapon.resetImage();
//________________________________________________________________________
    //for(j=0;j<12;j++)
    alienWeapon.positionX=alienPosition(alien[j].hit,alienWeapon.randomLocation);
    if(alienWeapon.positionY<1021){
        alienWeapon.resetImage();
        alienWeapon.positionY+=alienWeapon.alienWeaponSpeed;
        alienWeapon.printImage();
        }
    if(alienWeapon.positionY==1020){
        alienWeapon.resetImage();
        alienWeapon.positionY=246;
        ident4:
        alienWeapon.randomize();
        if(alien[alienWeapon.randomLocation].hit==0) goto ident4;
        }
    if(alienWeapon.positionX-3>ncc1701.positionX-60&&alienWeapon.positionX+3<ncc1701.positionX+60||ncc1701.positionY==alien[1].positionY+80){
        if(((((alienWeapon.positionX-3>=ncc1701.positionX-15)&&(alienWeapon.positionX+3<=ncc1701.positionX+15)))&&((alienWeapon.positionY>=ncc1701.positionY-10)&&(alienWeapon.positionY<=ncc1701.positionY+10)))||ncc1701.positionY==alien[1].positionY+80){
        alienWeapon.resetImage();
        alienWeapon.positionY=246;
        alienWeapon.randomize();
        ncc1701.resetImage();
        ncc1701.animation();
        delay(500);
        ncc1701.printImage();
        delay(500);
        ncc1701.resetImage();
        delay(500);
        ncc1701.printImage();
        delay(500);
        ncc1701.resetImage();
        delay(500);
        ncc1701.printImage();
        hideLives(ncc1701.lives,screenWidth,screenHeight);
        ncc1701.lives-=1;
        showLives(ncc1701.lives,screenWidth,screenHeight);
        }
        if(((alienWeapon.positionX-3>=ncc1701.positionX-60)&&(alienWeapon.positionX<=ncc1701.positionX+60))&&((alienWeapon.positionY>=ncc1701.positionY+46)&&(alienWeapon.positionY<=ncc1701.positionY+60))){
        alienWeapon.resetImage();
        alienWeapon.positionY=246;
        alienWeapon.randomize();
        ncc1701.resetImage();
        ncc1701.animation();
        delay(500);
        ncc1701.printImage();
        delay(500);
        ncc1701.resetImage();
        delay(500);
        ncc1701.printImage();
        delay(500);
        ncc1701.resetImage();
        delay(500);
        ncc1701.printImage();
        hideLives(ncc1701.lives,screenWidth,screenHeight);
        ncc1701.lives-=1;
        showLives(ncc1701.lives,screenWidth,screenHeight);
        }
    }
setcolor(YELLOW);
sprintf(pointsTab,"%d",ncc1701.points);
outtextxy(1700,100,"points: ");
outtextxy(1750,100,pointsTab);
outtextxy(1400,60,"ESC  <-  Exit");
outtextxy(1550,60,"F1 <-  Help");
outtextxy(1700,60,"Z  <-  Save");
winControl1=12;
for(g=0;g<12;g++) winControl1=winCheck(alien[g].hit,winControl1);
endGameWin(screenWidth, screenHeight, winControl1);
endGameLoss(screenWidth,screenHeight,ncc1701.lives);
//printf("\nstg: %d",stg);
}
//________________________________________________________________________
return 0;
}
