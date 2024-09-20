class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9 + 7;
        
       
        long long lcm_ab = lcm(a, b);
        
        
        long long l = 1;
        long long r = 1ll * n * min(a, b);
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            
            if (countDivisibles(mid, a, b, lcm_ab) >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l % mod;
    }
    
private:
   
    int countDivisibles(long long mid, int a, int b, long long lcm_ab) {
        return (mid / a) + (mid / b) - (mid / lcm_ab);
    }
    
  
    long long lcm(int a, int b) {
        return 1ll * a * (b / gcd(a, b)); 
    
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
