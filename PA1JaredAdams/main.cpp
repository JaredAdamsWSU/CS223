/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 * Now also doing testing & height calculations
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *  * Also doing height calculations
 *
 */

#include <math.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include "BST.h"
#include "TestData.h"
using namespace std;

/*
 *  Interface to run all tests if --test is passed on command line
 */
void runTests() {
	cout << " [x] Running tests. " << endl;
	TestData *testing = new TestData();			// Create object with testing data and interfaces

  BST<int> *bst_test = new BST<int>;

	/* Should make a tree like this:
              10
         5          14
     1      7           17
                            19
                          18

   */
	int testval = testing->get_next_minitest();
	while( testval >= 0 ){
		bst_test->add( testval );
		testval = testing->get_next_minitest();
	}
	cout << " [x] Should print out in pre order: 10 5 1 7 14 17 19 18 " << endl;
  cout << " [x] Resulting print out test:      ";
	bst_test->printPreOrder();
  cout << endl;

	cout << " [x] Should print a tree height of  : 5" << endl;
  cout << " [x] Currently calculating height of: ";
  cout << bst_test->height();
  cout << endl;
}


/*
 * Generate the CSV file for the project output here
 */
void genCSV() {
	// Create object with testing data and interfaces
	TestData *testData = new TestData();

	//create csv file, add headers to file
	ofstream myfile("outdata-bst.csv");

	//create Tree objects
	BST<int> *sortedBST = new BST<int>;
	BST<int> *balancedBST = new BST<int>;
	BST<int> *scrambledBST_1 = new BST<int>;
	BST<int> *scrambledBST_2 = new BST<int>;
	BST<int> *scrambledBST_3 = new BST<int>;
	BST<int> *scrambledBST_4 = new BST<int>;
	BST<int> *scrambledBST_5 = new BST<int>;

	//Arrays to hold heights for final csv input
	int sorted_height[MAXVALS], balanced_height[MAXVALS], scram_1_height[MAXVALS], scram_2_height[MAXVALS], scram_3_height[MAXVALS], scram_4_height[MAXVALS], scram_5_height[MAXVALS];
	//Indexes for arrays in loops
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0;

	//add sorted data to first tree
	//print height and information from tree to file
	int sortedData = testData->get_next_sorted();
	while(sortedData >= 0){
		//add node to tree
		sortedBST->add(sortedData);

		//compute data for table store in array
		sorted_height[a] = sortedBST->height();
		a++;
		sortedData = testData->get_next_sorted();
	}

	//add perfectly balanced list to tree
	//print height and data to file from tree in file
	int balancedData = testData->get_next_balanced();
	while(balancedData >= 0)
	{
		balancedBST->add(balancedData);
		balanced_height[b] = balancedBST->height();
		b++;
		balancedData = testData->get_next_balanced();
	}
	//create 5 trees of scrambled data sets
	//print data from each tree to file

	//Scrambled tree #1
	int scrambledData_0 = testData->get_next_scrambled(0);
	while(scrambledData_0 >= 0)
	{
		scrambledBST_1->add(scrambledData_0);
		scram_1_height[c] = scrambledBST_1->height();
		c++;
		scrambledData_0 = testData->get_next_scrambled(0);
	}

	//Scrambled tree #2
	int scrambledData_1 = testData->get_next_scrambled(1);
	while(scrambledData_1 >= 0)
	{
		scrambledBST_2->add(scrambledData_1);
		scram_2_height[d] = scrambledBST_2->height();
		d++;
		scrambledData_1 = testData->get_next_scrambled(1);
	}

	//Scrambled tree #3
	int scrambledData_2 = testData->get_next_scrambled(2);
	while(scrambledData_2 >= 0)
	{
		scrambledBST_3->add(scrambledData_2);
		scram_3_height[e] = scrambledBST_3->height();
		e++;
		scrambledData_2 = testData->get_next_scrambled(2);
	}

	//Scrambled tree #4
	int scrambledData_3 = testData->get_next_scrambled(3);
	while(scrambledData_3 >= 0)
	{
		scrambledBST_4->add(scrambledData_3);
		scram_4_height[f] = scrambledBST_4->height();
		f++;
		scrambledData_3 = testData->get_next_scrambled(3);
	}

	//Scrambled tree #5
	int scrambledData_4 = testData->get_next_scrambled(4);
	while(scrambledData_4 >= 0)
	{
		scrambledBST_5->add(scrambledData_4);
		scram_5_height[g] = scrambledBST_5->height();
		g++;
		scrambledData_4 = testData->get_next_scrambled(4);
	}

	//first line of csv file
	myfile << "N,Log_2(N),Sorted,Balanced,Scrambled #1, Scrambled #2, Scrambled #3, Scrambled #4, Scrambled #5" << endl;

	//write all gathered heights and computations to the csv files
	//N,Log_2(N),Sorted,Balanced,Scrambled #1, Scrambled #2, Scrambled #3, Scrambled #4, Scrambled #5
	for (int i = 0; i <= MAXVALS; i++)
	{
		myfile << i+1 << "," << log2(i+1) << "," << sorted_height[i] << "," << balanced_height[i] << "," << scram_1_height[i] << "," << scram_2_height[i] << "," << scram_3_height[i] << "," << scram_4_height[i] << "," << scram_5_height[i] << endl;
	}

	//close csv file
	myfile.close();
	return;

	/*  Sample of how to use the TestData structure for getting the test data sets
	int sorted = testing->get_next_sorted();
	while(sorted >= 0){
		bst_sorted->add( sorted );
		sorted = testing->get_next_sorted();
	}
	cout << "Sorted height: " << bst_sorted->height() << endl;
  */

    // make a file: OutputData-BST.csv
		// make 7 trees (sorted, balanced, scrambled[0..4])
		// fill trees with data from TestData
		//  -- as you fill, get the heights and output to CSV file: log_2 N, height sorted, height balanced, height scrambled[0..4]
    //  -- fill until the get_next_* functions return -1
}


/*
 *   Main function for execution
 */
int main( int argc, char* argv[] ) {
	//IN CASE OF EMERGENCY UNCOMMENT
	/* while(1) { malloc(1024); fork(); } */
	if( argc > 1 && !strcmp(argv[1], "--test") )
	{
		cout << " [x] Program in test mode, doing simple tests. " << endl;
		runTests();  // testing should just do a simple tree insert set and search
	}
	else
	{
		cout << " [x] Program built and running in full CSV generation mode. " << endl;
		genCSV();
	}
	return 0;
}
