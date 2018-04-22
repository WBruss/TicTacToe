#include <stdio.h>


void gridfill();
void grid();

//Global Variables
    int ctr, ctr1, ctr2;
    int choice = 0;
    int player = 0;
    char x = 'X';
    char o = 'O';
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int selected[10] = {0};

int main(){
    
    
    printf("Welcome to Tic Tac Toe by Bruss\n Enjoy!\n\n");

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

        scanf("%d",&choice);                //accepts the players choice
        
    //for loop to check if the choice made had been selected before
        for( ctr1 = 0; ctr1 < 10; ctr1++){
            if( choice == selected[ctr1]){                  //compares the current choice with the previous choices
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
        
        selected[ctr] = choice; //assigns the value of the players choice to the index of the selected array
       
        
    //The players choice
        if(player == 0){        //checks if it's player 1 to fill the grid with an X
            x = 'X';            //sets the character to X
            gridfill();         //fills the grid with the selected grid index
            
            grid();             //Prints the filled grid
            player = 1;         //sets the player to 1 for the second player 
        }
        else if(player == 1){   //checks if it's player 2 to fill the grid with an O
            x = 'O';            //sets the character to O
            gridfill();         //fills the grid with the selected grid index
            
            grid();             //Prints the filled grid
            player = 0;         //sets the player to 0 for the first player 
        }
  
        

    }
    puts(" ");

   

    grid();
}

//Fills the grid with the players selection
void gridfill(){
    switch( choice ){
        case 1:
        board[0][0] = x;
        break;
        case 2:
        board[0][1] = x;
        break;
        case 3:
        board[0][2] = x;
        break;
        case 4:
        board[1][0] = x;
        break;
        case 5:
        board[1][1] = x;
        break;
        case 6:
        board[1][2] = x;
        break;  
        case 7:
        board[2][0] = x; 
        break;
        case 8:
        board[2][1] = x;
        break;
        case 9:
        board[2][2] = x;
        break;
        default:
        puts("Invalid choice");
        ctr++;
        player = 0;
        break;
    }
}

//Prints out the updated grid
void grid(){
    printf(" %c | %c | %c  \n - - - - - \n %c | %c | %c  \n - - - - - \n %c | %c | %c \n\n",
    board[0][0],board[0][1],board[0][2],board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
}



