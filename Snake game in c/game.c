#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=20,width=20,x,y,fruitX,fruitY,flag,gameEnd,Score;
int tailX[100],tailY[100];
int body=0;
void snakemovement() {
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx=tailX[0];
    prevy=tailY[0];
    tailX[0]=x;  
    tailY[0]=y;
    for (i=1;i<=body;i++) {
        prev2x=tailX[i];
        prev2y=tailY[i];
        tailX[i]=prevx;
        tailY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag) {
        case 1: {
            x--;
            break;
        }
        case 2: {
            x++;
            break;
        }
        case 3: {
            y--;
            break;
        }
        case 4: {
            y++;
            break;
        }
    }
    if(x==0 || x==height || y==0 || y==height) {
        gameEnd =1;
    } if(x==fruitX && y==fruitY ) {
        label3:
    fruitX=rand()%20;
    if(fruitX == 0){
        goto label3;
    } 

    label4:
    fruitY=rand()%20;
    if(fruitY==0){
        goto label4;
    }
    Score+=1;
    body++;
    }

}
void input() {
    if(kbhit()) {
        switch(getch()) {
            case 'w':{
                flag=1;
                break; 
            }
            case 's':{
                flag=2;
                break; 
            }
            case 'a':{
                flag=3;
                break; 
            }
            case 'd':{
                flag=4;
                break; 
            }
        }
    }
}
void setup () {
    x=height/2;
    y=width/2;
    
    label1:
    fruitX=rand()%20;
    if(fruitX == 0){
        goto label1;
    } 

    label2:
    fruitY=rand()%20;
    if(fruitY==0){
        goto label2;
    } 
    gameEnd=0;
    Score=0;
    




}

void draw () {
    
    system("cls");
    int i,j,k,ch;

    for(int i=0;i<=height;i++) {
        for (int j=0;j<=width;j++){
            if(i==0||i==height||j==0||j==height) {
                printf("*");
                }else{
                    if(i==x && j==y){
                        printf("0");
                    } else if(i==fruitX && j==fruitY){
                        printf("@");
                    }else{
                            ch=0;
                           for(k=0;k<body;k++) {
                            if(i==tailX[k] && j==tailY[k]){
                                printf("o");
                                ch=1;
                            }
                           }
                           if(ch==0) {
                        printf(" ");
                           }
                        }


                    }
        }
     printf("\n");
    }
    printf("Your score is %d",Score);
}
void setup ();
void input();
void draw ();
void snakemovement();
int main () {
setup();
while(gameEnd!=1){
input();
draw();
snakemovement();
}


    return 0;
}


