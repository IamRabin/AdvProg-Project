
#include "BST.h"


/**** BSTree::BstNode Implementation  ****/
/**
 *[BstNode Constructor]
 * Constructor copies the value of key and data into a BST node.Creates a new
 * empty node.
 *-----------------------------------------------------------------------------
 */
template <typename K, typename D,comparator >
BSTree<K,D,comparator>::BstNode::BstNode(const K& key, const D& data)
: node_data(key,Data)
{
    par=left=right=NULL;
}



/**** BSTree Implementation  ****/
/**
 * [BSTree Constructor]
 *
 * @param comp [compares key based on comparison type.]
 * ----------------------------------------------------------------------------
 * This constructor builds a new tree. Initally the tree is empty and all the
 * pointers are set to NULL.
 */
  template <typename K, typename D,comparator >
  BSTree<K,D,comparator>::BSTree(comparator comp):mcomp(comp)
    {
        par=left=right=rootptr=NULL;
     }



/**
 * [BSTree description]
 *
 */
  template <typename K, typename D,comparator >
  BSTree<K,D,comparator>:: ~BSTree()
  {

  }




/**
 * [GetNewNode description]
 *
 * @param key  [key for this entry]
 * @param data [value for this entry]
 *-----------------------------------------------------------------------------
 *Returns a pointer called newnode that points to a new node.
 */
template <typename K, typename D,comparator >
BstTree<K,D,comparator>::BstNode* GetNewNode(const K& key, const D& data)
{
    BstNode* newNode = new BstNode(); // 'new' creates a node in the heap.
    newNode -> data = data;
    newNode -> key = key;
    newNode -> left = newnode -> right = NULL;
    return newNode;
}

/**
 * [insert description]
 *
 * @param rootptr [description]
 * @param data    [description]
 * @param key     [description]
 */
template <typename K, typename D,comparator >
BstNode<K,D,comparator>::BstNode* insert(BstNode<* rootptr,D data,K key)
{
    if(rootptr=NULL) // In case of empty tree
    {
        rootptr=GetNewNode(data,key);//  create a new node and set as root
        return root;
    }
    //if data to be inserted is smaller than data in root, insert in left child.
    else if (key<=root -> key)
    {
        rootptr->left= insert (rootptr->left, data, key);//pass address of left child.
    }
    //else, insert in right child.
    else
    {
        rootptr->right=insert(rootptr->right,data,key);
    }
    return rootptr; //return type is pointer to BstNode;collects the root address.

}

/**
 * [find description]
 *
 * @param  root [description]
 * @param  data [description]
 * @param  key  [description]
 * @return      [description]
 */
template <typename K, typename D,comparator >
BstNode<K,D,comparator>::iterator,bool find(BstNode* rootptr,D data,K key)
{
    if (root==NULL) return false ;
    else if (root->key==key) return true;
    else if (key <= root->key) return find(root->left,key);
    else return find(root->right, key);

}
