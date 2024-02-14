class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {   vector<int> v1;
            int count=0;
            for(int j=i;j>=0;j--)
            {   v1.push_back(nums[j]);
                if(nums[j]%p==0)
                {
                    count++;
                }
                if(count<=k)
                {
                    ans.insert(v1);
                }
                else
                {
                    break;
                }
            }
        }
        return ans.size();
    }
};