/*** Md Sajjad Hosen Noyon ***/


/***
      problem 1:
      you have an array of n numbers and also given a number k.
      you have to find k distinct odd number from the array and
      print them in descending order.
***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lim = 10000;
class Heap {
public:
      int heap[lim + 2];
      int left(int i);
      int right(int i);
      int parent(int i);
      void max_heapify(int heap[], int sz, int i);
      void print_heap(int heap[], int sz);
      int is_max_heap(int heap[], int sz);
      int heap_insert(int heap[], int sz, int value);
      int heap_delete(int heap[], int sz, int node);
      void heap_sort(int heap[], int sz);
};

int Heap:: left(int i) {
      return 2 * i ;
}
int Heap:: right(int i) {
      return 2 * i + 1 ;
}
int Heap:: parent(int i) {
      return i / 2 ;
}

void Heap:: max_heapify(int heap[], int sz, int i) {
      int l, r, largest = i, t;
      l = left(i);
      r = right(i);

      if(l <= sz && heap[l] > heap[largest]) {
            largest = l ;
      }
      if(r <= sz && heap[r] > heap[largest]) {
            largest = r ;
      }
      if(largest != i) {
            t = heap[i];
            heap[i] = heap[largest];
            heap[largest] = t;
            max_heapify(heap, sz, largest) ;
      }
}

void Heap:: print_heap(int heap[], int sz) {
      for(int i=1; i<=sz; i++)
            cout << heap[i] << " " ;
      cout << endl ;
}

int Heap:: is_max_heap(int heap[], int sz) {
      int p ;
      for(int i=sz; i>1; i--) {
            p = parent(i) ;
            if(heap[p] < heap[i]) return 0 ;
      }
      return 1 ;
}

int Heap:: heap_insert(int heap[], int sz, int value) {
      sz += 1 ;
      heap[sz] = value ;
      int i = sz ;
      while(i > 1 && heap[i] > heap[parent(i)]) {
            int p = parent(i) ;
            swap(heap[i], heap[p]) ;
            i = p ;
      }
      return sz ;
}

int Heap:: heap_delete(int heap[], int sz, int node) {
      int deleted_item = heap[node] ;
      heap[node] = heap[sz];
      sz -= 1 ;
      max_heapify(heap, sz, 1) ;
      cout << "Deleted item is: " << deleted_item << endl ;
      return sz ;
}
void Heap:: heap_sort(int heap[], int sz) {
      for(int i=sz; i>1; i--) {
            swap(heap[1], heap[i]) ;
            sz = sz - 1 ;
            max_heapify(heap, sz, 1) ;
      }
}

void solve() {
      Heap hp = Heap() ;
      int n, k ; cin >> n >> k ;
      for(int i=1; i<=n; i++) cin >> hp.heap[i] ;

      for(int i=n/2; i>=1; i--) hp.max_heapify(hp.heap, n, i) ;

      hp.heap_sort(hp.heap, n) ;
      //hp.print_heap(hp.heap, n) ;

      int prev = - 1;
      for(int i=n; i>=1 && k; --i) {
            if(hp.heap[i] % 2 == 1 && hp.heap[i] != prev) {
                  cout << hp.heap[i] << " " ;
                  k -= 1 ;
                  prev = hp.heap[i] ;
            }
      }
      cout << endl ;
}

int main() {
      int test = 1 ;
      cin >> test ;
      while(test--) {
            solve() ;
      }
}


/***
4

8 3
4 11 7 7 2 6 3 2

9 4
4 11 7 7 3 6 3 2 5

9 3
4 11 7 7 3 6 3 2 5

9 3
7 2 6 3 11 5 4 7 3
***/

