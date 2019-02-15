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
 #include<iostream>      //For performing input,output
 #include<iterator>     //For iterator,reverse iterator
 #include<memory>      //For managing dynamic memory
 #include<utility>    //For pair
 #include<algorithm> //For comparing,equal,max
 #include<stdexcept>//For out of range situation


 /**
  * [BstNode Description]
  * BstNode defines a node for Binary Search Tree which has key-value
  * pair, pointer to left and righ child. The internal node will also
  * contain pointer to parent.It takes any data type as the class is
  * templated.
  */
template < typename K, typename D, typename comparator=std::less<key> >
class BSTree
{
private:
    struct BstNode
    {

    BstNode* left;   //left child
    BstNode* right; // right child
    BstNode* par;  //parent

    D data;  // Data
    K key;  //Key value associated with data
    std::pair<const K, D> node_data // data is stored in node_data

    BstNode(const K& key, const D&);//cosntructor initialises the key/value pair

     };

     comparator mComp; //compartor used to compare and store elements.
     BstNode* rootptr;//pointer to root node in BST.

     friend class iterator;
     friend class const_iterator;


public:

/**
 * [BSTree description]
 * Constructor: BSTree (comparator comp=comparator());
 * Usage:BSTree<string,int> mytree;
 * Usage:BSTree<string, int>mytree(mycompareFunction)
 * ----------------------------------------------------------------------------
 * This constructor constructs a new empty tree and compares key based on the
 * choosen comparison type.
 */
  BSTree(comparator comp=comparator());



/**
 *[~BSTree() description]
 * Destructor: ~ BSTree()
 * Usage: Implicit
 * -----------------------------------------------------------------------------
 * Destroys the tree by deallocating memory.
 */
   ~BSTree();


/**
 *[Copy Function description]
 * Copy Constructor: BSTree(const BSTree& other);
 * Copy Assignment:BSTree& operator= (const BSTree& other);
 * Usage:BSTree<string,i nt>one=two;(Used to create a new object by initalising
 *                                   with the value that currently exists)
 *       one=two;(Used to assign an already existing object to another existing
 *                 object by deep copy.)
 *------------------------------------------------------------------------------
 *  Both the overloaded assignmnet operator and the copy constructor performs
 *  deep copy. Overloaded assignment only invoked if the object already exists.
 */
   constexpr BSTree (const BSTree& copy);
   constexpr BSTree& operator=(const BSTree& copy);


 /**[Move Semantics Description]
 * Usage:
 *-----------------------------------------------------------------------------
 * Move constructor, create a new BST by swapping members.
 * Move assignment, move the members of other onto this.
 *
 * compiler chooses between the copy constructor and the move constructor
 *  based on whether the argument to the assignment operator is an lvalue or
 *  an rvalue.
 */
    BST (BST<K,V,comp> &&other);
    BST& operator=(BST<K,V,comp> &&other);


/**
 *[GetNewNode Description]
 * This function will create a new node in the heap.It takes key and value
 * (data) as an input.
 * -----------------------------------------------------------------------------
 * Usage: BstNode<int,string> mynew_Node;
 */
    constexpr BstNode* GetNewNode(k key, D data);


/**
 *[Insert Description]
 * This function will allow to insert key and value in the tree.
 *------------------------------------------------------------------------------
 *Usage:insert(BstNode* root,D data,K key)
 *Usage: mytree.insert(root,"A string", 15);
 */
    constexpr BstNode* insert(BstNode* rootptr, K& key,D& data);


/**
 *[find Description]
 * This function will take the arguments of root node, key and data to be found.
 * This will return true if the key is found and false otherwise.
 * -----------------------------------------------------------------------------
 * Usage:
 */
   constexpr iterator find(BstNode* rootptr, K key, D data);



  /**
   *[const_iterator description]
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
 *-----------------------------------------------------------------------------
 * begin() and end () returns iterator to fully traverse the tree.It also acts
 * as a pointer to std::pair<const key,Entry>.
 */
   constexpr iterator begin();
   constexpr iterator end()
   constexpr const_iterator begin();
   constexpr const_iterator end();


/**
 *Usage:for (myTree<string, int>::const_iterator itr = i.cbegin();
 *          itr != i.cend(); ++itr) { ... }
 * ----------------------------------------------------------------------------
 * cbegin and cend returns a const_iterator pointing to the first node
 * and past the last node element respectively.It cannot modify the contents.
 */
   constexpr const_iterator cbegin();
   constexpr const_iterator cend();


/**
 * [balance description]
 * Performs balancing of the tree based on the concept of minimum height.
 * Traverses the BST inorder and store  results in a vector which produces
 * sorted sequence.Then a balanced BST is build using the recursive approach.
 * ----------------------------------------------------------------------------
 */
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
   constexpr D& operator[] (const K& key );


/**
 *[const operator[] description]
 * Usage: myTree [" a string" ]=151;
 *-----------------------------------------------------------------------------
 * It will return a refrence to data (D) with the indicated key in the
 * tree.Incase the key is not found in the tree, throws out of range exception.
 */

   constexpr const D& operator[] (const K& key) const;



/**
  *
  * ---------------------------------------------------------------------------
  * Overload of put to operator <<.It allows to print the key-value pair in
  * chain with order.
  */
    std::ostream& operator<<(std::ostream& os, const BST<K,D,comp>& mytree)

};


 /**
   * Comparison operators for BSTree
   */
    template <typename K, typename D,comparator >
    bool operator==(const BSTree<K, V, comp>& lhs,
                    const BSTree<K, V, comp>&  rhs);






/* * * * * Implementation Below This Point * * * * */










/* Constructor initialises a new empty tree. */

template <typename K, typename D,comparator >
BstTree<K,D,comparator>::BSTree(comparator comp):mComp(comp)
{
    par=left=right=rootptr=NULL;
}





template <typename K, typename D,comparator >
BstTree<K,D,comparator>::GetNewNode(D data, K key)
{
    BstNode<K,D>* newNode = new BstNode(); // 'new' creates a node in the heap.
    newNode -> data = data;
    newNode -> key = key;
    newNode -> left = newnode -> right = newNode -> par = NULL;
    return newNode;
}


template <typename K, typename D,comparator >
BstNode<K,D,comparator>::BstNode<K,D>* insert(BstNode<K,D>* rootptr,D data,K key)
{
    if(root=NULL) // In case of empty tree
    {
        root=GetNewNode(data,key);//  create a new node and set as root
        return root;
    }
    //if data to be inserted is smaller than data in root, insert in left child.
    else if (key<=root -> key)
    {
        root->left= insert (root->left, data, key);//pass address of left child.
    }
    //else, insert in right child.
    else
    {
        root->right=insert(root->right,data,key);
    }
    return root; //return type is pointer to BstNode;collects the root address.

}

template <typename K, typename D,comparator >
BstNode<K,D>::iterator,bool find(BstNode<K,D>* root,D data,K key)
{
    if (root==NULL) return ;
    else if (root->key==key) return true;
    else if (key <= root->key) return find(root->left,key);
    else return find(root->right, key);

}
