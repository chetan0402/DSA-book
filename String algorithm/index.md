# String algorithm

## Introduction

To understand the important of string algorithm let us consider the case of entering the URL. You will observe that after typing the prefix of the URL, a list of all possible URLs is displayed. That means, the browsers are doing some internal processing and giving us the list of matching URLs. This technique is sometimes called auto-completion.

Similarly, consider the case of entering the directory name in the command line interface. After tpying the prefix of directory name, if we press the tab button, we get a list of all matched directory names available. THis is anotehr example of auto completion.

In order to support these kinds of operations, we need a data structure which stores the string data efficiently. In this chapter, we will look at the data structures, the are useful for implementing string algorithms.

We start our discussion with the basic problem of strings: given a string, how do we search a substring? This is called a string matching problem. After discussin various string matching algorithms, we will look at different data structures for storing strings.

## String Matching Algorithms

In this setcion, we concentrate on checking whether a pattern P is a substring of another string T or not. Since we are trying to cehck a fixed string P, sometimes these algorithm are called exact string matching algorithms. To simplify our discussion. let us assume that the length of given text T is n and the length of the pattern P which we are trying to match has the length m. That means, T has the characters from 0 to n-1 and P has the charactesr from 0 to m-1. This algorithm is implemented in c++ as strstr().

In the subsequenct setcions, we start with the brute force method and gradually move towards better algorithms.
- Brute force method
- rabin-karp string matching algorithm
- String matching with finite automata
- KMP algorithm
- Boyer-moore algorithm
- Suffix trees

## Brute force method

In this method, for each possible position in the text T we check whether the pattern P matches or not. Since the length of T is n, we have n-m+1 possible choices for comparisons. This is because we do not need to check the last m-1 locations of T as the pattern length is m. The following algorithm searches for the first occurrence of a pattern string P in a text string T.

### Algorithm

Time complexity: (nm)

## Rabin-Karp String matching algorithm

In this method, we will use the hashing technique and instead of checking for each possible position in T, we check only if the hashing of P and the hashing of m character of T give the same result.

Initially, apply the hash function to the first m characters of T and check whether this result and P's hashing result is the same or not. If they are not the same, then go to the next character of T and again apply the hash function to m characters. If they are the same then we compare those m characters of T with P.

### Selecting Hash function

At each step, since we are finding the hash of m character of T, we need an efficient hash function. If the hash function takes O(m) complexity in every step, then the total complexity is O(nm). This is worse than the brute force method because first we are applying the hash function and also comparing.

Our objective is to select a hash function which takes O(1) complexity for finding the hash of m characters of T every time. Only then can we reduce the total complexity of the algorithm. If the hash function is not good (worst case), the complexity of Rabin-Karp algorithm is O(nm). If we select a good hash function, the complexity of the rabin-karp algorithm complexity is O(m+n). Now let us see how to select a hash function which can compute the hash of m character of T at each step in O(1).

For simplicity, let's assume that the characters used in string T are only integers. That means, all characters in T are digits. Since all of them are integers, we can view a string of m consecutive characters as decimal numbers. For example, string '61815' corresponds to the number 61815. With the above assumption, the pattern P is also a decimal value, and let us assume that the decimal value of P is p. For th given text T[0..n-1], let t(i) denote the decimal value of length-m substring T[i..i+m-1] for i=0,1,....,n-m-1. So, t(i)==p if and only if T[i...i+m-1]==P[0...m-1]

We can compute p in O(m) time using Horner's rule as:

`p = P[m-1]+10(P[m-2]+10(P[m-3]+...+10(P[1]+10P[0])))`

The code for above assumption is:
```c
int value=0;
for(int i=0;i<m-1;i++){
    value*=10;
    value+=P[i];
}
```