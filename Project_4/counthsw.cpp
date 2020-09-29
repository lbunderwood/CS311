// Luke Underwood
// 9/28/2020
// Project_4 for CS311
// counthsw.cpp
// source file for countHSW_recurse and supporting functions

// std library inclusions
#include <vector>

// other inclusions
#include "counthsw.h"

//ADD COMMENTS HERE
int countHSW(int& dim_x, int& dim_y,
             const int& hole_x, const int& hole_y,
             const int& start_x, const int& start_y,
             const int& finish_x, const int& finish_y)
{
    Board_Type board = createBoard(dim_x, dim_y, hole_x, hole_y);

    return countHSW_recurse(board, start_x + 1, start_y + 1, 
                            finish_x + 1, finish_y + 1);
}

// ADD COMMENTS HERE
Board_Type& createBoard(int& dim_x, int& dim_y, 
                        const int& hole_x, const int& hole_y)
{
    // create a board of the appropriate size
    // with an extra two rows and columns to create borders.
    // initialize all values to 0
    dim_x += 2;
    dim_y += 2;
    Board_Type board(dim_x, std::vector<int>(dim_y, 0));

    // set hole space to 1
    board[hole_x + 1][hole_y + 1] = 1;

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
}

// ADD COMMENTS HERE
int countHSW_recurse(Board_Type& board,
                     const int& current_x, const int& current_y,
                     const int& finish_x, const int& finish_y)
{
    // check for complete solution
    
    // we must be on the finish square
    if(current_x == finish_x && current_y == finish_y)
    {
        bool complete = true;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                // if there's a 0 left, it isn't a complete solution
                if(!board[i][j])
                {
                    complete = false;
                    break;
                }
            }

            if(!complete) break;
        }

        // return 1 if this is a complete solution
        if(complete) return 1;
    }

    // check for dead end is unneccessary
    // if there are no available moves left, a recursive call is not made
    int total = 0;
    for(int i = -1; i < 2; ++i)
    {
        for(int j = -1; j < 2; ++j)
        {
            // we don't want to check the current space
            if(i == 0 && j == 0) continue;

            // if there's an adjacent 0, try it
            if(!board[current_x + i][current_y + j])
            {
                board[current_x + i][current_y + j] = 1;
                total += countHSW_recurse(board,
                                          current_x + i, current_y + j, 
                                          finish_x, finish_y);
            }
        }
    }
    
    // return all the ones we've added up so far
    return total;
}