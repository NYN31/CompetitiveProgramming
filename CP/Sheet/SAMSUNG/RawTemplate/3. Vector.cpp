/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

#define sz 10


template<typename T> class Vector{
    int *arr; /// use T instead of int for all types of data
    int capacity; /// current vector capacity
    int current; /// current vector size
public:
    Vector(){
        arr = new int[1]; /// use T instead of int for all types of data
        capacity = 1;
        current = 0;
    }
    void push(int e) {
        if(current == capacity) {
            int *temp = new int[2 * capacity]; /// use T instead of int for all types of data

            for(int i=0; i<capacity; i++)
                temp[i] = arr[i];

            delete arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current++] = e;
    }
    int get(int index) {
        if(index > -1 && index < current)
            return arr[index];
    }
    void pop() {
        current--;
    }
    int length(){
        return current;
    }
    int getCapacity() { return capacity; }

    void print() {
        for(int i=0; i<current; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void solve() {
    Vector<int> vec;
    vec.push(5);
    vec.push(3);
    vec.push(7);
    vec.push(9);
    vec.push(2);
    vec.push(-1);

    vec.print();

    cout << vec.get(3) << endl;
    cout << vec.length() << endl;
    //cout << getCapacity() << endl;
    vec.pop();
    vec.print();
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
