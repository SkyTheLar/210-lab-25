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

const int RACE_NUM = 4;
//parallel array to race results
const string races [RACE_NUM] = {"Read", "Sort", "Insert", "Delete"};

int main() {
	//initialize vector, list, and set
	vector<string> vector;
	list<string> list;
	set<string> set;

	//initialize results arrays
	int vectorRs[RACE_NUM], listRs[RACE_NUM], setRs[RACE_NUM];

    //open file
	ifstream in("codes.txt");

	//read to vector
	auto start = high_resolution_clock::now();

	string temp;
	while (in >> temp)
		vector.push_back(temp);

	auto stop = high_resolution_clock::now();
	vectorRs[0] = duration_cast<milliseconds>(stop - start);

	//read to list
	start = high_resolution_clock::now();

	string temp;
	while (in >> temp)
		list.push_back(temp);

	stop = high_resolution_clock::now();
	listRs[0] = duration_cast<milliseconds>(stop - start);

	//read to set
	start = high_resolution_clock::now();

	string temp;
	while (in >> temp)
		set.insert(temp);

	stop = high_resolution_clock::now();
	setRs[0] = duration_cast<milliseconds>(stop - start);

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
