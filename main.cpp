/*****************************************************

COMSC 210 | Lab 25 | Skylar Robinson | IDE Used: Eclipse

******************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
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
	double vectorRs[RACE_NUM], listRs[RACE_NUM], setRs[RACE_NUM];

    //open file
	ifstream in;
	in.open("codes.txt");

	//declare temp string
	string temp;

	//read to vector
	auto start = high_resolution_clock::now();

	while (in >> temp)
		vector.push_back(temp);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	vectorRs[0] = duration.count();

	//reset file
	in.clear();
	in.seekg(0);

	//read to list
	start = high_resolution_clock::now();

	while (in >> temp)
		list.push_back(temp);

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	listRs[0] = duration.count();

	//reset file
	in.clear();
	in.seekg(0);

	//read to set
	start = high_resolution_clock::now();

	while (in >> temp)
		set.insert(temp);

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	setRs[0] = duration.count();

	//close file
	in.close();

	//sort the vector
	start = high_resolution_clock::now();

	sort(vector.begin(), vector.end());

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	vectorRs[1] = duration.count();

	//sort the list
	start = high_resolution_clock::now();

	list.sort();

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	listRs[1] = duration.count();

	//set is already sorted
	setRs[1] = -1;

	//insert TESTCODE into vector
	start = high_resolution_clock::now();

	vector.insert(vector.begin() + (vector.size() / 2), "TESTCODE");

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	vectorRs[2] = duration.count();


	//insert TESTCODE into list
	start = high_resolution_clock::now();

	auto it = list.begin();
	for (int i = 0; i < (list.size() / 2); i++)
		it++;
	list.insert(it, "TESTCODE");

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	listRs[2] = duration.count();

	//insert TESTCODE into set
	start = high_resolution_clock::now();

	set.insert("TESTCODE");

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	setRs[2] = duration.count();

	//delete the middle element of the vector
	start = high_resolution_clock::now();

	vector.erase(vector.begin() + (vector.size() / 2));

	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	vectorRs[3] = duration.count();

	//delete the middle element of the list

	//delete the middle element of the set

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
