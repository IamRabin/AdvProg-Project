#include "Implementation.cpp"
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <random>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;



//---------------------------------
// General Operations
//---------------------------------

int Max_No_of_Entries=15000;

template<typename E>
void Timer(E entry,ofstream& recordfile)
{
        recordfile<<"N,Lookup Time,Per entry lookup time,Log(N)"<<endl;
        for(int i=0;i<Max_No_of_Entries;i+=100)
        {
          auto start_time = chrono::high_resolution_clock::now();

        for(int x=0;x<i;++x)
        {
            entry.find(x);
        }

        auto end_time = chrono::high_resolution_clock::now();
        auto total_time=chrono::duration_cast<chrono::microseconds>(end_time-start_time).count();
        recordfile<<i<<","<<total_time<<","<<total_time/double(i)<<","<<log2(total_time/double(i)) <<endl;
        }
 };


 //---------------------------------
 // Binary Search tree: Unbalanced
 //---------------------------------

 void tiny_benchmark()

 {

  ofstream recordfile;
    recordfile.open ("test/perf_compare_unbalanced.txt");

    BSTree<int,int> supertree;
    for(int i=0;i<Max_No_of_Entries;++i)
    {
         pair<int, int> pair{i,i+2};
         supertree.insert(pair);

     }

    Timer(supertree,recordfile);
    recordfile.close();


    //---------------------------------
    // Binary Search Tree: Balanced
    //---------------------------------
  supertree.balance();
  ofstream recordfile2;
  recordfile2.open ("test/perf_compare_balanced.txt");

  Timer(supertree,recordfile2);
  recordfile2.close();


    //---------------------------------
    // Map opeation
    //---------------------------------
  map<int,int> mapper;
  ofstream mapfile;
    mapfile.open ("test/perf_compare_map.txt");
  for(int i=0;i<Max_No_of_Entries;++i)
    {
        pair<int, int> pair{i,i+2};
        mapper.insert(pair);
    }
    Timer(mapper,mapfile);
     mapfile.close();


     //---------------------------------
     // Unordered Map Operation
     //---------------------------------
   unordered_map<int,int> uo_mapper;
     ofstream mapfile2;
     mapfile2.open ("test/perf_compare_Umap.txt");
     for(int i=0;i<Max_No_of_Entries;++i)
    {
        pair<int, int> pair{i,i+2};
        uo_mapper.insert(pair);
    }
  Timer(uo_mapper,mapfile2);
    mapfile2.close();
 };



 int main()

 {
  tiny_benchmark();
  return 0;
 };
