#include "../src/main.cpp"
#include "../src/AVL.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

// TEST_CASE("AVL Insert", "[insert]"){
// 	AVL tree;   // Create a Tree object 
// 	tree.insert("Evan", "44985771");
// 	tree.insert("Earl", "31834874");
// 	tree.insert("Erica", "21456789");
// 	tree.printLevelCount();
// 	tree.insert("Enrique", "17891824");
// 	tree.printLevelCount();
// 	std::vector<std::string> actualOutput;
// 	std::vector<std::string> expectedOutput = {
// 		"successful", "successful", "successful", "successful",
// 		"Brian, Brandon, Briana, Bella"
// 	};
// 	REQUIRE(expectedOutput.size() == actualOutput.size());
// 	REQUIRE(actualOutput == expectedOutput);
// }

// TEST_CASE("AVL 1", "[1]") {
// 	AVL tree;
// 	tree.searchId("12345678");
// 	tree.searchName("Adam");
// 	tree.insert("Adam", "12345678");
// 	tree.searchId("23456789");
// 	tree.searchId("12345678");
// }

// TEST_CASE("AVL 2", "[2]") {
// 	AVL tree;
// 	tree.insert("David", "31239830");
// 	tree.insert("Danielle", "27782901");
// 	tree.insert("David", "11133245");
// 	tree.searchName("Danielle");
// 	tree.searchName("David");
// 	tree.searchId("11133245");
// 	tree.searchId("27782901");
// 	tree.searchId("31239830");
// }

// TEST_CASE("AVL 3", "[3]") {
// 	AVL tree;
// 	tree.insert("Evan", "44985771");
// 	tree.insert("Earl", "31834874");
// 	tree.insert("Erica", "21456789");
// 	tree.printLevelCount();
// 	tree.insert("Enrique", "17891824");
// 	tree.printLevelCount();
// }

// TEST_CASE("AVL 4", "[4]") {
// 	AVL tree;
// 	tree.insert("Brandon", "45674567");
// 	tree.insert("Brian", "35455565");
// 	tree.insert("Briana", "87878787");
// 	tree.insert("Bella", "95462138");
// 	tree.printInorder();
// 	tree.remove("45674567");
// 	tree.removeInorder(2);
// 	tree.printInorder();
// }

// TEST_CASE("AVL 5", "[5]") {
// 	AVL tree;
// 	tree.insert("Caroline", "50005000");
// 	tree.insert("Cory", "35354334");
// 	tree.insert("Cecilia", "76543210");
// 	tree.insert("Carla", "56567342");
// 	tree.insert("Cody", "83711221");
// 	tree.insert("Chris", "17449900");
// 	tree.printInorder();
// 	tree.printPreorder();
// 	tree.printPostorder();
// }