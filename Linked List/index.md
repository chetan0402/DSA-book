# Linked List

### Advantages of Linked list

#### They can be expanded in constant time. 

To create an array we must allocate memory for a certain number of elements. To add more elemnts to the array then we must create a new array and copy the old array into the new array.

We can prevent this by allocating lots of space initally but then you might allocate more than you need and wasting memory. With a linked list we can start with space for just one element allocated and add on new elements easily without the need to do any copying and reallocating

### Disadvantage

#### Access Time

Array is random-access, which means it takes O(1) to acess any element in the array. Linked lists takes O(n) for access to an element in the list in worst case. Another advantage of arrays in access time is special locality in memory. Arrays are defined as contiguous blocks of memory, and so any array element will be physically near its neighbors. This greatly benefits from modern CPU caching methods.

Althought the dynamic allocation of storage is a great advantage, the overhead with storing and retrieving data can make a big difference. Sometimes linked list are hard to manipulate. If the last item is deleted, the last but one must now have its pointer changed to hold a NULL reference. This required that the list is traversed to find the last but one link, and its pointer set to a NULL reference. Finally, linked lists wastes memory in terms of extra reference points

# Singly Linked List

Generally "linked list" means a singly linked list. This list conssits of a number of nodes in which each node has a next pointer to the following elements. The link of the last node in the list is NULL which indicates end of the list.

![alt text](image.png)

```c
struct ListNode{
    int data;
    struct ListNode *next;
}
```

### Basic Operations on a list 

- Traversing the list
- Inserting an item in the list
- Deleting an item from the list

### Traversing the list

- Follow the pointer
- Display the contents of the nodes (or count) as they are traversed.
- Stop when the next pointer points to NULL

```c
int ListLength(struct ListNode*head){
    struct ListNode*curren=head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
```

Time complexity: O(n)
Space complexity: O(1)

### Singly Linked List Insertion

- Inserting a new node before the head
- Inserting a new node after the tail
- Inserting a new node at a random position

#### Inserting a new node before the head

- Update the next pointer of the new node, to point to the current head
- Update head pointer to point to the new node

#### Inserting a new node after the tail

- New nodes next pointer points to NULL
- Last node next pointer points to the new node

#### Inserting a new node at random place

```c
void insertInLinkedLIst(struct ListNode**head,int data,int position){
    struct ListNode*p,*q;
    struct ListNode*newNode = (ListNode*) malloc(sizeof(struct ListNode));
    if(!newNode){
        printf("Memory error");
        return;
    }
    newNode->data=data;
    p=*head;
    if(position == 1){
        newNode->next=p;
        *head = newNode;
    }else{
        int k=1;
        while((p!=NULL) && (k<position-1)){
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            q->next = newNode;
            newNode->next=NULL;
        }else{
            q->next = newNode;
            newNode->next =p;
        }
    }
}
```

Time Complexity: O(n)
Space comeplexity: O(1)

### Singly Linked List Deletion

- Deleting the first node
- Deleting the last node
- Deleting an intermediate node

```c
void DeleteNodeFromLinkedList(struct ListNode*head,int position){
    int k=1;
    struct ListNode *p,*q;
    if(*head==NULL){
        return;
    }
    p=*head;
    if(position==1){
        *head = *head->next;
        free(p); // Delete the head object
        return;
    }else{
        while((p!=NULL) && (k<position-1>)){
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            return;
        }else{
            q->next = p->next;
            free(p);
        }
    }
}
```

Time complexity: O(n)
Space complexity: O(1)

#### Deleting the whole list

```c
void DeleteLinkedList(struct ListNode**head){
    struct ListNode*auxilaryNode, *iterator;
    iterator=*head;
    while(iterator){
        auxilaryNode = iterator -> next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}
```

Time complexity: O(n)
Space complexity: O(1)

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