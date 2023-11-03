
//https://leetcode.com/problems/intersection-of-two-linked-lists/description/



//Find the length of both the linked lists.

//Traverse the bigger linked list until the remaining nodes count becomes equal to the smaller one's.

//Traverse both the heads together. If both of them are same then the intersecting node is found.

/*
int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        //step1
        int lenA = length(headA), lenB = length(headB);

        //step2
        if(lenA>lenB){
            while(lenA>lenB){
                headA = headA->next;
                lenA--;
            }
        }
        else if(lenA<lenB){
            while(lenA<lenB){
                headB = headB->next;
                lenB--;
            }
        }
        
        //step 3
        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        
    }
*/
