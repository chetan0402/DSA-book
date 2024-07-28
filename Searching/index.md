# Searching

## What is searching?

In computer science, searching is the process of finding an item with specified properties from a collection of items. The items may be stored as records in a databse, simple data elements in arrays, text in files, nodes in trees, vertices and edges in graphs, or they may be elements of other search spaces.

## Why do we need searching?

Searching is one of the core computer science algorithms. We know that today's computers store a lot of information. To retriee this informaiton proficiently we need very efficient searching algorithms. There are certain ways of organizing the data the improves the searching rocess. That means, if we keep the data in proper order, it is easy to search the required element. Sorting is one of the techniques for making the elements ordered. In this chapter we will see diferent searching algorithms.

## Types of searching

Following are the types of searches which we will be discussing in this book.

- Unordered linear search
- sorted/ordered linear search
- binary search
- interpolation search
- binary searhc trees
- symbol tables and hashing
- string search algorithms

## Unordered linear search

Let us assume we are given an array where the order of the elements is not known. That means the elements of the array are not sorted. In this case, to search for an element we have to scan the compelte array and see if the element is there in the given list or not.

```c
int unorderedLinearSearch(int A[],int n,int data){
    for(int i=0;i<n;i++){
        if(A[i]==data) return i;
    }
    return -1;
}
```

Time complexity: O(n), in the worst case we need to scan the complete array. Space complexity: O(1)

## Sorted/Ordered linear search

If the elements of the array are already sorted, then in many cases we don't have to scan the complete array to see if the element is there in the given array or not. In the algorithm below, it can be seen that, at any point if the value at A[i] is greater than the data to be searched, then we just return -1 without searching the remaining array.

```c
int orderedLinearSearch(int A[],int n,int data){
    for(int i=0;i<n;i++){
        if(A[i]==data) return i;
        else if(A[i]>data) return -1;
    }
    return -1;
}
```

Time complexity of this algorithm is O(N). This is because in the worst case we need to scan the compelte array. BUt in the average case it reduces the complexity even though the growth rate is same.

Space complexity: O(1)

For the above algorithm we can make further improvement by incrementing the index at a faster rate (say,2). THis will reduce the number of comparisons for searching in the sorted list.

## Binary search

