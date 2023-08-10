#include <Arduino.h>

int myArray[] = {5, 7, 0, 3, 1, 8, 9, 4, 6, 2};

void setup()
{
   Serial.begin(115200);
   int sizeOfArray = findSizeOfArray(sizeof(myArray), myArray);
   Serial.print("The unsorted Array is: ");
   displayArrays(myArray, sizeOfArray);
   Serial.print("The size of Array is: ");
   Serial.println(sizeOfArray);
   Serial.println("Start QuickSort");
   long startTime = micros();
   quickSort(myArray, 0, sizeOfArray - 1);
   long endTime = micros();
   long elapsedTime = endTime-startTime;
   Serial.print("Start Time: ");
   Serial.print(startTime);
   Serial.println(" ms");
   Serial.print("Finish Time: ");
   Serial.print(endTime);
   Serial.println(" ms");
   Serial.print("Elapsed Time: ");
   Serial.print(elapsedTime);
   Serial.println(" ms");
   Serial.print("The sorted Array is: ");
   displayArrays(myArray, sizeOfArray);
}

void loop()
{

}

int findSizeOfArray(int numOfBytes, int myVector[])
{
  int sizeOfVector = numOfBytes/sizeof(myVector[0]);
  return sizeOfVector;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void displayArrays(int arrayData[], int sizeOfData) {
  for(int i = 0; i<sizeOfData; i++) {
  	if (i < sizeOfData-1){
      Serial.print(arrayData[i]);
      Serial.print(", ");
    }else{
      Serial.println(arrayData[i]);
	}
  }
}