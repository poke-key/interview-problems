// 6. Zigzag Conversion
// Solved
// Medium
// Topics
// Companies
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);



class Solution {
    public:
        string convert(string s, int numRows) {
            //base cases
            if (numRows == 1 || s.length() <= numRows)
                return s;
            
            //vector of rows for storing chars
            vector<string> rows(numRows);
            
            //vars to keep track of row + direction
            int currentRow = 0;
            bool goingDown = true;  //start by going down
            
            //for loop through the input string
            for (char c : s) {
                //add current char to correct row
                rows[currentRow] += c;
                
                //update direction if reached first or last row
                if (currentRow == 0) 
                    goingDown = true;  //set the down flag to true
                else if (currentRow == numRows - 1) 
                    goingDown = false; //else keep false, go up
                
                
                //move to next row, dependent on direction, do ternirary operation
                currentRow += goingDown ? 1 : -1;
            }
            
            /*combine all the rows, return the resulting outpit*/
            string result;
            for (const string& row : rows) {
                result += row;
            }
            
            return result;
        }
    };