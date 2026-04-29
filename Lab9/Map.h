#pragma once
#include <tuple>

template<typename K, typename V>
class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Entry* newData = new Entry[capacity];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    int findIndex(const K& key) const {
        for (int i = 0; i < size; i++)
            if (data[i].key == key)
                return i;
        return -1;
    }

public:
    Map() {
        capacity = 10;
        size = 0;
        data = new Entry[capacity];
    }

    ~Map() {
        delete[] data;
    }

    
    V& operator[](const K& key) {
        int idx = findIndex(key);
        if (idx != -1)
            return data[idx].value;

        if (size == capacity)
            resize();

        data[size].key = key;
        data[size].value = V();
        size++;
        return data[size - 1].value;
    }


    void Set(const K& key, const V& value) {
        int idx = findIndex(key);
        if (idx != -1) {
            data[idx].value = value;
            return;
        }

        if (size == capacity)
            resize();

        data[size++] = { key, value };
    }


    bool Get(const K& key, V& value) {
        int idx = findIndex(key);
        if (idx == -1)
            return false;
        value = data[idx].value;
        return true;
    }

    
    int Count() const {
        return size;
    }

    
    void Clear() {
        size = 0;
    }

    
    bool Delete(const K& key) {
        int idx = findIndex(key);
        if (idx == -1)
            return false;

        for (int i = idx; i < size - 1; i++)
            data[i] = data[i + 1];

        size--;
        return true;
    }

    
    bool Includes(const Map<K, V>& other) {
        for (int i = 0; i < other.size; i++) {
            if (findIndex(other.data[i].key) == -1)
                return false;
        }
        return true;
    }


    class Iterator {
    private:
        Entry* data;
        int index;

    public:
        Iterator(Entry* d, int i) : data(d), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            index++;
        }

        auto operator*() const {
            return std::tuple<K, V, int>(
                data[index].key,
                data[index].value,
                index
            );
        }
    };

    Iterator begin() {
        return Iterator(data, 0);
    }

    Iterator end() {
        return Iterator(data, size);
    }
};