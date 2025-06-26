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

int largestElement(vector<int>& arr){
    if(arr.size()==1){
        return arr[0];
    }
    int maxi = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);
    cout<<largestElement(arr)<<endl;

    return 0;
}