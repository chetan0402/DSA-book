# Algorithm Design Techniques

## Classification

There are many ways of classifying algorithm and a few of them are shown below:
- Implemntation method
- design method
- other classifications

## Classification by implementation method

### Recursion or iteration

A recursive algorithm is one that calls itself repeatedly until a base condition is satisifed. It is a common method used in functional programming languages like C,C++,etc.

Iterative algorithms use constructs like loops and sometimes other data sturctures like stacks and queues to solve the problems.

Some problems are suited to recursive and others are suited for iterative. For example, the ToH problem can be easily understood in recursive implementations. Every recursive version has an iterative version and vice versa

### Procedural or declarative

IN declarative programming languages, we say what we want without having to say how to do it. With procedural programming, we have to specify the exact steps to get the result. For example, SQL is more declarative than procedural, because the queries don't specify the steps to produce the result. Example of procedural langauges include: C,PHP and PERL

### Serial or parallel or distributed

In general, while discussin the algorithm we assume that computers execute one instruction at a time. These are called serial algorithms.

Parallel algorithms take advantage of computer architectures to process serveral instructions at a time. They divide the problem in subproblems and serve them to several processors or threads. Iterative algorithm are generally parallelizable.

If the parallel algorithms are distributed on to differents machines then we call such algorithms distributed algorithms.

### Deterministic or Non-deterministic

Deterministic algorithm solve the problem with a predefined process, whereas non-deterministic algorithms guess the best solution at each step through the use of heuristics.

### Exact or approximate

As we have seen, for many problems we are not able to find the optimal solutions. That means, the algorithms for which we are able to find the optimal solutions are called exact algorithms. In computer science, if we do not have the optimal solution, we give approximation algorithms.

## Classification by deisgn method

Another way of classifying algorithm is by their design method

### Greedy Method

Greddy algorithms work in stages. In each stage, a decision is made that is good at that point, without bothering about the future consequences. Generally, this means the some local best is chosen. It assumes that the local best seleciton also makes for the global optimal solution.

### Divide and Conquer

1) Divide: Breaking the problem in sub problems that are themselves smaller instances of the same type of problem.
2) Recursion: Recursively solving these sub problems.
3) Conquer: Appropriately combining their answers.

### Dynamic Programming

Dynamic programming and memoization work together. The difference between DP and divide and conquer is that in the case of the latter there is no dependency among the sub problems, where in DP there will be an overlap of sub-problems. By usign memoization, DP reduces the exponential complexity to polynomial complexity

The difference between dynamic progrmaming and recursion is in the memoization of recursive calls. When sub programms are independent and if tehre is no repetition, memoization does not help.

### Linear programming

In linear programming, there are inequalities in terms of inputs and maximizing some linear function of the inputs. Many problems can be discussed using linear progrmaming.

### Reduction

In this method we solve a different problem by transfofmring it into a known problem for which we have asympotically optimal algorithms. In this method, the goal is to find a reducing algorithm whose complexity is not dominated by the resulting reduced algorith,s. For example, the selcetion algorithm for finding the median in a list involves first sorting the list and then finding out the middle element in the sorted list.