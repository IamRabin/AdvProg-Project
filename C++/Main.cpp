#include "Implementation.cpp"

int main()
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
        bst.find(1);
        bst.find(3);
        bst.find(10);
       	bst.clear();

        //bst.printOrderedList(std::cout); //PrintNode and PrintStructure private functions also working.
        //bst.printTree(std::cout);

        //	Testing iterators methods and balance()
}
