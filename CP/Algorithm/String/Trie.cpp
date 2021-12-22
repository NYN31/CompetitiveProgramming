#include<bits/stdc++.h>
using namespace std ;

#define max_leaf  30
struct node{
    bool endpoint ;
    node* next[mx_leaf] ;
    node(){
        endpoint = false ;
        for(int i = 0; i < mx_leaf; i++) next[i] = NULL ;
    }
};

struct Trie{
    node* rt ;

    Trie(){rt = new node ;}

    void add_str(string s){
        int len = s.size() ;
        node* cur = rt ;
        for(int i = 0; i < len; i++){
            int ch = str[i] - 'a' ;
            if(cur->next[ch] == NULL) cur->next[ch] = new node ;
            cur = cur->next[ch] ;
        }
        cur->endpoint = true ;
    }

    bool search_str(string s){
        int len = s.size() ;
        node* cur = rt ;
        for(int i = 0; i < len; i++){
            int ch = str[i] - 'a' ;
            if(cur->next[ch] == NULL) return false ;
            cur = cur->next[ch] ;
        }
        return cur->endpoint ;
    }

    void delete_trie(node* cur){
        for(int i = 0; i < mx_leaf; i++)
            if(cur->next[i]) delete_trie(cur->next[i]) ;
        delete (cur) ;
    }
    ~Trie(){ delete_trie(rt) ;}
};

int main(){
    Trie tri ;

    int n ;
    cin>> n ;

    for(int i = 0; i < n; i++){
        string str ;
        cin>> str ;
        tri.add_str(str) ;
    }

    int q ;
    cin>> q ;
    while(q--){
        string str ;
        cin>> str ;
        if(tri.search_str(str))
            cout<< "Found !!!\n" ;
        else cout<< "Not found !!\n" ;
    }
    
    return 0 ;
}