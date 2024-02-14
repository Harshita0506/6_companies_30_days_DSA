class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        bool ans=true;
        long long wght=mass;
        for(int i=0;i<asteroids.size();i++)
        {
            if(wght>=asteroids[i])
            {
                wght+=asteroids[i];
            }
            else
            {
                ans=false;
                break;
            }
        }
        return ans;
    }
};