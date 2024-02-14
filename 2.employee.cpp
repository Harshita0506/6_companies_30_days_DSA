class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> m;
        vector<string> ans;
        for(auto &i:access_times)
        {
            int a=((i[1][0]-'0')*10+i[1][1]-'0')*60+((i[1][2]-'0')*10+i[1][3]-'0');
            m[i[0]].push_back(a);
        }

        for(auto &i:m)
        {
            if(i.second.size()<3)
            continue;
            sort(i.second.begin(),i.second.end());
            for(int j=0;j<i.second.size()-2;j++)
            {
                //cout<<j<<" "<<i.second.size()<<" "<<i.first<<endl;
                if(abs(i.second[j]-i.second[j+1])<60 && abs(i.second[j]-i.second[j+2])<60)
                {
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        return ans;
    }
};