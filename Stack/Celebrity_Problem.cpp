//  https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// method 1:

// if a person is celebrity his whole row will be 0

// if a person is celebrity his whole column will be 1 except diagnol 


// method 2:    

// put all persons in stack 

// while (st.size()!=1)

// stack ke top 2 log utha lenege A and B and check if A knows B
// if yes then A is not celebrity and then discard A and push B again in stack
// else then B is not the celebrity and then discard B and push A again into the stack 

// if stack size == 1 then that element might be a celebrity and then we will verify it with method 1 approach

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{   
    vector<vector<int>>M{{0,1,0},
                         {0,0,0},
                         {0,1,0},};
     int n=3;    
     stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()!=1)
        {
            int A=st.top();
            st.pop();
            int B=st.top();
            st.pop();
            if(M[A][B]==1)
            {
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        int ans=st.top();
        for(int i=0;i<n;i++)
        {
            if((M[ans][i]==1 || M[i][ans]==0)&& ans!=i )
            {
                return -1;
            }
        }
        cout<<ans;
        return 0;
}
