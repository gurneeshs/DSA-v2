#include <bits/stdc++.h>
using namespace std;

int NnumbersSum(int N)
{
    // your code goes here
    if (N == 0)
    {
        return 0;
    }
    return N + NnumbersSum(N - 1);
}

int main()
{
    cout<<NnumbersSum(4)<<endl;
    return 0;
}