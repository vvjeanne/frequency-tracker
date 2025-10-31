/* Ava Lindgren - CS210
   Project Three - 10/21/2025 */

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Grocery {
// Create private class
private:
	// Map of items and their purchase frequencies
	map<string, int> itemFreq;

	// Prints all items and their purchase frequencies
	void printItemFreq() {
		for (auto item : itemFreq) {
			cout << item.first << ": " << item.second << endl;
		}
	}

	// Searches the data text file for a specified item
	void findItem() {
		string item;
		cout << "Enter item name: ";
		cin >> item;
		// Prints frequency for entered item
		auto iter = itemFreq.find(item);
		if (iter != itemFreq.end()) {
			cout << "\nFrequency of " << item << ": " << iter->second << endl;
		}
		else {
			cout << "\nItem cannot be found. Please try again . . .\n" << endl;
		}
	}

	// Prints the histogram for all items and their frequencies
	void printHistogram() {
		// Create outer loop for each item
		for (auto item : itemFreq) {
			cout << item.first << " ";
			// Create inner loop for frequency
			for (int i = 0; i < item.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

// Create public class
public:
	// Reads data, initializes map, writes backup file
	Grocery() {
		// Opens and reads input file
		ifstream inputFile("CS210_Project_Three_Input_File.txt");
		if (!inputFile.is_open()) {
			cout << "Error opening input file . . ." << endl;
			exit(1);
		}
		string item;
		// Begin while loop
		while (inputFile >> item) {
			// Initialize grocery map with data in file
			itemFreq[item] ++;
		}
		// Close the file
		inputFile.close();

		// Opens and writes output file
		ofstream outFile("frequency.dat");
		for (auto item : itemFreq) {
			outFile << item.first << " " << item.second << endl;
		}
		// Close the file
		outFile.close();
	}

	// Creates function for the item menu and loops it until option 4: quit is selected
	void menu() {
		int userChoice = 0;
		while(true) {
			cout << "\n********** Menu Options **********\n";
			cout << "1: Look up item frequency\n";
			cout << "2: Print item frequencies\n";
			cout << "3: Print item frequency histogram\n";
			cout << "4: Exit program\n";
			cout << "**********************************";
			cout << "\nEnter your choice (1-4): ";
			cin >> userChoice; // Get input from user and save to userChoice

			// userChoice is option 1
			if (userChoice == 1) {
				findItem();
			}

			// userChoice is option 2
			else if (userChoice == 2) {
				cout << "\n********** Item Frequencies **********\n" << endl;
				printItemFreq();
			}

			// userChoice is option 3
			else if (userChoice == 3) {
				cout << "\n********** Item Histogram **********\n" << endl;
				printHistogram();
			}

			// userChoice is option 4
			else if (userChoice == 4) {
				// End the program
				cout << "\nEnding program . . .\n";
				break;
			}

			// userChoice is invalid
			else {
				cout << "Invalid choice. Please try again . . .\n";
			}
		}
	}

};

// Creates main function to begin and run the program
int main() {
	// Creates Grocery instance
	Grocery grocery1; 
	// Begins program loop
	grocery1.menu();
}