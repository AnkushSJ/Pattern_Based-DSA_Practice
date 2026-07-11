// Recursive Approach
int climb(int n){
    // base case
    if(n<=2){
        return n;
    }
    return climb(n-1)+climb(n-2);
}
int climbStairs(int n) {
    return climb(n);
}

// Top-Down Approach(Memorization)
int climb(int n, vector<int>&dp){
    if(n<=2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = climb(n-1,dp)+climb(n-2,dp);
}

int climbStairs(int n) {
    vector<int>dp(n+1,-1);
    return climb(n,dp);
}

// Bottom-Up Approach(Tabulation)
int climbStairs(int n) {  
    if(n<=2)
    return n;

    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];  
}

// Space Optimization
int climbStairs(int n) {

    if(n<=2)
    return n;

    vector<int>dp(3);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2]= dp[0]+dp[1];
    }

    return dp[2];
}

