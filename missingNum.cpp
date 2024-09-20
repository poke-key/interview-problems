//problem: find the missing number in an unsorted array of numbers ranging from 1 to n, with one number missing

#include <iostream>
#include <vector>

using namespace std;

/*takes in array and size n*/
int findMissingNum(const vector<int> &arr, int n) {

    int totalSum = n * (n + 1) / 2; //sum of all numbers 1 -> n

    int arraySum = 0;
    for(int num : arr) {
        arraySum += num;
    }

    return totalSum - arraySum;

}

int main() {

vector<int> arr = {1, 2, 4, 5, 6};  //sample array, n = 6
    int n = 6; 
    cout << "The missing number is: " << findMissingNum(arr, n) << endl;
    return 0;
}
