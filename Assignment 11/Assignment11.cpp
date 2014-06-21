/**
@file    Assignment11.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date    2014-06-16
*   Assignment #11 
*   due 2014-06-17
@brief
Shell Sort Experiment: The program runs an experiment to find out which
sorting method is better for which lengths of lists.
*/

/*
program is working as intended
*/

// ----------------------------------------------------------------------- //

#include <iostream>
#include <iomanip>
#include <vector>
#include "utilities.h"

using namespace std;
using Scobey::Pause;
using Scobey::userSaysYes;


// ----------  Global Constants  ----------------------------------------- //

const int SHORT_LIST = 1;
const int LONG_LIST = 50;
const int STEP_SIZE = 7;
const int NUM_TRIALS = 100;
const int MAX_IN_LIST = 10000;
const int FIELD_WIDTH = 7;


// ----------  Global Variables  ----------------------------------------- //

Scobey::RandomGenerator r;
Scobey::OperationCounter opCount;


// ----------  Function Prototypes  -------------------------------------- //

void FillVec
(
    vector<int>& vec,   // out
    int num             // in
);
/**<
Fill a vector with random values.
@param  vec     the vector to fill.
@param  num     the number of random values to put into the vector.
@pre    num &ge; 0
@post   vec has had its previous contents replaced
        with <tt>num</tt> random values.
*/

void PrintVec
(
    const vector<int>& vec  // in
);
/**<
Print a vector.
@param  vec     the vector to print.
@pre    none
@post   the contents of vec have been printed on a single line.
*/

void shellSort
(
    vector<int>& vec
);
/**<
Sort a vector using Shell sort.
@param  vec     The vector to sort.
@pre    none
@post   The contents of <tt>vec</tt> have been rearranged
        so that they are in ascending order.
*/

void insertionSort
(
    vector<int>& vec
);
/**<
Sort a vector using insertion sort.
@param  vec     The vector to sort.
@pre    none
@post   The contents of <tt>vec</tt> have been rearranged
        so that they are in ascending order.
*/


// ----------  main function  -------------------------------------------- //

int main()
{
    vector<int> vi;

    // optional test of insertionSort
    if (userSaysYes("\nTest revised insertionSort? "))
    {
        FillVec(vi, 10);
        cout << "\nOriginal list:\n";
        PrintVec(vi);
        insertionSort(vi);
        cout << "Insertion Sorted list:\n";
        PrintVec(vi);
        Pause();
    }

    // optional test of shellSort
    if (userSaysYes("\nTest revised shellSort? "))
    {
        FillVec(vi, 10);
        cout << "\nOriginal list:\n";
        PrintVec(vi);
        shellSort(vi);
        cout << "Shell Sorted list:\n";
        PrintVec(vi);
        Pause();
    }

    // print self-description
    cout << "\n\n"
         << "Comparison of insertionSort and selectionSort\n"
         << "=============================================\n\n"
         << "For each length of listin the table below, "
         << "this program runs " << NUM_TRIALS << " trials\n"
         << "of insertionSort versus shellSort, "
         << "and records the winner of each trial.\n"
         << "The results are printed in the table.\n\n"
         << "Note that the number of victories may not add up exactly to " 
         << NUM_TRIALS << ", since\nsome trials may end in a tie.\n\n";
    Pause();

    // print table header
    cout << "\n\n"
         << setw(FIELD_WIDTH) << "Length"
         << setw(3 * FIELD_WIDTH) << "Insertion Wins"
         << setw(3 * FIELD_WIDTH) << "Shell Wins"
         << endl
         << setw(FIELD_WIDTH) << "------"
         << setw(3 * FIELD_WIDTH) << "--------------"
         << setw(3 * FIELD_WIDTH) << "----------"
         << endl;

    // for each length of list:
    for (int length = SHORT_LIST; length <= LONG_LIST; length += STEP_SIZE)
    {
        // reset win counts to zero
        int insertionWins = 0;
        int shellWins = 0;

        // run trials
        for (int trial = 1; trial <= NUM_TRIALS; ++trial)
        {
            // create the vector and two copies
            // (so that each method is tested on the same list)
            FillVec(vi, length);
            vector<int> vc1(vi);
            vector<int> vc2(vi);

            // run the two methods, gathering counts
            opCount.reset();
            insertionSort(vc1);
            int totalInsertionOps = opCount.getNumberOfAssignments() 
                                  + opCount.getNumberOfComparisons();
            opCount.reset();
            shellSort(vc2);
            int totalShellOps = opCount.getNumberOfAssignments() 
                              + opCount.getNumberOfComparisons();

            // update wins
            if (totalInsertionOps < totalShellOps) ++insertionWins;
            if (totalShellOps < totalInsertionOps) ++shellWins;
        }

        // print report for this set of trials
        cout << setw(FIELD_WIDTH) << length
             << setw(3 * FIELD_WIDTH) << insertionWins
             << setw(3 * FIELD_WIDTH) << shellWins
             << endl;
    }
    cout << "\n\n";
    Pause();
}

// ----------  Function Definitions  ------------------------------------- //

void FillVec(vector<int>& vec, int num)
{
    // erase any old contents
    vec.clear();

    // make room for all the new elements (for efficiency)
    vec.reserve(num);

    // add all the required random values
    for (int i = 0; i < num; ++i) 
    {
        vec.push_back(r.getNextInt(MAX_IN_LIST));
    }
}

void PrintVec(const vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << setw(FIELD_WIDTH) << *it;
    }
    cout << endl << endl;
}

// ----------  Function Definitions TO BE FIXED  ------------------------- //

void shellSort(vector<int>& vec)
{
   for (int h = n / 2; h > 0; h = h / 2)
   {
      for (int unsorted = h; unsorted < n; unsorted++)
      {
         ItemType nextItem = theArray[unsorted];
         int loc = unsorted;
         while ( (loc >= h) && (theArray[loc - h] > nextItem) )
         {
            theArray[loc] = theArray[loc - h];
            loc = loc - h;
         } // end while
         theArray[loc] = nextItem;
      }  // end for
   }  // end for
}  // end shellSort

void insertionSort(vector<int>& vec)
{
    int p, a;
    for(int i = 1; i < vec.size(); i++)
    {
        a = vec[i];
        p = i - 1;

        while((p >= 0) && vec[p] > a)
        {
            opCount.incrementComparisons();
            vec[p + 1] = vec[p];
            p = p - 1;
        }
        opCount.incrementExchanges();
        vec[p + 1] = a;
    }
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region.
   // Initially, sorted region is theArray[0],
   // unsorted region is theArray[1..n-1].
   // In general, sorted region is theArray[0..unsorted-1],
   // unsorted region theArray[unsorted..n-1]
   for (int unsorted = 1; unsorted < n; unsorted++)
   {
      // At this point, theArray[0..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[0..unsorted]
      // for theArray[unsorted], which is the first entry in the
      // unsorted region; shift, if necessary, to make room
      ItemType nextItem = theArray[unsorted];
      int loc = unsorted;
      while ((loc > 0) && (theArray[loc - 1] > nextItem))
      {
         // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         loc--;
      }  // end while
      
      // At this point, theArray[loc] is where nextItem belongs
      theArray[loc] = nextItem; // Insert nextItem into sorted region
   }  // end for
}  // end insertionSort
