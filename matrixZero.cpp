//problem: write a function to take in m x n matrix (array) of random numbers, 
//and use the functions row (times) 2 and column-1 to set the entire array to 0

#include <iostream> 
#include <vector>
using namespace std;

//takes in 2d vector
void setMatrixToZero(vector<vector<int>>& matrix) {

    int m = matrix.size(); //get size of matrix
    int n = matrix[0].size(); //get size of beginning

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            matrix[i][j] = 0; //set as 0 instead
        }
    }

}

//test case over here
int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    setMatrixToZero(matrix);

    for(auto row : matrix) {
        for(auto elem : matrix) {
            cout << elem << " ";
        }

        cout << endl;
    } 

    return 0;


}