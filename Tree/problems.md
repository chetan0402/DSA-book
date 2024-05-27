# Problems on Binary Trees

### Q1. Give an algorithm for finding maximum element in binary tree.

One simple way of solving this problem is: find the maximum elemenet in left subtree, find maximum element in right subtree, compare them with root data and select the one which is giving the maximum value.

```c
int FindMax(struct BinaryTreeNode*root){
    int root_val,left,right,max=INT_MIN;
    if(root!=NULL){
        root_val=root->data;
        left=FindMax(root->left);
        right = FindMax(root->right);
        max=max(left,right);
        max=max(max,root_val);
    }
    return max;
}
```
Time complexity: O(n)
Space complexity: O(n)

### Q2. Give an algorithm for finding maximum element in binary tree without recusion

```c
int FindMaxUsingLeveOrder(struct BinaryTreeNode*root){
    struct BinaryTreeNode*temp;
    int max=INT_MIN;
    struct Queue*Q=CreateQueue();
    EnQueue(Q,root);
    while(!isEmptyQueue(S)){
        temp=DeQueue(S);
        max=max(max,temp->data);
        if(temp->left) EnQueue(S,temp->left);
        if(temp->right) EnQueue(S,temp->right);
    }
    DeleteQueue(S);
    return max;
}
```

Time complexity: O(n)
Space complexity: O(n)

### Q3. Give an algorithm for searching an element in binary tree.

```c
int Find(struct BinaryTreeNode*root,int data){
    if(root==NULL) return 0;
    if(data==root->data) return 1;
    return (Find(root->left,data) || Find(root->right,data));
}
```

### Q4. Give an algorithm for searching an element in binary tree withotu recursion

```c
int FindMaxUsingLeveOrder(struct BinaryTreeNode*root){
    struct BinaryTreeNode*temp;
    struct Queue*Q=CreateQueue();
    EnQueue(Q,root);
    while(!isEmptyQueue(S)){
        temp=DeQueue(S);
        if(data=temp->data) return 1;
        if(temp->left) EnQueue(S,temp->left);
        if(temp->right) EnQueue(S,temp->right);
    }
    DeleteQueue(S);
    return 0;
}
```

Time complexity: O(n)
Space complexity: O(n)

### Q5. Give an algorithm for inserting an element in binary tree

```c
void insert(struct BinaryTreeNode*root,int data){
    struct BinaryTreeNode*newNode;
    newNode=(struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));
    newNode->left=newNode->right=NULL;
    if(!newNode) return;
    if(!root){
        root=newNode;
        return;
    }
    BinaryTreeNode*temp;
    struct Queue*Q=CreateQueue();
    while(!isEmptyQueue(Q)){
        temp=DeQueue(Q);
        if(temp->left) EnQueue(Q,temp->left);
        else{
            temp->left=newNode;
            DeleteQueue(Q);
            return;
        }
        if(temp->right) EnQueue(Q,temp->right);
        else{
            temp->right=newNode;
            DeleteQueue(Q);
            return;
        }
    }
    DeleteQueue(Q);
}
```

Time complexity: O(n)
Space complexity: O(n)

### Q6. Give an algorithm for finding the size of binary tree.

```c
int sizeOfBinaryTree(struct BinaryTreenode*root){
    if(root==NULL) return 0;
    return (SizeOfBinaryTree(root->left) +1 +SizeOfBinaryTree(root->right));
}
```

### Q8. Give an algorithm for printing the level order data in reverse order. For example, the output for the below tree should be: 4 5 6 7 2 3 1

![alt text](image-7.png)

```c
void printInReverse(struct BinaryTreeNode*root){
    struct Queue*Q;
    struct Stack*s=CreateStack();
    struct BinaryTreeNode*temp;
    if(!root) return;
    Q=CreateQueue();
    EnQueue(Q,root);
    while(!isEmptyQueue(Q)){
        temp=DeQueue(Q);
        if(temp->right) EnQueue(Q,temp->right);
        if(temp->left) EnQueue(Q,temp->left);
        Push(S,temp);
    }
    while(!isEmptyStack(s)) printf("%d",Pop(s)->data);
}
```

Time complexity: O(n)
Space complexity: O(n)

### Q9. Give an algorithm for deleting the tree.

Recursively delete the tree

### Q10. Give an algorithm for finding the height of the binary tree

```c
int HeightOfBinaryTree(struct BinaryTree*root){
    if(root==NULL) return 0;
    return max(HeightOfBinaryTree(root->left),HeightOfBinaryTree(root->right)) +1;
}
```

### Q11. Sol the above without cursion

```c
int FindHeightOfBinaryTree(struct BinaryTreeNode*root){
    int level=1;
    struct Queue*Q;
    if(!root) return 0;
    Q=CreateQueue();
    EnQueue(Q,root);
    EnQueue(Q,NULL);
    while(!isEmptyQueue(Q)){
        root=DeQueue(Q)
        if(root==NULL){
            if(!isEmptyQueue(Q)) EnQueue(Q,NULL);
            level++;
        }else{
            if(root->left) EnQueue(Q,root->left);
            if(root->right) EnQueue(Q,root->right);
        }
    }
    return level;
}
```

**I have doubt in this**

