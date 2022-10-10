#include "../src/main.cpp"
#include "../src/AVL.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("AVL Insert", "[insert]"){
	AVL tree;   // Create a Tree object 
	tree.insert("Evan", "44985771");
	tree.insert("Earl", "31834874");
	tree.insert("Erica", "21456789");
	tree.printLevelCount();
	tree.insert("Enrique", "17891824");
	tree.printLevelCount();
	// std::vector<std::string> actualOutput;
	// std::vector<std::string> expectedOutput = {
	// 	"successful", "successful", "successful", "successful",
	// 	"Brian, Brandon, Briana, Bella"
	// };
	// REQUIRE(expectedOutput.size() == actualOutput.size());
	// REQUIRE(actualOutput == expectedOutput);
}
