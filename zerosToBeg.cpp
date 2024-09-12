//problem: given array of 0's and 1's, move all of the 0's and all of the 1's to the end of the array.

#include <iostream>
#include <vector>
using namespace std;

void moveZeroesAndOnes(vector<int>& arr) {

    int left = 0, right = arr.size() - 1; //initialize start & ends

    while(left < right) {
        if(arr[left] == 1 && arr[right] == 0) {
            swap(arr[left], arr[right]); //perform swap and incremnent to next value for each pointer
            left++;
            right--;
        }
        //check value, adjust accordingly. 
        if(arr[left] == 0) 
            left++;
        if(arr[right] == 1)
            right--;
    }
}

int main() {

    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1};

    moveZeroesAndOnes(arr);

    for(int num : arr) {
        cout << num << " ";
    }
    
    cout << endl;
    return 0;
}