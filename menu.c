#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice;
    while(1){
        system("cls");
        printf("1. Read from file\n");
        //Kazaha mi da napisha traversal (v sluchai che e greshno, NEVINEN SUM)
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
                break;
            case 2 :
                break;
            case 3:
                break;
            case 4 :
                exit(0);
        }
    }
    return 0;
}
