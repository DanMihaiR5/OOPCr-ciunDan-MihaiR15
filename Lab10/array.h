#pragma once
#include <exception>
using namespace std;


class ExceptieIndex : public exception {
public:
    const char* what() const throw() {
        return "Index invalid!";
    }
};

class ExceptieAlocare : public exception {
public:
    const char* what() const throw() {
        return "Memorie insuficienta!";
    }
};


class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};


template<class T>
class ArrayIterator {
private:
    T** List;
    int Current;

public:
    ArrayIterator(T** list = nullptr, int current = 0) {
        List = list;
        Current = current;
    }

    ArrayIterator& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        Current--;
        return *this;
    }

    bool operator!=(ArrayIterator<T>& other) {
        return Current != other.Current;
    }

    bool operator=(ArrayIterator<T>& other) {
        Current = other.Current;
        List = other.List;
        return true;
    }

    T* GetElement() {
        return List[Current];
    }
};

// ================= ARRAY =================

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void Resize() {
        Capacity = (Capacity == 0) ? 1 : Capacity * 2;
        T** newList = new T*[Capacity];

        for (int i = 0; i < Size; i++)
            newList[i] = List[i];

        delete[] List;
        List = newList;
    }

public:
    // constructor default
    Array() {
        Capacity = 0;
        Size = 0;
        List = nullptr;
    }

    // constructor cu capacitate
    Array(int capacity) {
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
    }

    // destructor
    ~Array() {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }

    // constructor copiere
    Array(const Array<T>& other) {
        Capacity = other.Capacity;
        Size = other.Size;

        List = new T*[Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*other.List[i]);
    }

    // operator []
    T& operator[](int index) {
        if (index < 0 || index >= Size)
            throw ExceptieIndex();
        return *List[index];
    }

    // add la final
    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity)
            Resize();

        List[Size++] = new T(newElem);
        return *this;
    }

    // insert element
    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size)
            throw ExceptieIndex();

        if (Size >= Capacity)
            Resize();

        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];

        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    // insert array
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size)
            throw ExceptieIndex();

        for (int i = 0; i < otherArray.Size; i++) {
            Insert(index + i, *otherArray.List[i]);
        }

        return *this;
    }

    // delete
    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw ExceptieIndex();

        delete List[index];

        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];

        Size--;
        return *this;
    }

    // operator =
    bool operator=(const Array<T>& other) {
        if (this == &other)
            return true;

        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;

        Capacity = other.Capacity;
        Size = other.Size;

        List = new T*[Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*other.List[i]);

        return true;
    }


    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    swap(List[i], List[j]);
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }


    int Find(const T& elem) {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }


    int GetSize() {
        return Size;
    }

    int GetCapacity() {
        return Capacity;
    }


    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size);
    }
};