#include <iostream>
#include <iomanip> // needed by setw
#include <cstdlib> // needed for random number generator
#include <ctime> // used to seed random numbers
// --- GLOBAL VARIABLES --- 
// constant array size const 
int MAXINDEX = 100;
// Namespace to make scoing to std unnecessary
using namespace std;
// -- Declare all protoptypes --
	// Declare the prototypes for the helper functions. These are implemented after the main.
	void GenerateArray(int IntArray[], int Count); // Build unsorted array
	void PrintArray(int IntArray[], int Count); // Print the array

	// Declare the prototypes for the sort functions. These are implemented after the main.
	void BubbleSort(int IntArray[], int Count);

	// Declare the prototypes for the search functions. These are implemented after the main.
	int BinarySearch(int IntArray[], int Low, int High, int Target);

// --- START OF MAIN --- 
int main(void) {
 // declare the variables needed for the program.
   int IntArray[MAXINDEX]; // to hold the array of integers
   int Num; // The number to sort for
   int Position; // this will hold the position of the number found or -1 if it is not found.

	// ------------------ START OF LOGIC ------------------------------------


    // -------------------------------------------------------------------------
	// BUBBLE SORT TEST
	// -------------------------------------------------------------------------
	cout << endl << endl << "BUBBLE SORT TEST " << endl;
	GenerateArray(IntArray, MAXINDEX); // generate 100 random integers
    cout << endl << "Here is the content of the array unsorted: " << endl;
    PrintArray(IntArray, MAXINDEX);
	BubbleSort(IntArray, MAXINDEX);
    cout << endl << "After the bubble sort" << endl << "Here is the content of the array unsorted: " << endl;
    PrintArray(IntArray, MAXINDEX);


    // -------------------------------------------------------------------------
	// BINARY SEARCH TEST
	// -------------------------------------------------------------------------
	cout << endl << endl << "BINARY SEARCH TEST " << endl;
	cout << endl << "Use the sorted array from the last test " << endl;

   cout << "Enter the first number in the array to search for: ";
   cin >> Num;
   Position = BinarySearch(IntArray, 0, MAXINDEX-1, Num);
   cout << " Should find the number at position 0" << endl << " Found at position " << Position <<endl;
   cout << "Enter the last number in the array to search for: ";
   cin >> Num;
   Position = BinarySearch(IntArray, 0, MAXINDEX-1, Num);
   cout << " Should find the number at position 99" << endl << " Found at position " << Position <<endl;

   cout << "Enter a random number in the array to search for: ";
   cin >> Num;
   Position = BinarySearch(IntArray, 0, MAXINDEX-1, Num);
   cout << " Found at position " << Position <<endl;


   cout << "Enter a number NOT in the array to search for: ";
   cin >> Num;
   Position = BinarySearch(IntArray, 0, MAXINDEX-1, Num);
   if (Position==-1)
	cout << " Correct: Number not found in array" << endl;
   else
	cout << " Incorrect result: Number found at position " << Position <<endl;
}

//////////////////////////////////////////////////////////////////////
// Function: void GenerateArray(int IntArray[], int Count);
// Purpose: Given "Count", generate "Count" number of random integers
// and put them in IntArray
// Parameters: IntArray: an integer array to hold MAXINDEX elements
// Count: number of elements in the array
// Return: None
//////////////////////////////////////////////////////////////////////
void GenerateArray(int IntArray[], int Count) {
   int k;
   srand((unsigned) time(NULL)); // seed the random number generator
   for (k = 0; k < Count; k++)
      IntArray[k] = rand()%1000;
   // Note that rand() returns a random integer between 0 and
   // RAND_MAX.  We use modulo - % - to limit the integer value to a
   // smaller range
}
////////////////////////////////////////////////////////////////////////////
// Function: void PrintArray(int IntArray[], int Count);
// Purpose: Print out the content of "IntArray"
// Parameters: IntArray: an integer array to hold MAXINDEX elements
// Count: number of elements in the array
// Return: None
////////////////////////////////////////////////////////////////////////////
void PrintArray(int IntArray[], int Count) {
   int k;
   //Print header
   cout << "Ones ->";
   for (k = 0; k < 10; k++)
   {
      cout << setw(4) << k << " |";
   }
   cout << endl;
   cout << "Tens ||" << setw(60) << setfill('=') << '|' << endl << setfill(' ');

   for (k = 0; k < Count; k++)
   {
      //Label new rows
      if (k % 10 == 0)
         cout << setw(4) << k/10 << " ||";

      //Print the array value
      cout << setw(4) << IntArray[k] << " |";
      //End rows
      if (k % 10 == 9)
         cout << endl;
   }
   cout << endl;
}

////////////////////////////////////////////////////////////////////////////
// Function: // int BinarySearch(int IntArray[], int Low, int High, int Target)
// Purpose: search "Target" in an ordered integer array
// Parameters: IntArray: Array of integers in ascending order
// Low: The starting index
// High: The ending index
// Target: The integer value to search
// Return: The index of the value if found
// -1 if not found
//////////////////////////////////////////////////////////////////////////// 
int BinarySearch(int IntArray[], int Low, int High, int Target) {
    int mid;

    while (High >= Low) {
        mid = (High + Low) / 2;
        if (IntArray[mid] < Target) {
            Low = mid + 1;
        }
        else if (IntArray[mid] > Target) {
            High = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
////////////////////////////////////////////////////////////////////
// Function: BubbleSort(int IntArray[], int Count)
// Purpose: Given an integer array with "Count" number of elements,
// sort the elements in ascending order
// Parameters: IntArray: an integer array to hold MAXINDEX elements
// Count: number of elements
// Return: None
////////////////////////////////////////////////////////////////////
void BubbleSort(int IntArray[], int Count)
   {
       for (int i = 0; i < Count - 1; i++) {
           for (int j = 0; j < Count - i - 1; j++) {
               if (IntArray[j] > IntArray[j + 1]) {
                   int temp = IntArray[j];
                   IntArray[j] = IntArray[j + 1];
                   IntArray[j + 1] = temp;
               }
           }
       }
  }
