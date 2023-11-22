#include <iostream>
#include <cmath> 

using namespace std;

//  обчислення кількості від’ємних елементів масиву
int countNegativeElementsRecursive(double arr[], int n, int i = 0) {
    if (i == n) {
        return 0; 
    }
    int count = countNegativeElementsRecursive(arr, n, i + 1);
    if (arr[i] < 0) {
        count++; 
    }
    return count;
}

//  знаходження мінімального за модулем елементу масиву
//INFINITY пошуку мінімального за модулем елементу. 
double findMinAbsoluteElementRecursive(double arr[], int n, int i = 0, double minElement = INFINITY) {
    if (i == n) {
        return minElement; 
    }
    if (abs(arr[i]) < abs(minElement)) {
        minElement = arr[i]; 
    }
    return findMinAbsoluteElementRecursive(arr, n, i + 1, minElement);
}

//  обчислення суми модулів елементів після мінімального за модулем елементу
double sumOfAbsoluteElementsAfterMinRecursive(double arr[], int n, double minElement, int i = 0) {
    if (i == n) {
        return 0; 
    }
    double sum = sumOfAbsoluteElementsAfterMinRecursive(arr, n, minElement, i + 1);
    if (arr[i] != minElement) {
        sum += abs(arr[i]); 
    }
    return sum;
}

// Функція для заміни від’ємних елементів їх квадратами
void replaceNegativeElementsWithSquaresRecursive(double arr[], int n, int i = 0) {
    if (i == n) {
        return; 
    }
    if (arr[i] < 0) {
        arr[i] = arr[i] * arr[i]; 
    }
    replaceNegativeElementsWithSquaresRecursive(arr, n, i + 1);
}
//розмір
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    //дійсні числа
    double* arr = new double[n];
    cout << "Enter " << n << " real numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    //масив
    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //цифри з -
    int negativeCount = countNegativeElementsRecursive(arr, n);
    cout << "Number of negative elements: " << negativeCount << endl;

    // Знаходження мінімального за модулем елементу
    double minElement = findMinAbsoluteElementRecursive(arr, n);
    cout << "Minimum absolute element: " << minElement << endl;

    // Обчислення суми модулів елементів після мінімального за модулем елементу
    double sumAfterMin = sumOfAbsoluteElementsAfterMinRecursive(arr, n, minElement);
    cout << "Sum of absolute elements after the minimum absolute element: " << sumAfterMin << endl;

    replaceNegativeElementsWithSquaresRecursive(arr, n);
    //модифікований масив 
    cout << "Modified array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
