# Priority Queues [Heaps]: Problems & Solutions

### Q1. What are the minimum and maximum number of elemnets in a heap of height h?

Since heap is a complete binary tree, it has at most 2^(h+1) -1 elements. This is because, to get maximum nodes, we need to fill all the h levels completley and the maximum number of nodes is nothing but the sum of all nodes at all h levels.

To get minimum nodes, we should fill the h-1 levels fully and the last level with only on element. As a result, the minimum number of nodes is nothing but the sum of all nodes from h-1 levels plus 1 and we get 2^h elements

### Q2. Is there a min-heap with seven distinct elements so that the preorder traversal of it gives the elements in sorted order?

Yes. For the tree below, preorder traversal produces ascending order.
![alt text](image-7.png)

### Q3. Is there a max-heap with seven distinct elements so that the preorder traversal of it gives the elements in sorted order?

Yes. For the tree below, preorder traversal produces descending order.
![alt text](image-8.png)

### Q4. Is there a min-heap/max-heap with seven distinct elemnets so that the inorder traversal of it gives the elements in sorted order?

No. Since a heap must be either a min-heap or a max-heap, the root will hold the smallest element or the largest. An inorder traversal will visit the root of the tree as its second step, which is not the appropriate place if the tree's root contains the smallest or largest element.

### Q5. Is there a min-heap/max-heap with seven distinct elements so that the postorder traversal of it gives the elemnets in sorted order?

![alt text](image-9.png)

### Q6. Show that the height of a heap with n elements is logn?

A heap is a complete binary tree. All the levles, except the lowest, are completley full. A heap has at least 2^h elements and at most elements 2^h < n < 2^(h+1)-1. This implies, h=logn

### Q7. Given a min-heap, give an algorithm for finding the maximum element.

For a given min heap, the maximum element will always be at leaf only. Now, the next question is how to find the leaf nodes in the tree.

![alt text](image-10.png)

If we carefully observe,the next node of the last element's parent is the first leaf node. Since the last element is always at the h->count-1th location, the next node of its parent can be calculared as:

![alt text](image-11.png)

Now, the only step remaining is scanning the leaf nodes and finding the maximum among them.

```c
int findMaxInMinHeap(struct Heap*h){
    int Max=-1;
    for(int i=(h->count+1)/2;i<h->count;i++){
        if(h->array[i]>Max) Max=h->array[i];
    }
}
```

### Q8. Give an algorithm for deleting an arbitrary element from min heap

To delete an element, first we need to search for an element. Let us assume taht we are using level order traversal for finding the element. After finding the element we need to fllowing the deleteMin process.

### Q9. Give an algorithm for deleting the ith indexed element in a given min-heap.

```c
int delete(struct Heap*h,int i){
    int key;
    if(n<i) return;
    key=h->array[i];
    h->array[i]=h->array[h->count-1];
    h->count--;
    precolateDown(h,i);
    return key;
}
```

### Q10. Prove that, for a compelte binary tree of height h of sum of the height of all nodes is O(n-h).

A compelte binary tree has 2^i nodes on level. Also, a node on level i has depth i and height h-i. Let us assume that S denotes the sum of the heights of all these nodes and S can be calculated as:

![alt text](image-12.png)

Multiplying with 2 on both sides gives: 2S=2h+4(h-1)+8(h-2)+...+2^(h-1) (1)

h=log(n+1)

![alt text](image-13.png)

### Q11. Give an algorithm to find all elements less than some value of k in a binary heap.

Start from the root of the heap. If the value of the root is smaller than k then print its value and call recursively once for its left child and once for its right child. If the value of a node is greater or equal than k then the function stops without printing that value.

The complexity of this algorithm is O(n), where n is the total number of nodes in the heap. This bound takes place in the worst case, where the value of every node in the heap will be smaller than k, so the function has to call each node of the heap.

### Q12.