#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
void Sort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
Sort::Sort(std::vector<int> vec, int nrElemente) {
    count = nrElemente;
    v = new int[count];

    for (int i = 0; i < count; i++)
        v[i] = vec[i];
}
Sort::Sort(int count, ...) {
    this->count = count;
    v = new int[count];

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        v[i] = va_arg(args, int);

    va_end(args);
}
Sort::Sort(const char* numbers) {
    count = 0;

    // numărăm câte elemente sunt
    for (int i = 0; numbers[i]; i++)
        if (numbers[i] == ',')
            count++;

    count++; // ultimul element

    v = new int[count];

    char* copy = new char[strlen(numbers) + 1];
    strcpy(copy, numbers);

    char* token = strtok(copy, ",");

    int i = 0;
    while (token != nullptr) {
        v[i++] = atoi(token);
        token = strtok(nullptr, ",");
    }

    delete[] copy;
}
void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < count; i++) {
        int key = v[i];
        int j = i - 1;

        if (ascendent) {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
        } else {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j--;
            }
        }

        v[j + 1] = key;
    }
}
Sort::Sort(int nrElemente, int min, int max) {
    count = nrElemente;
    v = new int[count];

    for (int i = 0; i < count; i++)
        v[i] = min + rand() % (max - min + 1);
}
Sort::~Sort() {
    delete[] v;
}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (ascendent) {
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
            }
            else {
                if (v[j] < v[j + 1])
                    swap(v[j], v[j + 1]);
            }

        }
    }
}

int Sort::partition(int low, int high, bool asc) {
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (asc) {
            if (v[j] < pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }
        else {
            if (v[j] > pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }

    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

void Sort::quickSortRec(int low, int high, bool asc) {
    if (low < high) {
        int pi = partition(low, high, asc);
        quickSortRec(low, pi - 1, asc);
        quickSortRec(pi + 1, high, asc);
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSortRec(0, count - 1, ascendent);
}

void Sort::Print() {
    for (int i = 0; i < count; i++)
        std::cout << v[i] << " ";
    std::cout << '\n';
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < count)
        return v[index];
    return -1;
}