#ifndef WEITA_VECTOR_H
#define WEITA_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <utility>

template <class T>
class WeitaVector {
private:
    T *a;       // Mang luu cac phan tu
    int n;      // So phan tu hien tai
    int cap;    // Dung luong da cap phat

public:
    // Khoi tao vector rong voi dung luong ban dau bang 2
    WeitaVector() : a(new T[2]), n(0), cap(2) {}

    ~WeitaVector() {
        delete[] a;
    }

    // Sao chep doc lap du lieu cua vector
    WeitaVector(const WeitaVector &v) : a(new T[v.cap]), n(v.n), cap(v.cap) {
        for (int i = 0; i < n; i++)
            a[i] = v.a[i];
    }

    WeitaVector& operator=(const WeitaVector &v) {
        if (this == &v)
            return *this;

        T *b = new T[v.cap];
        for (int i = 0; i < v.n; i++)
            b[i] = v.a[i];

        delete[] a;
        a = b;
        n = v.n;
        cap = v.cap;
        return *this;
    }

    // Them phan tu vao cuoi vector, tu dong mo rong dung luong khi can
    void push_back(const T &x) {
        if (n == cap)
            reserve(cap * 2);
        a[n++] = x;
    }

    void pop_back() {
        if (n > 0)
            n--;
    }

    int size() const {
        return n;
    }

    int capacity() const {
        return cap;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
        n = 0;
    }

    // Hoan doi du lieu cua hai vector
    void swap(WeitaVector &v) {
        std::swap(a, v.a);
        std::swap(n, v.n);
        std::swap(cap, v.cap);
    }

    // Tang dung luong ma khong thay doi so phan tu
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

    // Chen phan tu tai vi tri position
    void insert(int position, const T &value) {
        if (position < 0 || position > n)
            return;
        if (n == cap)
            reserve(cap * 2);

        for (int i = n; i > position; i--)
            a[i] = a[i - 1];
        a[position] = value;
        n++;
    }

    // Thay doi so luong phan tu cua vector
    void resize(int new_size, const T &value = T()) {
        if (new_size < 0)
            return;
        if (new_size > cap)
            reserve(new_size);
        for (int i = n; i < new_size; i++)
            a[i] = value;
        n = new_size;
    }

    // Tra ve iterator dau va sau phan tu cuoi
    T *begin() {
        return a;
    }

    const T *begin() const {
        return a;
    }

    T *end() {
        return a + n;
    }

    const T *end() const {
        return a + n;
    }

    T& operator[](int i) {
        return a[i];
    }

    const T& operator[](int i) const {
        return a[i];
    }

    T& at(int i) {
        if (i < 0 || i >= n)
            throw std::out_of_range("WeitaVector::at: index out of range");
        return a[i];
    }

    const T& at(int i) const {
        if (i < 0 || i >= n)
            throw std::out_of_range("WeitaVector::at: index out of range");
        return a[i];
    }

    T& front() {
        if (empty())
            throw std::out_of_range("WeitaVector::front: vector is empty");
        return a[0];
    }

    const T& front() const {
        if (empty())
            throw std::out_of_range("WeitaVector::front: vector is empty");
        return a[0];
    }

    T& back() {
        if (empty())
            throw std::out_of_range("WeitaVector::back: vector is empty");
        return a[n - 1];
    }

    const T& back() const {
        if (empty())
            throw std::out_of_range("WeitaVector::back: vector is empty");
        return a[n - 1];
    }

    void display() const {
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " ";
        std::cout << '\n';
    }
};

#endif
