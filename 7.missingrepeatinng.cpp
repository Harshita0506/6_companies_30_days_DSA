vector<int> find_missing(vector<int> nums)
{            
    unordered_map<int,int> mp;
    vector<int> v1;
    for(auto i:nums)
    {        mp[i]++;     }

        for(auto i:mp)
        {          
            if(i.second()==2)
            {      
                v1.push_back(i.first());
            }
            else if(i.second()==0)
            {
                v1.push_back(i.first());
            }
        }
        return v1;
};





