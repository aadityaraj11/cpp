#include <iostream>
#include <algorithm> // For the swap function
using namespace std;

int* cyclic(int *arr, int n) {
    int i = 0;
    while (i < n) {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }
    return arr;
}

int main() {
    int arr[] = {5,4,3,2,1};
    int n = 5;
    int* res = cyclic(arr, n); // Corrected the function call

    for (int i = 0; i < n; i++) {
        cout << res[i] << " "; // Use res to print the sorted array
    }
    return 0;
}
