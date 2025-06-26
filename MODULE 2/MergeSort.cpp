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
void merge(vector<int>& arr, int low, int mid, int high){
        if(low>=high) return;
        int h = 0;
        int siz = high - low +1;
        int i = low;
        int j = mid+1;
        vector<int> temp(siz,0);
        while((i<=mid) and (j<=high)){
            if(arr[i]<=arr[j]){
                temp[h] = arr[i];
                i++;
            }
            else{
                temp[h] = arr[j];
                j++;
            }
            h++;
        }
        while (i<=mid)
        {
            temp[h] = arr[i];
            i++;
            h++;
        }
        while(j<=high){
            temp[h] = arr[j];
            j++;
            h++;
        }
        for(int k=0;k<siz;k++){
            arr[k+low] = temp[k];
        }
    }void mergeSort(vector<int>& arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    mergeSort(arr,0,arr.size()-1);
    printArray(arr);

    return 0;
}