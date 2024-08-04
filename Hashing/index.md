# Hashing

## What is hashing?

Hashing is a technique used for storing and retrieving information as quickly as possible. It is used to perform optimal searches and is useful in implementing symbol tables.

## Why hashing?

In the trees chapter we saw that balanced binary searhc trees support operations such as insert, delete and search in O(logn) time. In applications, if we need these oeprations in O(1), then hashing provides a way. Remembeer that worst case complexity of hashing is still O(n), but it gives O(1) on the average.

## HashTable ADT