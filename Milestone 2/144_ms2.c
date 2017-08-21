/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : March 24 2017
Class       : IPC144SJJ - Introduction to Programming using C
Description : Final Project - Milestone 2
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Define statements:
#define LINEAR 1
#define FORM 0
#define TRUE 1
#define FALSE 0


// Constant TAX value:
const double TAX = 0.13;


// Item structure:
struct Item
{
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


// Function Prototypes Milestone 1:

/*---------------------------------------------------------------
----------------------PROTOTYPES M1------------------------------
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
//---------------------------------------------------------------


// Function Prototypes Milesone 2:

/*---------------------------------------------------------------
----------------------PROTOTYPES M2------------------------------
---------------------------------------------------------------*/

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Implementations Milestone 1:

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION M1---------------------
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
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
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


// Function Implementations Milestone 2:

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION M2---------------------
---------------------------------------------------------------*/

// Total After Tax
// calculates the total value with taxes
double totalAfterTax(struct Item item)
{
	double result = 0;

	result = item.price * item.quantity; // price in stock

	// apply taxes if isTaxed if true (non-zero)
	if (item.isTaxed != FALSE)
		result *= (1 + TAX); // 13%

	return result;
}
//----------------------------------------------------------

// Is Low Quantity
int isLowQuantity(struct Item item)
{
	int result = 0;

	// returns true (1) if less than minQuantity or false (0) elsewise
	if (item.quantity < item.minQuantity)
		result = TRUE;
	else
		result = FALSE;

	return result;
}
//----------------------------------------------------------

// Item Entry
struct Item itemEntry(int sku)
{
	struct Item newItem = { 0 };

	newItem.sku = sku;

	// SKU
	printf("        SKU: %d\n", sku);

	// Name
	printf("       Name: ");
	scanf("%20[^\n]", newItem.name);
	flushKeyboard();

	// Price
	printf("      Price: ");
	newItem.price = getDouble();

	// Quantity
	printf("   Quantity: ");
	newItem.quantity = getInt();

	// Minimum Quantity
	printf("Minimum Qty: ");
	newItem.minQuantity = getInt();

	// Is Taxed
	printf("   Is Taxed: ");
	newItem.isTaxed = yes();

	return newItem;
}
//----------------------------------------------------------

void displayItem(struct Item item, int linear)
{
	double totalPrice = 0;

	// calculate the total price for item
	totalPrice = totalAfterTax(item);

	// Linear printf
	if (linear == LINEAR)
	{
		// SKU Name Price isTaxed Quantity MinimumQty TotalPrice
		printf("|%3d|%-20s|%8.2lf|%5s| %3d | %3d |%12.2lf|%s\n",
			item.sku,
			item.name,
			item.price,
			(item.isTaxed?"Yes":"No"), // yes or no
			item.quantity,
			item.minQuantity,
			totalPrice,
			(isLowQuantity(item)?"***":"") // *** or blank
		);
	}
	// Form printf
	else if(linear == FORM)
	{
		printf("        SKU: %d\n"
			   "       Name: %s\n"
			   "      Price: %.2lf\n"
			   "   Quantity: %d\n"
			   "Minimum Qty: %d\n"
			   "   Is Taxed: %s\n"
			   "%s",
			item.sku,
			item.name,
			item.price,
			item.quantity,
			item.minQuantity,
			(item.isTaxed?"Yes":"No"),
			(isLowQuantity(item)?"WARNING: Quantity low, please order ASAP!!!\n":"")
		);
	}
}
//----------------------------------------------------------

// List Items
void listItems(const struct Item item[], int noOfItems)
{
	int i = 0;
	double grandTotal = 0;

	// Title
	printTitle();

	// Iterate the item "noOfItems" times
	for (i = 0; i < noOfItems; i++)
	{
		printf("%-4d", i+1); // print the row number
		displayItem(item[i], LINEAR); // displays the item in linear mode
		grandTotal += totalAfterTax(item[i]); // adds the item total to the grand total
	}

	// Print Footer
	printFooter(grandTotal);
}
//----------------------------------------------------------

// Locate Item
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int result = 0,
		i = 0;

	// Iterate the item "NoOfRecs" times
	for (i = 0; i < NoOfRecs; i++)
	{
		// check the sku
		if (item[i].sku == sku)
		{
			*index = i; // change the index value
			result = TRUE;
		}
	}

	return result;
}
//----------------------------------------------------------