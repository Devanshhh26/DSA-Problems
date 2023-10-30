/*

vector<int>dijkstra(vector<vector<int>>&vec,int vertices, int edges,int source)
{   

    // adjacency list bana li
    unordered_map<int ,list<pair<int,int>>>adjList;
    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    // distance vector bana lia aur usme infinity mark kar dia
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++)
    {
        dist[i]=INT_MAX;
    }

    // set create kaqr lia on the basis of distance and node
    set<pair<int,int>>st;

    // initialize distance vector and set with source node
    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        auto top=*(st.begin());                                    // set ka begin hamesha minimum distance valki node dega (structure of set<distance,node> aur set pehli value ke basis me sort karta hai that is distance ) , set ki jagah hum minimum priority queue bhi use kar sakte the
        int nodeDistance=top.first;                               // set se minimum distance nikal lia
        int topNode=top.second;                                     // aur uska node nikal lia
        st.erase(st.begin());                                       // fir use remove kar dia set se

        for(auto neighbour:adjList[topNode])                         // ab uss node ke neighbours ko nikala
        {   
            if(nodeDistance+neighbour.second<dist[neighbour.first])             // ab uss node se unke neighbours ka distance calculate kia by comparing (current node tak distance + neighbour tak distance) by the (current distance of neighbour in distance vector)
            {
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));          // agar yeh neighbour aur uska distance alreeady present ho set me to use erase kar do set se

                if(record!=st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first]=nodeDistance+neighbour.second;                // update the distance of neighbour in the distance vector
                st.insert(make_pair(dist[neighbour.first],neighour.first));         // neighbour aur neighbour ke distance ko set me push kardo
            }
        }
    }
    return dist;
}


*/