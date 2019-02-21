/*********************************************************************
 * @file
 * @author  Rabindra Khadka <rabindra.khadka@ymail.com>
 *          Tommaso Rodani <trodani@sissa.it>
 *
 * @version 1.0
 *
 *
 * @section DESCRIPTION
 * Binary Search Tre(BST) implements the following public operations:
 * 1. constructor- constructs empty tree.
 * 2. destructor- destroys after the tree is out of scope.
 * 3. insert()- inserting a new pair key-value.
 * 4. clear()- clearing the content of the tree.
 * 5. begin()- returns the iterator to the first node.
 * 6. end()- returns a proper iterator.
 * 7. cbegin()- returns a const_iterator to the first node.
 * 8. cend()-return a proper const_iterator
 * 9. balance()- balances the tree.
 * 10.find()- finds a given key and returning an iterator to that node.
 * 11.copy constructors
 * 12.move semantics
 *
 *
 */

 //including header guards

 #ifndef __BST_H_INCLUDED__
 #define __BST_H_INCLUDED__

 /*including dependencies */
 #include <iostream>      //For performing input,output
 #include <iterator>     //For iterator,reverse iterator
 #include <memory>      //For managing dynamic memory
 #include <utility>    //For pair
 #include <vector>    //For container functions
 #include <algorithm>//For comparing,equal,max,find
 #include <stdexcept>//For out of range situation


 /**
  * [BstNode Description]
  * BstNode defines a node for Binary Search Tree which has key-value
  * pair, pointer to left and righ child. The internal node will also
  * contain pointer to parent.It takes any data type as the class is
  * templated.
  */
template < typename K, typename D, typename comparator=std::less<K> >
class BSTree
{
private:
    struct BstNode;
    typedef std::unique_ptr<BstNode> upTreeNode;
    struct BstNode
    {

    K key;    //Key value associated with data
    D data;   // Data
    upTreeNode left;   //left child
    upTreeNode right; // right child
    BstNode* par;  //parent




    //int nodecount; //counting number of nodes in the BST
    BstNode(); //default constructor
    BstNode(const K& key, const D& data);//cosntructor initialises the key-value
    ~BstNode();//destructor

     };

     using node_data = std::pair<K, D>;// data is stored in node_data

     comparator mComp; //compartor used to compare and store elements.
     upTreeNode rootptr;//pointer to root node in BST.

     BstNode* FindMin() const;//function that returns pointer to min. key in tree

     friend class iterator;
     friend class const_iterator;


public:

/**
 * [BSTree description]
 * Constructor: BSTree (comparator comp=comparator());
 * Usage:BSTree<string,int> mytree;
 * Usage:BSTree<string, int>mytree(mycompareFunction)
 * ----------------------------------------------------------------------
 * This constructor constructs a new empty tree and compares key based on the
 * choosen comparison type.
 */
  BSTree(comparator comp=comparator());



/**
 *[~BSTree() description]
 * Destructor: ~ BSTree()
 * Usage: Implicit
 * ---------------------------------------------------------------------
 * Destroys the tree by deallocating memory.
 */
   ~BSTree();


/**
 *[Copy Function description]
 * Copy Constructor: BSTree(const BSTree& other);
 * Copy Assignment:BSTree& operator= (const BSTree& other);
 * Usage:BSTree<string,int>one=two;(Used to create a new object by initalising
 *                                   with the value that currently exists)
 *       one=two;(Used to assign an already existing object to another existing
 *                 object by deep copy.)
 *------------------------------------------------------------------------------
 *  Both the overloaded assignmnet operator and the copy constructor performs
 *  deep copy. Overloaded assignment only invoked if the object already exists.
 */
   BSTree (const BSTree& source);
   BSTree& operator=(const BSTree& source);

 /**
  * [copyHelper description]
  * @param node [description]
  * this function is used to copy recursively all the nodes of a tree,
  * copy constructor and copy assignement make use of it.
  *
  */
   void copyHelper(const std::unique_ptr<BstNode> nodeptr);


 /**[Move Semantics Description]
 * Usage:BSTree<string,int>one=two
 *-----------------------------------------------------------------------------
 * Move constructor, create a new BST by swapping members.
 * Move assignment, move the members of other onto this.
 *
 * compiler chooses between the copy constructor and the move constructor
 *  based on whether the argument to the assignment operator is an lvalue
 *  or an rvalue.
 */
    BSTree (BSTree<K,D,comparator> &&other);
    BSTree& operator=(BSTree<K,D,comparator> &&other);


/**
* [insert description]
* @param key  [key of the entry]
* @param data [value of the entry]
* ----------------------------------------------------------------------------
* Insert a record into the tree. K Key value of the record.
* D data to be inserted.
 */
    void insert(const K& key, const D& data);
    void print() const;
    void print(const upTreeNode&) const;





  /**
   *[const_
   * description]
   * Type:iterator
   * Type: const_iterator
   * ---------------------------------------------------------------------------
   * Iterators that can traverse the items in the tree in ascending order.
   */
   class iterator;
   class const_iterator;


/**
 *
 * Usage:for (myTree<string, int>::iterator itr = i.begin();
 *          itr != i.end(); ++itr) { ... }
 *-----------------------------------------------------------------------
 * begin() and end () returns iterator to fully traverse the tree.It also
 * acts as a pointer to std::pair<const key,Entry>.
 */
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

/**
 *Usage:for (myTree<string, int>::const_iterator itr = i.cbegin();
 *          itr != i.cend(); ++itr) { ... }
 * ----------------------------------------------------------------------
 * cbegin and cend returns a const_iterator pointing to the first node
 * and past the last node element respectively.It cannot modify the
 * contents.
 */
   const_iterator cbegin() const;
   const_iterator cend() const;

   /**
    *[find Description]
    *iterator find(const K& key);
    * Usage:if (myTree.find("a string") != myTree.end()) {...}
    * -----------------------------------------------------------------------------
    * Returns an iterator to the entry in the tree with the specificed key and
    * ends if it does not exits.
    */

    iterator find(const K& key) const;

/**
* [balance description]
* Performs balancing of the tree based on the concept of minimum height.
* Traverses the BST inorder and store  results in a vector which produces
* sorted sequence.Then a balanced BST is build using the recursive approach.
* storeBstNodes function stores all the nodes of the tree in a std::vector
* rebuildTree retrieve nodes from storeBstNodes and rebuild the tree balanced.
** -----------------------------------------------------------------------
*/
void storeBstNodes(BstNode* rootptr, std::vector<node_data>& N);
BstNode* rebuildTree(std::vector<node_data>& N, int start, int end);
void balance();



   /**
    * [clear description]
    * -------------------------------------------------------------------------
    * Deletes entire key-value pair from the tree.
    */
     void clear();


/**
 *[operator[] description]
 * Usage: myTree [" a string" ]=151;
 *------------------------------------------------------------------------------
 *  It will return refrence to data (D) with the indicated key in the tree.
 *  Incase the key is not in the tree, it gets inserted into the tree with
 *  default constructor and its data.
 */
   D& operator[] (const K& key );


/**
 *[const operator[] description]
 * Usage: myTree [" a string" ]=151;
 *-----------------------------------------------------------------------------
 * It will return a refrence to data (D) with the indicated key in the
 * tree.Incase the key is not found in the tree, throws out of range exception.
 */

   constexpr const D& operator[] (const K& key) const;



/**
  *[Put to operator << description]
  * ---------------------------------------------------------------------------
  * Overload of put to operator <<.It allows to print the key-value pair in
  * chain with order.
  */
    friend std::ostream& operator<<(std::ostream& os, const BSTree& mytree)
    {

     for (const auto& x : mytree)

       { os << x.first << ": " << x.second << std::endl;}

     return os;

   };




 /**
   * [const operator[] description]
   * Comparison operators for BSTree

    template <K, D, comparator >
    bool operator==(const BSTree<K, D, comparator>& lhs,
                    const BSTree<K, D, comparator>&  rhs);
    */
};

#endif
