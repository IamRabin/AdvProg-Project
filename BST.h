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
private:

    BstNode<K,D>* left;   //left child
    BstNode<K,D>* right; // right child
    BstNode<K,D>* par;  //parent

    D data;  // Data
    K key;  //Key value associated with data

};

public:
/**
 * [BstNode description]
 *
 * --------------------------------------------------------------------------
 * Usage:
 *
 */

   BstNode(const K& key,const D& data,BstNode<K,D>* l,BstNode<K,D>* r);

/**
 * [GetNewNode Description]
 * This function will create a new node in the heap.It takes key and value
 * (data) as an input.
 * ---------------------------------------------------------------------------
 * Usage: BstNode<int,string> mynew_Node;
 */
    BstNode* GetNewNode(k key, D data);

/**
 * [Insert Description]
 *This function will insert key and value in the tree.
 *----------------------------------------------------------------------------
 *Usage:insert(BstNode* root,D data,K key)
 *Usage: mytree.insert(root,"A string", 15);
 */

    BstNode* insert(BstNode* root,D data,K key);

/**
 * [find Description]
 *This function will take the arguments of root node, key and data to be found.
 *This will return true if the data is found and false otherwise.
 * ---------------------------------------------------------------------------
 * Usage:
 */

    bool find(BstNode* root,int data);


     clear()


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
BstNode<K,D>::GetNewNode(D data, K key)
{
    BstNode* newNode = new BstNode(); // 'new' creates a node in the heap.
    newNode -> data = data;
    newNode -> key = key;
    newNode -> left = newnode -> right = newNode -> par = NULL;
    return newNode;
}


template <typename K, typename D >
BstNode<K,D>::BstNode* insert(BstNode* root,D data,K key)
{
    if(root=NULL) // case of empty tree
    {
        root=GetNewNode(data,key);// if empty tree create a new node and set as root
        return root;
    }
    // if data to be inserted is smaller, insert in left child.
    else if (data<=root -> data) //if inserted data is less than data in root
    {
        root->left= insert (root->left, data, key);//passing address of left child
    }
    //else, insert in right child.
    else
    {
        root->right=insert(root->right,data);
    }
    return root; //return type pointer to BstNode , collects the root address

}

template <typename K, typename D >
BstNode<K,D>::bool find(BstNode* root,D data,K key)
{
    if (root==NULL) return false;
    else if (root->data==data) return true;
    else if (data <= root->data) return find(root->left,data);
    else return find(root->right, data);

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
