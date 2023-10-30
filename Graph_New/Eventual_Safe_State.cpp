// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
/*

jo node terminal node hota hai that is jiski outdegree 0 hoti hai vo safe node hota hai aur jo node jiske saare path kisi
terminal node me end ho uss node ko bhi safe node kehte hai

hume safe nodes in a graph nikalne hai ascending order me

yeh question easily cycle detection using dfs se ho jaega kyoki jo nodes kisi cycle me present honge vo kabhi safe nahi ho sakte 
kyoki unka 1 path aesa zaroor hoga jo khudpe aake end hoga jo safe node ki condition ko follow nahi karta that is ki saare path terminal node pe end hona chahiye
aur termonal node ki outdegree 0 hoti hai

to hum jab bhi cycle detect karte hai aur hume nahi milta hai to jab hum vapis se dfsVisited ko false mark karte hai hum tab 
uss element ko safe mark kar denge 

bool checkCycle(vector<int>adj[],int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,int safeNodes[])
  {
    visited[src]=true;
    dfsVisited[src]=true;
    safeNodes[src]=0;               // pehle src node ko bhi 0 mark kar do 
    for(auto nbr:adj[src])
    {
        if(!visited[nbr])
        {
            bool aageKaAns=checkCycle(adj,nbr,visited,dfsVisited,safeNodes);
            if(aageKaAns)
            {
                return true;    
            }
        }
        if(visited[nbr]==true &&  dfsVisited[nbr]==true)                // cycle present hai
        {
            return true;
        }
    }
    dfsVisited[src]=false;                          // cycle present nahi hai tabhi hum iss step me pahuchenge varna upar vali if statement se hi return kar jaate
    safeNodes[src]=1;                               // cycle present nahi hai isliye safeNodes[src] ko 1 mark kardo
    return false;
  }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        //vector<int>safeNodes(V,0);       TLE maar raha tha isliye iski jagah next line me array use kar lia
        int safeNodes[V]={0};               // pehle sabko 0 se initialise kar dia
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                checkCycle(adj,i,visited,dfsVisited,safeNodes);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(safeNodes[i]==1)               // agar safeNodes[i]==1 hua to matlab i ek safe node tha aur use ans me push kardo
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

*/