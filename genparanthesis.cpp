class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {

        //check if used all paranteshsis, hen add current string to results vector
        if(current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        //we can add opening parantehsis if open < max meaning we haven't used all n
        if(open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        //add closing parantehsis if more open than closed
        if(close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};