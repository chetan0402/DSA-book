# Hashing

## What is hashing?

Hashing is a technique used for storing and retrieving information as quickly as possible. It is used to perform optimal searches and is useful in implementing symbol tables.

## Why hashing?

In the trees chapter we saw that balanced binary searhc trees support operations such as insert, delete and search in O(logn) time. In applications, if we need these oeprations in O(1), then hashing provides a way. Remembeer that worst case complexity of hashing is still O(n), but it gives O(1) on the average.

## HashTable ADT

The common operation for hash table are:

- CreateHashTable: Creates a new hash table
- HashSearch: Searches the key in hash table
- HashInsert: INserts a new key into hash table
- HashDelete: delets a key from hash table
- DeleteHashTable: Deletes the hash table

## Understanding hashing

In simple terms we can treat array as a hash table. For understanding the use of hash tables, let us consider the following example: Give an algorithm for pritning the first repeated character if there are duplicated element in it. Let us think about the posisble solutions. The simple and brute force way of solvign is: given a string, for each character check whether that character is repeated or not. THe time complexity of this approach is O(n^2) with O(1) space complexity.

Now, let us find a better solution for this problem. Since our objective is to find the first repeated character, what if we remmeber the previous character in some array?

We know that the number of possible characters is 256. Create an array of size 256 and initialize it with all zeros. For each of the input characters go to corresponding position and increment its count. Since we are using arrays, it takes constnat time for reaching any location. While scanning the input if we get a character whose counter is already 1 then we can say that the character is the one which is repeating for the first time.

## Why not arrays?

In the previous problem, we have used an array of size 256 because we know the number of different possible characters [256] in advance. Now, let us consider a slight variant of the same problem. Suppose the given array has numbers instead of characters, then how do we solve the problem?

![alt text](image.png)

In this case the set of possible values is infinity. Creating a huge array and storing the counters is not possible. That means there are a set of universal keys and limited location in the memory. If we want to solve this problem we need to somehow map all the possible keys to the possible memory location. From the above discussion and diagram it can be seen that we need a mapping of possible keys to one of the available locations. As a result using simplea rrays is not the correct choice for solving the problems where the possible keys are very big. The process of mapping the keys to locations is called hashing.

## Components of hashing

Hashing has four keys compoenents:

1) Hash table
2) Hash functions
3) Collisions
4) Collison resolution techniques

## Hash table

Hash table is a generalization of array. With an array, we store the element whose key is k at a positon k of the array. That means, given a key k, we find the whose key is k by just looking in the kth position of the array. This is called direct addressing.

Direct addressing is applicable when we can afford to allocate an array with one position for every possible key. but if we do not have enough space to allocate a location for each possible key, then we need a mechanism to handle this case. nother way of defining the scenario is: if we have less locations and more possible keys, then simple array implementations is not enough.

In these cases one option is to use hash tables. Hash table or hash map is a data strucutre that stores the keys and their associated values, and hash table uses a hash function to map keys to their associated values. The general convention is that we use a hash table when the number of keys actually stored is small relative to the number of possible keys.

## Hash function

The hash function is used to transform the key into the index. Ideally, the hash function should map each possible key to a unique slot index, but is is difficult ot achieve in practice.

Given a collection of elements, a hash function that maps each item into a unique slot is referred to as a perfect hash function. If we know the elements and collection will never change, then it is possible to construct a perfect hash function. Unfortunately, given an arbitrary collection of elements, there is no systematic way to construct a perfect hash function. Luckily, we do not need the hash function to be perfect to still gain performance efficiency.

One way to awlays have a perfect hash function is to increase the size of the hash table so taht each possible value in the element range can be accommodated. This guarantees that each element will have a unique slot. Althought this is practical for small numbers of elements, it is not feasible when the number of possible elements is large. For example, if the elements were nine-digit social secuirty numbers, this method would require almost one billion slots. if we only want to store data for a class of 25 students, we will be wasting an enormous amount of memory.

Our goal is to create a hash function that minimizes the number of coolisions, is easy to compute, and evenly distributes the elements in the hash table. There are a number of common ways to extend the simple remainder method. WE will consider a few of them here.