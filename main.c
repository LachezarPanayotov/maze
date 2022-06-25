#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum{DOWN,RIGHT,UP, LEFT}way;

int size_row = 10;
int size_column = 13;
int maze[10][13] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,1,1,1,0,1},
    {1,0,0,0,1,1,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,1,1,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,0,0,1,1,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,2,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

void right_wall_hugging(int maze[size_row][size_column]){
    int way = 0;
    int r = 1;
    int c = 1;
    maze[1][1] = 9;
    for(int i = 0;i < size_row;i++){
        for(int j = 0;j < size_column;j++){
            printf(" %d ", maze[i][j]);
        }
        printf("\n");
    }
    while((r <= size_row - 2) && (c <= size_column - 2)){
        if(maze[r - 1][c]==2 || maze[r + 1][c]==2 || maze[r][c-1]==2 || maze[r][c+1]==2 ){
              break;
        }
        if(way == DOWN){
            if(maze[r][c - 1] == 0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
            else if(maze[r + 1][c] == 0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
            }
            else if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
            else{
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }
        }
        if(way == RIGHT){
            if(maze[r + 1][c] == 0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
            else if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
            }
            else if(maze[r - 1][c]){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }

            else{
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
        }
        else if(way == UP) {
            if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
            else if(maze[r - 1][c]==0){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
            }
            else if(maze[r][c - 1]==0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
            else{
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
        }
        else if(way == LEFT){
            if(maze[r - 1][c]==0){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }
            else if(maze[r][c - 1]==0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
            }
            else if(maze[r + 1][c]==0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
            else{
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
        }
        print_maze(maze);
    }
}

void print_maze(maze)
{

}

int main()
{
    right_wall_hugging(maze[10][13]);
    /*int way = 0;
    int r = 1;
    int c = 1;
    maze[1][1] = 9;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 13;j++){
            printf(" %d ", maze[i][j]);
        }
        printf("\n");
    }
    while((r <= 8) && (c <= 11)){
        if(maze[r - 1][c]==2 || maze[r + 1][c]==2 || maze[r][c-1]==2 || maze[r][c+1]==2 ){
              break;
        }
        if(way == DOWN){
            if(maze[r][c - 1] == 0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
            else if(maze[r + 1][c] == 0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
            }
            else if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
            else{
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }
        }
        if(way == RIGHT){
            if(maze[r + 1][c] == 0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
            else if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
            }
            else if(maze[r - 1][c]){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }

            else{
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
        }
        else if(way == UP) {
            if(maze[r][c + 1] == 0){
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
            else if(maze[r - 1][c]==0){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
            }
            else if(maze[r][c - 1]==0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
                way = LEFT;
            }
            else{
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
        }
        else if(way == LEFT){
            if(maze[r - 1][c]==0){
                maze[r][c] = 0;
                maze[r - 1][c] = 9;
                r--;
                way = UP;
            }
            else if(maze[r][c - 1]==0){
                maze[r][c] = 0;
                maze[r][c - 1] = 9;
                c--;
            }
            else if(maze[r + 1][c]==0){
                maze[r][c] = 0;
                maze[r + 1][c] = 9;
                r++;
                way = DOWN;
            }
            else{
                maze[r][c] = 0;
                maze[r][c + 1] = 9;
                c++;
                way = RIGHT;
            }
        }

        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 13;j++){
              if(maze[i][j]==9){
                printf("{%d}", maze[i][j]);
              }else{
                printf("-%d-" , maze[i][j]);
              }
            }
            printf("\n");
        }
        printf("--------------------------------------------\n");*/
};
