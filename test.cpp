
#include <bits/stdc++.h>
using namespace std;

template <class T>
class MyVector {
private:
    T *a;
    int n;
    int cap;

public:
    MyVector() {
        n = 0;
        cap = 2;
        a = new T[cap];
    }

    ~MyVector() {
        delete[] a;
    }

    MyVector(const MyVector &v) {
        n = v.n;
        cap = v.cap;
        a = new T[cap];
        for (int i = 0; i < n; i++)
            a[i] = v.a[i];
    }

    MyVector& operator=(const MyVector &v) {
        if (this == &v) return *this;

        T *b = new T[v.cap];
        for (int i = 0; i < v.n; i++)
            b[i] = v.a[i];

        delete[] a;
        a = b;
        n = v.n;
        cap = v.cap;
        return *this;
    }

    void push_back(T x) {
        if (n == cap) {
            reserve(cap * 2);
        }

        a[n++] = x;
    }

    void pop_back() {
        if (n > 0)
            n--;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= n) return;

        for (int i = pos; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;
    }

    void insert(int pos, const T &value) {
        if (pos < 0 || pos > n) return;
        if (n == cap) reserve(cap * 2);

        for (int i = n; i > pos; i--)
            a[i] = a[i - 1];
        a[pos] = value;
        n++;
    }

    T& operator[](int i) {
        return a[i];
    }

    const T& operator[](int i) const {
        return a[i];
    }

    T& at(int i) {
        if (i < 0 || i >= n)
            throw out_of_range("MyVector::at: index out of range");
        return a[i];
    }

    const T& at(int i) const {
        if (i < 0 || i >= n)
            throw out_of_range("MyVector::at: index out of range");
        return a[i];
    }

    T& front() {
        if (empty()) throw out_of_range("MyVector::front: vector is empty");
        return a[0];
    }

    const T& front() const {
        if (empty()) throw out_of_range("MyVector::front: vector is empty");
        return a[0];
    }

    T& back() {
        if (empty()) throw out_of_range("MyVector::back: vector is empty");
        return a[n - 1];
    }

    const T& back() const {
        if (empty()) throw out_of_range("MyVector::back: vector is empty");
        return a[n - 1];
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

    void resize(int new_size, const T &value = T()) {
        if (new_size < 0) return;
        if (new_size > cap) reserve(new_size);
        for (int i = n; i < new_size; i++)
            a[i] = value;
        n = new_size;
    }

    void reserve(int new_capacity) {
        if (new_capacity <= cap) return;

        T *b = new T[new_capacity];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        delete[] a;
        a = b;
        cap = new_capacity;
    }

    void swap(MyVector &other) {
        std::swap(a, other.a);
        std::swap(n, other.n);
        std::swap(cap, other.cap);
    }

    T* begin() {
        return a;
    }

    const T* begin() const {
        return a;
    }

    T* end() {
        return a + n;
    }

    const T* end() const {
        return a + n;
    }

    void display() const {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    cout << "Vector: ";
    v.display();

    cout << "So phan tu: " << v.size() << endl;
    cout << "Dung luong: " << v.capacity() << endl;
    cout << "Phan tu dau: " << v.front() << endl;
    cout << "Phan tu cuoi: " << v.back() << endl;
    cout << "Phan tu tai vi tri 2: " << v.at(2) << endl;

    v.pop_back();
    cout << "Sau pop_back: ";
    v.display();

    v.erase(1);
    cout << "Sau erase(1): ";
    v.display();

    v.insert(1, 25);
    cout << "Sau insert(1, 25): ";
    v.display();

    v.resize(6, 0);
    cout << "Sau resize(6, 0): ";
    v.display();

    v.reserve(10);
    cout << "Dung luong sau reserve(10): " << v.capacity() << endl;

    cout << "Duyet bang begin/end: ";
    for (int *it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    v[0] = 100;
    cout << "Sau khi sua: ";
    v.display();

    MyVector<int> other;
    other.push_back(999);
    v.swap(other);
    cout << "Sau swap, v: ";
    v.display();
    cout << "Sau swap, other: ";
    other.display();

    v.clear();
    cout << "Vector rong? " << (v.empty() ? "Co" : "Khong");

    return 0;
}
