#include <iostream>
#include <vector>
#include <fstream>
#include "BSTree.hpp"

using namespace BSTree;
using namespace std;

void check_numbers(vector<int>& numbers_array, int argc, char* argv[]) {
	bool test = false;
	for (unsigned int i = 1; i < argc; i++) {
		test = false;
		for (unsigned int j = 0; j < numbers_array.size(); j++) {
			if (atoi(argv[i]) == numbers_array[j]) {
				test = true;
			}
		}
		if (test == false) {
			numbers_array.push_back(atoi(argv[i]));
		}
	}
}
void print_menu() {
	cout << endl;
	cout << "1: show tree" << endl;
	cout << "2: show list of tree" << endl;
	cout << "3: add node in tree" << endl;
	cout << "4: delete node of tree" << endl;
	cout << "5: save tree in file" << endl;
	cout << "6: load tree from file" << endl;
	cout << "7: search" << endl;
	cout << "8: finish programm" << endl;
	cout << endl;
}
bool finish_program() {
	string choice;
	while (true) {
		cout << "Do you want to leave program? ( yes, no )" << endl;
		cin >> choice;
		if ((choice == "y") || (choice == "yes") || (choice == "Y") || (choice == "Yes") || (choice == "YES"))
			return true;
		else if ((choice == "n") || (choice == "no") || (choice == "N") || (choice == "No") || (choice == "NO"))
			return false;
	}
}


int main(int argc, char* argv[]) {
	vector<int> numbers_array;
	Tree tree;
	
	check_numbers(numbers_array, argc, argv);
	if (numbers_array.size() > 0) {
		for(unsigned int i = 0; i < numbers_array.size(); i++)
			tree.insert(numbers_array[i]);
	}
	cout<<tree<<endl;
	/*
	int choice = 0;
	while (true) {
		print_menu();
		cin >> choice;
		int value;
		string road;
		switch (choice) {
			case 1:
				cout << tree << endl;
				break;
			case 2:
				show_list_of_tree(tree);
				break;
			case 3:
				cout << "input value for insert" << endl;
				cin >> value;
				tree.insert(value);
				break;
			case 4:
				cout << "input delete value" << endl;
				cin >> value;
				tree.delete_node(value);
				break;
			case 5:
				cout << "please enter filename" << endl;
				cin >> road;
				tree.save_to_file(road);
				break;
			case 6:
				cout << "please enter road to file" << endl;
				cin >> road;
				tree.load_from_file(road);
				break;
			case 7:
				cout << "please enter the item to search for" << endl;
				cin >> value;
				tree.exists(value);
				break;
			case 8:
				if (finish_program()) {
					tree.~Tree();
					return 0;
				} else
					continue;
		}
	}
	*/
	return 0;
}
