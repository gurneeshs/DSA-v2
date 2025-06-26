#include <bits/stdc++.h>
using namespace std;

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

int secondLargestElement(vector<int>& arr){
    if(arr.size()==1){
        return -1;
    }
    if(arr.size()==2){
        return arr[0]==arr[1]?-1:arr[0]>arr[1]?arr[0]:arr[1];
    }
    int maxi = arr[0];
    int secondMaxi = maxi;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi){
            secondMaxi = maxi;
            maxi = arr[i];
        }
    }
    return secondMaxi;
}
int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    cout<<secondLargestElement(arr)<<endl;

    return 0;
}