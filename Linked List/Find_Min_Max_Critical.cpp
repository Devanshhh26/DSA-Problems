//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

/*
 vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        ListNode*prev=head;
        if(!prev)
        {
            return ans;
        }
        ListNode*curr=head->next;
        if(!curr)
        {
            return ans;
        }
        ListNode*forward=head->next->next;
        if(!forward)
        {
            return ans;
        }
        int firstCritical=-1;
        int lastCritical=-1;
        int minDist=INT_MAX;
        int i=1;
        while(forward)
        {
            bool isCP=((curr->val>prev->val && curr->val>forward->val)||(curr->val<prev->val &&  curr->val<forward->val))?true:false;
            if(isCP && firstCritical==-1)
            {
                firstCritical=i;
                lastCritical=i;
            }
            else if(isCP)
            {
                minDist=min(minDist,i-lastCritical);
                lastCritical=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            forward=forward->next;
        }
        if(firstCritical==lastCritical)
        {
            return ans;
        }
        else{
            ans[0]=minDist;
            ans[1]=lastCritical-firstCritical;
        }
    return ans;
    }
*/