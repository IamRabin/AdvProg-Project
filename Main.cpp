#include "Implementation.cpp"
/*


	void test_template_comparison()
{
    BSTree<int,int,std::greater<int>> t1;
    std::pair<int,int> p;
    std::vector<int> v{4,2,6,1,3,5,7};
    for(long unsigned int j=0; j< v.size(); j++)
    {
        p = {v[j], v[j]};
        t1.insert(p);
    }
    std::cout << "\ninserted v={4,2,6,1,3,5,7} in t1" << std::endl;
    std::cout << t1 << std::endl;
};*/

//	Initial consideration: 'BSTree.h' methods call
//  the functions defined in 'BSTreeSubclasses.hxx',
//  also tested by calling the formal ones.
int main()
{
    try
    {
        std::pair<int, int> pair{411,434};
        std::pair<int, int> pair2{299,210};
        std::pair<int, int> pair3{600,264};
        std::pair<int, int> pair4{241,991};
        std::pair<int, int> pair5{685,532};
        std::pair<int, int> pair6{113,311};
        std::pair<int, int> pair7{107,200};
        std::pair<int, int> pair8{434,798};
        //  Testing different kind of constructors.
        std::pair<char, int> my_pair{'A',7};
        BSTree<int,int> bst{};
        BSTree<char,int> bst1(my_pair);
        BSTree<char,int> bst2{bst1};
        std::cout << bst << std::endl;
        std::cout << bst1 << std::endl;
        std::cout << bst2 << std::endl;
        BSTree<char,int> bst3{std::move(bst1)};
        std::cout << bst3 << std::endl;
        std::cout << bst1 << std::endl;   //should now return 'Empty'


        //	Testing building-up-tree methods
        bst.insert(pair4); //the insert() method calls functions in BSTree<TKey,TValue>::Iterator.
        bst.insert(pair2);
        bst.insert(pair6);
        bst.insert(pair5);
        bst.insert(pair3);
        bst.insert(pair7);
	    bst.insert(pair8);
        std::cout << bst.insert(pair7) << std::endl;  //should return 0
       	bst2.clear();
        std::cout << bst2 << std::endl; //should now return 'Empty'
        //bst.printOrderedList(std::cout); //PrintNode and PrintStructure private functions also working.
        //bst.printTree(std::cout);

        //	Testing iterators methods and balance()

        int No_key=11;
        if(bst.find(No_key)==bst.cend()){std::cout << "Right" << std::endl;};	//testing find() and cend() methods, findNearest(..) private functions also working.
        bst.balance(); //testing also end(),begin(),rebuildBalancedTree(..) methods
        std::cout << bst << std::endl;
        BSTree<int,int> bst_1{};
        if(bst_1.begin()==bst.cend()){std::cout << "Right" << std::endl;};  //testing begin()

        //	Testing operator=

        bst_1=bst;
        //bst_1.printTree(std::cout);
        //bst.printTree(std::cout);
        BSTree<int,int> bst_2{};
        bst_2=std::move(bst_1);
        //bst_2.printTree(std::cout);
        if(bst_1.begin()==bst.cend()){std::cout << "Right" << std::endl;};

        // 	Testing operator[] and template
            int Key=7;
            std::cout << bst[Key] << std::endl;
            test_template_comparison();

    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
}
