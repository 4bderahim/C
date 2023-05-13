#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int i, j, height = 19 , width = 19;
int gameover, score;
int x, y, fruitx, fruity,flag,spd, game_spd = 20;

void draw()
{
    system("cls");
    printf("\t\t\t\tScore = %d\n", score);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1
                || j == 0
                || j == height - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y){
                    if (flag == 2) printf("<");
                    else if (flag == 1) printf("^");
                    else if (flag == 3) printf(">");
                    else if (flag == 4) printf("|");
                    else printf("|");}
                else if (i == fruitx
                         && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("press X to quit the game");
}

void generate_fruit(){
    lab1:
        fruitx = rand() % 20;
        if (fruitx == 0)
                goto lab1;
    lab2:
        fruity = rand()%20;
        if (fruity == 0)
                goto lab2;
}

void setup(){
    gameover = 0;
    x = height/2;
    y = width /2;
    label1:
        fruitx = rand() % 20;
        if (fruitx == 0)
                goto label1;
    label2:
        fruity = rand()%20;
        if (fruity == 0)
                goto label2;
    score = 0;
}

void snake_speed(){

    while (!spd){
            for (int i= 0; i <= 35;i++){
                printf("\n K to start.\n O to decrease speed.\n P to increase speed.\n SNAKE SPEED: %d\nTEST: ", (110-game_spd));


                    Sleep(game_spd);
                    for (int p = 0 ; p < 28 ;p++){

                            if (i == p) printf("##>");
                            else printf(" ");
                            }

            system("cls");
            }
            if ( kbhit() ){
                    switch(getch()){
                        case 'o':
                            if (game_spd <= 90) game_spd += 10;
                            break;

                        case 'p':
                            if (game_spd >= 20) game_spd -= 10;
                            break;
                        case 'k':
                            spd = 1;
                            break;
                            }
                        }
                    }
}


void input(){
    if(kbhit()){
            switch(getch()){
                case 'w':
                    flag = 1;
                    break;

                case 'a':
                    flag = 2;
                    break;

                case 'd':
                    flag = 3;
                    break;

                case 's':
                    flag = 4;
                    break;

                case 'x':
                    gameover = 1;
                    break;
            }
    }
}


void game_logic(){

    Sleep(game_spd);
    switch(flag){
    case (1):
        x--;

        break;

    case 2:
        y--;
        break ;

    case 3:
        y++;
        break;

    case 4:
        x++;
        break;

    default:
        break;
    }
    if (x == 0 || x == height || y == 0 || y == width) gameover = 1;
    if (x == fruitx && y == fruity){
            label1:
        fruitx = rand() % 19;
        if (fruitx == 0)
                goto label1;
    label2:
        fruity = rand()%19;
        if (fruity == 0)
                goto label2;
            score += 10;
            generate_fruit();
    }
}

int main(){
    snake_speed();
    if (!spd) return 0;
    setup();
    while(!gameover){
            draw();
            input();
            game_logic();

    }
    return 0;
}
