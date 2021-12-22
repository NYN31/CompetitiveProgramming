/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

#define sz 10


class Queue {
    int topId, frontId;
    int arr[sz + 5];
public:
    Queue() {
        topId = -1;
        frontId = 0;
    }
    bool isEmpty() { return frontId > topId; }
    int push(int e) {
        arr[++topId] = e;
    }
    void pop() {
        if(isEmpty()) cout << "Empty Queue" << endl;
        else ++frontId;
    }
    int front() {
        if(isEmpty()) return -1;
        else return arr[frontId];
    }
    int end() {
        if(isEmpty()) return -1;
        else return arr[topId];
    }
    void print() {
        if(isEmpty()) {
            cout << "Empty Queue" << endl;
        }else {
            for(int i=frontId; i<=topId; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

void solve() {
    Queue q;
    q.pop();
    q.print();
    q.push(5);
    q.push(6);
    q.push(8);
    q.print();
    cout << q.front() << " " << q.end() << endl;
    q.pop();
    q.print();
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
