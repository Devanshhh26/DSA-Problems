/*
what we want to do is create a visited map and parent map
parent map will map each element to its parent
then we will use the parent map to go from  the target node to source node and store it in the array

eg parent map [-1,1,1,1,2,4,8,3] lets saye the indexing starts from 1 so the parent of 1 is -1 ,2 is 1, 3 is 1, 4 is 1, 5 is 2,
6 is 4, 7 is 8, 8 is 3

now we want to go from 8 to 1 so now we will goto the parent of 8 that is 3 then we will go to the parent of  3 that is 1 and it is our source node
so basically we will continue this process until we reach the source node and keep storing the elements now the ans is 8->3->1 but it is in reverse so now we
can easily reverse it

*/



#include<unordered_map>
#include<list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unordered_map<int, bool>visited;
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(auto neighbour:adj[front])
		{
			if(!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour]=true;
				parent[neighbour]=front;
			}
		}
	}
	
	vector<int>ans;
	int currentNode=t;              // consider the destination node as currentNode
	ans.push_back(t);               // push it into verctor
	while(currentNode!=s)           // continue the loop untill source node is found
	{   
	    currentNode=parent[currentNode];    //jump from the current node to the parent of current node
		ans.push_back(currentNode);         // and then push the current node into vector
	}
	reverse(ans.begin(),ans.end());         // reverse the vecor to get answer in order
	return ans;
}
