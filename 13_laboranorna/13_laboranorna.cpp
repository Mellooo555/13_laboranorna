#include <iostream>
#include <vector>

using namespace std;

// Функція для обміну двох елементів
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функція для будування піраміди
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Ініціалізуємо найбільший елемент як корінь
    int left = 2 * i + 1; // Індекс лівого дитини
    int right = 2 * i + 2; // Індекс правого дитини

    // Якщо лівий дитина більший за батька
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Якщо правий дитина більший за батька
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Якщо найбільший елемент не корінь
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Рекурсивно перебудовуємо піраміду
        heapify(arr, n, largest);
    }
}

// Основна функція пірамідального сортування
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Будуємо піраміду (розміщаємо масив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Поступово видаляємо елементи з піраміди
    for (int i = n - 1; i > 0; i--) {
        // Переміщаємо поточний корінь в кінець
        swap(arr[0], arr[i]);
        // Перебудовуємо піраміду на скороченому масиві
        heapify(arr, i, 0);
    }
}

// Функція для виводу масиву на екран
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    cout << "Масив до сортування: ";
    printArray(arr);

    heapSort(arr);

    cout << "Масив після сортування: ";
    printArray(arr);
    return 0;
}
