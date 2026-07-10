// Recursive Approach
int fibonacci(int n){ 
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int fib(int n) {   
    return fibonacci(n);
}

// Top-Down Approach(Memorization)
int fibonacci(int n, vector<int>&dp){ 
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int fib(int n) {
    vector<int>dp(n+1,-1);
    return fibonacci(n,dp);
}

// Bottom-Up Approach(Tabulation)
int fib(int n) {
    if(n<=1)
    return n;

    vector<int>dp(n+1);
    // n = 0, dp = [0]
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
}

// Space Optimization
int fib(int n) {
    if(n<=1)
    return n;

    if(n==2)
    return 1;

    vector<int>dp(3); // can use const variables instead of array 
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[0]+dp[1];
    }

    return dp[2];
}