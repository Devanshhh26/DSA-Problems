// method 1: BTS ka inorder ek vector me store karlo aur fir uss vector me jis bhi element ka predecessor manga hai 
//          uss element se pehle vala element return kardo


// method 2: perform inorder traversal and find the value just less than x(max value that is less than x)

// method 3: 

/*
int main()
{
    Node*pred=0;
    Node*curr=root;
    while(curr)
    {
        if(curr->data<p->data)
        {
            pred=curr;
            root=root->right;
        }
        else{
            curr=curr->left;

        }
    }
    return pred;
}
*/
