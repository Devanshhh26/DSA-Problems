/*
this algorithm is used to find strongly connected components in the graph

strongly connected components are those components in which we if we start from any node we can traverse through all the other 
nodes present in that component

1. topological sort nikalo
2. graph ka transpose kar do that is agar 1 se 2 directed edge hai to edge ko 2 se 1 kardo
3. topological sort ke order me dfs call kardo


void dfs(int node,unordered_map<int,bool>vis,stack<int>&st,unordered_map<int,list<int>>&adjList)    // topological sort
{
    vis[node]=true;
    for(auto neighbour:adjList[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,vis,st,adjList);
        }
    }
    st.push(node);
}

void revDfs(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&transposeList)
{
    vis[node]=true;
    for(auto neighbour:transposeList)
    {
        if(!vis[neighbour])
        {
            revDfs(neighbour,vis,transposeList);
        }
    }
}

int stronglyConnectedComponents(int v,vector<vector<int>>&edges)
{   
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][0];
        adjList[u].push_back(v);
    }

    // topo sort
    stack<int>st;
    unordered_map<int,bool>vis;
    for(int i=0;i<v;i++)
    {
        if(!visi[i])
        {
            dfs(i,vis,st,adjList);
        }
    }

    // create a transpose graph

    unordered_map<int,list<int>>transpose;
    for(int i=0;i<v;i++)
    {   
        vis[i]=false;                           // kyoki jab humne pehle dfs call ki thi topological sort me tab vis true ho gaya tha sabke lie isliye ise vapis se false kar rahe hai
        for(auto neighbour:adjList[i])
        {
            transpose[neighbour].push_back(i);
        }
    }

    // dfs call using transposed graph
    int count=0;
    while(!st.empty())
    {
        int top=st.top();                       // har stack ke top element ke lie revDfs call karenge agar uska vis false hua to
        st.pop();
        if(!vis[top])
        {
            count++;                           // jitni baar bhi hume dfs karna pada ya jitni baar bhi vis false aaya utni baar count++ kar denge 
            revDfs(top,vis,transpose);
        }
    }
    return count;
}

*/