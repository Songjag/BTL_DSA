#ifndef WEITA_VECTOR_H
#define WEITA_VECTOR_H
#include <iostream>
#include <utility>
template <class T>
class WeitaVector {
private:
    T *a;
    int n;
    int cap;
public:
    WeitaVector() : a(new T[2]), n(0), cap(2) {}
    ~WeitaVector() { delete[] a; }
    WeitaVector(const WeitaVector &v) : a(new T[v.cap]), n(v.n), cap(v.cap) {
        for (int i = 0; i < n; i++)
            a[i] = v.a[i];
    }
    WeitaVector &operator=(const WeitaVector &other) {
        if (this != &other) {
            WeitaVector copy(other);
            swap(copy);
        }
        return *this;
    }
    void push_back(T x) {
        if (n == cap)
            reserve(cap * 2);
        a[n++] = x;
    }
    void pop_back() {
        if (n > 0)
            n--;
    }
    int size() const { return n; }
    int capacity() const { return cap; }
    bool empty() const { return n == 0; }
    void clear() { n = 0; }
    void swap(WeitaVector &v) {
        std::swap(a, v.a);
        std::swap(n, v.n);
        std::swap(cap, v.cap);
    }
    void reserve(int new_capacity) {
        if (new_capacity <= cap)
            return;

        T *b = new T[new_capacity];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        delete[] a;
        a = b;
        cap = new_capacity;
    }
    void erase(int position) {
        if (position < 0 || position >= n)
            return;
        for (int i = position; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }
    void insert(int position, T value) {
        if (position < 0 || position > n)
            return;
        if (n == cap)
            reserve(cap * 2);
        for (int i = n; i > position; i--)
            a[i] = a[i - 1];
        a[position] = value;
        n++;
    }
    void resize(int new_size, T value = T()) {
        if (new_size < 0)
            return;
        if (new_size > cap)
            reserve(new_size);
        for (int i = n; i < new_size; i++)
            a[i] = value;
        n = new_size;
    }
    T *begin() { return a; }
    const T *begin() const { return a; }
    T *end() { return a + n; }
    const T *end() const { return a + n; }
    T &at(int i) { return a[i]; }
    const T &at(int i) const { return a[i]; }
    T &front() { return a[0]; }
    const T &front() const { return a[0]; }
    T &back() { return a[n - 1]; }
    const T &back() const { return a[n - 1]; }
    void display() const {
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " ";
        std::cout << '\n';
    }
    T &operator[](int i) { return a[i]; }
    const T &operator[](int i) const { return a[i]; }
};
#endif
