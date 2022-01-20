// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
     // time complexity = nlog(n)
     // space complexity = o(n) //Asymptomatically 
    void merge(int arr[], int left, int mid, int right)
    {
         auto sizeOfSubArrayOne = mid-left+1;
         auto sizeOfSubArrayTwo = right-mid;
         
         //Create temporary arrays
         int leftArray[sizeOfSubArrayOne];
         int rightArray[sizeOfSubArrayTwo];
         
         //Copy data one by one into temporary array
         
         for(int i=0;i<sizeOfSubArrayOne;i++) {
             leftArray[i] = arr[left+i];
         }
         
         for(int i=0;i<sizeOfSubArrayTwo;i++) {
             rightArray[i] = arr[mid+1+i];
         }
         
         //Assign start indices for merging to begin
         auto indexOfSubArrayOne = 0;
         auto indexOfSubArrayTwo = 0;
         int indexOfMergedArray = left;
         
         //Merge the temp arrays into the OF array
         
         while(indexOfSubArrayOne<sizeOfSubArrayOne && indexOfSubArrayTwo<sizeOfSubArrayTwo) {
             if(leftArray[indexOfSubArrayOne]<rightArray[indexOfSubArrayTwo]) {
                 arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                 indexOfSubArrayOne++;
             }
             
             else {
                 arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                 indexOfSubArrayTwo++;
             }
             
             indexOfMergedArray++;
         } 
         
         //Copy remaining Elements (if Any) from left arr to merged array
         
        while(indexOfSubArrayOne<sizeOfSubArrayOne) {
             // Not needed since this is the only array left if(leftArray[indexOfSubArrayOne]<rightArray[indexOfSubArrayTwo]) {
                 arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                 indexOfSubArrayOne++;
                 indexOfMergedArray++;
             //}
        }
        
         //Copy remaining Elements (if Any) from right arr to merged array
        while(indexOfSubArrayTwo<sizeOfSubArrayTwo) {
             //if(leftArray[indexOfSubArrayOne]>rightArray[indexOfSubArrayTwo]) {
                 arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                 indexOfSubArrayTwo++;
                 indexOfMergedArray++;
             //}
        }
         
         
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        if (left >= right) {
            return; //Bascially stop the recursion when left and right cross each other
        }
        auto mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
        
        
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
