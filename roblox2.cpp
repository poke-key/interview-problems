#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
 
long long solution(vector<int>& cityLine) {
    int n = cityLine.size();
    if (n == 0) return 0; //base case

    //for each position, find the first smaller height on the left and right
    vector<int> left(n), right(n);
    stack<int> st;

    // Find the first smaller element on the left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && cityLine[st.top()] >= cityLine[i]) {
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    //clear the stack for reuse
    while (!st.empty()) st.pop();

    // Find the first smaller element on the right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && cityLine[st.top()] >= cityLine[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    long long maxSquareArea = 0;

    // For each building as height of square
    for (int i = 0; i < n; i++) {
        // Width available for this height
        int width = right[i] - left[i] + 1;
        // Possible square size is minimum of width and height
        int squareSize = min(width, cityLine[i]);
        maxSquareArea = max(maxSquareArea, (long long)squareSize * squareSize);
    }

    return maxSquareArea;
}