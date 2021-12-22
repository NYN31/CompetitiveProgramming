int l_bound(vector<ll>& arr,ll val){
    int lo = 0, hi = n-1, pos = n ;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2 ;
        if(arr[mid] >= val){
            pos = mid ;
            hi = mid - 1 ;
        }
        else lo = mid + 1 ;
    }
    return pos ;
}
 
int u_bound(vector<ll>& arr,ll val){
    int lo = 0, hi = n-1, pos = n ;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2 ;
        if(arr[mid] > val){
            pos = mid ;
            hi = mid - 1 ;
        }
        else lo = mid + 1 ;
    }
    return pos ;
}