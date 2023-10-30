// https://practice.geeksforgeeks.org/problems/median-of-bst/1


/*
void inorder(Node*root,vector<int>&ans)             // inorder traversal karke vector me store kara lia
{
    if(!root)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int>ans;
      inorder(root,ans);
      int n=ans.size();
      float res=0;
      if(n&1)                                       // agar odd hai
      {
          res=ans[(n-1)/2];
      }
      else{                                         // agar even hai
          float a1=ans[n/2];
          float a2=ans[(n/2)-1];
          res=(a1+a2)/2;
      }
      return res;
}

*/