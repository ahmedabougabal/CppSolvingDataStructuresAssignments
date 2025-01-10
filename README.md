# CppSolvingDataStructuresAssignments

**_I will document some of my DataStructures taken notes here._**

[![Awesome](https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg)](https://github.com/sindresorhus/awesome)
[![Project Status](https://img.shields.io/badge/status-Still%20in%20Progress-yellow)](https://github.com/yourusername/mernStackMilestoneProject_ITI)
![Binary Tree](https://img.shields.io/badge/Data%20Structure-Binary%20Tree-blue)
![Linked List](https://img.shields.io/badge/Data%20Structure-Linked%20List-brightgreen)

![Profile Views](https://komarev.com/ghpvc/?username=ahmedabougabal&color=brightgreen)

# Trees

- trees are used to store information.
- tree is usually upside down.
- each circle is called a node or a vertex.
- link between 2 nodes is an edge.

![image](https://github.com/user-attachments/assets/52695b9b-7247-4b18-a50b-0f12cf44c5b0)

- from the above tree, we deduce the following. . .
- the edge is the distance (connection) between 2 nodes, node 5 has no edge with node 4
- [Tree with n nodes has n - 1 edges](https://www.cs.purdue.edu/homes/spa/courses/sa12/mod8.pdf)
- the tree has 4 levels, levels (0,1,2,3)
- Node(1) has 2 children: 2 and 3
- The parent of Node(7) is node(2)
- Nodes {5, 9} are siblings (brothers)
- height (specific to each node) represents the number of edges on the longest downward path between a node(vertex) and a leaf.
- Tree of N levels has N-1 heights, since that the tree above has 4 levels, then the height is 4-1 = 3 edges
- the height of the node 1 (root) is 3 (start from the root to the longest path downward to the farest leaf)
- node 7 has a height = 0
- Node's Depth : the number of edges from the node to the root node.
  **_Difference between Depth and Height_**
  - depth is specific about 2 nodes (root node and the current node only)
  - height is going down from the node to the leaves. (height is about my current node and any other node (leaf) i can reach - longest path)
- there is only 1 path between any 2 nodes. (you are now at the root node and you wanted to go to the node 4, then there is only 1 way (simple tree)
- in a tree where every node has only 1 single parent, then there is only 1 path from a node to another.

**Sub Trees**

- recursive nature where each tree has a subtree and each subtree has another subtree.
- Problem solving tip: we deduce that when we want to get the elements of a tree, we will do this recursively.

# Binary Trees

- a tree where each node at least has at most 2 children (left and right nodes).
- a leaf node is a node with no children.

**this is a simple tree (a node has many children)**
![image](https://github.com/user-attachments/assets/896209b1-7bba-4d07-bdcd-c1a92d3d5433)

**this is a binary tree (each node has at most 2 children)**
![image](https://github.com/user-attachments/assets/61f26fc1-cb60-4e11-9841-9947f31100fe)

-- A linked List is a special case of a binary tree.

# binary tree traversal 1

traversal is a way of walking through an elements of a data structure.

we need to create an expression tree (leaves are operands and others are operators)

can draw this tree : (2+3)\*4

types of traversal

- LVR (left, visit, right)
- VLR (visit, left, right)
- LRV (left, right, visit)

---

<div align="center" style="background-color: #f9f9f9; padding: 15px; border-radius: 10px; border: 1px solid #e1e4e8;">
  <h3>⚠️ Heads Up!</h3>
  <p><strong>This ReadMe is under constant updates.</strong></p>
  <p>Stay tuned for new notes, revisions, and insights as I continue building this repository. 📚💡</p>
</div>

---

# Acknowledgments

> Thanks to Dr.Moustafa Saad, Nidal Fikri
