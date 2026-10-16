#include <bits/stdc++.h>
using namespace std;
template <class T>
class WeitaVector{
    private:
        T*a;
        int n;
        int capacity;
    public:
        WeitaVector(){
            n=0;
            capacity=2;
            a=new T[capacity];
        }
        ~WeitaVector(){
            delete[] a;

        }
        WeitaVector(const WeitaVector&v){
            n=v.n;
            capacity=v.capacity;
            a=new T[capacity];
            for (int i=0;i<n;i++){
                a[i]=v.a[i];
            }
        }
        WeitaVector& operator=(const WeitaVector &v){
            if (this==&v) return *this;
            T *b=new T[v.capacity];
            for (int i=0;i<v.n;i++){
                b[i]=v.a[i];
            }
            delete[] a;
            a=b;
            n=v.n;
            capacity=v.capacity;
            return *this;
        }
        void push_back(T x){
            if (n==capacity){
                capacity*=2;
                T *b=new T[capacity];
                for (int i=0;i<n;i++){
                    b[i]=a[i];
                }
                delete[] a;
                a=b;
            }
            a[n++]=x;
        }
        void pop_back(){
            if (n>0){
                n--
            }
        }
        int size() const{
            return n;
        }
        int capacity()const{
            return cap;
        }
        bool empty() const{
            return n==0;
        }
        void clear(){
            return n=0;
        }
};
