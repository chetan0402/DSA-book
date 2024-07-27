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

**Selection sort**: No. It divides the array into sorted and unsorted portions and iteratively finds the minimum values