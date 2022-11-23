#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

int pivotPlace(int* arr, int low, int high)
{
    int pivot = low;
    int j = high;
    for(int i = j-1;i>=low;i--)
    {
        if(arr[i]>arr[pivot] && arr[i]>arr[j])
        {
            int bla = arr[i];
            arr[i] = arr[j];
            arr[j] = bla;
            j--;
        }
    }

    if(arr[pivot]>arr[j])
    {
        int bla = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = bla;
    }

    /*
    for(int i = 0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<j<<endl;
    */
    return j;
}

int* quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int pivot = pivotPlace(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }

    return arr;
}

int main()
{
    int n = 16;
    // int arr[n] = {34, 46, 25, 5, 56, 16, 68, 36};
    int arr[n] = {3, 6, 1, 8, 2, 5, 3, 4, 4, 4, 3, 1, 8, 4, 100, -100};

    cout<<"Initial array"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    quickSort(arr, 0, n-1);
    cout<<"Sorted array"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
