//problem: solve a maze recursively

#include <iostream>
#include <vector>

using namespace std;
bool solveMaze(vector<vector<int>>& maze, int x, int y) {

    int m = maze.size();
    int n = maze[0].size();//similar logic as matrixZero

    //BASE CASE
    if(x == m -1 && y == n - 1) {//check for reachig destination and mark path
        maze[x][y] = 9; 
        return true;
    }

    //check if out of bounds or blocked cell

    if( x < 0 || y < 0 || x >= m || y >= n || maze[x][y] == 1)
        return false; //not solved
    
    maze[x][y] = 9;

    //explore in 4 dirs
    if(solveMaze(maze, x + 1, y) || solveMaze(maze, x, y + 1))
        return true;
    
    //backtrack
    maze[x][y] = 0;
    return false;
}

//test cases
int main() {

    return 0;
}