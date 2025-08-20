#include <iostream>
#include <string>
#include <stack>
using namespace std;

string funcPatternExpander(string inputStr) {
    stack<string> strStack;
    stack<int> numStack;
    string curr = "";
    
    for (int i = 0; i < inputStr.size(); i++) {
        char c = inputStr[i];

        if (c == '(') {
            //push current string to stack
            strStack.push(curr);
            curr = "";
        } 
        else if (c == ')') {
            int num = 1; //default repeat = 1
            if (i + 1 < inputStr.size() && inputStr[i + 1] == '{') {
                int j = i + 2;
                num = 0;
                while (j < inputStr.size() && isdigit(inputStr[j])) {
                    num = num * 10 + (inputStr[j] - '0');
                    j++;
                }
                if (j < inputStr.size() && inputStr[j] == '}') {
                    i = j; //move after '}' char is put
                }
            }

            string temp = curr;
            curr = strStack.top();
            strStack.pop();

            for (int j = 0; j < num; j++) {
                curr += temp;
            }
        } 
        else {
            curr += c;
        }
    }

    return curr;
}

int main() {
    string inputStr;
    getline(cin, inputStr);

    cout << funcPatternExpander(inputStr);
    return 0;
}