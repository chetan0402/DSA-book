# Problems

### Q1. Given an array A[0...n-1] of n numbers containing the repetition of some number. Give an algorithm for checking whether there are repeated elements or not. Space comexplity: O(1)

Since we are not allowed to use extra space, one simple way is to scan the elements one-by-one and for each element check whether that element appears in the remaining elements. If we find a match we return true.

```c
int checkDuplicatesInArray(int A[],int n){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(A[i]==A[j])
                return true;
    return false;
}
```

Time complexity: O(n^2)

### Q2. Can we improve the time complexity of Q1?

Using sorting technique

```c
int checkDuplicatesInArray(int A[],int n){
    heapsort(A,n);
    for(int i=0;i<n-1;i++)
        if(A[i]==A[i+1])
            return true;
    return false;
}
```

Time complexity: O(nlogn)

### Q3. Given an array A[0...n-1], where each element of the array represents a vote in the election. Assume that each vote is given as an integer representing the ID of the chosen cadidate. Give an algorithm for determining who wins the election.

This problem is nothing but finding the element which repeated the maximum number of times. The solution is similar to the Q1,

```c
int checkWhoWinsTheElection(int A[],int n){
    int i,j,counter=0,maxCounter=0,cadidate;
    cadidate=A[0];
    for(i=0;i<n;i++){
        candidate=A[i];
        counter=0;
        for(j=i+1;i<n;j++){
            if(A[i]==A[j]) counter++;
        }
        if(counter>maxCounter){
            maxCounter=counter;
            candidate=A[i];
        }
    }
    return candidate;
}
```

Time complexity: O(n^2)

### Q4. Can we improve the time complexity of Q3? Assume we don't have any extra space.

The approach is to sort the votes based on candidate ID, then can the sorted array and count up which candidate so far has the most votes. We only have to remember the winner, so we don't need a clever data strcuture. We can use heapsort as it is an in-place sorting algorithm.

```c
int checkWhoWinsTheElection(int A[],int n){
    int i,j,currentCounter=1,maxCounter=1;
    int currentCandidate,maxCandidate;
    currentCandidate=maxCandidate=A[0];
    heapsort(A,n);
    for(int i=1;i<=n;i++){
        if(A[i]==currentCandidate) currentCounter++;
        else{
            currentCandidate=A[i];
            currentCounter=1;
        }
        if(currentCounter>maxCounter) maxCounter=currentCounter;
        else{
            maxCandidate=currentCandidate;
            maxCounter=currentCounter;
        }
    }
    return candidate;
}
```

Time complexity: O(nlogn)

### Q5. Can we further imrpove the time complexity of Q3?

In the given problem, the number of candidates is less but the number of votes is significantly large. For this problem we can use counting sort.

Time complexity: O(n), n is the number of votes (elements) in the array. Space complexity: O(k), k is the number of candidates participating in the election.

### Q6. Given an array A of n elements, each of which is an integer in the range [1,n^2], how do we sort the array in O(n) time?

If we subtract each numberf by 1 then we get the range [0,n^2-1]. if we consider all numbers as 2-digit base n. Each digit ranges from 0 to n^2-1. Sort this using radix sort. This uses only two calls to counting sort. Finally, add 1 to all the numbers. SInce there are 2 calls, the complexity is O(2n) ~ O(n).

### Q7. For Q6, what if the range is [1...n^3]?

If we subtract each number by 1 then we get the range [0,n^3-1]. Considering all numbers as 3-digit base n: each digit ranges from 0 to n^3-1. Sort this using radix sort. This uses only three calls to counting sort. Finally, add 1 to all the numbers. Since there are 3 calls, the complexity is O(3n).

### Q8. Given an array with n integers, each of value less than n^100, can it be sorted in linear time?

Yes. The reasoning is same as in of Q6 & Q7.

### Q9. Let A and B be two arrays of n elements each. Given a number K,give an O(nlogn) time algorithm for determining whether there exists a is memeber of A and b is memeber of B such that a+b=K.

Since we need O(nlogn), it gives us a pointer that we need to sort. So, we will do that.

```c
int find(int A[],int B[],int n,K){
    int i,c;
    heapsort(A,n);
    for(i=0;i<n;i++){
        c=k-B[i];
        if(binarySearch(A,c)) return 1;
    }
    return 0;
}
```

O(nlogn)

### Q10. Let A,B and C be three arrays of n elements each. Given a number K, give an O(nlogn) time algorithm for determining whether there exists a is memeber of A,b is emember of B & c is memeber of C such that a+b+c=K.

Refer to searching chapter.

### Q11. GIven an array of n elements, can we output in sorted order the K elements following the median in sorted order in time O(n+KlogK).

Yes. Find the median and partition the median. With this we can find all the elements greater than it. Now find the Kth largest element in this set and partition it; and get all the elements less than it. Output the sorted list of the final set of elements. Clearly, this operation takes O(n+KlogK) time.

### Q12. Consider the sorting algorithms: Bubble sort, insertion sort, selection sort, merge sort, heap sort, and quick sort. Which of these are stable?

Lelt us assume that A is the array to be sorted. Also, let us say R and S have the same key and R appears earlier in the array than S. That means, R is at A[i] and S is at A[j], with i < j. To show any stable algorithm, in the sorted output R must precede S.

**Bubble sort**: Yes. Elements change order only when a smaller record follows a large. Since S is not smaller than R it cannot precede it.

**Selection sort**: No. It divides the array into sorted and unsorted portions and iteratively finds the minimum values in the unsorted position. After finding a minimum x, if the algorithm moves x into the sorted portion of the array by means of a swap, then the element swapped could be R which then could be moved behind S. This would invert the positions of R and S, so in general it is not stable. If swapping is avoided, it could be made stable but the cost in time would proabbly be very significant.

**Merge sort**: Yes, in the case of records with equal keys, the record in the left subarray gets preference. Those are the records that came first in the unsorted array. As a result, tehy will precede later records with the same key.

**Heap sort**: No, Suppose i=1 and R and S happen to be the two records with the largest keys in the input. The R will remain in location 1 after the array is heapified, and will be placed in location n in the first iteration of heapsort. Thus S will precede R in the output.

**Quick sort**: No, The partitioning step can swap the location of records many times, and thus two records with equal keys could swap position in the final output.

### Q13. Consider the same sorting algorithms as that of Q12. Which of them are in-place?

**Bubble sort**: Yes, because only two integers are required.

**Insertion sort**: Yes, since we need to store two integers and a record.

**Selection sort**: Yes. This algorithm would likely need space for two integers and one record.

**Merge sort**: No. Arrays need to perform the merge. (If the data is in the form of a linked list, the sorting can be done in-place, but this is a nontrivial modification.)

**Heap sort**: Yes, since the heap and partilaly-sorted array occupy opposite ends of the input array.

**Quick sort**: No, since it is recursive and stores O(logn) activation records on the stack. Modifying it to be non-recursive is feasible but nontrivial.

### Q14. Among Quick sort,Insertion sort, Selection sort, and Heap sort algorithms, which one needs the minimum numbers of swaps?

Selection sort - it needs n swaps only

### Q15. What is the minimum number of comparisons required to determine if an integer appears more than n/2 times in a sorted array of n integers?

Refer to searching chapter.

### Q16. Sort an array of 0's,1's and 2's: Given an array A[] consisting of 0's, 1's and 2's, give an algorithm for sorting A[]. The algorithm should put all 0's first, then all 1's and all 2's last.

Use counting sort. Since there are only three elemenets and the maximum value is 2, we need a temporary array with 3 elements.

Time comexplity: O(n) . Space complexity: O(1)

### Q17. Is there an other way of solving Q16?

Using quick sort. Since we know there there are only 3 elements, 0,1 and 2 in the array, we can select 1 as a pivot element for quick sort. Quick sort finds the correct place for 1 by moving all 0's to the left of 1 and all 2's to the right of 1. For doing this it uses only one scan.

Time complexity: O(n)

### Q18. How do we find the number that appeared the maximum number of times in an array?

One simple approach is to sort the given array and scan the sorted array. While scanning, keep track of the element that occur the maximum number of times.

```c
quicksort(A,n);
int i,j,count=1,number=A[0],j=0;
for(i=0;i<n;i++){
    if(A[j]==A){
        count++;
        number=A[j];
    }
    j=i;
}
printf("Number:%d,count:%d",number,count);
```

Time complexity: O(nlogn)

### Q19. Is there any other way of solving Q18?

Using binary tree. Create a binary tree with an extra field count which indicates the number of times an element appeared in the input. Let us say we have created a binary search tree. Now, do the in-order traversal of the tree. The in-order traversal of BST produces the sorted list. While doing the in-order traversal keep track of the maximum element.

Time complexity: O(2n)

### Q20. Is there yet another way of solving Q18?

Using hash table. For each element for the given array we use a counter, and for each occurrence of the element we increment the corresponding counter. At the end we can just return the element which has the maximum counter.

Time complexity: O(n). Space complexity: O(n)

### Q21. Given a 2GB file with one string per line, which sorting algorithm would we use to sort the file and why?

When we have a size limit of 2GB, it means that we cannot bring all the data into main memory.

How much memeory do we have avaiable? Let's assume we have X MB of memory available. Divide the file into K chunks, where X*K ~ 2GB.
- Bring each chunk into memory and sort the lines as usual
- Save the lines back to the file
- Now bring the next chunk into memory and sort
- Once we are done, merge them one by one; in the case of one set finishing, bring more data from the particular chunk.

The above algorithm is also known as external sort. Step 3-4 is known as K-way merge. The idea behind going for an external sort is the size of data. Since the data is huge and we can't bring it to the memory, we need to go for a disk-based sorting algorithm.

### Q22. Nearly sorted: Given an array of n elements, each which is at most K positions from its target position. device an algorithm that sorts in O(nlogK) time.

Divide the elements into n/K groups of size K, and sort each peice in O(KlogK) time, let's say using mergesort. This preserves the property that no element is more than K elements out of position. Now, merge each block of K elements with the block to its left.

### Q23. Is there any other way of solving Q22?

Insert the first K elemnets into a binary heap. Insert the next element from the array into the heap, and delete the minimum element fromt he heap. Repeat.