// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
 * list1, represents the list L1 of size N.
 * list2, represents the list2 of size M.
 */
void funcMerge (vector<int> list1, vector<int> list2)
{
    vector<int> result;
    int n = list1.size(), m = list2.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        result.push_back(list1[i++]);
        result.push_back(list2[j++]);
    }

    while (i < n) {
        result.push_back(list1[i++]);
    }

    while (j < m) {
        result.push_back(list2[j++]);
    }
//print
    for (int k = 0; k < result.size(); k++) {
        cout << result[k];
        if (k != result.size() - 1) cout << " ";
    }
}

int main()
{
    //input for list1
    int list1_size;
    cin >> list1_size;
    vector<int> list1;
    for ( int idx = 0; idx < list1_size; idx++ )
    {
        int temp;
        cin >> temp;
        list1.push_back(temp);
    }
    
    //input for list2
    int list2_size;
    cin >> list2_size;
    vector<int> list2;
    for ( int idx = 0; idx < list2_size; idx++ )
    {
        int temp;
        cin >> temp;
        list2.push_back(temp);
    }
    
    funcMerge(list1, list2);
    
    return 0;
}