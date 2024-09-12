//problem: given two integers m and n, loop repeatedly through an array of m and remove each nth element. Return the last element left. 
// (if m = 7 and n = 4, then begin with the array 1 2 3 4 5 6 7 and remove, in order, 4 1 6 5 2 7 and return 3)

//solution in c++

#include <iostream>
#include <vector>

using namespace std;

int findLastElement(int m, int n) {

    vector<int> arr(m); //initialize vector and pass in m size

    for(int i = 0; i < m; i++) {

        arr[i] = i + 1; //intiailize array with values 1, 2 etc. all the way until m.
    }
    int index = 0; //starting point
    while(arr.size() > 1) {
        index = (index + n - 1) % arr.size(); //calc the nth index
        arr.erase(arr.begin() + index); //remove the nth element
    }

    return arr[0]; //return last element remaining
}

int main() {
    //test
    int m = 7, n = 4;
    cout << "Last element: " << findLastElement(m, n) << endl;
    return 0;
}