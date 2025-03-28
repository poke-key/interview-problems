// 10. Regular Expression Matching
// Solved
// Hard
// Topics
// Companies
// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).


class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n+1, false)); //create dp table that represents matches between s and p

        dp[0][0] = true; //base case, empty

        for(int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2]; // '*' can match zero of the preceding element
        }
        /*POPULATE DP TABLE*/ 
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j-1] == '.' || p[j-1] == s[i-1] ) {
                    //curr chars match
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else if ( p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];

                    if(p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
                //default = false
            }
        }
        return dp[m][n];
    }
};