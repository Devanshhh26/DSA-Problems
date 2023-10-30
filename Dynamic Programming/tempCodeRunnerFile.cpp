int solveRecursion(int weight[], int value[], int index, int capacity) {
//   //base case -> only 1 item
//   if(index == 0 ) {
//     if(weight[0] <= capacity) {
//       return value[0];
//     }
//     else
//       return 0;
//   }

//   //include and exclude
//   int include = 0;
//   if(weight[index] <= capacity)
//     include = value[index] + solveRecursion(weight, value, index-1, capacity - weight[index] );

//   int exclude = 0 + solveRecursion(weight, value, index-1, capacity);

//   int ans = max(include, exclude);
//   return ans;
// }