#include "../include/AVL.h"
#include <iostream>
#include <string>
#include <vector>

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

bool isValidName(std::string &name) {
	for (char c : name) {
		if (!isalpha(c) && !isspace(c))
			return false;
	}
	return true;
}

bool isValidID(std::string &id) {
	if (id.length() != 8) return false;
	for (char c : id) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

void failure() {
	std::cout << "unsuccessful" << std::endl;
}

std::string getName(std::string &input) {
	int length = input.rfind('"') - input.find('"')-1;
	return input.substr(input.find('"')+1, length);
}

std::string getId(std::string &input) {
	return input.substr(input.rfind('"')+2);
}

void handleInsert(std::string &input, AVL &tree) {
	// Check valid name
	std::string name = getName(input);
	if (!isValidName(name)) return failure();

	// Check valid id
	std::string id = getId(input);
	if (!isValidID(id)) return failure();
	
	// Handle insert into AVL
	tree.insert(name, id);
}

void handleRemove(std::string &input, AVL &tree) {
	// Check valid id
	std::string id = input.substr(input.find(' ')+1);
	if (!isValidID(id)) return failure();

	// Handle remove(id)
	tree.remove(id);
}

void handleSearch(std::string &input, AVL &tree) {
	input = input.substr(input.find(' ')+1);
	if (input.find('"') != std::string::npos) {
		std::string name = getName(input);
		if (!isValidName(name)) return failure();

		// Handle search(name)
		tree.searchName(name);
	} else {
		std::string id = input;
		if (!isValidID(id)) return failure();

		// Handle search(id)
		tree.searchId(id);
	}
}

void handleRemoveInorder(std::string &input, AVL &tree) {
	input = input.substr(input.find(' ')+1);
	for (char c : input) {
		if (!isdigit(c)) return failure();
	}

	// Handle removing Nth node
	int n = std::stoi(input);
	tree.removeInorder(n);
}

// int main() {
// 	AVL tree;
// 	int num_of_commands;
// 	std::cin >> num_of_commands;
// 	std::cin.ignore();

// 	for (int i = 0; i < num_of_commands; i++) {
// 		std::string input;
// 		std::getline(std::cin, input);
		
// 		// Take a substring of input from beginning to first space
// 		std::string command = input.substr(0, input.find(' '));

// 		if (command == "insert")
// 			handleInsert(input, tree);
// 		else if (command == "remove")
// 			handleRemove(input, tree);
// 		else if (command == "search")
// 			handleSearch(input, tree);
// 		else if (command == "printInorder")
// 		 	tree.printInorder();
// 		else if (command == "printPreorder")
// 		 	tree.printPreorder();
// 		else if (command == "printPostorder")
// 		 	tree.printPostorder();
// 		else if (command == "printLevelCount")
// 		 	tree.printLevelCount();
// 		else if (command == "removeInorder")
// 			handleRemoveInorder(input, tree);
// 		else
// 			failure();
// 	}
// 	return 0;
// }