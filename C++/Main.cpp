
#include "Implementation.cpp"

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



        // Testing operator=
        std::cout << tree[1] << std::endl;
        BSTree<int,int> tree_2{};
        tree_2=tree;
        template_comparison_test();
    }

   catch (std::runtime_error& err)

     {
       std::cerr << err.what() << std::endl;
       return 1;
      }
}
