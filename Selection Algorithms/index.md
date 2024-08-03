# Selection Algorithms [Medians]

## What are selection algorithm?

Selection algorithm is an algorithm for findign the kth smallest/largest number in a list. This includes finding the minimum, maximum and median elements. For findign the kth order statistic, there are multiple solutions which provide different complexities, and in this chapter we will enumerate those possibilites.

## Selection by sorting

A selection problem can be converted to a sorting problem. In this method, we first sort the input elements and then get the desired element. It is efficient if we want to perform many selections.

For example, let us say we want to get the minimum element. After sorting the input elements we can simply return the first elemnet. Now, if we want to find the second smallest element, we can simply return the second element from the sorted list.

That means, for the second smallest element we are not performing the sorting again. The same is also the case with subsequenct queries. even if we want to get kth smallest element, just one scan of the sorted list is enough to find the element

From the above disucssion what we can say is, with the intial sorting we can answer any query in one scan, O(n). In general, this method requires O(nlogn) time. Suppose we are performing n queries, then the average cost per operation is jsut O(logn). This kind of analysis is called amortized analysis.

## Partition-based selection algorithm

for the algorithm check Q6. This algorithm is similar to quick sort.

## Linear selection algorithm - Median of Medians algorithm

- Worst-case performance: O(n)
- Best-case performance: O(n)
- Worst-space complexity: O(1) auxiliary

Refer to Q11.

## Finding the K smallest elements in sorted order.

For the algortihm check Q6. This algorithm is similar to quick sort.