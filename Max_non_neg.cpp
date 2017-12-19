// Arash Nemati Hayati
// Algorithm to find the maximum non-negative sub-array of an arbitray array of integers
// Email: a.nematihayati@gmail.com

vector<int> Solution::maxset(vector<int> &A) {
    unsigned long int sum = 0, count = 0, ids = 0, ide = 0;
    
    vector<int> id_start, id_end;
    vector<unsigned long int> tot_sum;
    for (int i = 0; i <= A.size() - 1; i++){
           if (A[i] >= 0){
               sum += A[i]; 
               count++;
               if (i == A.size() - 1){
                    tot_sum.push_back(sum);
                    id_start.push_back( i  - (count - 1) );    
                    id_end.push_back(i);
               }
           }
           else if (A[i] < 0 && count > 0){
                    tot_sum.push_back(sum);
                    id_start.push_back( i - (count) );    
                    id_end.push_back(i - 1);
                    sum = 0, count = 0; // reset for the next segment
           }
    }
    vector <int> segment;
    if (tot_sum.size() == 0)
        return segment;

    sum = tot_sum[0];
    ids = id_start[0];
    ide = id_end[0];
    for (int i = 1; i <= tot_sum.size() - 1; i++){
        if (sum < tot_sum[i]){
            sum = tot_sum[i];
            ids = id_start[i];
            ide = id_end[i];
        }
        else if (sum == tot_sum[i]) {
            if ( (ide - ids) < (id_end[i] - id_start[i]) ){
                ids = id_start[i];
                ide = id_end[i];
            }
            else if ( (ide - ids) == (id_end[i] - id_start[i]) ){
                 if (ids > id_start[i]){
                     ids = id_start[i];
                     ide = id_end[i];
                 }    
            }
        } 
            
    }
    for (int i = ids; i <= ide; i++){
        segment.push_back(A[i]);
    }
    return segment;
}
