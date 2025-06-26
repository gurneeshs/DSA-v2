/*
    https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>& cost, int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        int ans = min(solve(cost,n-1),solve(cost,n-2))+cost[n];
        return ans;
    }
    int solveMem(vector<int>& cost, int n, vector<int>& dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = min(solveMem(cost,n-1,dp),solveMem(cost,n-2,dp))+cost[n];
        return dp[n];  
    }
    int solveTab(vector<int>& cost, int n){
        if(n<1){
            return cost[0];
        }
        vector<int> dp(n+1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n];
    }
    int solveSO(vector<int>& cost, int n){
        if(n<1){
            return cost[0];
        }
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = 0;

        for(int i=2;i<=n;i++){
            curr = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int ans = min(solve(cost,n-1), solve(cost,n-2)); 
        // return ans;  

        // vector<int> dp(n+1,-1);
        // int ans = min(solveMem(cost,n-1,dp),solveMem(cost,n-2,dp));

        // int ans = min(solveTab(cost,n-1),solveTab(cost,n-2));
        
        int ans = min(solveSO(cost,n-1),solveSO(cost,n-2));

        return ans;
    }
};