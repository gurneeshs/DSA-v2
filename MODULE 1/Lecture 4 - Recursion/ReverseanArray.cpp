#include <bits/stdc++.h>
using namespace std;

void reverseArray(int i, vector<int>& arr){
    int n = arr.size();
    if(i >= n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,arr);
}

int main(){
    vector<int> arr{1,2,3,4,5,6};
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    reverseArray(0,arr);
    for(auto el:arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}