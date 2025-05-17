MOD = 10**9 + 7 #value problem gives to take mod with

def bilbo_steps(n):

    #base cases
    if n == 1:
        return 1
    if n == 2:
        return 2
    #dp[i][0]: ways to reach i ending in 1-step
    #dp[i][1]: ways to reach i ending in 2-step

    dp = [[0, 0] for _ in range(n + 1)] # we want a two dimensional dp matrix
    dp[1][0] = 1  # Only one way to reach step 1 (1 step)
    dp[2][0] = 1  # 1 + 1
    dp[2][1] = 1  # 2

    for i in range(3, n + 1):
        #end with 1-step: can come from either 1-step or 2-step before
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD
        #end with 2-step: only if last step was 1-step
        dp[i][1] = dp[i - 2][0] % MOD

    return (dp[n][0] + dp[n][1]) % MOD

# Input
n = int(input())
print(bilbo_steps(n))
