/*
    https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}

	int ch1 = solve(n-x,x,y,z)+1;
	int ch2 = solve(n-y,x,y,z)+1;
	int ch3 = solve(n-z,x,y,z)+1;

	int ans = max(ch1, max(ch2,ch3));
	
	return ans;

}
int solveMem(int n, int x, int y, int z, vector<int>& dp){
    /*
        T.C = O(n)
        S.C = O(n) + O(n)

        */
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int ch1 = solveMem(n-x,x,y,z,dp)+1;
	int ch2 = solveMem(n-y,x,y,z,dp)+1;
	int ch3 = solveMem(n-z,x,y,z,dp)+1;

	dp[n] = max(ch1, max(ch2,ch3));
	
	return dp[n];

}
int solveTab(int n, int x, int y, int z){
        /*
        T.C = O(n)
        S.C = O(n)

        */

	vector<int> dp(n+1,INT_MIN);
	dp[0] = 0;

	for(int i=1;i<=n;i++){
		int a=0,b=0,c=0;
		if(i-x>=0){
			dp[i] = max(dp[i-x] + 1,dp[i]);
		}
		if(i-y>=0){
			dp[i] = max(dp[i-y] + 1,dp[i]);
		}
		if(i-z>=0){
			dp[i] = max(dp[i-z] + 1,dp[i]);
		}
		
	}
	if(dp[n]<0){
		return 0;
	}
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// int ans = solve(n,x,y,z);
	// if(ans<0){
	// 	return 0;
	// }
	// return ans;

	// vector<int> dp(n+1,-1);
	// int ans = solveMem(n,x,y,z,dp);
	// if(ans<0){
	// 	return 0;
	// }
	// return ans;

	int ans = solveTab(n,x,y,z);
	return ans;
}