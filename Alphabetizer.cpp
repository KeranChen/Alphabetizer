#include <iostream>
#include <string>
#include <fstream>

#include "Alphabetizer.h"
#include "StringBST.cpp"

using namespace std;

/************************************Constructor******************************/
/*
Define one constructor for the Alphabetizer class.  The default 
          constructor takes no parameters and initializes the object. 
      
*/

Alphabetizer::Alphabetizer() {
	BST = new StringBST();
    
}

/*
destructor that destroys/deletes/recycles any
          heap-allocated data you may have used in the Alphabetizer.
*/
Alphabetizer::~Alphabetizer() {
	delete BST;
}	




/*
"run" function that takes no parameters.  This function will
          launch a process somewhat like the command loop you wrote in
          HW3, reading in commands from the standard input (cin).  Here
          are the commands:

            o a leading "f" or "r" which indicates whether the list of words 
              that follows will be printed in forward alphabetical order or 
              reverse.  Note: a second "f" or "r" are not order commands but 
              valid words to be added to the binary search tree (see next 
              bullet point). 
            o a word causes the word to be added to the binary search tree. 
              A word is defined as any sequence of non whitespace characters 
              (e.g. "@#$?!" is a valid word.)
            o Upon reaching the end of file on cin, the function will
              proceed to print the list that was stored in correct
              alphabetized order or reverse order, whichever was requested.
          
              The function should print the words in the order that the user 
              selected, in the following format:
      
              [ cin, X : FirstWord, SecondWord, ... , LastWord ]
        
              Where the "cin" is the origin of the words (cin) and "X" is
              either "f" or "r" depending on the order which the words
              were printed.  If a word appears multiple times in the
              original list it should be printed the same number of times
              in the final sorted list.
*/

void Alphabetizer::run() {
	string nextCommand;
	bool first = true;
	bool forward;
	//cin >> order;
	while (getline(cin, nextCommand)) {
		if (nextCommand.empty()) {
			break;
		}
		if (first) {
			
			if (checkForward(nextCommand)) {
				forward = true;
			} else {
				forward = false;
			}
			first = false;
		} else {
			BST->add(nextCommand);
		}
	}
	//std::cout << order;
	printResult("cin", forward);


}	

/*
"run" function that takes an input file name (string)
          and an order (string).  This function will read in the list of
          words from the input file stream, and then print them in the
          order specified.  The function should print the words in the
          order that the user selected, in the following format:
      
          [ Filename, X : FirstWord, SecondWord, ... , LastWord ]
        
          Where the "Filename" is the name of the origin file of the words 
          and "X" is either "f" or "r" depending on the order which the words 
          were printed.  If a word appears multiple times in the original list 
          it should be printed the same number of times in the final sorted 
          list. 
*/


void Alphabetizer::run(string filename, string order) {
    ifstream input;
    string nextCommand;
    
    bool forward;
    input.open(filename.c_str()); 
    if (not input.is_open()) {
        cerr << "Unable to read filename\n";
        return;
    }
    while (! input.eof()) {
        input >> nextCommand;
        BST->add(nextCommand);
    }
    input.close();
    if (checkForward(order)) {
        forward = true;
    } else {
        forward = false;
    }
    printResult(filename, forward);


}




/************************************Private**********************************/
/*
check whether we need to print forward or reversed here
input: string nextCommand
output: bool
*/
bool Alphabetizer::checkForward(string nextCommand) {
	if (nextCommand == "f") {
		return true;
	} else {
		return false;
	}
}

/*
generate the result in the desired order
input: string the source of the input, bool whether to print forward
ouput: void
[ cin, X : FirstWord, SecondWord, ... , LastWord ]
*/

void Alphabetizer::printResult(string source, bool forward) {
	std::cout << "[ "
			  << source;
			  
	if (forward) {
		std::cout << ", f : ";
		printForward();
	} else {
		std::cout << ", r : ";
		printReverse();
	}
	std::cout << "]\n";
}

/*
print the input in forward order
input: nothing
output: void
*/
void Alphabetizer::printForward() {
	string next;
	while (!BST->isEmpty()) {
		next = BST->getMin();
		BST->remove(next);
		if (BST->size() > 0) {
			std::cout << next
				  	<< ", ";
		} else {
			std::cout << next
					  << " ";
		}
	}
}

/*
print the input in reversed order
input: nothing
output: void
*/
void Alphabetizer::printReverse() {
	string next;
	while (!BST->isEmpty()) {
		next = BST->getMax();
		BST->remove(next);
		if (BST->size() > 0) {
			std::cout << next
				  	<< ", ";
		} else {
			std::cout << next
					  << " ";
		}
	}
}






























