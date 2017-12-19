// Arash Nemati Hayati
// Efficient algorithm that calculates the two prime numbers 
// that their sum is equal to an even number 
// Email: a.nematihayati@gmail.com

 bool is_prime( int A) {
    int counter = 0;
        for (int i = 2; i <= sqrt(A); i++){
                if (A % i == 0)
                    counter++;
            }
        if (counter == 0){
            return true;
        }
        else {
            return false;
        }
}
// Sieve of Eratosthenes -- gives all prime numbers smaller than or equal to the input
// O(nlog(logn)))
vector<int> find_primes( int A ){
    vector<bool> primes(A + 1, 1);
    vector <int> P;
    primes[0] = false; // exclude 0
    primes[1] = false; // exclude 1
    for (int i = 2; i <= sqrt(A); i++){
        for (int j = 2; i * j <= A; j++){
        primes[i * j] = false;
        }
    }
    for (int i = 0; i <= A; i++){
        if (primes[i]){
        P.push_back(i);
        }
    }
    return P;
}
vector<int> Solution::primesum(int A) {
    // calculate all prime numbers smaller than a given number
    vector<int> P, S, M;
    P = find_primes(A);
    for (int k = 0; k < P.size(); k++){
        int sub = A - P[k];
         if (is_prime(sub)){
            S.push_back(P[k]);
            S.push_back(sub);
            break;
            }
        }
    return S;
}
