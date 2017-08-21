/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : March 18 2017
Class       : IPC144SJJ - Introduction to Programming using C
Description : Final Project - Milestone 1
---------------------------------------------------------------*/

#include <stdio.h>

/*---------------------------------------------------------------
----------------------PROTOTYPES---------------------------------
---------------------------------------------------------------*/

// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
//---------------------------------------------------------------

// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION------------------------
---------------------------------------------------------------*/

// Welcome Message
void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");
}
//---------------------------------------------------------------

// Title Printing
void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
//---------------------------------------------------------------

// Footer
void printFooter(double grandTotal)
{
	printf("--------------------------------------------------------+----------------\n");

	// if the grandTotal is greater than 0, print the value
	if (grandTotal > 0)
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", grandTotal);
}
//---------------------------------------------------------------

// Flush Keyboard
void flushKeyboard(void)
{
	// Clear the input buffer
	while (getchar() != '\n')
		; // empty statement
}
//---------------------------------------------------------------

// Pause
// wait for user interaction and clear the keyboard
void pause(void)
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}
//---------------------------------------------------------------

// Get Int
// receive an integer from keyboard
int getInt(void)
{
	int inputInteger = 0, //user input
		returnScanf = 0, // return code from scanf function
		keepTrying = 1; // controls iteration
	char inputCharacter = 'x'; // controls <ENTER>

	// capture user input and check if its an integer
	do {
		
		returnScanf = scanf("%d%c", &inputInteger, &inputCharacter);

		if (returnScanf == 0 || inputCharacter != '\n')
		{
			// if not, clear buffer and try again
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}
		else
			// set to 0 to exit
			keepTrying = 0;
	} while (keepTrying == 1);

	return inputInteger;
}
//---------------------------------------------------------------

// Get Int Limited
// define lower and upper limit for integer input
int getIntLimited(int lowerLimit, int upperLimit)
{
	int inputInteger = 0;

	// receive the integer from user
	inputInteger = getInt();

	// check input limits
	while (inputInteger < lowerLimit || inputInteger > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		inputInteger = getInt();
	}
	
	return inputInteger;
}
//---------------------------------------------------------------

// Get Double
// receive a double from keyboard
double getDouble(void)
{
	double inputDouble = 0, //user input
		returnScanf = 0, // return code from scanf function
		keepTrying = 1; // controls iteration
	char inputCharacter = 'x'; // controls <ENTER>

	// capture user input and check if its a double
	do {

		returnScanf = scanf("%lf%c", &inputDouble, &inputCharacter);

		if (returnScanf == 0 || inputCharacter != '\n')
		{
			// if not, clear buffer and try again
			printf("Invalid number, please try again: ");
			flushKeyboard();
		}
		else
			// set to 0 to exit
			keepTrying = 0;
	} while (keepTrying == 1);

	return inputDouble;
}
//---------------------------------------------------------------

// Get Double Limited
// define lower and upper limit for double input
double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double inputDouble = 0;

	// receive the double from user
	inputDouble = getDouble();

	// check input limits
	while (inputDouble < lowerLimit || inputDouble > upperLimit)
	{
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		inputDouble = getDouble();
	}

	return inputDouble;
}
//---------------------------------------------------------------

// Yes
// return user interaction - 1 (Y)es and 0 (N)o
int yes(void)
{
	int result = 0;
	char inputCharacter;

	scanf("%c", &inputCharacter);
	flushKeyboard(); // clears buffer

	// check if the input character is (Y/y) or (N/n)
	while (inputCharacter != 'Y' && inputCharacter != 'y' && inputCharacter != 'N' && inputCharacter != 'n')
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c", &inputCharacter);
		flushKeyboard();
	}

	if (inputCharacter == 'Y' || inputCharacter == 'y')
		result = 1;
	else
		result = 0;

	return result;

}
//---------------------------------------------------------------

// Menu
int menu(void)
{
	int inputInteger = 0; //user input

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	inputInteger = getIntLimited(0, 7);

	return inputInteger;

}
//---------------------------------------------------------------

// Grocery Inventory System
void GroceryInventorySystem(void)
{
	int	isDone = 0; // controls the while loop

	// Welcome message
	welcome();

	while (isDone == 0)
	{

		// Menu
		switch (menu())
		{
			// Exits program
			case 0:
				printf("Exit the program? (Y)es/(N)o: ");

				// If user confirms (Yes), set variable to exit the loop
				if (yes() == 1)
					isDone = 1;

				break;
			//----------------------------------------------------------

			// List all items
			case 1:
				printf("List Items under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Search by SKU
			case 2:
				printf("Search Items under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Checkout an item
			case 3:
				printf("Checkout Item under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Stock an item
			case 4:
				printf("Stock Item under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Add new item or update item
			case 5:
				printf("Add/Update Item under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Delete item
			case 6:
				printf("Delete Item under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			// Search by name
			case 7:
				printf("Search by name under construction!\n");
				pause();
				break;
			//----------------------------------------------------------

			default:
				break;
		}
	}
}