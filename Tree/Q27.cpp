typedef struct{
    int data;
    Node*left=nullptr;
    Node*right=nullptr;
} Node;

Node*buildBinaryTree(int inorder[],int preorder[],int&preorder_index,int start,int end){
    if(start>end) return nullptr;
    Node* newNode = new Node;
    newNode->data = preorder[preorder_index];
    preorder_index++;
    if(start==end) return newNode;
    int inorder_index=0;
    for(int i=start;i<=end;i++) if(inorder[i]==newNode->data) inorder_index=i;
    newNode->left = buildBinaryTree(inorder,preorder,preorder_index,start,inorder_index-1);
    newNode->right = buildBinaryTree(inorder,preorder,preorder_index,inorder_index+1,end);
    return newNode;
}