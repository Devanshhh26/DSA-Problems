// https://leetcode.com/problems/combination-sum/description/

// hum kisi bhi element ko kitni baar bhi le sakte hai 
// agar jab hum target me se kisi element ko minus kare aur vo -ve me chale jae to hum backtrack karke use pop kar denge aur kisi aur element ko try karenge
// agar target=0 ho jae to matalb it is a possible sol to fir ans vector me v vector push kar denge

/*
  void combinationSum_helper(vector<int>&candidate,int target,vector<int>&v,vector<vector<int>>&ans,int index)
    {
        if(target<0)                                            // agar target less than 0 ho jae to return kar denge i.e. it is no t a possible solution
        {
            return;
        }
        if(target==0)                                           // agar target=0 ho jae to matlab it is a possible solution push it into ans vector
        {
            ans.push_back(v);
            return;
        }

        for(int i=index;i<candidate.size();i++)
        {
            v.push_back(candidate[i]);                                         // pehle element ko consider karenge aur v vector me push kar denge
            combinationSum_helper(candidate,target-candidate[i],v,ans,i);       // agar fir usi element ko consider karenge aur target se uss element ki value minus karke recursive call maar denge aur i ko increament nahi karenge kyoki hum ek element ko kitni bhi baar le sakte hai
            v.pop_back();                                                      // aur possible combinations banane ke lie pop kar denge i.e. backtrack karenge
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combinationSum_helper(candidates,target,v,ans,0);
        return ans;
    }
*/