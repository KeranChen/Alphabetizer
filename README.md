# Alphabetizer
Title: Alphabetizer
Author: Kaiyun Chen

Purpose:

In this project, I created a program called Alphabetizer, which can read input
from cin or from a file, and all the words in the input can be printed out 
in either forward or backward order, as specified by the users.
Also, in order to implement this Alphabetizer, I created a String BST class
which stores strings in a Search binary tree structure. 

ACK:
Christ Helped me debugged my Makefile

Files:
StringBST.h: header file the BST class that stores string
StringBST.cpp: implementation of StringBST
testStringBST.cpp: test program for StringBST
Alphabetizer.h: heder file for the Alphabetizer class
Alphabetizer.cpp: implementation for Alphabetizer
testAlphabetizer.cpp: test program for Alphabetizer

How to compile and run:

$make

if want to use the automation mode, in which the user will type in words
one by one, type

$./alphabetizer

then user can type in the order they want, "f" forward, "r" backwards
words they want to put into order

if want to use alphabetizer to read input from a file

$./alphabetizer order filename

Outline of the data structures:

Here in this project I used Binary Search Tree as the main data structrue to
store the input strings. Binary Search Tree is a data structrue that represent
a binary tree, in which all the nodes on the left subtrees of current node are
smaller, and all the nodes on the right subtree of the current node are larger.

I choose to use BST here to store the strings, because BST can maintain the 
order of all the input nodes, every time when we insert a node to it. So when 
we finish inserting all the words into BST, the words in the BST are already in
order in the struture. 

If the tree is balanced, every time we insert a word, time complexity will be
O(log n), but if the tree is unbalanced, time complexity will be O(n).
So to create this BST, it will take us about O(nlogn) time.
And the space complexity will be O(n), because we are store all the words.

Test:
I created 4 different input files: 
1. empty file
2. 1 word file
3. a regular file with 11 words, 4 are the same
4. an unbalanced file. ie. "a", "b" ,"c", "d"

and test the Aphabetizer. I test automation mode and file input mode.

To test BST. I created 3 different input string array
1. default StringBST with no input
2. 1 word
3. a regular string array with 11 words, 4 are the same
4. an unbalanced string array

and I tested all the public methods of the StringBST class.
