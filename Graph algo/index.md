# Graph algorithms

## Introduction

In the real world, many problems are represented in terms of objects and connections between them. For example, in an airline route map, we might be interested in quesitons like: "What's the fastest way to go from Hyderabad to New York?" or "What is the chepaest way to go fro Hyderabad to New York?". To answer these questions we need information about connects (airline routes) between objects (towns). Graphs are data structures used for solving these kinds or problems.

## Glossary

**Graph**: A graph is a pair (V,E), where V is a set of nodes, called vertices and E is a collection of pair of vertices, called edges.
- Vertices and edges are positions and store elements
- Definitions that we use:
  - Directed edge:
    - ordered pair of vertices (u,v)
    - first vertex u is the origin
    - second vertex v is the destination
  - Undirected edge:
    - unordered pair of vertices (u,v)
  - Directied graph:
    - all the edges are directed
  - Undirected graph:
    - all the edges are undirected
- When an edge connects two vertices, the verticles are said to be adjacent to each other and edge is indicent on both vertices.
- A graph with no cycles is called a tree.
- A self loop is an edge that connects a vertex to itself.
- Two edges are parallel if they connect the same pair of vertices
- The degree of a vertex is the number of edges incident on it.
- A subgraph is a subset of a graph's edges that form a graph.
- A path in a graph in a sequence of adjacent vertices. Simple path is a path with no repeated vertices.
- A cycle is a path where the first and last vertices are the same. A simple cycle is a cycle with no repeated vertices or edges.
- We say that one vertex is connected to another if there is a path that contains both of them.
- A graph is connected if there is a path from every vectex to every other vextex.
- If a graph is not connected then it consists of set of connected compoenents.
- A directed acyclic graph [DAG] is a directed graph with no cycles. ![alt text](image.png)
- A forest is a disjoint set of trees.
- A spanning tree of a connected graph is a subgraph that contains all of that graph's vertices and is a single tree. A spanning forest of a graph is the union of spanning tree of its connected components.
- A bipartite graph is a graph whose vertices can be divided into two sets such that that all edges connnect a vertex in one set with a vertex in the other set. ![alt text](image-1.png)
- In weighted graphs integers are assigned to each edge to represent distance or costs.
- Graph will all edges present are called complete graphs.
- Graphs with relatively few edges are called sparse graphs.
- Graphs with relatively few of the possible edges mixxing are called dense.
- Directed weighted graphs arre sometimes called network.
- We will denote the number of vertices in a given graph by |V|, and the number of edges by |E|. Note that E can range anywhere from 0 to (|V|(|V|-1))/2. This is because each node can connect to every other node.

## Application of graphs

- Representing relationships between compoenents in electronic circuits
- Transportation networks: Highway network, flight network
- Computer networks: Local area network, internet, web
- Databases: For representing ER diagrams in databases, for representing dependency of tables in databases.

## Graph representation

As in other ADTs, to manipulate graphs we need to represent them in some useful form. basically, there are three ways of doing this:

- Adjacency matrix
- Adjacency list
- Adjacency set

