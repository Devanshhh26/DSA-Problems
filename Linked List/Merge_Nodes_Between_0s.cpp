//https://leetcode.com/problems/merge-nodes-in-between-zeros/

/*

 ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* temp=head;
        int sum=0;
        while(curr!=NULL)
        {           
            if(curr->val!=0)                // jab tak zero nahi milta tab tak sum karte chalo
            {
                sum=sum+curr->val;
            }
            if(curr->val==0 && curr->next!=NULL)        // agar zero mil jae aur vo last element na ho
            {
                temp->val=sum;                          // temp me sum ki value store karwa do
                temp->next=curr;                        // temp ke next me curr ka address daal do
                temp=curr;                              // temp ko curr me shift kardo
                sum=0;                                  // sum ko firse 0 se initialize kar do
            }
            if(curr->val==0 && curr->next==NULL)        // agar zero aa jae aur vo last element ho
            {
                temp->val=sum;                          // temp me sum ki value store karwa do
                temp->next=NULL;                        // temp ke next ko null kar kar do
            }
            curr=curr->next;
        }
        return head;
    }

*/