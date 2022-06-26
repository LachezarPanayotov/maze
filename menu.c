#include <stdio.h>
#include <stdlib.h>
#include "read_from_file.c"
#include "traversal_by_user.c"

int main(){
    int choice;
    while(1){
        system("cls");
        printf("1. Read from file\n");
        printf("2. Traversal by user\n");
        printf("3. Traversal by computer\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        proverka:
            scanf("%d",&choice);
            if(!(choice >= 1 && choice <= 4)){
                printf("Number must be between 1 and 4: ");
                goto proverka;
            }
        system("cls");
        switch(choice){
            case 1:
                read_and_print("maze.txt");
                printf("\nPress any key to go back to menu...");
                getch();
                break;
            case 2 :
                traversal_by_user(10, 13, maze);
                printf("\nPress any key to go back to menu...");
                getch();
                break;
            case 3:
                printf("\nPress any key to go back to menu...");
                getch();
                break;
            case 4 :
                exit(0);
        }
    }
    return 0;
}
