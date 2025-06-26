/*
    https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/

#include <bits/stdc++.h>
using namespace std;


int solve(long long nStairs, int i){
    if(nStairs==i){
        return 1;
    }
    if(i>nStairs){
        return 0;
    }
    return solve(nStairs,i+1) + solve(nStairs,i+2);
}

int solveMem(long long nStairs, int i, vector<int>& dp){
    if(nStairs==i){
        return 1;
    }
    if(i>nStairs){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    dp[i] = dp[i+1] + dp[i+2];
    return dp[i];
}