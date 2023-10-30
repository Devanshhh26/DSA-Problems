/*
topological sort only works in DAG

normal dfs lagaenge but jab return kar rahe honge recursion me to uss element ko stack me push kar denge aur fir end me stack se
saare elements nikal ke vector me store kar lenge


void topoSort(int node,vector<bool>&visited,stack<int>&st,unordered_map<int,bool>&adjList)
{
    visited[node]=true;
    for(auto neighbour:adjList[node])
    {
        if(!visited[neighbour])
        {
            topoSort(neightbour,visited,stack,adjList);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>&edges,int v,int e)
{
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1]
        adjList[u].push_back(v);
    } 

    vector<bool>visited;
    stack<int>st;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            topoSort(i,visited,st,adjList);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

*/