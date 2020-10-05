// Luke Underwood
// 9/28/2020
// Project_4 for CS311
// counthsw.cpp
// source file for countHSW_recurse and supporting functions

// std library inclusions
#include <vector>

// other inclusions
#include "counthsw.h"

// countHSW function
// counts the number of possible holey spider walks on a given board
// a board has a hole and a finish
// every spot must be visited except the hole, which must not be
// parameters are x and y values of the board size, hole, start, and finish
// in that order each passed as two ints
// PRECONDITIONS : ***ALL*** parameters must be nonegative integers
//                 The x coordinates of the hole, start, and finish must be < dim_x
//                 The y coordinates of the hole, start, and finish must be < dim_y
//                 As a result of the previous three assertions, dim_x and dim_y must be > 0
int countHSW(const int& dim_x, const int& dim_y,
             const int& hole_x, const int& hole_y,
             const int& start_x, const int& start_y,
             const int& finish_x, const int& finish_y)
{
    Board_Type board = createBoard(dim_x + 2, dim_y + 2, 
                                   hole_x, hole_y,
                                   finish_x, finish_y);

    return countHSW_recurse(board, start_x + 1, start_y + 1);
}

// createBoard function
// creates a board on which a holey spider walk might take place
// a board has a hole and a finish
// a board is represented by a 2-D vector of int
// the hole, the outer border, and any visited spaces are represented by 1's
// so that if a space = 1, it is not a valid place to move
// the finish is represented by a 2 so that it can be checked for easily
// without passing around extra parameters
// PRECONDITIONS : ***ALL*** parameters must be nonegative integers
//                 dim_x and dim_y must be 2 larger than the actual dimensions of the board 
//                 to allow for a border of 1's
//                 The x coordinates of the hole, start, and finish must be < dim_x - 1
//                 The y coordinates of the hole, start, and finish must be < dim_y - 1
Board_Type createBoard(const int& dim_x, const int& dim_y, 
                       const int& hole_x, const int& hole_y,
                       const int& finish_x, const int& finish_y)
{
    // create a board of the appropriate size
    // with an extra two rows and columns to create borders.
    // initialize all values to 0
    Board_Type board(dim_x, std::vector<int>(dim_y, 0));

    // set hole space to 1
    board[hole_x + 1][hole_y + 1] = 1;

    // set finish space to 2
    board[finish_x + 1][finish_y + 1] = 2;

    // set all border spaces to 1
    for(int i = 0; i < dim_x; ++i)
    {
        board[i][0] = 1;
        board[i][dim_y - 1] = 1;
    }
    for(int i = 0; i < dim_y; ++i)
    {
        board[0][i] = 1;
        board[dim_x - 1][i] = 1;
    }

    return board;
}

// ADD COMMENTS HERE
int countHSW_recurse(Board_Type& board,
                     const int& current_x, const int& current_y)
{
    // BASE CASE :
    // check for complete solution

    // if we are on the finish square
    if(board[current_x][current_y] == 2)
    {
        // return 1 if this is a complete solution
        if(isComplete(board))
        {
            return 1;
        }
        // otherwise, return 0 to save further effort on a useless partial solution
        else
        {
            return 0;
        }
    }

    // RECURSIVE CASE :
    // (but also could be a base case if there's a dead end)

    // check for available moves
    // if there are available moves,
    // the space to move into is set to 1, and a recursive call is made
    // if there are no available moves left, 
    // a recursive call is not made, and the current position is set to 0
    board[current_x][current_y] = 1;
    int total = 0;
    for(int i = -1; i < 2; ++i)
    {
        for(int j = -1; j < 2; ++j)
        {
            // we don't want to check the current space
            if(i == 0 && j == 0) continue;

            // if there's an adjacent unvisited or final space, try it
            if(board[current_x + i][current_y + j] == 0 
            || board[current_x + i][current_y + j] == 2)
            {
                total += countHSW_recurse(board,
                                          current_x + i, current_y + j);
            }
        }
    }
    // reset current position to 0
    board[current_x][current_y] = 0;

    // return all the ones we've added up so far
    return total;
}

// ADD COMMENTS
bool isComplete(const Board_Type& board)
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            // if there's a 0 left, it isn't a complete solution
            if(board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}