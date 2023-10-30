
//  https://leetcode.com/problems/implement-queue-using-stacks/description/

// Method 1: it takes O(n) time for push, O(1) time for pop and front

// for push: Create TWO STACK S1,S2
// if we want to push and element then pop and push all the element of s1 into s2 and then push the new element in s1 and then pop all elements
// of s2 and push them back in s1 again

// for pop : s1.pop()

// for front: s1.top()

//-----------------------------------------------------------------------------------------------------------------

//Method 2  : it takes O(1) time for push, O(n) time for pop and front

// for push : directly push in s1

// for pop: if s2 is not empty then pop from s2 otherwise pop all elements of s1 and push them into s2 and then pop the top element from s2

// for front : if s2 is not empty then return s2.top() else pop and push all the elements of s1 into s2  then return s2.top()