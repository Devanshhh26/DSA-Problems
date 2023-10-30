// https://leetcode.com/problems/combination-sum-ii/

// method 1 : time aur space complexity me thodi prob aa sakti hai

// same as combination sum but isme hum ek element ko sirf 1 baar hi le sakte hai islie recursive call karte vakt i+1 karna padega aur
// hum unique combinations bhi chahie islie ek set banaenge jisme ans vector ko daal denge jo hume fir return me sirf unique elements dega
// hume pehle candidates vector ko sort bhi karna padega kyoki ek order me ans chahiye

/*
void combinationSum_helper(vector<int>&candidate,int target,vector<int>&v,vector<vector<int>>&ans,int index)
    {
        if(target<0)                                        
        {
            return;
        }
        if(target==0)                               
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<candidate.size();i++)
        {
            v.push_back(candidate[i]);                     
            combinationSum_helper(candidate,target-candidate[i],v,ans,i+1);  
            v.pop_back();                                                    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_helper(candidates,target,v,ans,0);
        set<vector<int>>st;
        for(auto it: ans)
        {
            st.insert(it);
        }
        ans.clear();
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
*/

// method 2 : efficient
// hume agar candidate[i]== candidate[i-1] milega to use hum skip kar denge

/*

void combinationSum_helper(vector<int>&candidate,int target,vector<int>&v,vector<vector<int>>&ans,int index)
    {
        if(target<0)                                        
        {
            return;
        }
        if(target==0)                               
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<candidate.size();i++)
        {   
            if(i>index && candidate[i]==candidate[i-1])
            {
                continue;
            }
            v.push_back(candidate[i]);                     
            combinationSum_helper(candidate,target-candidate[i],v,ans,i+1);  
            v.pop_back();                                                    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_helper(candidates,target,v,ans,0);
        return ans;
    }
*/