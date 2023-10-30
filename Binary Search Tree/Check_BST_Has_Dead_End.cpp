// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

// ek map banaenge aur jab bhi koi element visited karenge to use true mark kar denge map me
// hume sirf leaf nodes ko check karna hai 
// agar koi leaf node ki value se +1 value aur -1 value exist karti hogi map me to matlab deadend hai else nahi hai
// eg if node->data = 10 then check if 9 and 11 exist or not

/*

void fun(Node*root,unordered_map<int,bool>&visited,bool& ans)
{
    if(!root)
    {
        return;
    }
    visited[root->data]=true;                       // jo bhi element visit karo to use map me true kar kar do
    if(!root->left  &&  !root->right)               // agar hum leaf node me ho to
    {
        int xp1=root->data+1;                       // leaf node ke data se ek badi val nikalo aur xp1 me store karlo
        int xm1=root->data-1==0?root->data:root->data-1;                   // leaf node ke data se ek kam val nikalo but agar ek kam value 0 ho to node ka data hi consider karlo aur agar >0 ho to -1 karke jo bhi val aa rahi ho use store karlo xm1 me
        if(visited.find(xp1)!=visited.end() &&  visited.find(xm1)!=visited.end())           // check karo ki xp1 aur xm1 exist karte hai map me ya nahi
        {
            ans=true;                                   // if yes to ans ko true mark karo aur return kardo
            return;
        }
    }
    fun(root->left,visited,ans);                        // left jaake check karo    (preorder)
    fun(root->right,visited,ans);                       // right jaake check karo   (preorder)
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans=false;
    unordered_map<int,bool>visited;
    fun(root,visited,ans);
    return ans;
    
}
*/