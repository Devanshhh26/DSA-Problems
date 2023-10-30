// https://leetcode.com/problems/permutations-ii/description/

// method 1 : efficient
/*
void permutation_helper(vector<int>&nums,vector<vector<int>>&ans,int start)
    {
        if(start==nums.size())                          // agar start ka size nums ke size ke equal ho jae to ans vector me push kardo
        {   
            ans.push_back(nums);                    
            return;
        }
        unordered_map<int,bool>visited;                 // unordered_map banao check karne ke lie kya hum duplicate element ko traverse karke time waste to nahi kar rahe
        for(int i=start;i<nums.size();i++)
        {   
            if(visited.find(nums[i])!=visited.end())        // agar vo element already present ho map me to iska matlab ek  duplicate element ko traverse kar rahe hai to use skip kar sakte hai
            {
                continue;
            }
            visited[nums[i]]=true;                      // agar vo already visited nahi hai to visited me use true mark karo
            swap(nums[i],nums[start]);                  // swap karo
            permutation_helper(nums,ans,start+1);       // recursive call maaro
            swap(nums[i],nums[start]);                  // backtracking
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation_helper(nums,ans,0);
        return ans;
    }
*/


// method 2 : easy but inefficient
// jab ans aa jae jisme duplicates bhi ho use set me daalo vo sirf unique elements lega aur fir ek vector me daal lo vaha se

/*
/*
void permutation_helper(vector<int>&nums,vector<vector<int>>&ans,int start)
    {
        if(start==nums.size())                          // agar start ka size nums ke size ke equal ho jae to ans vector me push kardo
        {   
            ans.push_back(nums);                    
            return;
        }
         for(int i=start;i<nums.size();i++)
        {       
            swap(nums[i],nums[start]);                  // swap karo
            permutation_helper(nums,ans,start+1);       // recursive call maaro
            swap(nums[i],nums[start]);                  // backtracking
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation_helper(nums,ans,0);
        set<vector<int>>st;
        for(auto it: ans)
        {
            st.insert(it);
        }
        ans.clear();
        for(auto it: st)
        {
            sns.push_back(it);
        }
        return ans;
    }
*/