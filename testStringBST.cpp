#include <iostream>
#include <string>
#include "StringBST.h"
using namespace std;

void test();
void testPrint(StringBST *test);
void testContains(StringBST *test);
void testSize(StringBST *test);
void testIsEmpty(StringBST *test);
void testClear(StringBST *test);
void testRemove(StringBST *test);
void testGetMinMax(StringBST *test);
void testRemoveMinMax(StringBST *test);

int main() {
	std::cout << "StringBST test\n";
	test();
	return 0;
}

void test() {
	
	StringBST test1;
	string input2 [10] = {"Ram","Hourse","Swan", "Deer", "Kingfisher", "Bison", "Llama", "Deer", "Zillow", "Hourse"};
	StringBST test2(input2, 10);
	string input3 [1] = {"Ram"};
	StringBST test3(input3, 1);
	string input4 [3] =  {"aa", "bb", "cc"};
	StringBST test4(input4, 3);
	
	StringBST *test = &  test4;
	//testPrint(test);
	testContains(test);
	//testSize(test);
	//testClear(test);
	//testIsEmpty(test);
	//testPrint(test);
	//testRemove(test);
	//testGetMinMax(test);
	//testRemoveMinMax(test);
	
}

void testPrint(StringBST *test) {
	test->print();
}

void testContains(StringBST *test) {
	if (test->contains("Hourse")) {
		std::cout << "Yes, it contans \n";
	} else {
		std::cout << "No it doesn't contains\n";
	}
}

void testSize(StringBST *test) {
	std::cout << "size of this BST is "
			  << test->size()
			  << "\n";

}

void testIsEmpty(StringBST *test) {
	if (test->isEmpty()) {
		std::cout << "Yes, it is empty\n";
	} else {
		std::cout << "No, it is not empty\n";
	}
}

void testClear(StringBST *test) {
	test->clear();
}

void testRemove(StringBST *test) {
	std::cout << "Test remove \n";
	std::cout << test->size()
			  << "\n";
	test->print();
	if (test->remove("Ram")) {
		std::cout << "Yest, 1 ram has been removed\n";
	} else {
		std::cout << "No deer found\n";
	}
	if (test->remove("Swan")) {
		std::cout << "Yest, 1 swan has been removed\n";
	} else {
		std::cout << "No swan found\n";
	}
	std::cout << test->size()
			  << "\n";
	test->print();
}

void testGetMinMax(StringBST *test) {
	std::cout << "test get Min\n"
			  << "Min is "
			  << test->getMin()
			  << "\n";
	
    std::cout << "test get Max\n"
			  << "Max is "
			  << test->getMax()
			  << "\n";
	
   
	
}

void testRemoveMinMax(StringBST *test) {
	testGetMinMax(test);
	std::cout << "test remove Min \n";
	test->removeMin();
	std::cout << "test remove Max \n";
	test->removeMax();
	testGetMinMax(test);
}







