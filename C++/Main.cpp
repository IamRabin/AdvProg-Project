
#include "Implementation.cpp"

<<<<<<< HEAD


void template_comparison_test()
{
    BSTree<int,int,std::greater<int>> mytree;
    std::vector<int> treeholder{9,6,8,5,12,15};
    for(long unsigned int i=0; i< treeholder.size(); i++)
    {
        mytree.insert(treeholder[i],treeholder[i]);
    }
    std::cout << "inserted treeholder={9,6,8,5,12,15} " << std::endl;
    std::cout << mytree << std::endl;
};
=======
void template_comparison_test()
{
    BSTree<int,int,std::greater<int>> Atree;
    std::pair<int, int> pair;
    std::vector<int> treeholder{9,6,8,5,12,15};
    for(long unsigned int i=0; i< treeholder.size(); i++)
    {
        pair = {treeholder[i],treeholder[i]};
        Atree.insert(pair);
    }
    std::cout << "inserted treeholder={9,6,8,5,12,15} " << std::endl;
    std::cout << Atree << std::endl;
}
 int main()
{
    try
     {

        BSTree<int,int> tree{};


        //inserting for test
        std::pair<int,int> p1(1,1);
        std::pair<int,int> p2(2,2);
        std::pair<int,int> p3(3,3);
        std::pair<int,int> p4(4,4);
        std::pair<int,int> p5(5,5);

        tree.insert(p1);
        tree.insert(p2);
        tree.insert(p3);
        tree.insert(p4);
        tree.insert(p5);


        tree.print();

        tree.find(1);
        tree.find(3);
        tree.find(10);

        tree.clear();

        tree.print();
        tree.insert(p1);
        tree.insert(p2);
        tree.insert(p3);
        tree.insert(p4);
        tree.insert(p5);


        //  Testing different kind of constructors.

          BSTree<int,int> mytree{};
          BSTree<int,int> mytree2{tree};
          std::cout << mytree << std::endl;
          std::cout << mytree2 << std::endl;

          tree=tree; //calls the copy constructor, not the assignment
          std::cout<<mytree2<<std::endl;

    BSTree<int,int> mytree3;
    mytree3=mytree2; //calls the assignment operator overload
    std::cout<<mytree3<<std::endl;


         //Testing Iterator
          std::cout << "Iterating through all nodes from beginning to the end of"
                       <<"the tree by inorder traversal:" << std::endl;
          BSTree<int, int>::iterator i = tree.begin();
          while(i != tree.end())
          {
             std::cout << "[" << (*i).first << ", " << (*i).second << "] ";
             ++i;
          }




        //Testing balance()
>>>>>>> a9da71cac8a7b4293e7a3e4abd15197e4ff6b0bb

int main()
{
    try
     {

        tree.balance(); //testing  end(),begin(),rebuildBalancedTrees
        std::cout << tree << std::endl;
        BSTree<int,int> tree_1{};
        if(tree_1.begin()==tree.cend())
        {std::cout << "Right" << std::endl;};  //testing begin()


<<<<<<< HEAD
        //	Testing building-up-tree methods
        bst.insert(5,10);
        bst.insert(2,20);
        bst.insert(7,70);
        bst.insert(10,100);
        bst.insert(1,11);
        bst.insert(3,30);
        bst.print();
        bst.find(1);//finding
        bst.find(3);
        bst.find(10);
       	bst.clear();


        //  Testing different kind of constructors.

          BSTree<int,int> mybst{};
          BSTree<char,int> mybst1("TR",2);
          BSTree<char,int> mybst2{mybst1};
          std::cout << mybst << std::endl;
          std::cout << mybst1 << std::endl;
          std::cout << mybst2 << std::endl;
          BSTree<char,int>mybst3{std::move(bst1)};
          std::cout << mybst3 << std::endl;
          std::cout << mybst1 << std::endl;   //mybst1 will be empty




  //	Testing iterators methods and balance()
 //testing cend() methods, findNearest.
        int KN=1;
        if(bst.find(KN)==bst.cend())
        {std::cout << "Right" << std::endl;};


        bst.balance(); //testing  end(),begin(),rebuildBalancedTrees
        std::cout << bst << std::endl;
        BSTree<int,int> bst_1{};
        if(bst_1.begin()==bst.cend())
        {std::cout << "Right" << std::endl;};  //testing begin()


        //	Testing operator=

        bst_1=bst;
        bst_1.printTree(std::cout);
        bst.printTree(std::cout);
        BSTree<int,int> bst_2{};
        bst_2=std::move(bst_1);
        bst_2.printTree(std::cout);
        if(bst_1.begin()==bst.cend()){std::cout << "Right" << std::endl;};

        // 	Testing operator[] and template
            int key=1;
            std::cout << mybst[key] << std::endl;
            template_comparison_test();
    }

   catch (std::runtime_error& err)

=======
        // Testing operator=
        std::cout << tree[1] << std::endl;
        tree_1=tree;
        BSTree<int,int> tree_2{};
        tree_2=tree_1;
        template_comparison_test();
    }

   catch (std::runtime_error& err)

>>>>>>> a9da71cac8a7b4293e7a3e4abd15197e4ff6b0bb
     {
       std::cerr << err.what() << std::endl;
       return 1;
      }
}
