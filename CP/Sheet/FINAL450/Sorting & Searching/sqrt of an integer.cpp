class Solution {
  public:
    int countSquares(int N) {
        int total = sqrt(N);
        if(total * total == N) {
            total -= 1 ;
        }
        return total ;
    }
};
