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