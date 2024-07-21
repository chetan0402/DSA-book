# Sorting

## What is storing?

Sorting is an algorithm that arranges the elements of a lsit in a certain order [either ascending or descending]. The output is a permutation or reordering of the input.

## Classification of sorting algorithms

Sorting algorithms are generally categorized based on the followning parameters.

### By number of comparisons

In this method, sorting algorithms are classified based on the number of camparisons. For comparison based sorting algorithms, best case behavior is O(nlogn) and worst case behavior is O(n^2). Comparison-based sorting algorithms evalute the elements of the lsit by key comparison operation and need at least O(nlogn) comparisons for most inputs.

### By number of swaps

In this method, sorting algorithms are categorized by the number of swaps

### By memory usage

Some sorting algorithms are "in place" and they need O(1) or O(logn) memory to create auxiliary locations for sorting the data temprarily.

### By recursion

Sorting algorithms are either recursive [quick sort] or non-recursive [selection sort, and insertion sort] and there are some algorithms which use both (merge sort).

### by Stability

Sorting algorithm is stable if for all indices i and j such that the key A[i] equals key A[j], if record R[i] precedes record R[j] in the original file, record R[i] precedes record R[j] in the sorted list. Few sorting algorithms maintain the relative order of element with equal keys.

### By Adaptability

With a few sorting algorithms, the complexity changes based on pre-sortedness [quick sort]: pre-sortedness of the input affects the running time. Algorithms that take this into account are known to be adaptive.

## Other Classifications

Another method of classifying sorting algorithms is:
- Internal Sort
- External Sort

### Internal Sort

Sort algorithms that use main memory exclusively during the sort are called internal sorting algorithms. This kind of algorithm assumes high-speed random access to all memory.

### External Sort

Sorting algorithms that use external memory, such as tape or disk, during the sort came under this category.

## Bubble Sort

Bubble sort is the simplest sorting algorithm. It works by iterating the input array fromt he first element to the last, comparing each pair of elements and swapping them if needed. Bubble sort continues its iterations until no more swaps are needed. The algorithm gets its name from the way smaller elements "bubble" to the top of the list. Generally, insertion sort has better performance than bubble sort. Some researchers suggest that we should not teach bubble sort ebcause of its simplicity and high time complexity.

The only significant advantage that bubble sort has over other implementations is that it can detect whether the input list is already sorted or not.

### Implementation

```c
void BubbleSort(int A[],int n){
    for(int pass=n-1;pass>=0;pass--){
        for(int i=0;o<=pass-1;i++){
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
            }
        }
    }
}
```

We can improve it by using one extra flag. No more swaps indicate the completion of sorting. if the lsit is already sorted, we can use this flag to skip the remaining passes.

```c
void BubbleSortSkip(int A[],int n){
    int pass,i,swapped=1;
    for(pass=n-1;pass>=0 && swapped;pass-){
        swapped=0;
        for(i=0;i<=pass-1;i++){
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
                swapped=1;
            }
        }
    }
}
```

This modified version improves the best case of bubble sort to O(n).

### Performance

- Worst case complexity: O(n^2)
- Best case complexity: O(n)
- Wrost case space complexity: O(1)

