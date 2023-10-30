//  https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1


/*
pair<int,int> height(Node*root)     // pair me pehla int total height represent karta hai aur dusra int sum represent karta hai
    {
        if(root==NULL)
        {
            return {0,0};
        }
        // height nikalo tree ki
        auto lh=height(root->left);       
        auto rh=height(root->right);
        int sum=root->data;
        if(lh.first==rh.first)              // agar left height aur right height dono same ho matlab ki agar do branches ki height same ho
        {
            sum+=lh.second>rh.second?lh.second:rh.second;       // to jisse bhi sum maximum aa raha ho to use consider karenge
        }
        else if(lh.first>rh.first){         // agar left height zyada badi ho to left height ka sum nikal ke add kar denge sum me
            sum+=lh.second;
        }
        else{
            sum+=rh.second;                 // agar right height zyada badi hot o right height ka sum nikal ke add kar denge sum me
        }
        return {max(lh.first,rh.first)+1,sum};      // max height ki jitni hai vo return karenge aur uska sum return karenge
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto h=height(root);            
        return h.second;            // h.second me sum pada hai
        
    }
*/