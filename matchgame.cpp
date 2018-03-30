//============================================================================
// Name        : BPokhrel5.cpp
// Author      : Baivab Pokhrel
// Version     :
// Copyright   : Your copyright notice
// Description : Match Game
//============================================================================

//command to make it sleep for 3 seconds
#ifdef __WIN32__
#include <windows.h>

#define sleep(n) Sleep(1000 * n)
#endif

#ifdef __APPLE__
#include <unistd.h>
#endif
#include <iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
void printBoard(  const vector< vector <string> >&);//funtion used to print the gameboard used in the game
int main()
{
    srand(time(NULL));//to enerate diffferent random numbers
    int tr =0,tr1=0;//to input numbers and alphabeta into double vectors
    int row;//input for row
    int column;//inut for column
    int product=0;///int to store product of rows and column
    int pairs=0;//to calculate time
    int time1=0;//to store time
    int seconds=0;//to calculate seconds
    int firstView,secondView;//input to store to numbers of our shown vector
    int timer1=0,timer2=0;//timer to keep track of time
    int time2=0;//time to store the tie elapsed
    int seconds1;//seconds to store seonds elapsed
    int xa,ya,xb,yb;//int to store the index of first and second view
    vector<vector<string> > showBoard;//vector to store numbers which is visible to user
    vector<vector<string> > hiddenBoard;//vectors to store alphabets which is not visible to user
    vector<vector<string> > displayBoard;//a copy of showBoard to temporarily display the board if the case of not matching slots
    vector<string> try1;//a vector used to make 2-d vector
    vector<string> try2={" 1"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10","11","12","13", "14","15" ,"16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60",
                         "61","62","63","64"};//vetor containing 64 digits in the form of alphabets
    vector<string> try3={" A"," B"," C"," D"," E"," F"," G"," H"," I"," J"," K"," L"," M"," N"," O"," P"," Q"," R"," S"," T"," U","     V"," W"," X"," Y"," Z"," [" ," /", " ]" ," ^" ," _", " `"   } ;//vector containg 26 alphabets with 6 following alphabets
    vector<string> try4;//vector used to make 2-d vector
    vector<string> try5;//vector used to make 2-d vector
   //introduction to the game
    cout<<"In this game, pairs of letters will be hidden on a rectangular grid."<<endl;
    cout<<"Once the grid is established you will be asked to enter the number of two slots."<<endl;
    cout<<"If the letters at those slots match, they will stay in view"<<endl;
    cout<<"If not, after 3 seconds the letters will disappear and be replaced by the numbers."<<endl;
    cout<<"You job is find all the pairs.\n\n\n"<<endl;
    
    
    //prompt for user input of rows and column
    cout<<"Size requirement of row x col must be beteen 16 and 64 and be even"<<endl;
    cout<<"Enter rows:"<<endl;
    cin>>row;
    cout<<"Enter columns:"<<endl;
    cin>>column;
    product=row*column;
    while(product<16 || product>64 || product%2!=0)//loop if the product of rows and column is not a desired number
    {
        cout<<"Size requirement of row x col must be beteen 16 and 64 and be even"<<endl;
        cout<<"Enter rows:"<<endl;
        cin>>row;
        cout<<"Enter columns:"<<endl;
        cin>>column;
        product=row*column;
        }

    for(int k=0;k<(product/2);k++)//loop make a vetor withh required number of alphabets twice
    {
        try4.push_back(try3[k]);
        try4.push_back(try3[k]);
    }
    
    for (int i=1; i<=row; i++)//loop to make a 2-d vector of hidden board which contais required number of rows and column
    {
        
        for (int j=1; j<=column; j++) {
            int index=rand()%try4.size();//keeping alphabets in random index
            try5.push_back(try4[index]);
            try4.erase(try4.begin() + index);
            
        }
        
        hiddenBoard.push_back(try5);//pushig back a 1-d vector to a 2-d vector
        try5.clear();
    }
    
    for (int i=1; i<=row; i++)//1-d vector containing all the required numbers
    {
        
        for (int j=1; j<=column; j++) {
            try1.push_back(try2[tr]);//pushibg back required numbers into a 1-d vectors
            tr++;
            
        }
        
        showBoard.push_back(try1);//pushing back 1-d vector to make a 2-d vector of numbers
        try1.clear();
    }
    
    //to give user a prompt of time limit
    pairs=product/2;
    time1= (pairs*30)/60;
    seconds=(pairs*30)%60;
    cout<<"\n\nAllowing 30 seconds per pair\nYou will have "<<time1<<" minutes "<<seconds<<" seconds "<<" to find "<<pairs<<" pairs."<<endl;
    cout<<"Let's play\n"<<endl;
	printBoard(showBoard);//printing a visible board
    
    
    

    while(true)//infinite loop running over whole program with break statement below
          {
              timer1=time(0);//timer number 1 which starts at the beginning of loop
              displayBoard.insert(displayBoard.end(), showBoard.begin(), showBoard.end());//copying shw=owBoard to displayBoard whihc is cleared again at the end of loop

              
              cout<<"\n\nEnter first slot of view"<<endl;//first prompt
              cin>>firstView;//first input
              while(firstView > product || firstView < 1)//if the first input is not a desired number
              {
                  cout<<"Enter first slot of view"<<endl;//re-prompt
                  cin>>firstView;
                  
              }
              cout<<"Enter second slot of view"<<endl;//second prompt
              cin>>secondView;//second input
              while(secondView > product || secondView < 1||secondView==firstView)//if the second input is not a desired number
              {
                  cout<<"Enter second slot of view"<<endl;//re-prompt
                  cin>>secondView;
                  
              }
              xa=(firstView-1)/column;//to get first index of first slot
              ya=(firstView-1)%column;//to get second index of first slot
              xb=(secondView-1)/column;//to get first index of second slot
              yb=(secondView-1)%column;//to get second index of second slot
              if(showBoard[xa][ya]==hiddenBoard[xa][ya]&&showBoard[xb][yb]==hiddenBoard[xb][yb])//if statement to check if the digits were already previouly matched
              {
                  printBoard(showBoard);
                  cout<<"\nPreviously Matched"<<endl;//prompt
                  
              }
              
              else if(hiddenBoard[xa][ya]==hiddenBoard[xb][yb])//else of if to see if the slots match
              {
                  
                  
                  //replacing those index of visible board with the hidden board's alphabets
                  showBoard[xa][ya]=hiddenBoard[xa][ya];
                  showBoard[xb][yb]=hiddenBoard[xb][yb];
                  printBoard(showBoard);//printing visible board
                  cout<<"\aMatch"<<endl;//prompt
                  if(showBoard==hiddenBoard)//to check if all the digits are already matched
                   //it is inside the match case because before all slots to match it should atleast have 1 index remaining to match
                  {
                      cout<<"\nAll matched within "<< time2/60<<" minutes and "<<time2%60<<" seconds."<<endl;//displaying how much time the user took
                      break;//break out of the infinite loop
                  }
                  sleep(3);//sleepign for 3 seconds
                  for(int m=0;m<100;m++)cout<<"\n";//printing 100 empty lines
                   printBoard(showBoard);
              }
            else if(hiddenBoard[xa][ya]!=hiddenBoard[xb][yb])//else of if to see if the slots do not match
              
              {
                //replacing those index of temporary display board with the hidden board's alphabets
                 displayBoard[xa][ya]=hiddenBoard[xa][ya];
                 displayBoard[xb][yb]=hiddenBoard[xb][yb];
                 printBoard(displayBoard);//printing temporary diplay board
                  cout<<"No Match"<<endl;//prompt
                  sleep(3);//sleep for 3 seconds
                 for(int m=0;m<100;m++)cout<<"\n";//printing 100 empty lines
                  printBoard(showBoard);
              }
              
              if(time2>pairs*30)//to check if the time elapsed is over the tie limit
              {
                  cout<<"\nTime has expired"<<endl;
                  cout<<"You revealed:"<< endl;
                  printBoard(showBoard);//revealing what user inputted
                  cout<<"\nAll the pairs were at:"<<endl;
                  printBoard(hiddenBoard);//revealing what the answer was
                  break;
                  
              }
              displayBoard.clear();//clear the display which was a temporary board
              tr1=0;
              
              timer2=time(0);
              seconds1=difftime(timer2,timer1);//to find the diffrence in time
              time2=time2+seconds1;//total time elapsed
              
          }
    
	
}

void printBoard( const vector< vector<string> >& board)//function to print a 2-d vector
{
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout<<board[i][j]<<"  ";
            
            
        }
        cout << "\n";
    }
}
