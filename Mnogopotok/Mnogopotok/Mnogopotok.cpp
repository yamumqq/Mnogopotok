﻿#include <iostream>
#include <thread>
#include <vector>

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() > 1) {
            int mid = arr.size() / 2;
            std::vector<int> left(arr.begin(), arr.begin() + mid);
            std::vector<int> right(arr.begin() + mid, arr.end());

            Sort(left);
            Sort(right);

            Merge(arr, left, right);
        }
    }

private:
    void Merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    std::vector<int> arr(10);
    std::cout << "Введите 10 целых чисел для сортировки: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }

    MergeSort mergeSort;
    std::thread mergeSortThread([&mergeSort, &arr]() {
        mergeSort.Sort(arr);
        });
    mergeSortThread.join();

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}