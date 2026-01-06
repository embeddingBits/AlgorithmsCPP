#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
using namespace std;

constexpr int MIN_SIZE = 1000;

template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    vector<T> temp;
    temp.reserve(right - left + 1);

    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    copy(temp.begin(), temp.end(), arr.begin() + left);
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right, int depth = 0) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    if (right - left > MIN_SIZE && depth < thread::hardware_concurrency()) {
        thread t1(mergeSort<T>, ref(arr), left, mid, depth + 1);
        thread t2(mergeSort<T>, ref(arr), mid + 1, right, depth + 1);
        t1.join();
        t2.join();
    } else {
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
    }

    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {9, 4, 7, 3, 1, 6, 2, 8, 5};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}

