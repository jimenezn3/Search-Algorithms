// Nick Diaz
// Comparison between Selection and Linear search algorithms

#include <iostream>
#include <iomanip>  // needed by setw
#include <cstdlib>  // needed for random number generator
#include <ctime>     // used to seed random numbers

//   --- GLOBAL VARIABLES  ---
// constant array size
const int MAXINDEX = 100;

// Namespace to make scoping to std unnecessary
using namespace std;

// -- Declare all protoptypes --
	// Declare the prototypes for the helper functions. These are implemented after the main.
	void GenerateArray(int IntArray[], int Count);  // Build unsorted array
	void PrintArray(int IntArray[],  int Count);     // Print the array


	// Declare the prototypes for the sort functions. These are implemented after the main.
	void SelectionSort(int IntArray[], int Count);


	// Declare the prototypes for the search functions. These are implemented after the main.
	int LinearSearch(int IntArray[], int Count, int Target);


//   --- STAR OF MAIN  ---
int main(void)
{
 // declare the variables needed for the program.
   int IntArray[MAXINDEX];  // to hold the array of integers
   int Num;    // The number to sort for
   int Position;  // this will hold the position of the number found or -1 if it is not found.


	// ------------------ START OF LOGIC  ------------------------------------

	// -------------------------------------------------------------------------
	//     LINEAR SEARCH TESTS
	//   Search unsorted array
	// -------------------------------------------------------------------------

	cout << endl << endl << "LINEAR SEARCH TESTS " << endl;
	GenerateArray(IntArray, MAXINDEX); // generate 100 random integers
    cout << endl << "Here is the content of the array: " << endl;
    PrintArray(IntArray, MAXINDEX);

	/* TEST ONE: FIND FIRST ELEMENT IN THE ARRAY */
   cout << "Enter the first number in the array to search for: ";
   cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Found at position " << Position  <<endl;

   	/* TEST TWO: FIND LAST ELEMENT IN THE ARRAY */
   cout << "Enter the last number in the array to search for: ";
	cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Should find the number at position 99" << endl << "  Found at position " << Position  <<endl;

    /* TEST THREE: FIND ANY ELEMENT IN THE MIDDLE OF THE ARRAY */
   cout << "Enter a random number in the array to search for: ";
   cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Found at position " << Position  <<endl;

    /* TEST FOUR: SEARCH FOR ELEMENT NOT IN ARRAY */
   cout << "Enter a number NOT in the array to search for: ";
    cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   if (Position==-1)
	cout << "  Correct: Number not found in array" << endl;
   else
	cout << "  Incorrect result: Number found at position " << Position  <<endl;


    // -------------------------------------------------------------------------
	//     SELECTION SORT TEST
	// -------------------------------------------------------------------------
	cout << endl << endl << "SELECTION SORT TEST  " << endl;
	GenerateArray(IntArray, MAXINDEX); // generate 100 random integers
    cout << endl << "Here is the content of the array unsorted: " << endl;
    PrintArray(IntArray, MAXINDEX);

	SelectionSort(IntArray, MAXINDEX);
    cout << endl << "After the selection sort" << endl << "Here is the content of the array sorted: " << endl;
    PrintArray(IntArray, MAXINDEX);

	// -------------------------------------------------------------------------
	//     LINEAR SEARCH TESTS
	//   Search sorted array
	// -------------------------------------------------------------------------
	cout << endl << endl << "LINEAR SEARCH TESTS " << endl;
	cout << endl << "Use the sorted array from the last test " << endl;

	/* TEST ONE: FIND FIRST ELEMENT IN THE ARRAY */
   cout << "Enter the first number in the array to search for: ";
   cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Should find the number at position 0" << endl << "  Found at position " << Position  <<endl;

   	/* TEST TWO: FIND LAST ELEMENT IN THE ARRAY */
   cout << "Enter the last number in the array to search for: ";
    cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Should find the number at position 99" << endl << "  Found at position " << Position   <<endl;

    /* TEST THREE: FIND ANY ELEMENT IN THE MIDDLE OF THE ARRAY */
   cout << "Enter a random number in the array to search for: ";
    cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   cout << "  Found at position " << Position  <<endl;


    /* TEST FOUR: SEARCH FOR ELEMENT NOT IN ARRAY */
   cout << "Enter a number NOT in the array to search for: ";
    cin >> Num;
   Position = LinearSearch(IntArray, MAXINDEX, Num);
   if (Position==-1)
	cout << "  Correct: Number not found in array" << endl;
   else
	cout << "  Incorrect result: Number found at position " << Position  <<endl;

}


//////////////////////////////////////////////////////////////////////
// Function: void GenerateArray(int IntArray[], int Count);
// Purpose:  Given "Count", generate "Count" number of random integers
//           and put them in IntArray
// Parameters: IntArray: an integer array to hold MAXINDEX elements
//             Count:    number of elements in the array
// Return:     None
//////////////////////////////////////////////////////////////////////
void GenerateArray(int IntArray[], int Count)
{
   srand((unsigned) time(NULL));  // seed the random number generator

   for (int k = 0; k < Count; k++)
      IntArray[k] = rand()%1000;
   // Note that rand() returns a random integer between 0 and
   // RAND_MAX.  We use modulo - % - to limit the integer value to a
   // smaller range
}

////////////////////////////////////////////////////////////////////////////
// Function: void PrintArray(int IntArray[], int Count);
// Purpose:  Print out the content of "IntArray"
// Parameters: IntArray: an integer array to hold MAXINDEX elements
//             Count:    number of elements in the array
// Return:     None
////////////////////////////////////////////////////////////////////////////
void PrintArray(int IntArray[], int Count)
{
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

//////////////////////////////////////////////////////////////////////
// Function: bool getTargetInteger(int & number);
// Purpose:  Ask for integer from IOSTREAM and return in the parameter reference address
//           If a valid response is not given
// Parameters: Reference parameter to hold input retrieved from IOSTREAM
// Return:    FALSE  If a valid response is not given in 3 tries
//            TRUE   If a valid response is given
//////////////////////////////////////////////////////////////////////
bool getTargetInteger(int & intValue)
{
    bool inputState = true;
    int tries = 1;

     cin >> intValue;

     while (cin.fail() && tries <3)
      {
          tries++;
          cin.clear();
          cin.ignore(100,'\n');
          cout << "Invalid input. try again " << endl;
          cin >> intValue;
      }

      if (tries>=3)
      {
                inputState= false;
                cin.clear();
                cin.ignore(100,'\n');
      }

      return inputState;
}


////////////////////////////////////////////////////////////////////
// Function: LinearSearch(int IntArray[], int Count, int Target)
// Purpose:  Given an integer array with "Count" number of elements,
//           try to find "Target".
// Parameters: IntArray: an integer array to hold MAXINDEX elements
//             Count:    number of elements
//             Target:   the integer you are searching for
// Return:     The position of the Target in the array
//             -1 if not found
////////////////////////////////////////////////////////////////////
int LinearSearch(int IntArray[], int Count, int Target)
{
   for (int i = 0; i < Count; ++i) {
       if (IntArray[i] == Target) {
           return i;
       }
   }
   return -1; // Target not found
}



////////////////////////////////////////////////////////////////////
// Function: SelectionSort(int IntArray[], int Count)
// Purpose:  Given an integer array with "Count" number of elements,
//           sort the elements in ascending order
// Parameters: IntArray: an integer array to hold MAXINDEX elements
//             Count:    number of elements
// Return:     None
////////////////////////////////////////////////////////////////////
void SelectionSort(int IntArray[], int Count)
{
   int i, j, smallestIndex, temp;

   for (i = 0; i < Count - 1; ++i) {
       smallestIndex = i;
       for (j = i + 1; j < Count; ++j) {
           if (IntArray[j] < IntArray[smallestIndex]) {
               smallestIndex = j;
           }
       }

        temp = IntArray[i];
        IntArray[i] = IntArray[smallestIndex];
        IntArray[smallestIndex] = temp;
   }
}
