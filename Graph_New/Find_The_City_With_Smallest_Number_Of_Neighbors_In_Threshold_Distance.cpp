// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

/*
hume aesi city nikalni hai jiske threshold distance ke andar minimum neighbors ho
simple dijsktra lagegi har node ko as a source node maanke baaki nodes ka usse distance nikal lenge but ek choti si modification
yeh karenge ki threshold distance se compare karenge agar zyada hua to use consider nahi karenge

agar 2 cities ke minimum neigbors same aaye to badi vali city ko consider karenge for example agar city 0 aur city 3 ke number of 
neighbors same hai to city 3 ko an consider karenge kyoki 3 > 0


class Solution {
public:

    int dijkstra(int src,int n,unordered_map<int,list<pair<int,int>>>&adjList,int &distanceThreshold)
    {
        vector<int>dist(n,INT_MAX);
        set<pair<int ,int>>st;
        dist[src]=0;
        st.insert({0,src});
        int reachableCities=0;
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(st.begin());
            int nodeDist=top.first;
            int node=top.second;
            if(node!=src    &&  nodeDist<=distanceThreshold)                // agar node src node nahi hai aur uska distance threshold distance se kam hai to count ko increament kardo
            {
                ++reachableCities;
            }

            for(auto nbr:adjList[node])
            {
                int currDist=nodeDist+nbr.second;
                if(currDist<dist[nbr.first])
                {
                    auto it=st.find({dist[nbr.first],nbr.first});
                    if(it!=st.end())
                    {
                        st.erase(it);
                        dist[nbr.first]=currDist;
                        st.insert({dist[nbr.first],nbr.first});
                    }
                }
            }
        }
        return reachableCities; 
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int ,list<pair<int,int>>>adjList;
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int city=0;
        int minReachableCities=INT_MAX;
        for(int u=0;u<n;u++)
        {
            int reachableCitiesCount=dijkstra(u,n,adjList,distanceThreshold);          // har city ko source maanke dijkstra laga dia
            if(reachableCitiesCount<=minReachableCities)                               // har city ke threshold distance ke under neighbors nikal lie aur agar kam ya equal hue to minimum ko update kar lia , isme same vala case bhi handle ho jaega kyoki 0 se end jaa rahe hai to minimum agar same bhi aaya to update badi vali city se hi hoga
            {
                minReachableCities=reachableCitiesCount;                                // count update kar lia
                city=u;                                                                 // city update kar li
            }
        }
        return city;
    }
};

*/