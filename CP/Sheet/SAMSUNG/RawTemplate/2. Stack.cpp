
/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

#define sz 10


class Stack {
    int topId;
    int arr[sz + 5];
public:
    Queue() {
        topId = -1;
    }
    bool isEmpty() { return topId <= -1; }
    int push(int e) {
        arr[++topId] = e;
    }
    void pop() {
        if(isEmpty()) cout << "Empty Stack" << endl;
        else --topId;
    }
    int top() {
        if(isEmpty()) return -1;
        else return arr[topId];
    }
    void print() {
        if(isEmpty()) {
            cout << "Empty Stack" << endl;
        }else {
            for(int i=0; i<=topId; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

void solve() {
    Stack s;
    s.pop();
    s.print();
    s.push(5);
    s.push(6);
    s.push(8);
    s.print();
    cout << s.top() << endl;
    s.pop();
    s.print();
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






