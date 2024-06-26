#include<iostream>
using namespace std;
void display_board(char** board, int rows, int columns);
void Working_for_players_turn (char** board, int rows, int columns);
void checks(char** board, int rows, int columns, int move);
int main ()
{
	int rows,columns;
	cout<<"Enter number of rows"<<endl;
	cin>>rows;
	cout<<"Enter number of columns"<<endl;
	cin>>columns;

 char** board = new char*[rows];
  for (int i = 0; i < rows; i++) 
  {
    board[i] = new char[columns];
    for (int j = 0; j < columns; j++) 
	{
      board[i][j] = '_';
    }
  }
		
	Working_for_players_turn(board, rows, columns);
	for (int i = 0; i < rows; i++) 
	{
    delete[] board[i];
	}
    delete[] board;
	
}


void display_board(char** board, int rows, int columns)
{

for(int i=0;i<rows;i++)
{
	for(int j=0;j<columns;j++)
	{
		cout<<board[i][j]<<" ";
	}
	cout<<endl;
}
cout<<endl;
}
  

    


void Working_for_players_turn (char** board, int rows, int columns)
{
	display_board(board, rows, columns);	

	
	int move;
	int set;
	int player=2;
		while(1)
		{
		set=rows-1;
		cout<<"This is the turn of player "<<((player%2)+1)<<endl;
		cout<<"player "<<((player%2)+1)<<"choice a column between 0 to"<<(columns-1)<<endl;
		cin>>move;
		if(player%2!=0)
		{
		for(int i=0;i=rows,set>=0;i++,set--)
		{
				
		if(board[set][move]=='_')
		{
			board[set][move]='+';
			display_board(board, rows, columns);
			checks(board, rows, columns,move);
			break;
		}
		}
		if(board[0][move]!='_')
		{
		cout<<endl<<"The column is full please try another column"<<endl;
		cout<<endl;	
		continue;
		}
		}
		else if(player%2==0)
		{
		for(int i=0;i=rows,set>=0;i++,set--)
		{
			if(board[set][move]=='_')
		{
			board[set][move]='x';
			display_board(board, rows, columns);
			checks(board, rows, columns,move);
			break;
		}
		}
		if(board[0][move]!='_')
		{
		cout<<endl<<"The column is full please try another column"<<endl;	
		cout<<endl;
		continue;
		}
		}
		player++;
		}
}


void checks(char** board, int rows, int columns, int move)
{
   // Check if either player has won
  bool win = false;
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      char current = board[i][j];
      if (current != '_') {
        // Check horizontal
        if (j <= rows - 4) {
          win = true;
          for (int k = 1; k < 4; k++) {
            if (board[i][j + k] != current) {
              win = false;
              break;
            }
          }
        }
        if (win) {
          break;
        }

        // Check vertical
        if (i <= columns - 4) {
          win = true;
          for (int k = 1; k < 4; k++) {
            if (board[i + k][j] != current) {
              win = false;
              break;
            }
          }
        }
        if (win) {
          break;
        }

        // Check diagonal up-right
        if (i >= 3 && j <= rows - 4) {
          win = true;
          for (int k = 1; k < 4; k++) {
            if (board[i - k][j + k] != current) {
              win = false;
              break;
            }
          }
        }
        if (win) {
          break;
        }

        // Check diagonal up-left
        if (i >= 3 && j >= 3) {
          win = true;
          for (int k = 1; k < 4; k++) {
            if (board[i - k][j - k] != current) {
              win = false;
              break;
            }
          }
        }
        if (win) {
          break;
        }
      }
    }
    if (win) {
      break;
    }
  }
}
