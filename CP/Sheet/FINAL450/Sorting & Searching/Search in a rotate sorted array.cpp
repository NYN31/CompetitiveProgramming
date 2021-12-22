int search(vector<int>& nums, int t) {
    int lo = 0, hi = nums.size() - 1, mid, ans = -1, f = nums[0];
    if(f == t) return 0;
    while(lo <= hi) {
        mid = (hi + lo) / 2 ;

        if(nums[mid] == t) {
            ans = mid ;
            break ;
        }
        else if(t > f && nums[mid] > t) {
            if(nums[mid] < f) lo = mid + 1 ;
            else hi = mid - 1 ;
        }
        else if(t > f && nums[mid] < t) {
            if(nums[mid] < f) hi = mid - 1 ;
            else lo = mid + 1;
        }
        else if(t < f && nums[mid] < t) {
            if(nums[mid] < f) lo = mid + 1 ;
            else hi = mid - 1 ;
        }
        else if(t < f && nums[mid] > t) {
            if(nums[mid] < f) hi = mid - 1 ;
            else lo = mid + 1 ;
        }
        else break;

    }
    return ans ;
}
