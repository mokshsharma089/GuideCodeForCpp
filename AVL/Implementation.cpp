#include <iostream>
#include <queue>
using namespace std;
//Every Node Of the AVL tree would be an object of Node Class
class Node{
  public:
    int val;
    Node *left,*right;
    Node(int m){
      val=m;
      left=NULL;
      right=NULL;
    }
};
//each object of Class Avl would represent a different AVL tree
class Avl{
  private:
    Node* root;
  public:
    Avl(){
      root=NULL;
    }
    int height();//tells the height of the complete AVL tree
    int heightHelper(Node*);//tells the height of tree starting from Node R
    int BalanceCalculator(Node*);// tells the balance number(for avl tree balance number must be either -1,0,or 1) of Node R
    Node* Balance(Node*,int);//would balance the node R it would be called by insert or any function whenever BalanceCalculator returns unacceptable value such as 2 etc
    //int key represents the value which was inserted in tree which caused the imbalance
    //it is needed to see in which child and grandchild insertion has been done so we can find out which rotation has to be performed
    void insert(int);//object would call this function to insert Value given to this function
    //work would be done recursively by insertHelper(Node* R,int Key) function using balance function
    Node* insertHelper(Node*,int);
    //algorithm for insertion heightHelper
    //1.start from root and go to the correct position where new Node Can be inserted with this key value (only be inserted at leaf)
    //2.Insert the New node
    //3. GO back  from New_Node(where value is inserted) to Root and keep checking if node has beacome unbalanced if yes then just call Balance(Node *) on the Node
    //Going back in this manner should be easy as recursion uses stack (call stack)

    Node* RightRotation(Node*);//also represents LEFT LEFT ROTATION
    Node* LeftRotation(Node*);//also represents RIGHT RIGHT Rotation
    Node* LeftRightRotation(Node*);
    Node* RightLeftRotation(Node*);
    void PrintLevelOrder();
};

int Avl::height(){
  return heightHelper(this->root);
}

int Avl::heightHelper(Node* R){
  if(R==NULL){
    return -1;
  }
  int leftHeight=heightHelper(R->left);
  int rightHeight=heightHelper(R->right);
  return 1+max(leftHeight,rightHeight);
}

int Avl::BalanceCalculator(Node* R){
  int leftHeight=heightHelper(R->left);
  int rightHeight=heightHelper(R->right);
  return leftHeight-rightHeight;
}

Node* Avl::Balance(Node* R,int key){
  //if controls reach here then that means Node* R has imbalance ie NOT -1,0 or 1
  int bal=BalanceCalculator(R);
  cout<<endl<<"We need to balance as at "<<R->val<<" balance becomes "<<bal<<endl;
  //children and grandchildren are in context of R
  if(bal>1){
    //case of Left heavy AVL tree present at R
    //have to perform either right rotation(LL rotation) or left-right rotation(LR rotation)
    if(key < (R->left->val)){
      //this means insertion was done at left grandchild {through left child}
      //Perform LL rotation on R {LL rotation is nothing but right Rotation}
      R=RightRotation(R);
    }
    else if(key > (R->left->val)){
      //this means insertion was done at right granchild {through left child}
      //Perform LR rotation on R
      R=LeftRightRotation(R);
    }
  }
  else if(bal<-1){
    //case of Right heavy AVL tree present at R
    // have to perform either left rotation(RR rotation) or Right-Left Rotation(RL rotation)
    if(key > (R->right->val)){
      //this means insertion was done at right grandchild {throught right child}
      //Perform RR rotation on R {RR rotation is nothing but left Rotation}
      R=LeftRotation(R);
    }
    else if(key < (R->right->val)){
      //this means insertion was done at left grandchild {throught right child}
      //Perform RL rotation on R
      R=RightLeftRotation(R);
    }
  }
  return R;
}

void Avl::insert(int key){
  //the insertHelper() function would insert ,make tree balanced and return new root for this tree
  this->root=insertHelper(this->root,key);
  cout<<"\nKey "<<key<<" was inserted in tree"<<endl;
}

Node* Avl::insertHelper(Node* root,int key){
  if(root==NULL){
    //we have reached the correct position
    //Make Node Here and return node to whoever called Here
    Node* T=new Node(key);
    return T;
  }
  else if(root->val < key){
    //insert in its right children
    root->right=insertHelper(root->right,key);
    //will return balanced tree below it so add at root->right and then if this insertion makes this node unbalanced
    //then if this insertion makes this node unbalanced then call Balance() function for this root
  }
  else if(root -> val > key){
    //insert in left subtree
    root->left=insertHelper(root->left,key);
    //will return balanced tree below it so add at root->left and
    //then if this insertion makes this node unbalanced then call Balance() function for this root
  }
  int Bal=BalanceCalculator(root);
  if(!(Bal==0 or Bal==1 or Bal==-1)){
    root=Balance(root,key);
  }

  return root;
}

//Rotations are here
Node* Avl::RightRotation(Node* A){
  cout<<endl<<"Performing Right rotation on "<<A->val<<endl;
  Node* B=A->left;
  A->left=B->right;//make A's left child to B's right Child
  B->right=A;//make A as B's Right Child
  cout<<endl<<"Right rotation on "<<A->val<<" succesfull"<<endl;
  return B;//now root is B
}

Node* Avl::LeftRotation(Node* A){
  cout<<endl<<"Performing left rotation on "<<A->val<<endl;
  Node* B=A->right;
  A->right=B->left;//make A's right Child to B's right child
  B->left=A;//make A as B's left child
  cout<<endl<<"left rotation on "<<A->val<<" succesfull"<<endl;
  return B;//now Root is B
}

Node* Avl::LeftRightRotation(Node* A){
  Node* B=A->left;
  A->left=LeftRotation(B);//perform left rotation on B(A->left) and store at A->left
  return RightRotation(A);//perform right rotation at root and return
}

Node* Avl::RightLeftRotation(Node* A){
  Node* B=A->right;
  A->right=RightRotation(B);//perform right rotation on B(A->right) and store at A->right
  return LeftRotation(A);//perform left rotation at root and return
}
void Avl::PrintLevelOrder(){
  cout<<endl<<"-------Level Wise Printing-------";
  Node *R=this->root,*temp;
  int level=1;
  queue<Node*> q;
  q.push(R);
  while(!q.empty()){
    cout<<endl<<"Level "<<level<<" Nodes are = ";
    int size=q.size();
    for(int i=0;i<size;i++){
      temp=q.front();
      cout<<temp->val<<" , ";
      q.pop();
      if(temp->left!=NULL){
        q.push(temp->left);
      }
      if(temp->right!=NULL){
        q.push(temp->right);
      }
    }
    level++;
  }
  cout<<endl;
}
int main(){
  Avl T;
  T.insert(14);
  T.insert(17);
  T.insert(11);
  T.insert(7);
  T.insert(53);
  T.insert(4);
  T.insert(13);
  T.PrintLevelOrder();
  T.insert(12);
  T.PrintLevelOrder();
  //works perfectly have checked 


  return 1;
}
