class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> result;

    int sLen = s.length();
    int aLen = a.length();
    int bLen = b.length();

    for (int i = 0; i <= sLen - aLen; ++i) {
        // Check if s[i..(i + aLen - 1)] == a
        bool isAEqual = true;
        for (int j = 0; j < aLen; ++j) {
            if (s[i + j] != a[j]) {
                isAEqual = false;
                break;
            }
        }

        if (isAEqual) {
            // Iterate over possible indices j for b
            for (int j = max(0, i - k); j <= min(sLen - bLen, i + k); ++j) {
                // Check if s[j..(j + bLen - 1)] == b
                bool isBEqual = true;
                for (int l = 0; l < bLen; ++l) {
                    if (s[j + l] != b[l]) {
                        isBEqual = false;
                        break;
                    }
                }

                if (isBEqual && abs(i - j) <= k) {
                    result.push_back(i);
                    break;  // Break to avoid duplicate indices for the same i
                }
            }
        }
    }

    return result;
    }
};