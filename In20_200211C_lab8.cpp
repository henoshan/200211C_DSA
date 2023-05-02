#include <iostream>
using namespace std;

// function to heapify the tree
// n: size of the heap
// root: index of the root node of the subtree to be heapified
void heapify(int arr[], int n, int root) {
  int largest = root; // Initialize largest as root
  int left = 2*root + 1; // Calculate the index of left child
  int right = 2*root + 2; // Calculate the index of right child
 
  // If left child is larger than root
  if (left < n && arr[left] > arr[largest]){
    largest = left;
  }
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]); // Swap the root with the largest child
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
  
// function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap
    // Starting from the last non-leaf node and heapifying all subtrees
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Extract elements from heap one by one
    // Starting from the last element and placing it at the end of the array
    // Then heapifying the reduced heap
    for (int i=n-1; i>=0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// function to display the contents of an array
void displayArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int heap_arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>heap_arr[i];
    }
    
    cout<<"Input array"<<endl;
    displayArray(heap_arr, n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
  
    return 0;
}
