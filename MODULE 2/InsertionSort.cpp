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

void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int j = i-1;
        int temp = arr[i];
        int loc = i;
        while(j>=0){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
                loc = j;
            }
            j--;
        }
        arr[loc] = temp;
    }
}

int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    insertionSort(arr);
    printArray(arr);

    return 0;
}