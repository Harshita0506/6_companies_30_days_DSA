class Solution {
public:
    bool check(vector<int>& nums)
    {
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] <= nums[i-1])
            {
                return false;
            }
        }

        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        for(int i=0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                //for making all subarray arr1[0-->i-1] and [j+1-->n-1]
                vector<int> arr;
                for(int k=0; k<i; k++)
                {
                    arr.push_back(nums[k]);
                }

                for(int k=j+1; k<n; k++)
                {
                    arr.push_back(nums[k]);
                }

                if(check(arr))
                {
                    ct++;
                }

            }

        }

        return ct;
    }
};