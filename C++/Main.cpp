
#include "Implementation.h"



 int main()
{
    try
     {



        //inserting for test
        std::pair<int,int> p1(1,1);
        std::pair<int,int> p2(2,2);
        std::pair<int,int> p3(3,3);
        std::pair<int,int> p4(4,4);
        std::pair<int,int> p5(5,5);

        BSTree<int,int> tree{};

        tree.insert(p1);
        tree.insert(p2);
        tree.insert(p3);
        tree.insert(p4);
        tree.insert(p5);


        //tree.print();

        tree.find(1);
        tree.find(3);
        tree.find(10);



        //  Testing different kind of constructors.

          BSTree<int,int> mytree{};
          BSTree<int,int> mytree2{tree};
          std::cout << mytree << std::endl;
          std::cout << mytree2 << std::endl;

          mytree=tree; //calls the copy constructor, not the assignment
          std::cout<<mytree2<<std::endl;

    BSTree<int,int> mytree3;
    mytree3=mytree2; //calls the assignment operator overload
    std::cout<<tree<<std::endl;


         //Testing Iterator
          std::cout << "Iterating through all nodes from beginning to the end of"
                       <<"the tree by inorder traversal:" << std::endl;

          BSTree<int, int>::iterator i = tree.begin();
          while (i != tree.end())
          {
             std::cout << "[" << (*i).first << ", " << (*i).second << "] "<<std::endl;
             ++i;
          }



        // Testing operator=
        std::cout << tree[1] << std::endl;
        BSTree<int,int> tree_2{};
        tree_2=tree;
        

    }

//This means if you want to write out errors or warning that the consuming
//program won't understand you have to write them to cerr so that you don't
//confuse the second program that's reading your programs normal cout output.

   catch (std::runtime_error& err)

     {
       std::cerr << err.what() << std::endl;
       return 1;
      }
}
