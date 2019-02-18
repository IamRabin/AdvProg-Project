

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
 *[BstNode Destructor]
 *This will destroy the node from the memory when the destructor is called or
 *the node goes out of scope
 * ---------------------------------------------------------------------------
 */
template <typename K, typename D,comparator >
BSTree<K,D,comparator>::BstNode::~BstNode() {
    std::cout << "~Node@" << this << endl;
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
 *-----------------------------------------------------------------------------
 *This will destroy the tree from the memory when the destructor is called or
 *when the tree goes out of scope.
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
    //**** if key not found, it will insert it in right child? ****
    else
    {
        rootptr->right=insert(rootptr->right,data,key);
    }
    return rootptr; //returns pointer to BstNode;collects the root address.

}





/**
 * [find description]
 *
 * @param  const K& key [reference to const K]
 * ---------------------------------------------------------------------------
 * This function returns an iterator to the entry in the BSTree.
 *
 *
 */
template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::iterator
BSTree<K,D,comparator>::iterator<K,D,comparator>::find(const K& key) const
{
  BstNode<K,D,comparator> * current{root};
  while (current)
  {
    // when key found return iterator to the node that holds it
    if (current->key == key)
    {
      return iterator{current};
     }
    // if the key to be found is smaller than current one, go left
    else if (current-> key > key)
    {
      current = current-> left;
     }
     // if the key to be found is greater than current one, go right
    else
    {
      current = current -> right;}
  }
  // if the key is not found, return end, that returns an iterator to nullptr
  return end()
}





/**
 *[FindMin description]
 * This function finds the smallest key in the tree.
 * @param  rootptr [It is the pointer to a node]
 * @return         [returns pointer to the node with min key]
 * ----------------------------------------------------------------------------
 */
template <typename K, typename D,comparator >
BstNode<K,D,comparator>::BstNode* FindMin(BstNode* rootptr)
{
	while(rootptr->left != NULL) rootptr = rootptr->left;
	return rootptr;
}



/**
 * begin() and end () returns iterator(s) to fully traverse the tree.
 */

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::iterator begin()
{ return iterator{FindMin()}; }

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::iterator end()
{ return iterator{nullptr}; }

/**
 * begin() and end () returns const_iterator(s) to fully traverse the tree.
 */

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::const_iterator begin()
{ return const_iterator{FindMin()}; }

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::const_iterator end()
{ return const_iterator{nullptr}; }


/**
 * cbegin and cend returns a const_iterator pointing to the first node
 * and past the last node element respectively.
 * It cannot modify the contents.
 *
 */

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::const_iterator cbegin()
const { return const_iterator{FindMin()}; }

template <typename K, typename D,comparator >
typename BSTree<K,D,comparator>::const_iterator cend()
const { return const_iterator{nullptr}; }



/**
 *[operator[] description]
 * This square bracket operator overloaded will be implemented interms of
 * insert().
 * @param  key [key is the reference to const K type]
 * -----------------------------------------------------------------------------
 * This operator overloading function will call insert to get a pair of an
 * iterator and and a , then look at its second field.
 */
template <typename K, typename D,comparator >
BstNode<K,D,comparator>::constexpr D& operator[] (const K& key )
{
    iterator itr = find(key);//get the underlying iteratorby calling find
    if (itr != end())
    return (*itr).second;
    insert(node_data{key, D{}});
    return (*find(key)).second;
  }
}




//********* Iterator Implementation*********************

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
    //if there aren't right child, go up till there is one and return it
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

}


  //copyHelper function, copy node and than recursively child nodes
  template <typename K, typename D,comparator>
  void BSTree<K,D,comparator>::copyHelper(BstNode * nodeptr)
  {
    if (nodeptr)
    {
      insert(nodeptr->data);
      copyHelper(nodeptr->left);
      copyHelper(nodeptr->right);
    }
  }



  //copy Constructor, use copyHelper
  template <typename K, typename D,comparator>
  constexpr BSTree<K,D,comparator>::BSTree(const BSTree& copy)
  {
    rootptr=nullptr;
    copyHelper(copy.rootptr);
  }

  //copy assignment, use copyHelper to copy all members from one tree to the other
  template <typename K, typename D,comparator>
  constexpr BSTree<K,D,comparator>::BSTree& operator=(const BSTree& copy)
  {
    clear();
    copyHelper(copy.rootptr); //call helper to perform copy
    return *this;
  }
