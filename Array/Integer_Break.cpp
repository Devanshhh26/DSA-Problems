// https://leetcode.com/problems/integer-break/description/

/*

1. If n is less than or equal to 3, it returns n - 1. This is because for values of n less than 4, 
   it's better to break it into smaller integers (e.g., 2 = 1 + 1) to maximize the product.
2. If n is divisible by 3, it tries to break it into as many 3s as possible, as this will maximize the product.
   For example, for n = 6, it returns 3 * 3 = 9.
3. If n leaves a remainder of 1 when divided by 3, it breaks it into as many 3s as possible and leaves one 3 as 4. 
   For example, for n = 10, it returns 3 * 3 * 4 = 36.
4. If n leaves a remainder of 2 when divided by 3, it breaks it into as many 3s as possible and adds one more 2. 
   For example, for n = 8, it returns 3 * 3 * 2 = 18.

*/

/*
int integerBreak(int n) {
        if(n<4)
        {
            return n-1;
        }
        int ans=0;
        if(n%3==0)
        {
            int div=n/3;
            ans=pow(3,div);
        }
        if(n%3==1)
        {
            int div=n/3;
            div=div-1;
            ans=pow(3,div);
            ans=ans*4;
        }
        if(n%3==2)
        {
            int div=n/3;
            ans=pow(3,div);
            ans=ans*2;
        }
        return ans;

    }
*/