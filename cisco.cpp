#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * list1, represents the first list of size N.
 * list2, represents the second list of size M.
 */
void funcSum(vector<int> list1, vector<int> list2)
{
    //convert first list to number (digits are in reverse order)
    long long num1 = 0;
    long long multiplier = 1;
    for (int i = 0; i < list1.size(); i++) {
        num1 += list1[i] * multiplier;
        multiplier *= 10;
    }
    
    // same thing
    long long num2 = 0;
    multiplier = 1;
    for (int i = 0; i < list2.size(); i++) {
        num2 += list2[i] * multiplier;
        multiplier *= 10;
    }
    
    long long sum = num1 + num2;
    
    //extract in reverse order, print it
    if (sum == 0) {
        cout << "0";
        return;
    }
    
    bool first = true;
    while (sum > 0) {
        if (!first) {
            cout << " ";
        }
        cout << (sum % 10);
        sum /= 10;
        first = false;
    }
}

int main()
{
    //input for list1
    int list1_size;
    cin >> list1_size;
    vector<int> list1;
    for (int idx = 0; idx < list1_size; idx++) {
        int temp;
        cin >> temp;
        list1.push_back(temp);
    }
    
    //input for list2
    int list2_size;
    cin >> list2_size;
    vector<int> list2;
    for (int idx = 0; idx < list2_size; idx++) {
        int temp;
        cin >> temp;
        list2.push_back(temp);
    }
    
    funcSum(list1, list2);
    
    return 0;
}