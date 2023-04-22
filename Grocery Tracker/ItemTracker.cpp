/*
 * ItemTracker.cpp
 *  CS 210
 *  Created on: Apr 16, 2023
 *      Author: Aidan Gorospe
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class ItemTracker
{
//Declare public and private methods

// Methods used to initialize the object
public:
  void readDat();
  void displayMenu();
  void backupDat();

// Methods used by displayMenu to do what the user wants
private:
  map<string, int> freqs;
  void searchItem();
  void printFreqList();
  void printHistogram();
};

void ItemTracker::displayMenu()
{
  //Display Text that asks for input.
  int selection;
  cout << "Input Selection.\n";
  cout << "1: Get item amount" << endl;
  cout << "2: Print items and values" << endl;
  cout << "3: Print item histogram" << endl;
  cout << "4: Exit" << endl;
  cin >> selection;
  //uses if-else statements to give proper methods based on input.
  if(selection == 1)
  {
    searchItem();
  }
  else if(selection == 2)
  {
    printFreqList();
  }
  else if(selection == 3)
  {
    printHistogram();
  }
  else if(selection == 4)
  {
    exit(0);
  }

  // After running user selected code, write a new line to sepparate
  // lines and display the menu again.
  cout << "\n";
  displayMenu();
}

void ItemTracker::readDat()
{
  //opens the file to read the text
  ifstream dataFile("CS210_Project_Three_Input_File.txt");
  string item;
  while (dataFile >> item)
  {
    freqs[item]++;
  }
  dataFile.close();
}

void ItemTracker::searchItem()
{
  //asks user for what item to search for, then grabs the number of that item
  string item;
  //asks input for item
  cout << "What is the item?\n";
  cin >> item;
  cout << "Number of item: " << freqs[item] << "\n";
}

void ItemTracker::printFreqList()
{
  //prints the frequency/number of all the items
  cout << "Frequency list:\n";
  for (auto const &item : freqs)
  {
    cout << item.first << " " << item.second << endl;
  }
}

void ItemTracker::printHistogram()
{
  //Turns the number of items into a chart and displays them
  cout << "Histogram:\n";
  //loop through each item
  for (auto const &item : freqs)
  {
    cout << item.first << "  ";
    for (int j = 0; j < item.second; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void ItemTracker::backupDat()
{
  //backs up the data by writing the map to a seperate file
  ofstream backupfile;
  backupfile.open("frequency.dat");

  // loop through each item
  for (auto const &item : freqs)
  {
    // grab key-value and write to format
    backupfile << item.first << ": " << item.second << endl;
  }

  backupfile.close();
}

int main()
{
  ItemTracker it;
  // Read the data from the file
  it.readDat();
  // Write the backup
  it.backupDat();
  // Display menu
  it.displayMenu();
}

