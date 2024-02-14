typedef long long ll;
class Solution {
public:
    
    //mask bit =  1 means visited already
    
    ll mod = 1e9+7;
    
    ll solve(ll previ,vector<int> &nums,ll remlen,ll mask,vector<vector<ll>> &dp)
    {
        if(remlen == 0) return 1; //valid permutation generated
        
        if(dp[previ][mask] != -1) return dp[previ][mask];
        
        ll ans = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(mask&(1<<j)) continue; //already visited then cant be taken
            
            if(nums[previ]%nums[j] == 0 or nums[j]%nums[previ]==0)
            {
                ans += solve(j,nums,remlen-1,mask|(1<<j),dp); //mask|(1<<j) will set the jth bit denoting jth index is visited
                ans %= mod;
            }
        }
        return dp[previ][mask] = ans%mod;
    }
    
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<ll>> dp(15,vector<ll>(1<<15,-1));
        ll ans = 0;
        //initially you can start with any index
        for(int i = 0;i<n;i++)
        {
            ans += solve(i,nums,n-1,0|(1<<i),dp); //initial mask was 0, you do or with 1<<i and the ith index is marked as visited.
            ans %= mod;
        }
        return ans%mod;
    }
};