// Luke Underwood
// 9/28/2020
// Project_4 for CS311
// counthsw.h
// header file for countHSW_recurse and supporting functions

#ifndef COUNTHSW_H
#define COUNTHSW_H

#include <vector>

// define the type that will be used for the board
using Board_Type = std::vector<std::vector<int>>;

// ADD COMMENTS HERE
int countHSW(const int& dim_x, const int& dim_y,
             const int& hole_x, const int& hole_y,
             const int& start_x, const int& start_y,
             const int& finish_x, const int& finish_y);

// ADD COMMENTS HERE
Board_Type& createBoard(int& dim_x, int& dim_y, 
                        const int& hole_x, const int& hole_y);

// ADD COMMENTS HERE
int countHSW_recurse(Board_Type& board,
                     const int& current_x, const int& current_y,
                     const int& finish_x, const int& finish_y);

#endif // #ifndef COUNTHSW_H