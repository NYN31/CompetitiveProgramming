
vector<int> Find(int arr[], int n , int x )
{
    vector <int> ans ;
    int firstPosition = lower_bound(arr, arr + n, x) - arr ;
    int lastPosition = upper_bound(arr, arr + n, x) - arr ;

    cout << firstPosition << " " << lastPosition << endl ;

    if(firstPosition == lastPosition || firstPosition >= n) {
        ans.push_back(-1);
        ans.push_back(-1);
    }else {
        ans.push_back(firstPosition);
        ans.push_back(lastPosition - 1);
    }
    return ans ;
}
