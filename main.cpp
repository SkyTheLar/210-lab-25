/*****************************************************

COMSC 210 | Lab 25 | Skylar Robinson | IDE Used: Eclipse

******************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int TEST_NUM = 4;
//parallel array to test results
const string tests [TEST_NUM] = {"Read", "Sort", "Insert", "Delete"};

int main() {
	//initialize vector, list, and set
	vector<string> vector;
	list<string> list;
	set<string> set;

    //open file
	ifstream in("codes.txt");

	//read to vector
	auto start = high_resolution_clock::now();

	string temp;
	while (in >> temp)
		vector.push_back(temp);

	auto end = high_resolution_clock::now();

    return 0;
}



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
