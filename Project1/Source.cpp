/*
Trevor Schmidt, CS 142 - 002, trevorjschmidt97@gmail.com
Simple String Editor
Description: User inputs a string and has options to make into a sentence, add more text, and copy/paste/find/replace.

Test Case 1:
Input:
clash of clans
y
n
find
clans
replace
titans
Output:
Welcome to the Simple Editor. Enter a string to be edited:
clash of clans
Do you want to make this string a sentence (y/n)?
Clash of clans.
Do you want to insert more text into your current text (y/n)?
If you would like to find/replace or copy/paste, enter find or copy:
Enter substring to find:

Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?
Enter replacement string:
Final text is
Clash of titans.

Test case 2:
Input:
bob the builder
n
y
 big
7
copy
0
4
0
Output:
Welcome to the Simple Editor. Enter a string to be edited:
bob the builder
Do you want to make this string a sentence (y/n)?

Do you want to insert more text into your current text (y/n)?
Enter text to be inserted:
Enter position where text is to be inserted:
bob the big builder
If you would like to find/replace or copy/paste, enter find or copy:
Enter position and length of text to be copied, and position for paste:


Final text is
bob bob the big builder

Test Case 3:
Input:
bond, James Bond!
y
n
find
James
replace
Trevor
Output:
Welcome to the Simple Editor. Enter a string to be edited:
bond, James Bond!
Do you want to make this string a sentence (y/n)?
Bond, James Bond!
Do you want to insert more text into your current text (y/n)?
If you would like to find/replace or copy/paste, enter find or copy:
Enter substring to find:

Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?
Enter replacement string:
Final text is
Bond, Trevor Bond!
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	//Variables
	string userInput = "_";
	char makeSentence;
	char period = '.';
	char exclamation = '!';
	char question = '?';
	char insertText;
	string addText;
	string input = "_";
	int inputLocation;
	string copOrPas;
	string findString;
	string fdr;
	string replaceString;
	int posCopy;
	int lengthCopy;
	int posPaste;

	// Get Line
	cout << "Welcome to the Simple Editor. Enter a string to be edited: " << endl;
	getline(cin, userInput);
	cout << userInput << endl;

	// Turn into Sentence
	cout << "Do you want to make this string a sentence (y/n)?" << endl;
	cin >> makeSentence;
	if (makeSentence == 'y') {
		userInput.at(0) = toupper(userInput.at(0));
		if (!((userInput.at(userInput.size() - 1) == '.') || (userInput.at(userInput.size() - 1) == exclamation) || (userInput.at(userInput.size() - 1) == question))) 
		{
			userInput.push_back(period);
		}
		cout << userInput;
	}
	cout << endl;

	// Add More Text
	cout << "Do you want to insert more text into your current text (y/n)? " << endl;
	cin >> insertText;
	cin.ignore();
	if (insertText == 'y') {
		cout << "Enter text to be inserted: " << endl;
		getline(cin, addText);
		cout << "Enter position where text is to be inserted: " << endl;
		cin >> inputLocation;
		cin.ignore();
		if ((inputLocation > userInput.length()) || (inputLocation < 0)) {
			cout << "No change made. Position must be non-negative and not exceed " << userInput.length() << " , the length of the current text." << endl;
		}
		else if ((inputLocation <= 0) || (inputLocation <= userInput.length())) {
			userInput.insert(inputLocation, addText);
			cout << userInput << endl;
		}
	}

	// Find/replace or copy/paste
	cout << "If you would like to find/replace or copy/paste, enter find or copy: " << endl;
	getline(cin, copOrPas);
	if (copOrPas == "find") {
		cout << "Enter substring to find: " << endl;
		getline(cin, findString);
		cout << endl << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)? " << endl;
		cin >> fdr;
		cin.ignore();
		if (fdr == "find") {
			if ((userInput.find(findString) != string::npos)) {
				cout << findString << " was found at position " << userInput.find(findString) << "." << endl;
			}
			else if (userInput.find(findString) == string::npos) {
				cout << findString << " was not found." << endl;
			}
		}
		else if (fdr == "delete") {
			if (userInput.find(findString) != string::npos) {
				userInput.erase(userInput.find(findString), findString.size());
			}
			else if (!(userInput.find(findString) != string::npos)) {
				cout << findString << " was not found. No change made." << endl;
			}
		}
		else if (fdr == "replace") {
			if (!(userInput.find(findString) != string::npos)) {
				cout << findString << " was not found. No change made." << endl;
			}
			else if (userInput.find(findString) != string::npos) {
				cout << "Enter replacement string:" << endl;
				getline(cin, replaceString);
				userInput.replace(userInput.find(findString), findString.size(), replaceString);
			}
		}
	}
	else if (copOrPas == "copy") {
		cout << "Enter position and length of text to be copied, and position for paste: " << endl;
		cin >> posCopy;
		cin.ignore();
		cout << endl;
		cin >> lengthCopy;
		cin.ignore();
		cout << endl;
		cin >> posPaste;
		cin.ignore();
		if ((posCopy >= userInput.length()) || ((lengthCopy + posCopy) >= userInput.length()) || (posPaste >= userInput.length())) {
			cout << "Values entered do not support copy/paste." << endl;
		}
		else {
			userInput.insert(posPaste, (userInput.substr(posCopy, lengthCopy)));
		}
	}

	// Output final text
	cout << "Final text is" << endl;
	cout << userInput << endl;

	return 0;
}