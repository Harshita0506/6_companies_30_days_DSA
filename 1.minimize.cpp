class Solution {
public:

// Calculates LCM of two numbers a and b
// Uses the formula LCM(a,b) = (a*b) / GCD(a,b) 
// GCD is calculated using Euclidean algorithm, which takes O(log(min(a,b))) time
// So overall time complexity is O(log(min(a,b)))
    long long calculateLCM(long long a, long long b) {
        return (a * b) / __gcd(a, b);
    }

// Calculates maximum integer possible if we distribute 'count' integers 
// based on repeating interval of divisor1 and divisor2
// Steps:
// 1) Calculate LCM of divisor1 and divisor2 - O(log(min(divisor1, divisor2)))
// 2) Distribute count in blocks of size (LCM-1)
// 3) Add extra integers left over after division by (LCM-1)
// Overall time complexity is O(1)
    int calculateMax(int count, long long divisor1, long long divisor2 = 1) {
        long long lcmResult = calculateLCM(divisor1, divisor2); 
        return count + count / (lcmResult - 1) - (count % (lcmResult - 1) ? 0 : 1);
    }

// Finds minimum possible maximum integer in either array
// Calculates maximum for 3 cases:
// 1) Distributing uniqueCnt1 based on divisor1
// 2) Distributing uniqueCnt2 based on divisor2
// 3) Distributing all integers based on both divisors 
// Returns minimum of these 3 maximums
// Overall time complexity is O(1) 
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        auto calculateMaxLambda = [&](int count, long long d1, long long d2 = 1) {
            long long lcmResult = calculateLCM(d1, d2);
            return count + count / (lcmResult - 1) - (count % (lcmResult - 1) ? 0 : 1);
        };

        return max({calculateMaxLambda(uniqueCnt1, divisor1), 
                   calculateMaxLambda(uniqueCnt2, divisor2),  
                   calculateMaxLambda(uniqueCnt1 + uniqueCnt2, divisor1, divisor2)});
    }
};

// Example 
// divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
// LCM is 14
// Distributing uniqueCnt1=1 based on divisor1=2 gives max of 1
// Distributing uniqueCnt2=3 based on divisor2=7 gives max of 3  
// Distributing all gives max of 4
// Taking minimum gives 4 as final answer







//binary search solution
class Solution {
public:
    // Recursive function to return gcd of a and b  
    long long gcd(long long int a, long long int b) 
    { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
    } 
    
    // Function to return LCM of two numbers  
    long long lcm(int a, int b) 
    { 
        return (a / gcd(a, b)) * b; 
    }

    bool conditionSatisfied(int d1, int d2, int u1, int u2, long long max_value) {
        long long both_invalid = max_value / lcm(d1, d2);
        long long arr1_invalid = ( max_value / d1 ) - both_invalid;
        long long arr2_invalid = ( max_value / d2 ) - both_invalid;
        long long both_valid = max_value - arr1_invalid - arr2_invalid - both_invalid;

        if (u1 > arr2_invalid) {
            both_valid = both_valid - ( u1 - arr2_invalid );
        }
        if (u2 > arr1_invalid) {
            both_valid = both_valid - ( u2 - arr1_invalid );
        }

        if (both_valid >= 0) return true;
        return false;
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long lower_limit = 1;
        long long upper_limit = INT_MAX;
        
        while ( lower_limit + 1 < upper_limit ) {
            long long mid = (upper_limit + lower_limit) >> 1;
            if (conditionSatisfied(d1, d2, u1, u2, mid)) upper_limit = mid;
            else lower_limit = mid;
        }
        return upper_limit;
    }
};