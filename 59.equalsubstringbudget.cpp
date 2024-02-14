class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum=0,i=0,j=0,ans=0;
        while(j<s.size())
        {
            int a=s[j]-'a';
            int b=t[j]-'a';
            sum+=abs(a-b);
            if(sum<=maxCost)
            {
                j++;
                ans=max(ans,(j-i));
            }
            else if(maxCost<sum)
            {
                while(maxCost<sum)
                {
                    int x=s[i]-'a';
                    int y=t[i]-'a';
                    sum-=abs(x-y);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};