/*

https://leetcode.com/problems/count-primes/

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
public:

    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        int ct = 0;
        
        for(int i=2; i*i<n; i++){
            if(sieve[i]){
                for(int j=i*i; j<n; j+=i){
                    sieve[j] = false; 
                }
            }
        }

        for(int i=2; i<n; i++){
            if(sieve[i]) ct++;
        }
        return ct;
    }
};