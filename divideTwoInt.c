//leetcode problem: Divide Two Integers
// Solved
// Medium
// Topics
// Companies
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

int divide(int dividend, int divisor) {

    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX; //overflow handle

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; //gets sign of result

    //use absolute values for simpleness
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);

    //result of division, return value
    long long result = 0;  //change this to long long

    //use bit shifting to subtract multiples of divisor
    while(absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        int numShifts = 0;

        ///find largest multiple of divisor to subtract
        while((tempDivisor << 1) <= absDividend) {
            tempDivisor <<= 1;
            numShifts++;
        }
    
        absDividend -= tempDivisor; //subtract from dividend
        result += (1LL << numShifts); //shift using long long for safety
    }

    //apply the sign while returning
    return sign == 1 ? result : -result;
}
