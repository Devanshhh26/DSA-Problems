//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// same as merged two sorted linked list

// but instead we have to merge k lists

// treat each list->bottom as a single list and merge it with the list->next list and keep doing it untill only one link remains

// start merging from end so it is easier as we do no have to save the list->next links

//{ Driver Code Starts

/*
#include <iostream>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
/*    
Node *merge(Node *a,Node* b)
{
    if(!a)          // if a is empty
    return b;
    if(!b)          // if b is empty
    return a;
    Node* ans=NULL;                             
    if(a->data <b->data)            // join ans with a if a is less than b
    {
        ans=a;
        a->bottom=merge(a->bottom,b);   // move a to the next element in bottom
    }
    else
    {
        ans=b;                              
        b->bottom=merge(a,b->bottom);
    }
    return ans;
}
    
Node *flatten(Node *root)
{
    if(root==NULL)
    return 0;
    Node* mergedLL=merge(root,flatten(root->next));         // going to the last list and then merging them
    return mergedLL;
}
*/