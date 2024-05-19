# Linked List

### Advantages of Linked list

#### They can be expanded in constant time. 

To create an array we must allocate memory for a certain number of elements. To add more elemnts to the array then we must create a new array and copy the old array into the new array.

We can prevent this by allocating lots of space initally but then you might allocate more than you need and wasting memory. With a linked list we can start with space for just one element allocated and add on new elements easily without the need to do any copying and reallocating

### Disadvantage

#### Access Time

Array is random-access, which means it takes O(1) to acess any element in the array. Linked lists takes O(n) for access to an element in the list in worst case. Another advantage of arrays in access time is special locality in memory. Arrays are defined as contiguous blocks of memory, and so any array element will be physically near its neighbors. This greatly benefits from modern CPU caching methods.

Althought the dynamic allocation of storage is a great advantage, the overhead with storing and retrieving data can make a big difference. Sometimes linked list are hard to manipulate. If the last item is deleted, the last but one must now have its pointer changed to hold a NULL reference. This required that the list is traversed to find the last but one link, and its pointer set to a NULL reference. Finally, linked lists wastes memory in terms of extra reference points

The ptrdiff pointer field contains the difference between the pointer to the next node and the pointer to the previous node. POinter difference is calcualted by using X-OR operation.