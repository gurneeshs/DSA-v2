/*
https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int solve(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    long long int ans = (((n-1))*(((solve(n-1)%MOD) + (solve(n-2)%MOD))%MOD))%MOD;
    return ans;
}
long long int solveMem(int n, vector<long long int>& dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (((n-1)%MOD)*(((solveMem(n-1,dp)%MOD) + (solveMem(n-2,dp)%MOD))%MOD))%MOD;
    
    return dp[n];
}
long long int solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[i] = ((i-1)*((dp[i-1])+(dp[i-2])))%MOD;
    }
    return dp[n];
}
long long int solveSO(int n){
    long long int prev1 = 0;
    long long int prev2 = 1;
    long long int curr;

    for(int i=3;i<=n;i++){
        curr = ((i-1)*(prev1+prev2))%MOD;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
long long int countDerangements(int n) {
    // Write your code here.
    // return solve(n);

    // vector<long long int> dp(n+1,-1);
    // return solveMem(n,dp);

    // return solveTab(n);
    return solveSO(n);
}