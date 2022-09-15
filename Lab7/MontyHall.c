//
//  MontyHall.c
//  
//
//  Created by Shen, Zhengyi on 9/15/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // Where is the grand prize?
    srand( time(NULL) );
    int choice = -1;
    int prize = rand() % 3; // 0 <= rand() <= 32767
    int not_prize[2] = {(prize + 1) % 3, (prize + 2) % 3};
    int prompt = -1;
    char door_switch = 'n';
    int door_to_switch = -1;
    
    printf("\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" ** Monty Hall Simulator **\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("    ╔═════╦═════╦═════╗\n");
    printf("    ║     ║     ║     ║\n");
    printf("    ║  1  ║  2  ║  3  ║\n");
    printf("    ║     ║     ║     ║\n");
    printf("    ╚═════╩═════╩═════╝\n");
    printf("\n");
    
    // Ask contestant to pick a door
    printf("Please Pick a Door\n");
    scanf("%d", &choice);
    choice--;
    
    printf("You chose Door %d\n", choice + 1);
    
    //if the prize was picked, then choose a door that is not the prize
    if (choice == prize) {
        int door = rand() % 2;
        prompt = not_prize[door];
        
        if (prompt == not_prize[0]) {
            door_to_switch = not_prize[1];
        }
        else {
            door_to_switch = not_prize[0];
        }
    }
    
    //if the prize was not picked, then pick the other door without the prize
    else {
        if (choice == not_prize[0]) {
            prompt = not_prize[1];
        }
        else if (choice == not_prize[1]) {
            prompt = not_prize[0];
        }
        door_to_switch = prize;
    }
    
    printf("The prize is not behind Door %d\n", prompt + 1);
    printf("Would you like to switch from Door %d to Door %d? (y/n)\n", choice + 1, door_to_switch + 1);
    
    //get the choice whether to switch doors or not
    scanf(" %c", &door_switch);
    
    if (door_switch == 'y') {
        printf("You chose to switch to Door %d\n", door_to_switch + 1);
        choice = door_to_switch;
    }
    else {
        printf("You chose to stick with Door %d\n", choice + 1);
    }
    
    //compare final selection with the prize
    if (choice == prize) {
        printf("\n");
        printf(" =-=-=-=-=You Won!-=-=-=-=-\n");
        printf("\n");
    }
    
    else {
        printf("\n");
        printf(" =-=-=-=-=You Lost-=-=-=-=-\n");
        printf("\n");
    }
    
    printf("    ╔═════╦═════╦═════╗\n");
    printf("    ║     ║     ║     ║\n");
    
    switch(prize){
        case 0:
            printf("    ║ 🐐  ║  2  ║  3  ║\n");
            break;
        case 1:
            printf("    ║  1  ║ 🐐  ║  3  ║\n");
            break;
        case 2:
            printf("    ║  1  ║  2  ║ 🐐  ║\n");
            break;
    }
    
    printf("    ║     ║     ║     ║\n");
    printf("    ╚═════╩═════╩═════╝\n");
    printf("\n");
    
}
