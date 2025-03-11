#include <iostream>

void rearrangeEvenFirst(int arr[], int size) {
    int start = 0, end = size - 1;

    while (start < end) {
        // If the left element is even, move the pointer fo rward
        if (arr[start] % 2 == 0) {
            start++;
        }
        // If the right element is odd, move the pointer backward
        else if (arr[end] % 2 != 0) {
            end--;
        }
        // If the left element is odd and the right element is even, swap them
        else {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}

int main() {
    int arr[] = {3, 8, 5, 12, 7, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    rearrangeEvenFirst(arr, size);

    std::cout << "\nArray after rearranging evens first: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
