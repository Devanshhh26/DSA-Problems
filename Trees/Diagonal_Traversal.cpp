//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// ek qeueue banaenge fir usme root element daal denge

//  fir ek loop chalenge jabtak q empty nahi hoti

// pehle q ka front element pic karenge aur use pop kar denge q se

// fir front element ko push kare denge ans vector me

// fir check karenge uss element ka koi left child exist karta hai ya nahi agar haan to q me daal denge

// aur fir right child me traverse chale jaenge


// in short right child valo ko pehle daal denge vector me aur left child valo ko queue me daalenge aaage check karne ke lie

/*
vector<int> diagonal(Node *root)
{   
    vector<int>ans;
   if(root==NULL)
    {
        return ans;
    }
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
        Node*temp=q.front();
        q.pop();
        while(temp)
        {
            ans.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            temp=temp->right;
        }
   }
   return ans;
}
*/