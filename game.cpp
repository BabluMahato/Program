/**
 header file inclusion
*/

#include <iostream>
#include <stdlib.h> 
#include <ctime>
#include <string.h>
#include <map>
using namespace std;

/**
 Global Data variable declearation 
*/

/* Stores the player score */
int PlayerScore = 0;

/*  Stores Computer score */
int ComputerScore = 0;

/* Counts total number of game */
int count = 0;

/* maps to map input and symbol */
map<int , string> input_map{{1,"Rock"},{2, "Paper"},{3, "Scissor"}};


/** 
    Input and output format

    input format 
    symbol                              input
    -------------------------------------------
    Fist(Rock)                          ----> 1
    Open hand(Paper)                    ----> 2
    Index of middle finger(Scissors)    ----> 3
     for every game 
      1. input symbol
      2. Press 0 to exit or any key to continue    

    output format
    -------------
    for every game
        Game no.  Player input    Computer input     winner

    After  all the game
    total game   Player score     Computer score     winner
*/



/**
 Functions
*/

int PlayerInput()
{
    int countInput = 0;
    unsigned int PlayerChoice;

    /* Display  input choice */
    cout << "Select input "<<endl;
    cout << "1 : Rock "<< endl;
    cout << "2 : Paper "<< endl;
    cout << "3 : Scissors "<< endl;

    /* do while loop is intended for taking vaild input */
    do
    {
        if(countInput > 0)
        {
            cout << " select valid input"<<endl;
        }
        cin >> PlayerChoice;
        countInput ++;

    }while(PlayerChoice != 1 && PlayerChoice != 2 && PlayerChoice != 3);

    return PlayerChoice;
}

int ComputeInput()
{
    int ComputerChoice;
    
    /*
        Seed random number generator with time so that 
        random number will be actually random at every time 
    */
    srand(time(0));

    /* take computer choice %3 ao that it will be in range (0,1,2) + 1 */
    ComputerChoice = rand() % 3 + 1 ; 

    return ComputerChoice;
}

void PrintResult(int PlayerChoice, int ComputerChoice)
{
    cout<< "Game no." << "\tPlayer input " << "\t\tComputer input" << "\t\t winner" <<endl;
    cout<< count << "\t\t" << input_map[PlayerChoice] << "\t\t\t" << input_map[ComputerChoice] << "\t\t\t";

    if(PlayerChoice == 1  && ComputerChoice == 3)
    {
        cout << " player  "<<endl;
        PlayerScore++;
    }
    else if(PlayerChoice == 2  && ComputerChoice == 1)
    {
        cout << " player "<<endl;
        PlayerScore++;
    }
    else if(PlayerChoice == 3  && ComputerChoice == 2)
    {
        cout << " player "<<endl;
        PlayerScore++;
    }
    else if(PlayerChoice == ComputerChoice)
    {
        cout<< " tie ! "<<endl;
    }
    else
    {
        cout<<" computer  "<<endl;
        ComputerScore++;
    }
}

int main()
{
    int ComputerChoice, PlayerChoice; 

    while(true)
    {
        count++;

        ComputerChoice = ComputeInput();
        PlayerChoice = PlayerInput();

        PrintResult(PlayerChoice, ComputerChoice);

        /* press any key to continue , 0 for exit */
        char ch;
        cout<<"\npress --> 0 to exit \nany key to continue\n";
        cin>>ch;
        if(x == '0')
        {
            break;
        }

        /* 
            Clear Screen after every game
            The first one (\033[2J) clears the entire screen (J) from top to bottom (2).
            The second code (\033[1;1H) positions the cursor at row 1, column 1.
        */
        cout << "\033[2J\033[1;1H";

    }

    /* Print Final Score */
    cout<< "total game" << "\tPlayer score " << "\tComputer score" << "\twinner" <<endl;
    cout<< count << "\t\t" << PlayerScore << "\t\t" << ComputerScore << "\t\t";
 
    if(ComputerScore == PlayerScore)
    {
        cout << "Tie "<<endl;
    }
    else if(ComputerScore > PlayerScore)
    {
        cout<<"Computer "<<endl;
    }
    else
    {
        cout<<"Player"<<endl;
    }

}