
#include "Implementation.cpp"



void test()
{
    BSTree<int,std::string,std::greater<int>> mybst;
    std::pair<int,std::string> np;
    std::vector<int> v{4,2,6,1,3,5,7};
    for( int i=0; i< v.size(); i++)
    {
        np = {v[i], v[i]};
        mybst.insert(np);
    }
    std::cout << "\ninserted v={4,2,6,1,3,5,7} in mybst" << std::endl;
    std::cout << mybst << struct name_t {
        /* data */
    };d::endl;
};


/*
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
*/
