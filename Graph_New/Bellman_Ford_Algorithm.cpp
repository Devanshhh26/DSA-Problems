/*
-ve weights ko handle karne ke lie use hoti hai but -ve sycle nahi hona chahiye


n-1 times if(dist[u]+w)<dist[v])
          {
            dist[v]=dist[u]+w;
          }
condition ko run karenge -ve weight ko handle karne ke lie

aur agar -ve cycle find karne ke lie n times yeh condition run karenge aur check karenge ki dist ki value change hoti hai ya nahi agar hui
to iska matlab -ve cycle present hai else nahi present hai

int bellmanFord(int n,int m,int src,int dest,vector<vector<int>>edges)
{
    vector<int>dist(n+1,1e9);           // dist vector ko infinity se mark kar rahe hai
    dist[src]=0;                        // starting node ke distance ko 0 mark kar dia
    for(int i=1;i<=n;i++)               // loop ko n-1 baar chalana hai
    {
        // traverse on edge list
        for(int j=0;j<m;j++)  
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dist[u]!=1e9 &&  ((dist[u]+w)<dist[v]))          // agar current node ka distance inifinity na ho aur current node + weight ki value jis node pe jaa rahe hai usse kam hui to value update kar do
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    // checking for negative cycle          
    bool flag=0;    
    for(int j=0;j<m;j++)                            // jo 2 loop upar hai usme se andar vale loop ko 1 baar aur chalaenge jisse uska total count dono loop ko mila ke n ho jaega aur n baar chala ke hum -ve cycle check kar sakte hai
    {
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];
        if(dist[u]!=1e9 &&  ((dist[u]+w)<dist[v]))          // agar if condition true hoti hai matlab value change hogi to hum flag ko true mark kar denge
        {
            flag=1;
        }
    }
    if(flag==0)         // agar flag ki value 0 hui to iska matlab -ve cycle present nahi hai
    {
        return dist[dest];
    }
    return -1;
}

*/