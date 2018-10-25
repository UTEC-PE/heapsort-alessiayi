#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int size, int curr){
  int max = curr;
  int left = 2*curr + 1;
  int right = 2*curr + 2;

  if (left < size && arr[left] > arr[max]){
    max = left;
  }
  if (right < size && arr[right] > arr[max]){
    max = right;
  }
  if (max != curr){
    swap(arr[curr], arr[max]);
    heapify(arr, size, max);
  }
}

void heapsort(int* arr, size_t size) {
  for (int i = size / 2 - 1; i >= 0; i--){
    heapify(arr, size, i);
  }
  for (int i=size-1; i>=0; i--){
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
  }

}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
