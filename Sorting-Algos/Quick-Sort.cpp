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
 // time complexity = nlog(n)

{
    public:
        
               
        
        
        void swap(int *a, int *b) { //Function takes value by reference and swaps them 
            int t = *a;
            *a = *b;
            *b = t;
        }
        
        
        //Function to sort an array using quick sort algorithm.
        void quickSort(int arr[], int low, int high)
        {
            if(low < high) {
                int partitioningIndex = partition(arr,low,high);
                
                // Now separately sort elemenst before and after the partition
                
                quickSort(arr, low, partitioningIndex-1);
                quickSort(arr, partitioningIndex+1, high);
                
            }
        }
         
         
         
        //We take the last element as pivot, then place pivot at correct position,
        //Compare elements with it and place smaller on left and bigger on right
        int partition (int arr[], int low, int high)
        {
           int pivot = arr[high];
           int i = low -1; // Index of smaller element //Also the right position of the pivot as we progress further and further
           
           for(int j=low;j<=high;j++) {
               
               //if the element is smaller than pivot 
               if (arr[j] < pivot) {
                   
                   i++; //first increment //then swap
                   swap(&arr[i], &arr[j]);
                   
               }
               //Otherwise we will just go to the next
               
           }
           //At the end 
           swap(&arr[i+1],&arr[high]);
           
           return (i+1);
        }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends

