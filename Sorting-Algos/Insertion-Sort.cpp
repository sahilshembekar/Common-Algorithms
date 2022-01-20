
// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

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
    // Time Complexity: O(n^2) 
    
    // void insert(int arr[], int i)
    // {
    //     //code here
    // }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i=0;i<n;i++) {
            int key = arr[i];
            int j = i-1; // j is the index before i and then onwards
            
            //Traverse backwards one by one and move elements
            // greater than the key to one position ahead of their current posiion
            
            while(j>=0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j = j-1;
            }
            
            //Ultimately insert the key/element at the correct postion
            arr[j+1] = key;
        }
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
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends
