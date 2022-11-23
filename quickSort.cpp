#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

int* quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int pivot = low;
        int arr2[len];
        int j = ;
        for(int i = pivot+1;i<=high;i++)
        {
            if(arr[i]<arr[pivot])
            {

            }
        }
        quickSort(arr, low, pivot);
        quickSort(arr, pivot+1, high);
    }

    return arr;
}

int main()
{
    int n = 6;
    int arr[6] = {5, 2, 3, 1, 6, 4};

    quickSort(arr, 0, 5);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    count<<endl;
}
