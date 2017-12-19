// Arash Nemati Hayati
// Efficient algorithm that calculates square root of an integer
// Email: a.nematihayati@gmail.com

int Solution::sqrt(int A) {
    int low = 0, high = A - 1; // one int for all variables in the line
    long int mid = 0;
    long int f;
    while (low <= high){
        mid = low + (high - low) / 2;
        f = mid * mid;
        int f2 = (mid + 1) * (mid + 1);
  //      printf("low %d mid %d high %d A %d\n", low, mid, high, A);
        if (f == A) return mid;
        else if (f < A) {
            if (f2 > A) return mid;
            else if (f2 == A) return (mid + 1);
            else low = mid + 1; // root lies after mid
        }
        else high = mid - 1; // root lies before mid
    }
    return mid;
}
