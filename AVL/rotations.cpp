//Just shows the code for rotations

// Rotations can be of 4 types
// 1. right rotation (left-left-rotation)
// 2. left rotation (right-right-rotation)
// 3. left-right rotation
// 4. right-left rotation

//yes names can be confusing

//1. Left Left rotation

//root == A where balance must be >=2 (left heavy)
//        A
//       / \
//     B    T4
//    / \
//   C  T3
//  / \
// T1 T2
// A is the unbalanced node which is left heavy
//Insertion must have been in C  so left left rotation needs to take place

//Output after Rotation
 //       B
 //    /    \
 //   C      A
 //  / \    / \
 // T1 T2  T3 T4
Node* RightRotation(Node* root){
  Node *leftChild=root->left;//represents B
  Node *rightGrandChildThroughLeftChild=leftChild->right;//represents T3
  root->left=rightGrandChildThroughLeftChild;//A->left=T3
  leftChild->right=root;//B->right=A
  return leftChild;//Return B which is the new root now
}

//2. Right Right rotation

//root == A where balance must be <= -2 (minus 2) (right heavy)
//    A
//  /   \
// T1    B
//      / \
//    T2   C
//         /\
//        T3 T4
//Insertion must be in C

//Output After Rotation
//       B
//    /     \
//   A       C
//  / \     / \
// T1 T2   T3 T4
Node* LeftRotation(Node* root){
  Node * rightChild=root->right;//represents B
  Node * leftGrandChildThroughRightChild=rightChild->left;//represents T2
  root->right=leftGrandChildThroughRightChild;//A->right=T2
  rightChild->left=root;//B->left=A
  return rightChild;//Return B which is new root now
}


//3. Left Right Rotations

// Root == A where balance must be >= 2 (left heavy) and new insertion in right Grand child of root(ie.in C)
//     A
//    / \
//   B  T4
//  / \
// T1  C
//    / \
//   T2 T3

// Output after rotations
//       C
//    /     \
//   B       A
//  / \     / \
// T1 T2   T3 T4
Node* LeftRightRotation(Node* root){
  Node* leftChild=root->left;
  root->left=LeftRotation(leftChild);//A->left=leftRotation(B)
// Output after this rotation is
//        A
//       / \
//     C    T4
//    / \
//   B  T3
//  / \
// T1 T2
  return RightRotation(root);//rightRotation on A
}

//4. Right Left Rotation

//root == A where balance must be <= -2(minus 2) and new insertion in left Grand Child of root (ie in C)
//   A
//  / \
// T1  B
//    /\
//   C  T4
//  /\
// T2 T3

//Output after rotations
//       C
//    /     \
//   A       B
//  / \     / \
// T1 T2   T3 T4
Node* RightLeftRotation(Node* root){
  Node* rightChild=root->right;
  root->right=RightRotation(rightChild);//A->right=RightRotation(B)
// Output after this rotation is
//    A
//  /   \
// T1    C
//      / \
//    T2   B
//         /\
//        T3 T4
  return LeftRotation(root);//leftRotation on A
}
