/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

template<typename T, typename U> class VectorPair{
    int capacity, current;
    T *first;
    U *second;

public:
    VectorPair() {
        first = new T[1];
        second = new U[1];
        capacity = 1;
        current = 0;
    }
    void push(T a, U b) {
        if(current == capacity) {
            T *temp1 = new T[2 * capacity];
            U *temp2 = new U[2 * capacity];

            for(int i=0; i<current; i++) {
                temp1[i] = first[i];
                temp2[i] = second[i];
            }


            delete first;
            delete second;
            capacity *= 2;
            first = temp1;
            second = temp2;
        }
        first[current] = a;
        second[current] = b;
        current++;
    }
    void pop() {
        current--;
    }
    int length(){
        return current;
    }
    T getFirst(int index) {
        return first[index];
    }
    U getSecond(int index) {
        return second[index];
    }
    void print() {
        for(int i=0; i<current; i++) {
            cout << "{" << first[i] << ", " << second[i] << "} " ;
        }
        cout << endl;
    }
};

void solve() {
    VectorPair<int,int> vp;
    vp.push(1,2);
    vp.push(2,3);
    vp.push(3,4);

    vp.print();

    VectorPair<int, string> vp2;
    vp2.push(1, "noyon");
    vp2.push(2, "noyon");
    vp2.push(3, "nihal");

    vp2.print();

    for(int i=0; i<vp2.length(); i++) {
        cout << vp2.getFirst(i) << " " << vp2.getSecond(i) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int test = 1, no = 0;
    //cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}
