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

int findMin(vector<int> arr, int k){
    int n = arr.size();
    int mini = arr[k];
    int loc = k;
    for(int i=k;i<n;i++){
        if(arr[i]<mini){
            mini = arr[i];
            loc = i;
        }
    }
    return loc;
}

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int mini = findMin(arr,i);
        swap(arr[mini], arr[i]);
    }
}

int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    selectionSort(arr);
    printArray(arr);

    return 0;
}