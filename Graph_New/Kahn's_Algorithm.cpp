/*
1. find indegree of all nodes
2. 0 indegree valo ko queue me push kardo
3. do bfs

jab bhi koi node ko hatanege to jin jin ko vo point kar raha tha unki indegree kam ho jaegi

vector<int>topologicalSort(vector<vector<int>>&edges,int v,int e)
{
    unordered_map<int,list<int>>adjList;

    // creating adjList
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
    }

    // find all indegree
    vector<int>indegree(v);
    for(auto i:adjList)
    {
        for(auto j:i.second)
        {
            indegree[j]++;              // jis jis ko bhi adjList[i] point karta hai un sabki indegree +1 kardo
        }
    }

    // 0 indegree valo ko push kardo
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    // do bfs
    vector<int>ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();

        //ans ko store kar lo
        ans.push_back(front);

        // neighbour ke indegree update karlo kyoki current element process ho chuka hai
        for(auto neighbour:adjList[front])
        {
            indegree[neighbour]--;
            if(indegree[neighour]==0)               // agar kisi ki indegree 0 ho jae to use q me push kardo
            {
                q.push(neighbour);   
            }
        }
    }
    return ans;
}

*/