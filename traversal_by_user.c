#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void traversal_by_user(int size_row, int size_column, char maze[size_row][size_column]){
    int row = 1;
    int column = 0;
    maze[row][column] = 'P';
    print_maze(size_row, size_column, maze);
    while(1){
        switch(getch()){
            case 72:
                if(maze[row - 1][column] == 'X'){
                    printf("Can't go there\n");
                    continue;
                }else{
                    maze[row][column] = ' ';
                    row--;
                    maze[row][column] = 'P';
                    system("cls");
                    print_maze(size_row, size_column, maze);
                }

                break;

            case 80:
                if(maze[row + 1][column] == 'X'){
                    printf("Can't go there\n");
                    continue;
                }else{
                    maze[row][column] = ' ';
                    row++;
                    maze[row][column] = 'P';
                    system("cls");
                    print_maze(size_row, size_column, maze);
                }

                break;

            case 75:
                if((column - 1) >= 0){
                    if(maze[row][column - 1] == 'X'){
                        printf("Can't go there\n");
                        continue;
                    }else{
                        maze[row][column] = ' ';
                        column--;
                        maze[row][column] = 'P';
                        system("cls");
                        print_maze(size_row, size_column, maze);
                    }
                }else{
                    printf("Can't go there\n");
                }

                break;

            case 77:
                if(maze[row][column + 1] == 'X'){
                    printf("Can't go there\n");
                    continue;
                }else if(maze[row][column + 1] == 'E'){
                    system("cls");
                    printf("Congrats! You finished the maze");
                    exit(0);
                }else{
                    maze[row][column] = ' ';
                    column++;
                    maze[row][column] = 'P';
                    system("cls");
                    print_maze(size_row, size_column, maze);
                }

                break;
        }
    }
}

void print_maze(int size_row, int size_column, char maze[size_row][size_column]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 13; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char maze[10][13] = {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {' ',' ','X',' ','X',' ','X',' ',' ',' ',' ',' ','X'},
        {'X',' ','X',' ',' ',' ','X',' ','X','X','X',' ','X'},
        {'X',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X'},
        {'X',' ','X',' ',' ',' ',' ',' ','X','X','X',' ','X'},
        {'X',' ','X',' ','X','X','X',' ','X',' ',' ',' ','X'},
        {'X',' ','X',' ','X',' ',' ',' ','X','X','X',' ','X'},
        {'X',' ','X',' ','X','X','X',' ','X',' ','X',' ','X'},
        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','E'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','X'}
    };

    traversal_by_user(10, 13, maze);
    return 0;
}
