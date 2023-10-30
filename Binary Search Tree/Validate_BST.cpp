// https://leetcode.com/problems/validate-binary-search-tree/description/

//  Method 1: inorder nikal lenge aur check karenge ki agar yeh sorted hai ya nahi agar sorted hoga to valid BST hoga kyoki BST ka inorder sorted hota hai

// Method 2:    node apne lowerbound se bada hona chahie aur upper bound se chota hona chahiye
//  jab hum left me check karenge tab jo previous node tha vo uppperbound me change ho jaega kyoki vo obviously use bada hoga
//  jab hum right me check karenge tab jo previous node hoga vo lowerbound me change ho jaega kyoki vo obviously chota hoga 
