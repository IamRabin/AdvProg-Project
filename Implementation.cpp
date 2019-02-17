
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


/**
 * [BstNode Destructor]
 *
 * ---------------------------------------------------------------------------
 */
template <typename K, typename D,comparator >
BSTree<K,D,comparator>::BstNode::~BstNode() {
    cout << "~Node@" << this << endl;
    if (left) delete left;
    if (right) delete right;
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
 * [BSTree Destructor]
 *
 */
  template <typename K, typename D,comparator >
  BSTree<K,D,comparator>:: ~BSTree()
  {
      cout << "Destructor of Tree" << endl;
       if (rootptr) delete rootptr;
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
BSTree<K,D,comparator>::BstNode* GetNewNode(const K& key, const D& data)
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

template <typename K, typename D,comparator >
BSTree<K,D,comparator>::iterator
{

  friend class BSTree;
  using node = BSTree<K,D,comparator>::BstNode;

private:
  // pointer to the node currently used by iterator
  node * current;


public:
  // costructor initialize iterator to node n
  iterator(node * n) : current{n} {}

  //deference operator, return std::pair<const K,D> of current node
  std::pair<const K, D,>& operator*() const { return current-> node_data; }

  // forward operator, to move iterator to next node
  iterator& operator++()
  {
    //if current has right child go right
    if (current -> right != nullptr) {
      current = current -> right;
      //now go to the leftmost node adn return it
      while (current-> left) {
        current = current->left;
      }
      return *this;
    }
    //if there aren't right child, go up till there is a right child and return it
    else {
      node_data* up = current -> par;
      while ( up != nullptr && current == up->right) {
        current = up;
        up = up->par;
      }
      current = up;
      return *this;
    }

    // comparison operators
    bool operator==(const iterator& other) { return (current == other.current);}
    bool operator!=(const iterator& other) { return (current != other.current);}
  }
}

template <typename K, typename D,comparator>
BSTree<K,D,comparator>::const_iterator : public BSTree<K,D,comparator>::iterator
{
  friend class BSTree;
  using node = BSTree<K,D,comparator>::BstNode;
  using it = BSTreeBSTree<K,D,comparator>::iterator;

  public:
    //constructor from  iterator
    using it::iterator;

    //const dereference from iterator
    const std::pair<const K, D,>& operator*() const { return it::operator*();}

    //operators from iterator:
    using it::operator++;
    using it::operator==;
    using it::operator!=;
