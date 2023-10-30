//  https://leetcode.com/problems/online-stock-span/description/

// pehle span ko 1 se initialiaze kar lenege uske baad ek stack banaenge stack<pair<int,int> vala jisme first int price store karega aur second int span

//  first element ko stack me push kar denge with a span of 1

// uske baad jo bhi price aaega use check karenge st.top() ke sath agar vo st.top() bada ho to hum price aur uske span ko push akr denge 

// agar st.top() chota ho price se to hum span ko add kar denge st.top() ke span se aur st.pop() kar denge aur yeh hum tab tak karenge jab tak st.top() greater nahi ho jata fir upar vali line execute karenge

/*
int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price)
        {
            span=span+st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
*/