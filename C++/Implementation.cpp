

#include "BST.h"

/**** BSTree Implementation  ****/


/**
 * [insert description]
 * @param key  [key of the entry]
 * @param data [value of the entry]
 * ----------------------------------------------------------------------------
 * Insert a record into the tree. K Key value of the record.
 * D data to be inserted.
 */
template <typename K, typename D,typename comparator >
void BSTree<K,D,comparator>::insert(std::pair<const K, D> entry)
{
  std::unique_ptr<BstNode> newNode(new BstNode(entry));
  if (rootptr == nullptr//first case tree is empty
    { rootptr = std::move(newNode);}//moving the content of newNode to rootptr
                                    //setting a new emoty node.
  else
  {
    BstNode* parent = rootptr.get();
    BstNode* current = rootptr.get();
    while (current != nullptr)
     {
      parent = current;
      if (current-> node_data.first < entry.first)
        { current = current->right.get(); }
      else
        { current = current->left.get(); }
      }
    if (parent->node_data.first < entry.first)
    { parent->right = std::move(newNode);}
    else
    { parent->left = std::move(newNode);}


    }

  }


/*
print functions used to print nodes in key ascending order
Used to debug tree functions.
 */

template <typename K, typename D,typename comparator >
void BSTree<K,D,comparator>::print() const noexcept
{ print(rootptr);}


template <typename K, typename D,typename comparator >
void BSTree<K,D,comparator>::print(const upTreeNode &node) const noexcept
{
  if ( node==nullptr) {return; }
  print(node->left);
  std::cout<<  node->node_data.first << " : " << node->node_data.second << std::endl;
  print(node->right);
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
 template <typename K, typename D, typename comparator >
 typename BSTree<K,D,comparator>::iterator
 BSTree<K,D,comparator>::find(const K& key)
{
  BstNode * current{rootptr.get()};
  while (current)
  {
    // when key found return iterator to the node that holds it
    if (current->node_data.first == key)
    {
      //std::cout<< "Key Found" << std::endl;
      return iterator{current};
    }
    // if the key to be found is smaller than current one, go left
    else if (mComp(key, current-> node_data.first))
    {
      //std::cout<<"Going left"<<std::endl;
      current = current-> left.get();
    }
     // if the key to be found is greater than current one, go right
    else
    {
      //std::cout<<"Going right"<<std::endl;
      current = current -> right.get();}
  }

  //std::cout<<"Key not found"<<std::endl;
  // if the key is not found, return end, that returns an iterator to nullptr
  return end();
}





/**
 *[FindMin description]
 * This function finds the smallest key in the tree.
 * @param  rootptr [It is the pointer to a node]
 * @return         [returns pointer to the node with min key]
 * ----------------------------------------------------------------------------
 */
    template <typename K, typename D,typename comparator >
    typename BSTree<K,D,comparator>::BstNode*
    BSTree<K,D,comparator>::FindMin() const noexcept
    {
      if ((rootptr==nullptr)) { return nullptr;};
      BstNode* current = rootptr.get();
    	while(current->left.get() != nullptr)
      {
        current = current->left.get();
    	}
      return current;

    }














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
D& BSTree<K,D,comparator>::operator[] (const K& key )
{
    std::pair< K, D>entry{key, D{}};
    iterator itr=find(key);//get the underlying iterator by calling find
    if (itr != end())
    {
    return (*itr).second;
    }
    insert(entry);
    return (*find(key)).second;
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
 constexpr const D& BSTree<K,D,comparator>::operator[] (const K& key) const
 {
    const_iterator itr = find(key);
    if (itr != end()) {
        return itr -> second;
    }
    throw std::out_of_range{" key not found in the tree"};
}




/**
 * [iterator description]
 * @param n [description]
 *
 * Iterator class used to travel the tree using relative positions pointers:
 * parent, left, right.
 * It moves only forward, implemented with the operator++ overload.
 */
template <typename K, typename D,typename comparator>
class BSTree<K,D,comparator>::iterator
{

  friend class BSTree;
  using node = BSTree<K,D,comparator>::BstNode;
  //using node_data = typename BSTree<K,D>::node_data;

private:
  // pointer to the node currently used by iterator
  node * current;


public:
  // costructor initialize iterator to node n
  iterator(node * n) : current{n} {}

  //deference operator, return std::pair<const K,D> of current node
  std::pair<const K, D>& operator*() const { return current-> node_data; }

  // forward operator, to move iterator to next node
  iterator& operator++()
  {
    //if current has right child go right
    if (current -> right != nullptr) {
      current = current -> right.get();
      //now go to the leftmost node adn return it
      while (current-> left.get()) {
        current = current->left.get();
      }
    }


    //if no any right child found,walk up till it finds the right child & return


    else {
      node * up = current -> par;
      while ( up != nullptr && current == up->right.get()) {
        current = up;
        up = up->par;
      }
      current = up;
    }
    return *this;
  }

    // comparison operators
    bool operator==(const iterator& other) { return (current == other.current);}
    bool operator!=(const iterator& other) { return (current != other.current);}
  };



template <typename K, typename D,typename comparator>
class BSTree<K,D,comparator>::const_iterator : public BSTree<K,D,comparator>::iterator
{
  friend class BSTree;
  using node = BSTree<K,D,comparator>::BstNode;
  using it = BSTree<K,D,comparator>::iterator;

  public:
    //constructor from  iterator
    using it::iterator;

    //const dereference from iterator
    const std::pair<const K, D>& operator*() const { return it::operator*();}

};





//copyHelper function, copy node and than recursively child nodes
template <typename K, typename D,typename comparator>
void BSTree<K,D,comparator>::copyHelper(const std::unique_ptr<BstNode>& nodeptr)
{
  if (nodeptr)
  {
    insert(nodeptr->node_data);
    copyHelper(nodeptr->left);
    copyHelper(nodeptr->right);
  }
}

  //copy Constructor, use copyHelper
  template <typename K, typename D,typename comparator>
  BSTree<K,D,comparator>::BSTree(const BSTree& source)
  {
    std::cout<<"Copy constructor called" <<std::endl;
    rootptr=nullptr;
    copyHelper(source.rootptr);
  }

  //copy assignment, use copyHelper to copy all members from one tree to the other
  template <typename K, typename D,typename comparator>
  BSTree<K,D,comparator>& BSTree<K,D,comparator>::operator=(const BSTree& source)
  {
    std::cout<<"Copy assignment called" <<std::endl;

    //check for self assignment; tree1==tree1
    if(this==&source)
    {
      return *this;
    }

    clear();
    copyHelper(source.rootptr); //call helper to perform copycopyHelper
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
    BSTree<K,D,comparator>:: BSTree(BSTree<K,D,comparator> &&other):
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
     BSTree<K,D,comparator>& BSTree<K,D,comparator>::
     operator=(BSTree<K,D,comparator> &&other)
    {
      // if the tree at the left hand side of the assignment isn't empty,
      // it's cleared. Existing nodes are deleted.
     if (rootptr != nullptr)
      {
        std::cout << "Clearing out previous content at left hand side..." << std::endl;
        rootptr = nullptr;
      }
      // if the other tree isn't empty, its root is moved.
     if (other != nullptr)
      {
        std::cout << "Moving root to the left-side." << std::endl;
        rootptr = std::move(other.rootptr);
      }

     return *this;
     }


    /**
     *  [clear description]
     *
     * ------------------------------------------------------------------------
     *  Deletes entire key-value pair from the tree.
     *
     */
     template <typename K, typename D, typename comparator >
     void BSTree<K,D,comparator>::clear()
     {
       rootptr.reset();
       std::cout << "BSTree Cleared" << std::endl;
     }










           /**** Balance function Implementation ****/


     //Construct Binary Tree recursively
     template <typename K, typename D, typename comparator >
     void BSTree<K,D,comparator>::
     rebuildTree(std::vector<std::pair<const K, D>>& N,int start,int end)
     {


         if (start>end)
         return;

        /* Making the middle data element the root.*/
        int mid=(start+end)/2;

        insert(N[mid]);


        //insert(N[mid])

        /* Building left and right subtrees */
        rebuildTree(N,start,mid-1);
        rebuildTree(N,mid+1,end);


     }


      template <typename K, typename D,typename comparator >
      void BSTree<K,D,comparator>::balance()
      {
         iterator it{this->begin()};
         iterator end{this->end()};
         std::vector<std::pair<const K, D>> N;
         std::cout<<N.size()<<std::endl;
         if(it==end)
         {
             return;
         }

         for (;it != end; ++it)
         {
      	     N.push_back(*it);
         }

          clear();
          rebuildTree(N, 0, N.size()- 1);

       }
