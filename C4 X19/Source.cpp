/*
Exercise 19 Chapter 4 from
"Software - Principles and Practice using C++" by Bjarne Stroustrup
EXERCISE: Define a class Name_value that holds a string and a value.
Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.

EX 19 From Chapter 4:
Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a vector
called names and the number to a vector called scores
(in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
Terminate input with NoName 0.
Check that each name is unique and terminate with an error message if a name is entered twice.
Write out all the (name,score) pairs, one per line.
*/

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------


int main()

try
{
	vector<string> Names;
	vector<int> Scores;

	bool keep_going = true;
	string temp_s{ "poop" };
	int temp_i{ 100 };

	cout << "Welcome to the Name-Score program ver. 1.0\n";
	cout << "Please enter Name Score pairs,\n";
	cout << "Duplicate names are not permitted.\n";
	cout << "NoName 0 to terminate.\n";
	
	while (keep_going) {
		cin >> temp_s;
		cin >> temp_i;


		// Check for duplicates //

		for (int i = 0; i < Names.size(); i++ ) {
			if (temp_s == Names[i]) {
				keep_going = false;
				error("Duplicate Names not allowed!\n");
			}
		}
		if (temp_s == "NoName" || temp_i == 0) {
			keep_going = false;
			break;
		}
		Names.push_back(temp_s);
		Scores.push_back(temp_i);
	}
	for (int j = 0; j < Names.size(); j++) {
		cout << Names[j] << "\t\t" << Scores[j] << "\n";
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------
