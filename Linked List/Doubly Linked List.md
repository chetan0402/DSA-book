# Doubly Linked List

```c
struct DLLNode{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
}
```

### Doubly Linked List Insertion

- Inserting a new node before the head.
- Inserting a new node after the tail.
- Inserting a new node at middle of list.

![alt text](image-1.png)

```c
void DLLInsert(struct DLLNode**head,int data,int position){
    int k=1;
    struct DLLNode*temp,*newNode;
    newNode=(struct DLLNode*) malloc(sizeof(struct DLLNode));
    if(!newNode){
        return;
    }
    newNode->data=data;
    if(postion==1){
        newNode->next=*head;
        newNode->prev=NULL;
        *head->prev=newNode;
        *head=newNode;
        return;
    }
    temp=*head;
    while((k<position-1>) && temp->next!=NULL){
        temp = temp->next;
        k++;
    }
    if(temp->next==NULL){
        nextNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
    }else{
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
    return;
}
```

Time Complexity: O(n)
Space Complexity: O(1)

### Double Linked List Deletion

```c
void DLLDelete(struct DLLNode**head,int position){
    struct DLLNode*temp,*temp2;
    temp=*head;
    int k=1;
    if(*head==NULL){
        return;
    }
    if(postion==1){
        *head=*head->next;
        if(*head!=NULL){
            *head->prev=NULL;
        }
        free(temp);
        return;
    }
    while((k<position-1) && temp->next!=NULL){
        temp=temp->next;
        k++;
    }
    if(temp->next==NULL){
        temp2=temp->prev;
        temp2->next=NULL;
        free(temp);
    }else{
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    return;
}
```

Time complexity: O(n)
Space Complexity: O(1)

## Memory-efficient Doubly Linked List

```c
typedef struct ListNode{
    int data;
    struct ListNode*ptrdiff;
}
```