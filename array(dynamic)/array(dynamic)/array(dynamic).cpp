#include <iostream>

int main() {
    // Get the size of the array from the user
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamically allocate memory for the 1D array
    int* dynamicArray = new int[size];

    // Fill the array with values
    std::cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> dynamicArray[i];
    }

    // Display the elements of the array
    std::cout << "Dynamic 1D Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";

    // Don't forget to free the dynamically allocated memory
    delete[] dynamicArray;

    return