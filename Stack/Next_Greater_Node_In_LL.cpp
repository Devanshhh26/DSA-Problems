// https://leetcode.com/problems/next-greater-node-in-linked-list/

/*
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head)
        {
            ll.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        vector<int>ans(ll.size(),0);
        for(int i=0;i<ll.size();i++)
        {
            while(!st.empty()   &&  ll[i]>ll[st.top()])
            {
                int kid=st.top();
                st.pop();
                ans[kid]=ll[i];
            }
            st.push(i);
        }
        return ans;

*/