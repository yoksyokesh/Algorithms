// ALGORITHM : Merge Sort
// TIME COMPLEXITY : 0(NlogN)

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int k = left;
    int j = mid;
    while ((i <= mid - 1) and (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            ++i;
            ++k;
        }
        else
        {
            temp[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while (i <= (mid - 1))
    {
        temp[k] = arr[i];
        ++k;
        ++i;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        ++k;
        ++j;
    }
    for (int i = left; i <= right; ++i)
        arr[i] = temp[i];
}

void _mergesort(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        _mergesort(arr, temp, left, mid); // recursively calling _mergesort function based on divide and conquer algorithm
        _mergesort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main()
{
    int t;
    cin >> t; // to run through multiple test cases
    while (t--)
    {
        int n; // number of element of array
        cin >> n;
        int arr[n]; // array to store our input elements
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int temp[n];
        _mergesort(arr, temp, 0, n - 1); // calling of _mergesort function
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
