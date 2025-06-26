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

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i <= (high-1)){
            i++;
        }
        while(arr[j]>pivot && j >= (low+1) ){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swap(arr[low], arr[j]);
    return j;

}
void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int p = partition(arr,low,high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }

}
int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    quickSort(arr, 0, arr.size()-1);
    printArray(arr);

    return 0;
}