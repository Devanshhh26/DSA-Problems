// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// ek map banaenge aur usme cumulative sum store karenege aur uske sath sath index bhi (i.e. uss element tak kya sum hai) aur har element ka cumulative sum check karenge map me 
// agar vo already exist karta hoga to uske index se jo already exist kar raha hahi uska index minus kar denge aur ans aa jaega
// agar vo exist nahi karta ho use insert kar denge map me
// agar humara cumulative sum hi 0 ho jae to hume use bhi check karna hoga

// A[] = {15,-2,2,-8,1,7,10,23}             array
// csum= {15,13,15,7,8,15,25,28}            corressponding cumulative sum
// jaha jaha 15 repeate ho raha hai uske beech me 0 sum array hai

/*
 int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int csum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            csum+=A[i];                         // cummulative sum nikala uss element ka
            if(csum==0)                         // agar cummulative sum hi 0 ho gaya to check krenge max len ke lie
            {
                ans=max(ans,i+1);
            }
            else if(mp.find(csum)==mp.end())        // agar map me vo sum present nahi ha to map me daal do sum aur uska index
            {
                mp[csum]=i;
            }
            else{                                   // agart map me exist karta hai to use check karo max len ke lie by subtracting new index with old index
                ans=max(ans,i-mp[csum]);
            }
        }
        return ans;
    }
*/