class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
    int left = 0, maxLen = 0;
    std::unordered_map<int, int> freq;

    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;

        // Adjust the left boundary if the frequency condition is violated
        while (freq[nums[right]] > k) {
            freq[nums[left]]--;
            left++;
        }

        // Update the length of the longest good subarray
        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};