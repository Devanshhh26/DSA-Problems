// https://practice.geeksforgeeks.org/problems/sum-equals-to-sum4006/1

// ek map banaenge aur usme saare possible pairs ka sum daal denge aur jab koi sum repeat hoga to return true kar denge agar koi repeat na ho to return false

/*
 int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=a[i]+a[j];
                if(mp.find(sum)!=mp.end())
                {
                    return true;
                }
                else{
                    mp[sum]=true;
                }
            }
        }
        return false;
    }
*/