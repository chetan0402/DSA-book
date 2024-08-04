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

In this method, for each possible position in the text T we check whether