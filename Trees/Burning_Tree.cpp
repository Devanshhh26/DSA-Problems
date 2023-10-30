//  https://practice.geeksforgeeks.org/problems/burning-tree/1

/*

//finding the target node and creating a mapping of each node with its parent node
Node*makeNodetoParentMappingAndFindTargetNode(Node*root,unordered_map<Node*,Node*>&parentMap,int target)
    {
        queue<Node*>q;
        Node*targetNode=0;
        q.push(root);
        parentMap[root]=0;
        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();
            if(front->data==target)                 // found the target and stored in targetNode
            {
                targetNode=front;
            }
            if(front->left)                         // agar node ka left exist karta hai to use push kardo q me aur front ko left child ka parent mark kardo
            {
                q.push(front->left);
                parentMap[front->left]=front;
            }
            if(front->right)                        // agar node ka right exist karta hai to use push kardo q me aur front ko right child ka parent mark kardo
            {
                q.push(front->right);
                parentMap[front->right]=front;
            }
        }
        return targetNode;
    }
//  ek unordered_map banaenge jo bataega ki yeh node already burnt hai ya nahi aur ek q banaenge jisme current node ke adjacent nodes add honge burn hone ke lie

    int burnTree(Node*targetNode,unordered_map<Node*,Node*>&parentMap)
    {
        unordered_map<Node*,bool>isBurnt;
        queue<Node*>q;          // currently set on fire
        int T=0;
        q.push(targetNode);
        isBurnt[targetNode]=true;
        while(!q.empty())
        {
            int size=q.size();
            bool isFireSpreaded=false;                  // yeh hume bataega ki iss round me koi burn hua ya nahi agar haan to time ko bada denge
            for(int i=0;i<size;++i)
            {
                Node*front=q.front();
                q.pop();
                if(front->left  &&  !isBurnt[front->left])         // agar front ka left child exist karta hai aur vo already burnt nahi hai to use q me push kardo aur isBurnt true kardo uska aur isFireSpreaded bhi true kardo
                {
                    q.push(front->left);
                    isBurnt[front->left]=true;
                    isFireSpreaded=true;
                }
                if(front->right  &&  !isBurnt[front->right])        // agar front ka right child exist karta hai aur vo already burnt nahi hai to use q me push kardo aur isBurnt true kardo uska aur isFireSpreaded bhi true kardo
                {
                    q.push(front->right);
                    isBurnt[front->right]=true;
                    isFireSpreaded=true;
                }
                if(parentMap[front] &&  !isBurnt[parentMap[front]])     // agar front ka parent exist karta hai aur vo already burnt nahi hai to use q me push kardo aur isBurnt true kardo uska aur isFireSpreaded bhi true kardo
                {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]]=true;
                    isFireSpreaded=true;
                }
            }
            if(isFireSpreaded)              // agar isFireSpreaded true jao to time++ kardo
            {
                T++;
            }
        }
        return T;
        
    }
      
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parentMap;
        Node*targetNode=makeNodetoParentMappingAndFindTargetNode(root,parentMap,target);
        return burnTree(targetNode,parentMap);
    }
*/
