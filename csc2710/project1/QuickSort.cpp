//Ashlyn Hanks

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>

using namespace std::chrono;

using namespace std;
void Load(int arr[])
{
	ifstream inFile;
	inFile.open("Data.txt");
	
	int i;
	for (i=0; i<100000; i++)
	{
		inFile >> arr[i];
	}
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 

int main() 
{
    int arr[2000]; 
    //int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    ifstream inFile;
    inFile.open("randomlist.txt");
    
  
    int i;
    clock_t cl;

    for(i=0; i<2000; i++)
    {
	inFile >> arr[i];
    }
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time to sort random list:" << duration.count() << "microseconds" << endl;
    inFile.close();

    inFile.open("almostsorted.txt");
    
    int arr2[2000];
    clock_t c2;

    for(i=0; i<2000; i++)
    {
        inFile >> arr2[i];
    }

    
    int m = sizeof(arr2)/sizeof(arr2[0]); 
    auto start = high_resolution_clock::now();
    quickSort(arr2, 0, m);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time to sort random list:" << duration.count() << "microseconds" << endl;
    inFile.close();

    inFile.open("duplicated.txt");

    int arr3[2000];
    clock_t c3;

    for(i=0; i<2000; i++)
    {
        inFile >> arr3[i];
    }

    c3 = clock();
    int o = sizeof(arr3)/sizeof(arr3[0]);
    auto start = high_resolution_clock::now();
    quickSort(arr3, 0, m);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time to sort random list:" << duration.count() << "microseconds" << endl;


    inFile.close();

    inFile.open("reversed.txt");

    int arr4[2000];
    clock_t c4;

    for(i=0; i<2000; i++)
    {
        inFile >> arr4[i];
    }

    c4 = clock();
    int p = sizeof(arr4)/sizeof(arr4[0]);
    auto start = high_resolution_clock::now();
    quickSort(arr4, 0, p);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time to sort random list:" << duration.count() << "microseconds" << endl;

    inFile.close();
   
    //endl; 
    return 0; 
} 
