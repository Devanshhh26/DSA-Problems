
//  https://leetcode.com/problems/implement-stack-using-queues/

//Method 1: it requires 2 queues
// for push : (1) push the new element in q2
//            (2) push all the elements of q1 into q2
//            (3) push all the elements of q2 into q1

// for pop : q1.front()

// for top : q1.front()

//-----------------------------------------------------------------------------
// for push : (1) push the new element directly in the q
//            (2) loop chalao till size-1   fir q.pop() karo aur fir usi element ko q.push() kardo

// for pop : q.front();

// for top : q.front();