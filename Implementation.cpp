

#include "BST.h"


/**** BSTree::BstNode Implementation  ****/
/**
 *[BstNode Constructor]
 * Constructor copies the value of key and data into a BST node.Creates a new
 * empty node.
 *-----------------------------------------------------------------------------
 */
template <typename K, typename D,typename comparator >
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
template <typename K, typename D,typename comparator >
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
  template <typename K, typename D,typename comparator >
  BSTree<K,D,comparator>::BSTree(comparator comp):mcomp(comp)
    {
        rootptr=NULL;
     }



/**
 *[BSTree Destructor]
 *-----------------------------------------------------------------------------
 *This will destroy the tree from the memory when the destructor is called or
 *when the tree goes out of scope.
 */
  template <typename K, typename D,typename comparator >
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
template <typename K, typename D,typename comparator >
BstTree<K,D,comparator>::BstNode* GetNewNode(const K& key, const D& data)
{
    std::unique_ptr<BstNode> newNode(new BstNode())
    newNode -> data = data;
    newNode -> key = key;
    newNode -> left = newnode -> right = NULL;
    return newNode;
}




/**
 * [insert description]
 *
 * @param rootptr [pointer to root]
 * @param data    [value in entry]
 * @param key     [key of an entry]
 */
template <typename K, typename D,typename comparator >
typename BstNode<K,D,comparator>:: BstNode* BstNode<K,D,comparator>::
                    insert_helper(BstNode* rootptr,const K& key,const D& data)
{
    if(rootptr=NULL) // In case of empty tree, create new node
    {
        rootptr=GetNewNode(const K& key,const D& data);
        return rootptr;
    }
    //if data to be inserted is smaller than data in root, insert in left child.
    else if (key<=rootptr -> key())
    {
       rootptr->left()= insert_helper (rootptr->left(),key,data);//pass address of l.child.
    }
    //else, insert in right child.
    else
    {
        rootptr->right()=insert_helper(rootptr->right(),key,data);
    }
    return rootptr; //returns tree with nodes inserted

}

/**
 * [insert description]
 *
 * @param key  [key of the entry]
 * @param data [value of the entry]
 *-----------------------------------------------------------------------------
 * Insert a record into the tree. K Key value of the record.
 * D data to be inserted.
 */

template <typename K, typename D,typename comparator >
BSTree<K,D,comparator>::void insert(const K& key, const D& data)
 {
    rootptr = insert_helper(rootptr, key, data);
    nodecount++;
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
template <typename K, typename D,typename comparator >
typename BSTree<K,D,comparator>::iterator
BSTree<K,D,comparator>::find(const K& key) const
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
    template <typename K, typename D,typename comparator >
    BstNode<K,D,comparator>::FindMin () const
    {
    	while(rootptr->left != NULL) rootptr = rootptr->left;
    	return iterator{rootptr};
    }




/**
 * [Begin and End description]
 *
 * begin() and end () returns iterator to fully traverse the tree.
 * It also acts as a pointer to std::pair<const key,Entry>.
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
 * and past the last node element respectively.It cannot modify the contents.
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
 * iterator and a value , then look at its second field.
 */
template <typename K, typename D,typename comparator >
BstNode<K,D,comparator>::constexpr D& operator[] (const K& key )
{
    iterator itr = find(key);//get the underlying iterator by calling find
    if (itr != end()){
    return (*itr).second;
    }
    insert(node_data{key, D{}});
    return (*find(key)).second;
  }
}



/**
 *[const operator[] description]
 * Usage: myTree [" a string" ]=151;
 * @param  key [key is the reference to const K type]
 *-----------------------------------------------------------------------------
 * It will return a refrence to data (D) with the indicated key in the
 * tree.Incase the key is not found in the tree, throws out of range
 * exception.
 */
 template <typename K, typename D,typename comparator >
 BSTree<K,D,comparator>::
 constexpr const D& operator[] (const K& key) const
 {
    const_iterator itr = find(key);
    if (iter != end()) {
        return iter -> second;
    }
    throw std::out_of_range{" key not found in the tree"};
}
 }



/**
 * [iterator description]
 * @param n [description]
 *
 * Iterator class used to travel the tree using relative positions pointers:
 * parent, left, right.
 * It moves only forward, implemented with the operator++ overload.
 */
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

    //if no any right child found,walk up till it finds the right child & return


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


template <typename K, typename D,typename comparator>
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


/**
 * [Move constructor ]
 *
 * @param && other [Takes a rvalue reference to the class type]
 * ----------------------------------------------------------------------------
 * The new tree is created by swapping members.
 */

    template <typename K, typename D,typename comparator >
    BSTree<K,D,comparator>:: BST (BST<K,V,comp> &&other):
    rootptr{ std::move(other.rootptr) }
    {std::cout << "Last tree constructed with move-constructor." << std::endl;}



/**
 *[Move Assignment]
 *@param && other[passes on rvalue reference to the class type]
 *-----------------------------------------------------------------------------
 * In move assignment,it copies the data members and release the data pointer
 * from the source object so that the destructor does not free the memory
 * multiple times.
 */

    template <typename K, typename D,typename comparator >
    BSTree<K,D,comparator>:: BST& operator=(BST<K,V,comp> &&other)
    {
      // if the tree at the left hand side of the assignment isn't empty,
      // it's cleared. Existing nodes are deleted.
     if (!is_empty())
      {
        cout << "Clearing out previous content at left hand side..." << endl;
        rootptr = NULL;
      }
      // if the other tree isn't empty, its root is moved.
     if (!other.is_empty())
      {
        cout << "Moving root to the left-side." << endl;
        rootptr = std::move(other.rootptr);
      }

     return *this;
     }



  /**
    *[Put to operator << description]
    *@param const BST<K,D,comp>& mytree [reference to the constant class type]
    * -----------------------------------------------------------------------
    * Overload of put to operator <<.It allows to print the key-value pair in
    * chain with order.
    */
      template <typename K, typename D,typename  comparator >
      std::ostream& operator << (std::ostream& os, const BSTree& mytree)
      {

       for (const auto& x : mytree)

         { os << x.first << " : " << x.second << std::endl;}

       return os;

       }



    /**
     *  [clear description]
     *
     * ------------------------------------------------------------------------
     *  Deletes entire key-value pair from the tree.
     *
     */
     template <typename K, typename D, typename comparator >
     BSTree<K,D,comparator>:: void clear()
     {
       rootptr=NULL;
       rootptr=delete;
     }



     //creates a left unbalanced tree

     template <typename K, typename D, typename comparator >
     void BSTree<K,D,comparator>::void storeBstNodes(BstNode* rootptr,
                                                   std::vector<node_data>& N)
     {
         if (rootptr==NULL)
         return;

         storeBstNodes(rootptr->left,N);
         N.push_back(rootptr);
         storeBstNodes(rootptr->right,N)
     }



   /********* Balance function Implementation **********/


     //Construct Binary Tree recursively

     BstNode*rebuildTree(std::vector<node_data>& N,int start,int end)
     {


         if (start>end)
         return NULL;

        /* Making the middle data element the root.*/
        int mid=(start+end)/2
        BstNode*rootptr=N[mid];

        //insert(N[mid])

        /* Building left and right subtrees */
        rootptr->left=rebuildTree(N,start,mid-1);
        rootptr->right=rebuildTree(N,mid+1,end);

        return rootptr;

     }


      template <typename K, typename D,typename comparator >
      void BSTree<K,D,comparator>::balance()
      {
         Iterator it{this->begin()};
         Iterator end{this->end()};
         std::vector<node_data> N;

         if(start==end)
         {
             return;
         }

         for (;it != end; ++it)
         {
      	     pairs.push_back(*it);
         }

          clear();
          rebuildTree(N, 0, N.size()- 1);

       }
