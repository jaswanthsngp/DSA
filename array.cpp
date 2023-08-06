#include <iostream>
#include <cmath>
using namespace std;

void printArray(int *arr, int start, int end, char c);
void insertIntoArray(int *arr, int n);
void deleteFromArray(int *arr, int n);
void linearSearch(int *arr, int n);
void binarySearch(int *arr, int n);
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
// void heapSort(int *arr, int n);
void merge(int *arr, int start, int mid, int end, int *buffArray);
void mergeSort(int *arr, int start, int end, int *buffArray);
// void quickSort(int *arr, int n);
void subArrays(int *arr, int n);
void subSequences(int *arr, int n);

int main(){
    int *arr, n, i, choice;
    cout<<"Enter the size of Array ";
    cin>>n;
    arr= new int[n+1];
    cout<<"Enter Array Elements"<<endl;
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"The array elements are"<<endl;
    printArray(arr, 0, n-1, '\n');
    cout<<"Enter\n";
    cout<<"1 to Insert into Array\n";
    cout<<"2 to Delete from Array\n";
    cout<<"3 to perform Linear Search\n";
    cout<<"4 to perform Binary Search\n";
    cout<<"5 to perform Bubble Sort\n";
    cout<<"6 to perform Insertion Sort\n";
    cout<<"7 to perform Selection Sort\n";
    cout<<"8 to perform Merge Sort\n";
    cout<<"9 to get a list of sub-arrays\n";
    cout<<"10 to get a list of sub-sequences\n";
    cout<<"Any other key for something else"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
            insertIntoArray(arr, n);
            break;

        case 2:
            deleteFromArray(arr, n);
            break;
        
        case 3:
            linearSearch(arr, n);
            break;
        
        case 4:
            binarySearch(arr, n);
            break;
        
        case 5:
            bubbleSort(arr, n);
            break;

        case 6:
            insertionSort(arr, n);
            break;
        
        case 7:
            selectionSort(arr, n);
            break;
        
        case 8:
            int *buffArray;
            buffArray= new int[n];
            mergeSort(arr, 0, n-1, buffArray);
            break;

        case 9:
            subArrays(arr, n);
            break;
        
        case 10:
            subSequences(arr, n);
            break;
        
        default:
            cout<<"Program ended for now, here are the array elements"<<endl;
            printArray(arr, 0, n-1, '\n');
            break;
    }
    return 0;
}

void printArray(int *arr, int start, int end, char endsWith= '\n'){
    for(int i=start; i<=end; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endsWith;
}

void insertIntoArray(int *arr, int n){
    int val, pos;
    cout<<"Enter the element to insert ";
    cin>>val;
    cout<<"Enter the index to insert ";
    cin>>pos;
    n= n+1;                                 // Resize the array
    for(int i=n; i>pos; i--)                // start from rightmost, move elements to right,
        arr[i]= arr[i-1];                   // until the position to insert arrives, creating an empty space
    arr[pos]= val;                          // put the value into that empty space
    printArray(arr, 0, n-1, '\n');
}

void deleteFromArray(int *arr, int n){
    int pos;
    cout<<"Enter the index of element to delete ";
    cin>>pos;
    for(int i= pos; i<n-1; i++)             // starting from pos, move elements to left, 
        arr[i]= arr[i+1];                   // until last, each element replacing it's right
    n= n-1;                                 // resize the array, discarding last element
    printArray(arr, 0, n-1, '\n');
}

void linearSearch(int *arr, int n){         // Also called sequential search
    int target;
    bool found= false;
    cout<<"Enter the number you want to find ";
    cin>>target;                            // compares each element with the target
    for(int i=0; i<n; i++){                 // and returns the index where it is found
        if(arr[i]==target){
            cout<<"Found at index "<<i<<endl;
            found= true;                    // Time Complexity: O(1) O(n) O(n)
        }                                   // Space Complexity: O(1) 
    }
    if(!found)
        cout<<"Element doesn't exist"<<endl;
}

void binarySearch(int *arr, int n){         // Works best on sorted array
    int start= 0, end= n-1, mid, target;
    bool found= false;
    cout<<"Enter the number you want to find ";
    cin>>target;
    while(start<=end && !found){            // if the target is less than the middle value,
        mid= (start+end)/2;                 // search in the 1st half, else search in 2nd half
        printArray(arr, start, end, '\n');  // repeat till you find it or exhaust the array
        if(target<arr[mid])                 // traversing recursively
            end= mid-1;                     // obviously, you will find the target in the middle 
        else if(target>arr[mid])            // of the array, if it is there
            start= mid+1;
        else if(target==arr[mid]){
            cout<<"Found at index "<<mid<<endl;
            found= true;                    // Time Complexity: O(1) O(log n) O(log n)
        }                                   // Space Complexity: O(1)
    }
    if(!found)
        cout<<"Element doesn't exist"<<endl;
}

void bubbleSort(int *arr, int n){           // Also known as Sinking Sort.
    int temp;
    printArray(arr, 0, n-1, '\n');          // The element swaps with the next,
    for(int i=0; i<n-1; i++){               // if it is greater than it.
        for(int j=0; j<n-1; j++){           // This results in gradually moving 
            if(arr[j]>arr[j+1]){            // each element to its position,
                temp= arr[j+1];             // where heavier elements settle down first
                arr[j+1]= arr[j];           // Heavier ones sink to the bottom gradually and
                arr[j]= temp;               // Lighter ones rise to the top like a bubble
            }                               // Time Complexity: O(n^2)
        }                                   // Space Complexity: O(1)
        printArray(arr, 0, n-1, '\n');
    }
}

void insertionSort(int *arr, int n){    
    int temp;
    printArray(arr, 0, n-1, '\n');
    for(int i=1; i<n; i++){                 // Starting from the second element,
        int j= i, temp= arr[i];             // goes to the left, moving every element
        while(j>0 && temp<arr[j-1]){        // similar to insertion, if it is lesser 
            arr[j]= arr[j-1];               // then settles in it's new position, similar to insertion 
            j--;                            // Time Complexity: O(n^2)
        }                                   // Space Complexity: O(1)
        arr[j]= temp;
        printArray(arr, 0, n-1, '\n');
    }
}

void selectionSort(int *arr, int n){        // This is what we do naturally
    printArray(arr, 0, n-1, '\n');
    for(int i=0; i<n; i++){                 // select the min, swap it with first element
        int minI= i;                        // then ignoring first, do the same for second
        for(int j=i+1; j<n; j++)            // repueat until all the elements are covered
            if(arr[j]<arr[minI])
                minI= j;
        int temp= arr[i];                   // Time Complexity: O(n^2)
        arr[i]= arr[minI];                  // Space Complexity: O(1)
        arr[minI]= temp;
        printArray(arr, 0, n-1, '\n');
    }
}

void merge(int *arr, int start, int mid, int end, int *buffArray){
    int ls= start, rs= mid+1, ln= mid+1-start, rn= end-mid, i, j, k;
    for(i=0; i<ln; i++)                             // a buffer array of the same size of initial array is taken
        buffArray[ls+i]= arr[ls+i];                 // and the elements we have to sort will be transferred to the 
    for(i=0; i<rn; i++)                             // same locations as in initial
        buffArray[rs+i]= arr[rs+i];                 // Now, considering each of it's half as a sorted array, 
    i=j=k=0;                                        // we are going to merge it into the initial array,
    while(i<ln && j<rn){                            // replacing the elements
        if(buffArray[ls+i]<buffArray[rs+j]){
            arr[start+k]= buffArray[ls+i];
            i++; k++;                               // this loop will compare elements of both arrays and
        }else{                                      // appends the smaller element in each iteration,
            arr[start+k]= buffArray[rs+j];          // until one of the arrays are exhausted
            j++; k++;
        }
    }
    while(i<ln){                                    // these loops will take care of the elements of 
        arr[start+k]= buffArray[ls+i];              // un-exhausted array. Since those are sorted,
        i++; k++;                                   // just append those directly
    }
    while(j<rn){
        arr[start+k]= buffArray[rs+j];
        j++; k++;
    }
}

void mergeSort(int *arr, int start, int end, int *buffArray){       // Divide and Rule
    if(start>=end)                                  // terminating condition
        return;
    int mid= (start+end)/2;
    printArray(arr, start, mid, '\t');
    printArray(arr, mid+1, end, '\n');
    mergeSort(arr, start, mid, buffArray);          // sort the first half
    printArray(arr, start, mid, '\t');
    printArray(arr, mid+1, end, '\n');
    mergeSort(arr, mid+1, end, buffArray);          // sort the second half
    printArray(arr, start, mid, '\t');
    printArray(arr, mid+1, end, '\n');
    merge(arr, start, mid, end, buffArray);         // and merge both at end
    printArray(arr, start, end, '\n');
    cout<<endl;                                     // Time Complexity: O(nlogn), Space Complexity: O(n)
}

void subArrays(int *arr, int n) {
    for(int i=0; i<n; i++) {                        // `i` will be starting point
        for(int j=i; j<n; j++) {                    // `j` will be ending point
            for(int k=i; k<=j; k++)
                cout<<arr[k]<<' ';                  // then print everything in between
            cout<<endl;
        }
    }
}

void subSequences(int *arr, int n) {
    unsigned int s= pow(2, n);                      // no. of subsequences
    for(int i=1; i<s; i++) {                        // follows convention 001, 010, 011, 100, ....
        for(int j=0; j<n; j++)
            if(i & (1<<j))                          // if jth bit is set, print jth element
                cout<<arr[j]<<' ';
        cout<<endl;
    }
}
