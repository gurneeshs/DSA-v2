#include <bits/stdc++.h>
using namespace std;

int findFactorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*findFactorial(n-1);
}

int main(){
    cout<<findFactorial(5)<<endl;
    return 0;
}