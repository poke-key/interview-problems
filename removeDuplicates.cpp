//problem: remove duplicates from a list
//solution: C++

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void removeDuplicates(vector<int> &arr) {

    unordered_set<int> seen;

    vector<int> result;

    for(int num : arr) {

        if(seen.find(num) == seen.end()) {
            
            seen.insert(num);
            result.push_back(num);
        }
    }
    arr = result;
}

int main() {

    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    removeDuplicates(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;


}