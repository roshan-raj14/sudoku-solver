// try by giving input all blank spaces, execution flow samajh aajayega

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, char value) 
{
    int n = board.size();

    for(int i=0; i<n; i++) 
    {
        //row check
        if(board[row][i] == value)
        return false;
            
        //col check
        if(board[i][col] == value) 
        return false;

        //3*3 box check
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
        return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board) 
{
    int n = board.size();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //check for empty cell
            if(board[i][j] == '.') 
            {
                //try to fill with values ranging from 1 to 9
                for(char val = '1'; val<='9'; val++) 
                {
                    //check for safety
                    if(isSafe(i, j, board, val)) 
                    {
                        //insert
                        board[i][j] = val;

                        //recursion sambal lega
                        bool remainingBoardSolution = solve(board);
                        if(remainingBoardSolution == true) 
                        {
                            return true; 
                        }
                        else 
                        {
                            //backtrack
                            board[i][j] = '.';
                        }
                    }
                }
                //if 1 se 9 tak koi bhi value se solution nahi nikla ,current cell pr, 
                //that means piche kahin pr galti hai, go back by returning false
                return false;
            }
        }
    }
    //all cells filled, no empty cells remaining
    return true;
}





void sudokuSolver(vector<vector<char>>& board) 
{
    solve(board);
}

int main()
{
    // vector<vector<char>> board = {{'.','8','6','4','7','.','9','.','3'},
    //                               {'.','.','.','9','.','1','.','8','.'},
    //                               {'1','.','.','.','3','8','.','.','4'},
    //                               {'.','5','.','.','.','.','4','.','9'},
    //                               {'.','.','3','5','.','9','.','6','2'},
    //                               {'2','9','1','.','.','6','.','.','8'},
    //                               {'.','.','2','8','1','.','.','.','.'},
    //                               {'8','1','.','3','.','4','7','.','.'},
    //                               {'4','3','.','2','6','.','.','.','.'}};
    
    vector<vector<char>> board(9,vector<char> (9));

    cout<<"Fill the board row-wise please!"<<endl;
    for(int i=0; i<9; i++)
    {
        cout<<"Enter your required clues and enter '.' for empty places"<<endl;
        for(int j=0; j<9; j++)
        {
            cin>>board[i][j];
        }
    }
    
    sudokuSolver(board);

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
