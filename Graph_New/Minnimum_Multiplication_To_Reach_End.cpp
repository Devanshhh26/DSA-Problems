//https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

/*

ek visited vector banaenge aur jo node aaega to uss tak pahuchne me kitne steps lage hai vo store kar lenge aur hum bfs travel kar rahe hai to vo hume humesha minimum steps hi dega

int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int>q;
        const int mod=100000;
        vector<int>ans(100000,-1);              // visited vector ko -1 se initialize kar do
        ans[start]=0;                           // starting number ko ans array me 0 se initialize kar do
        q.push(start);                          // fir use q me push kardo
        while(!q.empty())
        {
            int front=q.front();                // element ko nikalo
            q.pop();
            if(front==end)                      // agar front end ho jae iska maltab hum final ans tak pahuch gae
            {
                return ans[end];                // return kardo ans vector ke end ke index me jo bhi value padi hogi jo minimum steps bata rahi hogi
            }
            for(auto it:arr)                    // agar end tak nahi pahuche to hum jo current element hai usko array ke andar baaki saare elements se multiply karenge
            {
                int newNode=(front*it)%mod;         // out of bound na chale jae isliye mod kia
                if(ans[newNode]==-1)                // agar jo new element hai vo abhi tak visit nahi hua hai 
                {
                    ans[newNode]=ans[front]+1;      // pichle element me pahuchne me jitne steps lage the usme 1 plus karde to new element me pahuchne pe jitne steps lagenege vo aa jaega
                    q.push(newNode);                // fir new element ko bhi q me push kar denge
                }
            }
        }
        return -1;
    }

*/