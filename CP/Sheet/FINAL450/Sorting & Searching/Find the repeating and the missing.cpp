
int *findTwoElement(int *arr, int n) {
    static int ans[2];
    int freq[n + 1] = { 0 };
    for(int i=0; i<n; i++) {
        freq[arr[i]] += 1;
        if(freq[arr[i]] > 1) {
            ans[0] = arr[i];
        }
    }
    for(int i=1; i<=n; i++) {
        if(freq[i] == 0) {
            ans[1] = i;
            break;
        }
    }
    return ans;
}
