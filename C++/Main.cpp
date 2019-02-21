
#include "Implementation.cpp"



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

int main()
{
    try
     {

        BSTree<int,int> bst{};


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

     {
       std::cerr << err.what() << std::endl;
       return 1;
      }
}
