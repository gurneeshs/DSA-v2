/*
    https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/
#include <bits/stdc++.h> 
using namespace std;
long long int solveVar(vector<int> &nums, int st, int n){

    long int prev2 = 0;
    long int prev1 = nums[st];

    for(int i=st+1;i<n;i++){
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;

        long long int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }

    long long int ans1 = solveVar(valueInHouse,1,n);
    long long int ans2 = solveVar(valueInHouse, 0, n-1);

    return max(ans1,ans2);

}