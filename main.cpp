#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "Alphabetizer.h"

using namespace std;

void testAlphabetizer();
void testAlphabetizer(string filename, string order);

int main(int argc, char *argv[]) {
	
	if (argc == 1) {
        testAlphabetizer();
    } else {
        if (argc == 2) {
            cerr << "Usage: alphabetizer [order filename]\n";
            return 1;
        }
        std::string order(argv[1]);
        if (order != "f" && order != "r") {
            cerr<< "Usage: alphabetizer [order filename]\n";
            return 1;
        }
        std::string filename(argv[2]);

        
        testAlphabetizer(filename, order);
    }
}

void testAlphabetizer() {
	
	Alphabetizer alph;
	alph.run();
	
}


void testAlphabetizer(string filename, string order) {
    Alphabetizer alph;
    std::cout << filename << endl;
    std::cout << order << endl;
    alph.run(filename, order);
    return;
}