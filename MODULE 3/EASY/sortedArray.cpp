#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << "]" << endl;
    cout << endl;
}

vector<int> createAndInitializeArray()
{
    cout << "Enter Size of Array: ";
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

bool arraySortedOrNot(vector<int>& arr){
    if(arr.size()==1){
        return true;
    }
    if(arr.size()==2){
        return arr[0]<=arr[1]?true:false;
    }
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    if(arraySortedOrNot(arr)){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is not Sorted!!"<<endl;
    }

    return 0;
}