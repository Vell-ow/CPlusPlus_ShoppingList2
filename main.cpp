#include <iomanip>
#include <cstdlib>
#include <fstream>
// 
// Programmer:    Andrew Coviello
// Homework 9
// Project 1
// Problem Statement: Write a program that reads each item on a grocery 
// list from a text file, then displays that item on the console.
// Then, prepare and write a report of the grocery list onto another text 
// file.
//
// The text file containing the grocery list should be named grocery.txt
// (You can find this file at the bottom of this homework assignment, or 
// make up your own.). Each item on the grocery list should occupy 4 
// lines in the file.
//
// Line 1:  A description of the grocery item, such as "Green Apples", 
// "Orange Juice", or "Soup".  (Notice that the item description can 
// contain blanks.)
// Line 2:  The quantity of the item to purchase (a whole number)
// Line 3:  The estimated price for each item (a real number)
// Line 4:  A unit-of-measure for an item (e.g., "ea.", "lbs.", "pack").
//
// 1. Place the name of the input text file (grocery.txt) in a constant 
// at the top of your program.
// 2. Open the input text file.
// 3. If there is an error opening the file, then print a message and 
// exit the program.
// 4. Use a while loop to read each grocery item on the list.
// 5. Using the getline function, read the description of the grocery 
// item into a string.
// 6. If the read fails (i.e., returns false) exit the loop.
// 7. Using the >> operator, read the quantity of the item to purchase 
// into an  int.
// 8. Using the >> operator, read the estimated unit price into a double.
// 9. Using the getline function, read the unit-of-measure into a string.
// 10. Get rid of the dangling \n between this step and the prior step 
// using another getline statement.
// 11. Display the item description, estimated unit price, 
// unit-of-measure, and quantity on the console.
// 12. When the loop is finished, close the input file.
// 13. Stop the program.
//
#include <iostream>
using namespace std;

int main() {

  // file input stream to receive input 
  ifstream infile;
  // file output stream to receive output
  ofstream outfile;
  int itemCt;
  double price, groceryTotal;
  // strings used in reading process
  string itemName, units, itemDesc, val, line;
  line.assign(20, '_');
  const string FILE_NAME_1 = "grocery.txt", FILE_NAME_2 = "output.txt";

  infile.open(FILE_NAME_1);

  outfile.open(FILE_NAME_2);

  outfile << setw(30) << setprecision(2) << fixed << "***************** My Grocery List **************" << endl;  
  outfile << setw(35) << " Est." << setw(10) << "Item" << endl;
  outfile << left << "---------Item-------" << setw(5) << " Qnty " << setw(5) << "Unit" << setw(10) << "Unit-$" << setw(5) << "Total" << endl;
  while(getline(infile, itemName) && itemName.length() > 0)
  {
    infile >> itemCt;
    infile >> price;
    groceryTotal += (itemCt * price);
    // whenever changing the data type that a file reads in, always use
    // infile.ignore() to clear the buffer(and toss \ns)
    infile.ignore();
    getline(infile, units);
    outfile << setw(22) << itemName << setw(4) << itemCt << setw(5) << units << setw(10) << price << setw(3) << itemCt * price << endl;
  }
  outfile << setw(50) << right << line << endl;
  outfile << left << setw(20) << "Grocery Total" << setw(26) << right << groceryTotal << endl;
  // change all instances of cout to outfile once the shit is formatted

  /*
    ***************** My Grocery List **************  
                                     Est.    Item
  ---------Item-------  Qnty  Unit  Unit-$   Total 
  Tuna Noodle Dish         2  ea.    10.64   21.28
  Granny Smith Apples      3  lbs.    0.85    2.55
                  <...more items...>
  Birthday Cake            1  ea.    38.29   38.29
                                           -------
  Grocery Total                              ??.??
  */
  infile.close();
}
