class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> q(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i+=2)
        {
            nums[i]=q.top();
            q.pop();
        }
    for(int i=0;i<n;i+=2)
        {
            nums[i]=q.top();
            q.pop();
        }
    }
};