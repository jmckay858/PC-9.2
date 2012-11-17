//============================================================================
// PC 9.1 - Test Scores #1
// -------------------------
// Programmer: Jeremy F McKay
// Date: November 13, 2012
// -------------------------
// This program will dynamically allocate an array for the user to input
// test scores then display them in descending order and show the average.
// ---------1---------2---------3---------4---------5---------6---------7
// 1234567890123456789012345678901234567890123456789012345678901234567890

#include <iostream>
using namespace std;

int *dynamicArray(int elements);

void sortGrades(int *grades, int SIZE);
void enterGrades(int *grades, int SIZE);
int findAverage(int total, int SIZE);
int findSum(int *grades, int SIZE);
void printResults(int *grades, int SIZE);

int main() {
	int *grades, //Dynamic array
		elements; // How many array elements there are
	cout << "\n   "
		 << "How many tests do you want to enter? ";
	cin >> elements;

	while (elements <= 0)
	{
		cout << "   "
			 << "Please enter a positive number\n"
			 << "   "
			 << "How many tests do you want to enter? ";
		cin >> elements;
	}

	grades = dynamicArray(elements);
	//Get grades
	enterGrades(grades,elements);
	//Sort grades
	sortGrades(grades, elements);
    printResults(grades, elements);
	// free the dynamically allocated memory
	delete [] grades;
	grades = 0;

	return 0;
}

int *dynamicArray(int elements)
{
	int *array;
	array = new int[elements];
	cout << "\n   "
		 << "Array created";
	return array;
}

void sortGrades(int *grades, int SIZE)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = *(grades+startScan);
		for(int index = startScan + 1; index < SIZE; index++)
		{
			if (*(grades+index) < minValue)
			{
				minValue = *(grades+index);
				minIndex = index;
			}
		}
		*(grades+minIndex) = *(grades+startScan);
		*(grades+startScan) = minValue;
	}
}

void enterGrades(int *grades, int SIZE)
{

	for (int index = 0; index < SIZE; index++)
	{
	cout << "\n   "
		 << "Enter test " << (index+1)
		 << ": ";
	cin >> *(grades+index);
	while (*(grades+index) <= 0)
		{
			cout << "   "
				 << "Please enter a positive number\n"
				 << "   "
				 << "How many tests do you want to enter? ";
			cin >> *(grades+index);
		}
	}
}

int findSum(int *grades, int SIZE)
{
	int tnum, sum;
	for(tnum = 0; tnum < SIZE; tnum++)
	  sum += *(grades+tnum);
	return sum;
}

int findAverage(int total, int SIZE)
{
	double average;
	return average = total / SIZE;

}

void printResults(int *grades, int SIZE)
{
	// Display grades in Descending order
	cout	 << "   TEST SCORES"
			 << "\n  "
			 << "-------------"
			 << "\n";
	for (int index = SIZE-1; index >= 0; index--)
		{
			cout << "   "

				 <<	*(grades+index) << endl;
		}

	// Display Average
	cout 	 << "\n   AVERAGE OF SCORES"
			 << "\n  "
			 << "-------------"
			 << "\n   "
			 << findAverage(findSum(grades,SIZE), SIZE);
}



