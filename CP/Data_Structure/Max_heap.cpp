#include<bits/stdc++.h>
using namespace std;

int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}
int parent(int i)
{
    return i/2;
}

void max_heapify(int heap[], int n, int i)
{
    int l, r, largest = i;
    l = left(i);
    r = right(i);

    if(l<=n && heap[l]>heap[largest])
        largest = l;


    if(r<=n && heap[r]>heap[largest])
        largest = r;


    if(largest != i)
    {
        swap(heap[i], heap[largest]);
        max_heapify(heap, n, largest);
    }
}

void print_heap(int heap[], int n)
{
    for(int i = 1; i<=n; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int is_max_heap(int heap[], int n)
{
    int p;
    for(int i = n; i>1; i--){
        p = parent(i);
        if(heap[p] < heap[i])
            return 0;
    }
    return 1;
}

int heap_insert(int heap[], int n, int value)
{
    int i;
    n = n+1;
    heap[n] = value;
    i = n;
    while(i>1 && heap[i]>heap[parent(i)])
    {
        int p = parent(i);
        swap(heap[i], heap[p]);
        i = p;
    }
    return n;
}

int heap_delete(int heap[], int n, int node)
{
    int delete_item = heap[node];
    heap[node] = heap[n];
    n = n-1;
    max_heapify(heap, n, 1);
    cout << "Delete Item is: " << delete_item << endl;
    return n;
}

void heap_sort(int heap[], int n)
{
    int n2 = n;
    for(int i = n; i>1; i--)
    {
        swap(heap[1], heap[i]);
        n = n-1;
        //print_heap(heap, n);
        max_heapify(heap, n, 1);
    }
    print_heap(heap, n2);
}

int main()
{
    int n, heap[100];
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> heap[i];
   // print_heap();
    for(int i = n/2; i>=1; i--)
        max_heapify(heap, n, i);

    if(is_max_heap(heap, n))
        cout << "Yes, this is max heap after heaping." << endl;
    else cout << "No, this is not max heap after heaping" << endl;

    print_heap(heap, n);

    while(1)
    {
        int ch;
        cout << "\n1. Insert" << endl; /// nlogn complexity
        cout << "2. Delete" << endl;
        cout << "3. Sort" << endl;
        cout << "4. Print" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        if(is_max_heap(heap, n)) cout << "YES, max heap" << endl;
        if(ch == 1){
            int node_value; cin >> node_value;
            n = heap_insert(heap, n, node_value); /// returned heap size
        }
        else if(ch == 2){
            int node; cin >> node;
            n = heap_delete(heap, n, node); /// returned heap size
        }
        else if(ch == 3) heap_sort(heap, n);
        else if(ch == 4) print_heap(heap, n);
    }

    return 0;
}
/*
9
12 7 1 3 10 17 19 2 5
*/

