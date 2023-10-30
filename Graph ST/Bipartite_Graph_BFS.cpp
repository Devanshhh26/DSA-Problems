//  https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// no two adjacent nodes should have same color
/*

private :
    bool check(int start,int V,vector<int>adj[],int color[])
    {
        queue<int>q;                
	    q.push(start);                                      // q pe pehla node push kardo 
	    color[start]=0;                                     // pehle node ke index pe 0 color kardo                           
	    while(!q.empty())                               
	    {
	        int node=q.front();                             // pehla node nikal lo aur store karlo
	        q.pop();                                                    
	        for(auto adjNode:adj[node])                     // ab uske adjacent nodes ko traverse karo 
	        {
                if(color[adjNode]==-1)                      // agar vo -1 hue to matlab vo color nahi ho rakhe to unhe node ke opposite color me color kardo that is agar node 0 hai to unhe 1 kardo aur agar 1 hai to -1 kardo color array me
                {
                    color[adjNode]=!color[node];
                    q.push(adjNode);                        // aur fir adjacent node ko bhi q me push kardo
                }
                else if(color[adjNode]==color[node])        // agar node aur adjacent node ka color same aa jae to it is not a bipartite graph so return false
                {
                    return false;
                }
	        }
	    }
	    return true;
    }

public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];                           // ek color array bana lo aur sabko -1 se initialize kar do
	    for(int i=0;i<V;i++)
	    {
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++)                // ultiple components handle karne ke lie
	    {
	        if(color[i]==-1)
	        {
	            if(check(i,V,adj,color)==false)
	            {
	                return false;
	            }
	            
	        }
	    }
	    return true;
	}

*/