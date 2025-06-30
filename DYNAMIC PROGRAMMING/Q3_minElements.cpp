/*
    https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/

#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& num, int x){
    // base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solve(num,x-num[i]);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    return mini;
}
int solveMem(vector<int>& num, int x,vector<int>& dp){
    // base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveMem(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);

        }
    }
    dp[x] = mini;
    return dp[x];
}
int solveTab(vector<int>& num, int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if((i-num[j]>=0) && dp[i-num[j]]!=INT_MAX){
                dp[i] = min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x]!=INT_MAX){
        return dp[x];
    }
    return -1;
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // int ans = solve(num,x);
    // if(ans!=INT_MAX){
    //     return ans;
    // }
    // return -1;

    // vector<int> dp(x+1,-1);
    // int ans = solveMem(num,x,dp);
    // if(ans!=INT_MAX){
    //     return ans;
    // }
    // return -1;

    int ans = solveTab(num,x);
    return ans;
}