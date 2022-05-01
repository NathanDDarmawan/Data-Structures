#include <iostream>
using namespace std;

// merge Sort
void merge(int array[], int left, int mid, int right)
{
    int subArray1 = mid - left + 1;
    int subArray2 = right - mid;
  
    // Create temp arrays (L for Left R for Right)
    int *LArray = new int[subArray1],
         *RArray = new int[subArray2];
  
    // Copy data to temp arrays left & right arrays
    for (int i = 0; i < subArray1; i++)
        LArray[i] = array[left + i];
    for (int j = 0; j < subArray2; j++)
        RArray[j] = array[mid + 1 + j];
  
    // Initializing initial indexes
    int indexOfSubArray1 = 0, 
        indexOfSubArray2 = 0; 
    int indexOfMergedArray = left; 
  
    // Merge temp arrays back into array
    while (indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2) {
        if (LArray[indexOfSubArray1] <= RArray[indexOfSubArray2]) {
            array[indexOfMergedArray] = LArray[indexOfSubArray1];
            indexOfSubArray1++;
        }
        else {
            array[indexOfMergedArray] = RArray[indexOfSubArray2];
            indexOfSubArray2++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of left array
    while (indexOfSubArray1 < subArray1) {
        array[indexOfMergedArray] = LArray[indexOfSubArray1];
        indexOfSubArray1++;
        indexOfMergedArray++;
    }
    // Same for right array
    while (indexOfSubArray2 < subArray2) {
        array[indexOfMergedArray] = RArray[indexOfSubArray2];
        indexOfSubArray2++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// binary search function (recursive)
int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


// utility function to print arrays
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main(void) {
    // initializing array (integers only)
    int arr[] = {9, 8, 2, 5, 6, 4, 18, 20, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array:" << endl;
    printArray(arr, n);
    cout << endl;

    //Merge sort driver
    mergeSort(arr, 0, n - 1);
    cout << "\nSorted Array:" << endl;
    printArray(arr, n);
    cout << endl;

    //binary search
    int x = 4;
    int result = binarySearch(arr, x, 0, n - 1);
    if (result == -1)
        cout << "\nElement " << x <<" is not found" << endl;
    else
        cout << "\nElement " << x <<" is found at position " << result << endl;
}
