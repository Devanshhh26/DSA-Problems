/*
1. pehle edges vector ko sort kar lenge on the basis of the weight
2.parent aur rank vector banalenge
3.har node ki rank 0 initialize kar denge aur har element ko khudka parent mark kar denge
4. minimmum weight ke lie ek variable bana lenge
5. loop chalaenge har node ke lie
6. pehle 2 vertex jinke beech me sabse kam weight hai unke parent nikalke u aur v me store karwa denge aur unka weight bhi sabse kam hoga kyoki humne pehle hi edges vector ko sort kar dia tha
    agar u aur v different hue to hum unke beech ka weight add kar denge minWeight variable me
7.  fir hum u aur v ko ek disjoint set me add kar denge on the basis of the rank


void makeSet(vector<int>&parent,vector<int>&rank,int n)         
{
    for(int i=0;i<n;i++)                            
    {
        parent[i]=i;
        rank[i]=0;

    }
}

int findParent(vector<int>&parent,int node)             //hume element ke top most ancestor tak jana hai aur hume tabhi pata chalega ki vo top most ancestor hai jab vo element hi khudka parent hoga to jab hum iss condition ko hit karenge to matlab we have found the parent
{
    if(parent[node]==node)                              // agar element hi khud ka parent aa jae to return kar denge element ko
    {
        return node;
    }
    return parent[node]=findParent(parent,parent[node]);    // recursive call maar denge parent node ko as a node jisse parent node ka parent nikal sake 
}

void unionSet(int u,int vector<int>&parent,vector<int>&rank)
{
    u=findParent(parent,u);                                  // u ka parent nikal lia
    v=findParent(parent,v);                                  // v ka parent nikal lia

    if(rank[u]<rank[v])                                     // agar u ki rank choti hai to v ko u ka parent mark kar denge
    {
        parent[u]=v;
    }
    else if (rank[v]<rank[u])                              // agar v ki rank choti hai to u ko v ka parent mark kar denge
    {
        parent[v]=u;
    }
    else                                                    // agar dono ki rank same hai to kisi ko bhi kisi ka bhi parent mar kar sakte hai but parent jisko mark karenge uski rank increament kar denge
    {
        parent[v]=u;
        rank[u]++;
    }
}

bool cmp(vector<int>&a,vector<int>&b)                       // weight ke basis pe sort kar denge edges vector ko
{
    return a[2]<b[2];
}

int MST(vector<vector<int>>&edges,int n)
{   
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank(n);
    makeSet(parent,rank,n);

    int minWeight=0;

    for(int i=0;i<edges.size();i++)
    {
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int w=edges[i][2];
        if(u!=v)
        {
            minWeight=minWeight+w;
            unionSet(u,v,parent,rank); 
        }
    }
    return minWeight;
}

*/