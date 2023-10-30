/*

private :
    bool dfs(int node,int col,vector<int>adj[],int col or[])
    {
       color[node]=col;                                 // color array me uss node ke index pe col ki value daal do (0 ya 1)
       for(auto it: adj[node])                          // node ke adjacent nodes ko traverse karo
       {
           if(color[it]==-1)                               // agar vo color nahi ho rakhe 
           {
               if(dfs(it,!col,adj,color)==false)            // col ki value change kardo agar 0 hai to 1 aur agar 1 hai to 0 aur firse recursive col mardo
               {
                   return false;
               }
           }
           else if(color[it]==col)                          // agar koi element already colored hai aur uske color col ki value ke equal hai to it means it is bipartite
           {
               return false;
           }
       }
       return false;
    }

public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++)
	    {
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(dfs(i,0,adj,color)==false)
	            {
	                return false;
	            }
	            
	        }
	    }
	    return true;
	}

*/