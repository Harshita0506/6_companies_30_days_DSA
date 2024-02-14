class Solution {
public:
    long sumScores(string s) {
        int n = s.length();
        vector<int> z(n, 0); // Z-function array
        int l = 0, r = 0; // Initialize the segment match

        for (int i = 1; i < n; i++) {
            if (i <= r) 
                z[i] = min(z[i - l], r - i + 1); // Calculate z[i] using already computed values if within the segment match
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++; // Extend the segment match
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1; // Update the segment match range
            }
        }
        
        long sum = n; // Initialize sum with the length of the string
        for (int i = 0; i < n; i++) {
            sum += z[i]; // Add z[i] to the sum
        }
        
        return sum;
    }
};