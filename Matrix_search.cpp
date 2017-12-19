// Arash Nemati Hayati
// Efficient algorithm that searches for a value in an m x n matrix.
// Email: a.nematihayati@gmail.com

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int Nrow = A.size();
    int Ncol = A[0].size();
    int low_row = 0, high_row = Nrow - 1;
    int mid_row;
    
    // Search for row
    while (low_row <= high_row) {
        mid_row = low_row + (high_row - low_row) / 2;
        if (A[mid_row][Ncol - 1] == B || A[mid_row][Ncol - 1] == B)
            return 1;
        
        else if (A[mid_row][Ncol - 1] < B) // element is in greater rows
                 low_row = mid_row + 1;
                 
        // element is in that row
        else if (A[mid_row][Ncol - 1] > B && A[mid_row][0] < B){
            low_row = high_row + 1; // exit 
        }
        // element is in smaller rows
        else
                 high_row = mid_row - 1;
    } 

    // Search for column
    int low_col= 0, high_col = Ncol - 1;
    int mid_col;
        while (low_col <= high_col) {
                mid_col = low_col + (high_col - low_col) / 2;
              if (A[mid_row][mid_col] == B)
                 return 1;
                 
              else if (A[mid_row][mid_col] < B)
                    low_col = mid_col + 1;
              else 
                    high_col = mid_col - 1;
        }
    return 0;
}
