/*Created by Matt Perry
**Started: 10/4/2019
**Finished: 10/8/2019
**Source File for countHAR
**A recursive backtracking soltuion to the holey ant
**
*/
#include "counthar.h"

//Forward Definition 
//definition below
void countHAR_recurse(std::vector<std::vector<int>> & board, int cur_x, int cur_y, 
                         const int & final_x, const int & final_y, const int & size_x,
                         const int & size_y, int & remaining, int & counter);

// wrapper function for countHAR_recurse
// size_x,size_y are board demensions
// hole_x,hole_y are the hole location
// start_x,start_y are starting location
// final_x,final_y are finish location
// PRE: All 8 ints passed must be >= 0
// POST: Returns the count of valid holey ant runs
// ERROR: None
int countHAR(int size_x, int size_y, int hole_x, int hole_y,
             int start_x, int start_y, int final_x, int final_y)
{
    int remaining = (size_x * size_y);

    //counter for counting number of solutions
    int counter = 0;

    std::vector<std::vector<int>>board(size_y, std::vector<int>(size_x));
    //Setting hole to 1 and removing it from remaining
    board[hole_y][hole_x]=1;
    remaining--;
    //setting start to 1 and removing it from remaining
    board[start_y][start_x]=1;
    remaining--;

    countHAR_recurse(board, start_x, start_y, final_x, final_y,
                     size_x, size_y, remaining, counter);

    return counter;
}
// Recursive backtracking function to explore all possible movements of the ant on the board!
// cur_x,cur_y current x,y position. final_x,final_y final x,y position of ant. size_x,size_y are board dim, x and y. 
// PRE: Hanlded by wrapper function see countHAR for PRE requirements.
// POST: None
// ERROR: None
void countHAR_recurse(std::vector<std::vector<int>> & board, int cur_x, int cur_y, 
                         const int & final_x, const int & final_y, const int & size_x, 
                         const int & size_y, int & remaining, int & counter) 
{

    //BASE CASE
    //IF we are at the finish location and no tiles remain incremenet count
    // Then return
    if(cur_x == final_x && cur_y == final_y && remaining == 0)
    {
        counter ++;
        return;
    }
    //Pre Recursive Check. If the final position is filled then we can stop.
    if(board[final_y][final_x] == 1)
    {
        return;
    }
    //RECURSIVE CASE
    //Checks all 4 possible directions to go.
    // check right
    if(cur_x+1 < size_x && board[cur_y][cur_x+1] == 0)
    {    
    cur_x++;
    remaining --;
    board[cur_y][cur_x] = 1;
    countHAR_recurse(board, cur_x, cur_y, final_x, final_y, size_x, size_y, remaining, counter);
    remaining ++;
    board[cur_y][cur_x] = 0; 
    cur_x--;
    }
    // check left
    if(cur_x-1 >= 0 && board[cur_y][cur_x-1] == 0)
    {
    cur_x--;
    remaining --;
    board[cur_y][cur_x] = 1;   
    countHAR_recurse(board, cur_x, cur_y, final_x, final_y, size_x, size_y, remaining, counter);
    remaining ++;
    board[cur_y][cur_x] = 0; 
    cur_x++;
    }
    // check up
    if(cur_y+1 < size_y && board[cur_y+1][cur_x] == 0)
    {
    cur_y++;
    remaining --;
    board[cur_y][cur_x] = 1;
    countHAR_recurse(board, cur_x, cur_y, final_x, final_y, size_x, size_y, remaining, counter);
    remaining ++;
    board[cur_y][cur_x] = 0; 
    cur_y--;
    }
    // check down
    if(cur_y-1 >= 0 && board[cur_y-1][cur_x] == 0)
    {
    cur_y--;
    remaining --;
    board[cur_y][cur_x] = 1;
    countHAR_recurse(board, cur_x, cur_y, final_x, final_y, size_x, size_y, remaining, counter);
    remaining ++;
    board[cur_y][cur_x] = 0; 
    cur_y++;
    }
    // if no valid turn then go home..
    return;
}
