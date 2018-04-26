#include <stdio.h>

//Function prototypes
void gridfill( int *choicePtr, char *board, int *ctrPtr, char *xPtr );
void grid( char *board);

//Main function
int main(){
    char x;                                                             //Holds the character chosen by a player
    char *xPtr = &x;                                                    //Pointer to the address of X
    int ctr;                                                            //Used in counter of the main for loop
    int *ctrPtr = &ctr;                                                 //Pointer to the counter ctr
    int ctr1;                                                           //For loop counter variable
    int player = 0;                                                     //Store the current player of the game
    int selected[10] = {0};                                             //Stores the choices made during the game play
    int choice = 0;                                                     //Holds the choice that the player keys in
    int *choicePtr;                                                     //Pointer to the choice variable
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};     //This is the structure of the grid in the game. It stores the character choices made
    choicePtr = &choice;                                                //Assigns the address of choice to the pointer choicePtr
    char *boardPtr = &board[0][0];                                      //Assigns the address of boad to pointer boardPtr
    
    printf("Welcome to Tic Tac Toe by Bruss\n Enjoy!\n\n");

    printf("This is a two player game. Played on a three by three grid.\n");
    printf("One player plays with the character 'X' and the other with the character 'O'.\n");
    printf("The goal of the game is to have a set of three characters in a continuous straight, vertically, horizontally or diagonally.\n");
    printf("Player 1 starts the game. the game play is alternate, one player plays after the other.\n");
    printf("The game ends if one player wins or when all the cells are filled. If no player wins the game ends at draw.\n");

    printf("Player 1 is X\nPlayer 2 is O\n\n");

    printf("Choose the grid (1-9) you want to place in.\n\n");

    for( ctr = 9; ctr > 0; ctr--){
        
        //if statements that checks if a player has won.
        if( board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
            board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
            board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
            board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
            board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
            board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' ||
            board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
            board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X' 
        ){
            puts("\nPlayer 1 won.");        //Prints out player one has won
            break;                          //Ends the game when player one wins
        }
        else if( board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' || 
                 board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
                 board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
                 board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
                 board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
                 board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' ||
                 board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
                 board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O' 
        ){
            puts("\nPlayer 2 won.");        //Prints out player two has won
            break;                          //Ends the game when player one wins
        }

        printf("You have %d choices left.\n\n",ctr);        //Prints out the remaining number of choices the player can make

        scanf("%d",choicePtr);                //accepts the players choice
        
    //for loop to check if the choice made had been selected before
        for( ctr1 = 0; ctr1 < 10; ctr1++){
            if( *choicePtr == selected[ctr1]){                  //compares the current choice with the previous choices
                printf("Choice unavailable\n");                 
                printf("Make another choice\n");            //Gives instructions to make another choice
                
                if(player == 0){            //checks if the current player is 0 
                    player = 1;             //Resets the player to the previous player 1 so that the choice remains unchanged
                    ctr++;                  //increments the ctr variable thats supposed to decrement the loop
                    break;                  //ends the loop
                }
                else if( player == 1){      //checks if the current player is 1 
                    player = 0;             //Resets the player to the previous player 0 so that the choice remains unchanged
                    ctr++;                  //increments the ctr variable thats supposed to decrement the loop
                    break;                  //ends the loop
                }
                
            }
        }
        
        selected[ctr] = *choicePtr; //assigns the value of the players choice to the index of the selected array
       
        
    //The players choice
        if(player == 0){        //checks if it's player 1 to fill the grid with an X
            x = 'X';            //sets the character to X
            gridfill(&choice, boardPtr, &ctr, &x );         //fills the grid with the selected grid index
            
            grid( boardPtr );             //Prints the filled grid
            player = 1;         //sets the player to 1 for the second player 
        }
        else if(player == 1){   //checks if it's player 2 to fill the grid with an O
            x = 'O';            //sets the character to O
            gridfill(&choice, boardPtr, &ctr, &x );         //fills the grid with the selected grid index
            
            grid( boardPtr );             //Prints the filled grid
            player = 0;         //sets the player to 0 for the first player 
        }        

    }
    puts(" ");                  //Prints a new line   

    grid( boardPtr );           //Prints the final grid after the game ends
}

//Fills the grid with the players selection
void gridfill( int *choicePtr, char *board, int *ctrPtr, char *xPtr ){
    switch( *choicePtr ){
        case 1:
        *board = *xPtr;
        break;
        case 2:
        *(board + 1) = *xPtr;
        break;
        case 3:
        *(board + 2) = *xPtr;
        break;
        case 4:
        *(board + 3) = *xPtr;
        break;
        case 5:
        *(board + 4) = *xPtr;
        break;
        case 6:
        *(board + 5) = *xPtr;
        break;  
        case 7:
        *(board + 6) = *xPtr; 
        break;
        default:
        case 8:
        *(board + 7) = *xPtr;
        break;
        case 9:
        *(board + 8) = *xPtr;
        break;
        puts("Invalid choice");
        *ctrPtr++;
        break;
    }
}

//Prints out the updated grid
void grid( char *board ){
    printf(" %c | %c | %c  \n - - - - - \n %c | %c | %c  \n - - - - - \n %c | %c | %c \n\n",
    *(board), *(board + 1), *(board + 2),*(board + 3),*(board + 4),*(board + 5),*(board + 6),*(board + 7),*(board + 8));
}



