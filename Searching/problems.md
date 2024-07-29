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

Time complexity: O(n^2)

### Q6. Can we improve the complexity of Q5 solution?

Yes. Sort the given array. After sorting, all the elements with equal values come adjacent. Now, just do another scan on this sorted array and see which element is appearing the maximum number of times.

TIme complexity: O(nlogn)

### Q7. Is there any other way of solving Q5?

Yes, using hash table. For each element of the input, keep track of how many times that element appeared in the input. That means the counter value represents the number of occurrences for that element.

Time complexity: O(n)

### Q8 Can we improve Q5 time complexity? Assume that the element's range is 1 to n. That means all the element are within this range only.

Yes. We can solve this problem in two scans. We cannot use the negation technique of Q3 for this problem because of the number of repetitions. in the first scn, instead of negating, add the value n. That means for each occurrence of an element add the rray size to that element. In the second scan, check the element value by dividing it by n and return the elemnet which gives the maximum value. The code based on this method is given below.

```c
void maxRepititions(int A[],int n){
    int i=0,max=0,maxIndex;
    for(i=0;i<n;i++) A[A[i]%n]+=n;
    for(i=0;i<n;i++)
        if(A[i]/n > max){
            max = A[i]/n;
            maxIndex=i;
        }
    return maxIndex;
}
```

**Note**:
- This solution does not work if the given array is read only.
- This solution will work only if the array elements are positive.
- If the elements range is not in 1 to n then it may give exceptions.

Time compelxity: O(n)

### Q9. Given an array of n numbers, give an algorithm for finding the first element in the array which is repeated. For example, in the array A={3,2,1,2,2,3}, the first repeated number is 3 (not 2). That means, we need to return the first elemnet among the repeated elements.

We use can the brute force solution that we used for Q1. For each element, since it checks whether there is duplicate for that element or not, whichever element duplicates first will be returned.

### Q10. For Q9, can we use the sorting technique?

No. For proving the failed case, let us consider the following array. For example, A={3,2,1,2,2,3}. After sorting we get A={1,2,2,2,3,3}. In this sorted array the first repeated element is 2 but the actual answer is 3.

### Q11. For Q9, can we use hashing technique?

Yes. But the simple hashing technique which we used for Q3 will not work. For example, if we consider the input array as A={3,2,1,2,3}, then the first repeated element is 3, but using our simple hashing technique we get the answer as 2. This is because 2 is coming twice before 3. Now let us change the hashing table behavior so that we go the frist repeated element. Let us say, isntead of storing 1 value, initially we store the position of the element in the array. As a result the hash table will look like

![alt text](image-12.png)

Now, if we see 2 again, we just negate the current value of 2 in the hash table. That means, we make its counter value as -2. The negative value in the hash table indicates that we have seen the same element two times. Similarly, for 3 (the next element in the input) also, we negate the current value of the hash table and finally the hash table will look like:

![alt text](image-13.png)

After processing the complete input array, scan the hash table and return the highest negative indexed value from it. The higest negative value indicates that we have seen that element first and also repeating.

**What if the element is repeated more than twice?** In this case, just skip the element if the corresponding value i is already negative.

### Q12. For Q9, can we use the technique that we use for Q3 (negation technique)?

No. As an example of contradiction, for the array A={3,2,1,2,2,3} the first repeated element is 3. But with negation technique the result is 2.

### Q13. Finding the missing number: We are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers i missing in the list. Given an algorithm to find the mixxing integers. Example: I/P: [1,2,4,6,3,7,8] O/P: 5

Brute force solution: One simple solution to this is, for each number in 1 to n, check whether that number is in the given array or not.

```c
int findMissingNumber(int A[],int n){
    int i,j,found=0;
    for(i=1;i<=n;i++){
        found=0;
        for(j=0;j<n;j++)
            if(A[j]==i)
                found=1;
        if(!found) return i;
    }
    return -1;
}
```

Time complexity: O(n^2)

### Q14. For Q13, can we use sorting technique?

Yes. Sorting the list will give the elements in increasing order and with another scan we can find the misisng number.

Time complexity: O(nlogn)

### Q15. For Q13, can we use hashing technique?

Yes. Scan the input array and insert elements into the hash. For inserted elemnets, keep counter as 1. This indicates that the corresponding element has occurred already. Now, scan the hash table and return the element which has counter value ero.

Time complexity: O(n)

### Q16. For Q13, can we improve the complexity?

Yes. We can use summation formula.

1) Get the sume of numbers, sum=n*(n+1)/2
2) Subtract all the numbers from sum and you will get the missing number.

### Q17. In Q13, if the sum of numbers goes beyond the maximum allowed integer, then there can be integer overflow and we may not get the correct answer. Can we solve this problem?

1) XOR all the array element, let the result of XOR be X.
2) XOR all numbers from 1 to n, let XOR be y.
3) XOR of x and y gives the misisng number.

Time complexity: O(n)

### Q18. Find the number occuring an odd number of times: Given an array of positive integers, all numbers occur an even number of times except one number which occurs an odd number of times. Find the number in O(n) tiem & constant space. Example: [1,2,3,2,3,1,3]. Answer=3

Do a bitwise XOR of all the elements. We get the number which has odd occurrences. This is beucase, A XOR A = 0.

Time complexity: O(n)

### Q19. Find the two repeating element in a given array: Given an array with size, all elements of the array are in range 1 to n and also all elements occur only once except two numebrs which occur twice. Find thoes two repeating numbers. For example: if the array is 4,2,4,5,2,3,1 with size=7 and n=5. The input has n+2=7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.

One simple way is to scan the complete array for each element of the input elements. That means use two loops. In the outer loop, select elements one by one and count the number of occurrences of the selected element in the inner loop. For the code below, assume that printRepeatedElements is called with n+2 to indicate the size.

```c
void printRepeatElements(int A[],int size){
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(A[i]==A[k])
                printf("%d",A[i]);
}
```

Time complexity: O(n^2)

### Q20. For Q19, can we improve the time complexity?

Sort the array using any comparison sorting algorithm and see if there are any elements which are contigous with thee same value.

Time complexityL O(nlogn)

### Q21. For Q19, can we improve the time complexity?

Use count array. This solution is like using a hash table. For simplicity we can use array for storing the counts. Traverse the array once and keep track of the count of all elements in the array using a temp array count[] of size n. When we see an element whose count is already set, print it as duplicate. For the code below assume that printRepeatedElements is called with n+2 to indicate the size.

```c
void printRepeatedElemenets(int A[],int size){
    int*count=(int *)calloc(sizeof(int),(size-2));
    for(int i=0;i<size;i++){
        count[A[i]]++;
        if(count[A[i]]==2)
            printf("%d",A[i]);
    }
}
```

Time complexity: O(n)

### Q22. Consider Q19. Let us assume that the numbers are in the range 1 to n. Is there any other way of solving the problem?

Yes, by using XOR operations. Let the repeating numbers be X and Y, if we XOR all the elements in the array and also all integers from 1 to n, then the result wil be X XOR Y. The 1's in binary repesentation of X XOR Y correspond to the differnet bits between X and Y. If the kth bit of X XOR Y is 1, we can XOR all the elemnets in the array and also all integers from 1 to n whose kth bits are 1. The result will be one of X and Y.

![alt text](image-14.png)

Time complexity: O(n)

### Q23. Consider Q19. Let us assume that the numbers are in range 1 to n. Is there yet other way of solving the problem?

We can solve this by creating two simple mathematical equations. let us assume that two numbers we are going to find are X and Y. We know the sum for n numbers is n(n+1)/2 and the product is n!. Make two equations using these sum and product formulae, and get values of two unknowns using the two equations. Let the summation of all numbers in array be S and product be P and the numbers which are being repeated are X and Y.

![alt text](image-15.png)

Using the eabove two equations, we can find out X and Y. There can be an addition and multiplication oveflow problem with this approach.

Time complexity: O(n)

### Q24. Similar to Q19, let us assume that the numbers are in the range to n. Also, n-1 elements are repeating thrice and reminaing element repeated twice. Find the element which repeated twice.

If we XOR all the elements in the array and all integers from 1 to n, then all the element which rare repeated thrice will become zero. This is because, since the elmenet is repeating thrice and XOR anotehr time from range makes the element appear four times. As a result, the output of a XOR a XOR a XOR a = 0. It is the same case with ll elements that are repeated three times.

With the same logic, for the elmenets which repeated tiwce, if we XOR the input elements and also the range, then the total number of appearances for that elemnet is 3. As a result, the output of a XOR a XOR a = a. Finally, we get the element which repeated twice.

Time complexity: O(n)

### Q25. Given an array of n elemenets. Find two elements in the array such that their sum is equal to given element K.

**Brute Force solution**: One simple solution to this is, for each input element, check whether there is any element whose sum is K. this we can solve just by using two simple for loops. The code for this solution canbe given as:

![alt text](image-16.png)

Time compelxity: O(n^2)

### Q26. For Q25, can we improve the time complexity?

Yes. Let us assume that we have sorted the given array. This operation takes O(nlogn). On the sorted array, maintain indices loIndex=0 nd hiIndex=n-1 and compute A[loIndex]+A[hiIndex]. If the sum equals K, then we are done with the solution. If the sum is less than K, decrement hiIndex, if the sum is greater than K, incremenet loIndex

Time complexity: O(nlogn)

### Q27. Does the solution of Q25 work even if the array is not sorted?

Yes. Since we are checking all possibilities, the algorithm ensures that we get the pair of numebrs if they exist.

### Q28. Is there any other way of solving Q25?

Yes, using hash table. Since our objective is to find two indexes of the array whose sum is K. Let us say those indexes are X and Y. That means A[X]+A[Y]=K. What we need is, for each element of the inptu array A[X], check whether K-A[X] also exists in the input array. Now, let us simplify that searching with hash table.

**Algorithm**:
- For each element of the input array, insert it into the hash table. Let us say the current element is A[X].
- Before proceeding to the next element we check whether K-A[X] also exists in the hash table or not.
- There existence of such number indicates that we are able to find the indexes.
- Otherwise proceed to the next input element.

Time complexity: O(n)

### Q29. Given an array A of n elements. Find three indices, i,j & k such that A[i]^2 + A[j]^2 = A[k]^2?

**Algorithm**:
- Sort the given array in-place.
- For each array index i compute A[i]^2 and store in array.
- Search for 2 numbers in array from 0 to i-1 which adds to A[i] similar to Q25. This will give us the result in O(n) time. If we find such a sum, return true, otherwise continue.

![alt text](image-17.png)

Time complexity: O(nlogn) + n*O(n) = n^2

### Q30. Two elements whose sum is closet to zero. Given an array with both positive and negative numbers, find the two elements such that their sum is closet to zero. For the below array, algorithm shoudl give -80 and 85. Example [1,60,-10,70,-80,85]

**Brute force solution**: For each element, find the sum with every other element in the array and compare sums. Finally, return the minimum sum.

O(n^2)

### Q31. Can we improve the time complexity of Q30?

Use sorting.

**Algorithm**:
1) Sort all the elements of the given input array.
2) Maintain two indexes, one at the beginning (i=1) and the other at the ending (j=n-1). Also, maintain two variables to keep track of the smallest positive sum closet to zero and the smallest negative sum closet to zero.
3) While i<j:
   1) If the current pair sum is >zero and < positiveClosert then update postiveClosert. Decrement j.
   2) If the current pair sum is < zero and >negativeClosest then update the negativeClosest. Increment i.
   3) Else, print the pair.

![alt text](image-18.png)

Time complexity: O(nlogn)

### Q32.