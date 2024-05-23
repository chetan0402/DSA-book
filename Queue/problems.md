# Problems on Queues

### Q1. Give an algorithm for reversing a queue Q. To access the queue, we ar eonly allowed to use the methods of queue ADT

```c
void ReverseQueue(struct Queue*Q){
    struct Stack*S=CreateStack();
    while(!isEmptyQueue(Q)) Push(S,DeQueue(Q));
    while(!isEmptyQueue(S)) EnQueue(Q,Pop(s));
}
```

Time complexity: O(n)

### Q2. How to implement a queue using two stacks?

Let S1 and S2 be the two stacks to be used in the implementation of queue. All we have to do is to define the EnQueue and DeQueue operations for the queue.

```c
struct Queue{
    struct Stack*S1;
    struct Stack*S2;
}
```

**EnQueue Algorithm**

- Just push on to stack S1

```c
void EnQueue(struct Queue*Q,int data){
    Push(Q->S1,data);
}
```

Time complexity: O(1)

**DeQueue Algorithm**
- If stack S2 is not empty then pop from S2 and return the element
- if stack is empty, then transfer all elements from S1 to S2 and pop the top element from S2 and return that popped element [we can optimize the code little by transferring only n-1 elements from S1 to S2 and pop the nth element from S1 and return that popped elemnet].
- If stack S1 is also empty then throw error.

```c
int DeQueue(struct Queue*Q){
    if(!isEmptyQueue(Q->S2)) return Pop(Q->S2);
    else{
        while(!isEmptyStack(Q->S1)) Push(Q->S2,Pop(Q->S1));
        return Pop(Q->S2);
    }
}
```

Time complexity: From the algorithm, if the stack S2 is not empty then the complexity is O(1). If the stack S2 is empty then, we need to transfer the elements from S1 to S2. But if we carefully observe, the number of transferred elements and the number of popped elemnets from S2 are equal. Due to this the avgerage complexity of pop operation in this case is O(1). Amortized complexity of pop operation is O(1)

### Q3. Show how to efficiently implement one stack using two queues. Analyse the running time of stack operations.

Let Q1 and Q2 be thw two queues to be used in the implement of stack. All we have to do is to define the push and pop operations for the stack.

```c
struct Stack{
    struct Queue*Q1;
    struct Queue*Q2;
}
```

In below algorithms, we make sure that one queue is empty always.

**Push operation algorithm**: Whichever is queue is not empty, push the elemnt into it.
- Check wheather queue Q1 is empty or not. If Q1 is empty then EnQueue the element into Q2.
- Otherwise EnQueue the element into Q1

```c
Push(struct Stack*S,int data){
    if(isEmptyQueue(S->Q1)) EnQueue(S->Q2,data);
    else EnQueue(S->Q1,data);
}
```
Time complexity: O(1)

**Pop operation algorithm**: Transfer n-1 elements to other queue and delete last from queue for performing pop operation.
- If queue Q1 is not empty then transfer n-1 elements from Q1 to Q2 and then, DeQueue the last element of Q1 and return it.
- If queue Q2 is not empty then transfer n-1 elements from Q2 to Q1 and then, DeQueue the last element of Q2 and return it.

```c
int Pop(struct Stack*S){
    int i,size;
    if(isEmptyQueue(S->Q2)){
        size = size(S->Q1);
        i=0;
        while(i<size-1){
            EnQueue(S->Q2,DeQueue(S->Q1));
            i++;
        }
        return DeQueue(S->Q1);
    }else{
        size=size(S->Q2);
        while(i<size-1){
            EnQueue(S->Q1,DeQueue(S->Q2));
            i++;
        }
        return DeQueue(S->Q2);
    }
}
```

Time complexity: Running time of pop operation is O(n) as each time pop is called, we are transferring all the elemnts from one queue to other.

### Q4. Given a queue Q containing n elements, transfer these items on to a stack S so that front element of Q appears at the top of the stack and the orer of all other items is preserved. using enqueue and dequeue oeprations for the queue and push and pop operations for the stack, outline an efficient O(n) algorithm to accomplish the above task, using only a constant amount of additional storage

Assume the elements of queue Q are a1,a2 ... an. Dequeueing all elements and pushing them onto the stack will result in a stack with an at the top and a1 at the bottom. This is done in O(n) time as dequeue and push each require constnat time per operation. The queue is now empty. By popping all elements and pushing them on the queue we will get a1 at the top of the stack. This is done again in O(n) time. As in big-oh arithmetic we can ignore constant factors, the process is carried out in O(n) time.

### Q5. A queue is set up in a circular array A[0..n-1] with front and rear defined as usual. Assume that n-1 locations in the array are available for storing the elements. Give a formula for the number of elements in the queue in terms of rear, front and n.

- Rear of the queue is somewhere clockwise from the front
- To enqueue an element, we move rear one position clockwise and write the element in that position
- To dequeue, we simply move front one position clockwise.
- Queue migratesi n a clockwise direction as we enqueue and dequeue
- Emptiness and fullness to be checked carefully
- Analyze the possible situations. We will get this:
- if rear == front => `rear-front+1`
- else => `rear-front+n`