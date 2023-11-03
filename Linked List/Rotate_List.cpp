//https://leetcode.com/problems/rotate-list/

/*

int getLength(ListNode* head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return 0;
        int len=getLength(head);
        int rotate=k%len;    //  the number of times we have to rotate a list will always be total length % k
        if(rotate==0)
        {
            return head;
        }
        int newLastNodePos=len-rotate-1;  
        ListNode* newLastNode=head;
        for(int i=0;i<newLastNodePos;i++)
        {
            newLastNode=newLastNode->next;  // reaching to the position just before the elements we have to rotate
        }
        ListNode* newHead=newLastNode->next;
        newLastNode->next=NULL;             
        ListNode* it=newHead;
        while(it->next!=NULL)
        {
            it=it->next;
        }
        it->next=head;
        return newHead;

    }

*/
