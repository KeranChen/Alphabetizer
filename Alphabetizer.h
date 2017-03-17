#ifndef ALPHABETIZER_H
#define ALPHABETIZER_H
#include "StringBST.h"

using namespace std;

class Alphabetizer {
public:
	Alphabetizer();
	~Alphabetizer();
    
	void run();
    void run(string filename, string order);

private:
	StringBST *BST;
   
	bool checkForward(string nextCommand);
	void printResult(string source, bool forward);
	void printForward();
	void printReverse();

};
#endif