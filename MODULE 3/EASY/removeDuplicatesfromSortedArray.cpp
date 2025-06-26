/*
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

    Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.
*/
/*


*/
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
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 1;
    }
    int i = 1;
    int j = 1;
    while (i < nums.size())
    {
        if (nums[i] == nums[i - 1])
        {
            i++;
            ;
        }
        else
        {
            nums[j] = nums[i];
            j++;
            i++;
        }
    }
    return j;
}

int main()
{
    vector<int> arr = createAndInitializeArray();
    printArray(arr);

    return 0;
}