// method 1: BTS ka inorder ek vector me store karlo aur fir uss vector me jis bhi element ka predecessor manga hai 
//          uss element se next vala element return kardo


// method 2: perform inorder traversal and find the value just more than x(min value that is greater than x)

// method 3:

/*
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node*curr=root;
        Node*succ=0;
        while(curr)
        {
            if(curr->data>x->data)
            {
                succ=curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return succ;
*/