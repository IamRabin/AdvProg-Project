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


public:


/**
 * [GetNewNode Description]
 * This function will create a new node in the heap.It takes key and value
 * (data) as an input.
 * ---------------------------------------------------------------------------
 * Usage: BstNode<int,string> mynew_Node;
 */
    BstNode<K,D>* GetNewNode(k key, D data);

/**
 * [Insert Description]
 *This function will allow to insert key and value in the tree.
 *----------------------------------------------------------------------------
 *Usage:insert(BstNode* root,D data,K key)
 *Usage: mytree.insert(root,"A string", 15);
 */

    BstNode<K,D>* insert(BstNode<K,D>* root,K key,D data);

/**
 * [find Description]
 *This function will take the arguments of root node, key and data to be found.
 *This will return true if the key is found and false otherwise.
 * ---------------------------------------------------------------------------
 * Usage:
 */

   bool find(BstNode<K,D>* root, K key, D data);






};








template <typename K, typename D >
BstNode<K,D>::GetNewNode(D data, K key)
{
    BstNode<K,D>* newNode = new BstNode(); // 'new' creates a node in the heap.
    newNode -> data = data;
    newNode -> key = key;
    newNode -> left = newnode -> right = newNode -> par = NULL;
    return newNode;
}


template <typename K, typename D >
BstNode<K,D>::BstNode<K,D>* insert(BstNode<K,D>* root,D data,K key)
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

template <typename K, typename D >
BstNode<K,D>::bool find(BstNode<K,D>* root,D data,K key)
{
    if (root==NULL) return false;
    else if (root->key==key) return true;
    else if (key <= root->key) return find(root->left,key);
    else return find(root->right, key);

}
