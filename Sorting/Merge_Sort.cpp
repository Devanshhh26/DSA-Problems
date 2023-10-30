#include<iostream>
#include<vector>
using namespace std;

void merge(int* arr,int start,int end)
{
    int mid=(start+end)/2;
    int len1 =mid-start+1;
    int len2 =end-mid;
    int* left=new int[len1];
    int* right=new int[len2];

    // copy  1st half of values of array into len1

    int k=start;
    for(int i=0;i<len1;i++)
    {
        left[i]=arr[k];
        k++;
    }

    // copy 2nd half of values of array into len2
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        right[i]=arr[k];
        k++;
    }

    //merge logic
    int leftIndex=0;
    int rightIndex=0;
    int mainArrayIndex=start;

    // check which element is smaller among left[i] , right[i] until one of the array is exhausted

    while(leftIndex<len1 && rightIndex<len2)
    {
        if(left[leftIndex]<right[rightIndex])
        {
            arr[mainArrayIndex]=left[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex]=right[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }
    }

    // if right array is exhausted it means left array still has some elements left so as it is copy those elements

    while(leftIndex<len1)
    {
        arr[mainArrayIndex]=left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // if left array is exhausted it means right array still has some elements left so as it is copy those elements

    while(rightIndex<len2)
    {
        arr[mainArrayIndex]=right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }


}

void mergeSort(int* arr,int start,int end)
{   
    // if s==e single element
    // if s>e invalid array
    if(start>=end)
    {
        return;
    }
    int mid=(start+end)/2;

    //left part sort

    mergeSort(arr,start,mid);

    // right part sort

    mergeSort(arr,mid+1,end);

    // merge two sorted arrays

    merge(arr,start,end);
}

int main()
{
    int arr[]={11,21,67,3,56,90,32,77,44,44,26,87,44};
    int n=13;
    int start=0;
    int end=n-1;
    mergeSort(arr,start,end);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}