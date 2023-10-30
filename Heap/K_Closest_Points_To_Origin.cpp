// https://leetcode.com/problems/k-closest-points-to-origin/description/

// pehle saare elements ek min heap me daal denge aur usme se fir k elements store karwa lenege


/*
  class mycomp{
        public:
        bool operator()(pair <int,int>&a,pair<int,int>&b)
        {
            int distA=a.first*a.first+a.second*a.second;
            int distB=b.first*b.first+b.second*b.second;
            return distA>distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;           // min heap

        for(auto p:points)
        {
            pq.push({p[0],p[1]});                                               // har vector ko min heap me push kar dia
        }
        while(!pq.empty() && k--)                                               // jab tak ya to min heap empty na ho jae ya fir k=0 na ho jae
        {
            auto& top=pq.top();                                                 // pop karo aur store karo element ko
            ans.push_back({top.first,top.second});
            pq.pop();
        }
        return ans;
    }
*/