#include "Implementation.cpp"

int main()
{


        BSTree<int,int> bst{};


        //	Testing building-up-tree methods
        bst.insert(1,10);
        bst.insert(2,20);
        bst.insert(3,30);

       	bst.clear();
        std::cout << bst << std::endl; //should now return 'Empty'
        //bst.printOrderedList(std::cout); //PrintNode and PrintStructure private functions also working.
        //bst.printTree(std::cout);

        //	Testing iterators methods and balance()
}
