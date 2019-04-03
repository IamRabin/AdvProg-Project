# Programming Project
This repo contains the project completed as an assessment for the `Advanced Programming` course of DSSC @ University of Trieste, Italy.

# Binary Search Tree

![](Figures/BST_PIC.png )


## Introduction

A binary search tree consists of nodes which itself is a small binary tree
containing left pointer, right pointer and a data entry. As node itself is a
small tree, the left and right pointer recursively points to sub-tree or nodes
ahead. For each node, all elements to the left of the node is smaller or equal
to the node element and all the elements to the right are greater than the node
element. Binary Search Tree has the advantage of fast insert and lookup which
yields the time complexity in average O(log(n)) and at the worst case scenario
time goes up to O(n).

In this project, a templated binary  search tree has been implemented with its
various functions. The performance of this constructed binary search tree was
compared with the standard library class map and unordered map based on the
cases of balanced and unbalanced binary search tree respectively.


## Type Heirarchy

In the program, `BSTree` class defines `BSTNodes` and `Iterators` in a nested
form as shown in figure 1 below.The iterators class are declared friends of
`BstNode struct` so that it can access the data members of the node. Node
consists of key-data pair which are the entry element in a node of a binary
tree.

![](Figures/Heirarchy.png )

 **Fig. 1** - Binary Search Tree Program Schematic

## Characteristics of a Binary Search Tree:

While designing  the program, some of the questions were staged as follows;
- what kind of characteristics will a tree have?
- What are the common behaviour shown by each node of the tree?
- What type of access control can be set for the data members  and its function?.
- Which classes can be a friend of the BST node to access its data members?

![](Figures/code_snippet.png )


 **Fig. 2** - Snippet of Base type Binary Search Tree

As seen above in fig 2, the `BStNode` is under `struct` and the access was made
private so that user will not be able to modify the node data members. Also a
node contains three pointers namely pointers to left child, right child and
pointer to parent. The smaller or equal keys are found on the left of the node
and higher value keys are found on the right of the node.

`BSTree` has two members namely `rootptr` which is a pointer to root node and `mComp` which is used to compare and store entry elements. The classes `iterators` and `const_iterators` are declared as friends of the `BstNode` with public access as they are used to perform forward iterations through the BSTree.Overloading `operator++` was used to iterate in forward direction. `Const_iterator` is a derived class from the base class `iterator`.

## Member Functions:

`BstNode` has mainly two functions constructors and destructors that initialises its data members upon calling constructor and destroys as destructor is called.The main members functions of `BSTree` class are discussed below:

1.`Insert`: This function will allow to insert key and value in the tree with the use of insert helper function.

2.`Find`:This function returns an iterator to the entry in the tree with the specified key and ends if it does not exits.

3.`Copy and Move Semantics` : In the case of copy semantics both the overloaded assignment operator and the copy constructor performs deep copy. Overloaded assignment is invoked if the object already exists and the copy constructor is invoked to create a new object from the existing object. Similarly with move semantics, move constructor creates a new BST by swapping members while move assignment move the members of other onto this. Compiler chooses between the copy constructor and the move constructor based on whether the argument passed is a l-value or a r-value.

4.`Begin and End` :Begin() and end () function returns iterator to fully traverse the tree. It also acts as a pointer to std::pair<const key,Entry>.

5.`Compare`: Compare performs templated defined comparison between keys and prints out the keys according to the chosen compare method.

6.`Operator []`: It will return reference to data (D) with the indicated key in the tree. In case the key is not in the tree, it gets inserted into the tree with default constructor and its data.

7.`Balance`:Performs balancing of the tree based on the concept of minimum height 1 or -1. Traverses the BST in order and store  results in a vector which produces sorted sequence. Then a balanced BST is build using the recursive approach.

## Testing of Function members of BSTree:

Testing was performed by using the 'main.cpp' file where all the member functions of the class BSTree was tested. After the test run were successfully performed, memory leak check was done using valgrind .
At first, the code was compiles using gcc with debugging information on `$ gcc -Wall -g myprog.c -o myprog`.Then finally the memcheck tool was run using valgrind with the following output in fig 3. `[valgrind --leak-check=yes ./myprog]`

![](Figures/valgrind.png)
**Fig. 3**- Snippet of Valgrind result with no memory leak.

## Performance Comparison:

 Find function was used to perform lookup while recording the time it took to
 find the elements in different STL containers namely map, unordered map and our
 binary search tree. At first the entries were limited up to 15 k and then increased
 up to 10^6.The performance time can be visually seen in fig 4 and fig 5 below
 which depicts the performance of the data structures with large and small data
 entries respectively.

![](Figures/large_entry.png)

**Fig. 4**- Comparing lookup time between STL data structures vs BST with entries up to 10^6.



![](Figures/Small_Entries.png )

**Fig. 5** - Comparing lookup time between STL data structures vs BST with entries up to 15k.





 ## Conclusion:

 In case of small amount of data entries, unordered map had the best performance
 due to the fact that it had less hash key collision but when the entries
 were increased our balanced binary search tree had the best performance with almost
 constant search time. Unbalanced key showed the worst performance with both large
 and smaller amount of entries.
