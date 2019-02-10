/*****************************************************
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
template <typename K, typename D >
class BstNode
{
protected:
    BstNode<K,D>* left;   //left child
    BstNode<K,D>* right; // right child
    BstNode<K,D>* par;  //parent

    D data;  // Data
    K key;  //Key value associated with data


public:

    /**
     * This constructor will copy the value data and key into a BstNode.
     * Usage:     
     * -----------------------------------------------------------------------
     *
     */

    BstNode(const K& key,const D& data,BstNode<K,D>* l,BstNode<K,D>* r);


   /**
    * Secondary node constructor which makes a copy of the original one.
    * Usage: BstNode<K,D> one =two;
    *        one=two;
    * -------------------------------------------------------------------------
    * Allows to make this tree a deep copy of the original tree
     */

    BstNode(const BstNode<K,D>*& copy);


/* Mutable member functions allowing us to change key and value */
    /**
     * usage:
     * .......................................................................
     * Allows to change and return the key.
     */
    K& get_key() {return key};

    /**
     * [get_data description]
     *........................................................................
     *
     * @return [description]
     */
    D& get_data() {return data; }

   /**
    * [get_left description]
    */
    BstNode<K,D>*& get_left() {return left;}

    /**
     * [get_right description]
     */
    BstNode<K,D>*& get_right() {return right;}

    void set_key(const K& entry ){key=entry}
    void set_data(const D& Value ){data=Value;}
    void set_left(BstNode* l){left=l;}
    void set_right(BstNode* r){right=l;}

/* Immutable Member Functions */

   const K& get_key() const{return key;}
   const D& get_data const{return data;}
   const BstNode<K,D>* get_left() const {return left;}
   const BstNode<K,D>* get_right() const {return right;}

 /*Convienence Functions */

 bool is_leaf ()const {return (left==NULL) && (right==NULL);}

};






template <typename K, typename D >
BstNode<K,D>::BstNode(const K& Key,const D& value=D(),p(NULL),l(NULL),r(NULL)
{
data = value;
key=Key;
left=l;
right=r;
par=p;
}

template <typename K, typename D >
BstNode<K,D>::BstNode(const BstNode<K,D>*& copy)
{
    if(copy==NULL)
       this==NULL;

    else
    {
          data=copy.data;
          key=copy.key;
          left=copy.left;
          right=copy.right;
          par=copy.par;
      }
}




template <typename K, typename D,typename compare=std::less<K> >
class BalanceTree{
public:
    /**
     * constructor:BalanceTree(compare comp=compare());
     * usage:AVLTree<string,int>myBalanceTree;
     * usage:BalanceTree<string,int>myBalanceTree(MycomparisonFunction);
     * ------------------------------------------------------------------
     * Builds a new tree that compares keys using the indicated
     * comparator.
     */
    BalanceTree(compare comp=compare());
}
