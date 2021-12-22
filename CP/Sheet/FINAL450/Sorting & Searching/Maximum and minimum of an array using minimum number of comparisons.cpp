
int middle(int A, int B, int C) {
    int mn = min({A, B, C});
    int mx = max({A, B, C});
    if(A != mn && A != mx) return A;
    else if(B != mn && B != mx) return B;
    else return C;
}
