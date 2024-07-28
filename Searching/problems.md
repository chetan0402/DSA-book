# Problems

### Q1. Given an array of n numbers, give an algorithm for checking whether there are any duplicate elements in teh array or no?

This is one of the simplest problems. One obvious answer to this is exhaustively searching for duplicates in the array. That means, for each input element check whether there is any element with the same value. This we can solve jusut by using two simple for loops.

### Q2. Can we improve the complexity of Q1's solution?

Yes. sort the given array. After sorting, all the elements with euqal values will be adjacent. Now, do another scan on this sorted array and see if there re elements witht he same value and adjacent.

Time complexity: O(nlogn)

### Q3. Is there any alternative way of solving Q1?

Yes, using hash table. Hash tables are a simple and effective method used to implement dictionaries. Average time to search for an element is O(1), while worst-case tie is O(n). Refer to hashing chapter for more details on hashing algorithms. As an example, consider the array, A={3,2,1,2,2,3}

Scan the input array and insert the elements into the hash. For each inserted element, keep the coutner as 1. This indicates that the corresponding element has occurred already. For the given array, the hash table will look like.

![alt text](image-4.png)

Time complexity: O(n)

### Q4. Can we further improve the complexity of Q1 solution?

Let us assume that the array elements are positive numbers and all the elements are in the range 0 to n-1. For each element A[i], go to the array elements whose index is A[i]. That means select A[A[i]] and mark - A[A[i]]. Continue this process until we encounter the element whose value is already negated. if one such element exists then we say duplicate elements exist in the given array. As an example, consider the array, A={3,2,1,2,2,3}.

Initially,

![alt text](image-5.png)

At step-1, negate A[abs(A[0])],
![alt text](image-6.png)
At step-2, negate A[abs(A[1])],
![alt text](image-7.png)
At step-3, negate A[abs(A[2])],
![alt text](image-8.png)
At step-4, negate A[abs(A[3])],
![alt text](image-9.png)
At step-4, observe that A[abs(A[3])] is already negative. That means we have encountered the same value twice.

![alt text](image-10.png)

Time complexity: O(n)

Note:
- This solution does not work if the given array is read only.
- This solution will work only if all the array elements are positive.
- If the elements range is not in 0 to n-1 then it may give exceptions.

### Q5. Given an array of n numbers. Give an algorithm for finding the element which appears the maximum numbers of times in the array?

**Brute Force solution**: One simple solution to this is, for each input element check whether there is any element with the same value, and for each such occurrence, increasement the coutner. Each time, check the current counter with the max coutner and update it if this value is greate rhtan max counter. This we can solve just by using two simple for loops.

![alt text](image-11.png)