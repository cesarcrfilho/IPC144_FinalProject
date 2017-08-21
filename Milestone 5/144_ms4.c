/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : April 17 2017
Class       : IPC144SJJ - Introduction to Programming using C
Description : Final Project - Milestone 5
---------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


// Define statements:
#define LINEAR 1
#define FORM 0
#define TRUE 1
#define FALSE 0
// Define statements MS3
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
// Define statements MS4
#define DATAFILE "test.txt"


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


// Function Prototypes Milestone 2:

/*---------------------------------------------------------------
----------------------PROTOTYPES M2------------------------------
---------------------------------------------------------------*/

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
//---------------------------------------------------------------

// Function Prototypes Milestone 3:

/*---------------------------------------------------------------
----------------------PROTOTYPES M3------------------------------
---------------------------------------------------------------*/

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);
//---------------------------------------------------------------

// Function Prototypes Milestone 4:

/*---------------------------------------------------------------
----------------------PROTOTYPES M4------------------------------
---------------------------------------------------------------*/

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);

// Function Prototypes Final Assembly:

/*---------------------------------------------------------------
----------------------FINAL ASSEMBLY-----------------------------
---------------------------------------------------------------*/

void saveToFile(const struct Item item[], char fileName[], int NoOfRecs);

// Function Prototypes Milestone 5:

/*---------------------------------------------------------------
----------------------PROTOTYPES M5------------------------------
---------------------------------------------------------------*/

void deleteItem(struct Item item[], int* NoOfRecs);
void searchItem(struct Item item[], const int NoOfRecs);


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
		printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
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

	// Between 0 and 7
	inputInteger = getIntLimited(0, 7);

	return inputInteger;

}
//---------------------------------------------------------------

// Grocery Inventory System
void GroceryInventorySystem(void)
{
	int	isDone = 0, // controls the while loop
		numRecords = 0; // hold the number of records read

	struct Item groceryItems[MAX_ITEM_NO]; // 21 items

	// Welcome message
	welcome();

	// Fill groceryItems with information from the file
	// if it doesn't work, exit the program
	if (loadItems(groceryItems, DATAFILE, &numRecords) == FALSE)
		printf("Could not read from %s.\n", DATAFILE);
	// if it works, continue the execution
	else
	{

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
					listItems(groceryItems, numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Search by SKU
				case 2:
					search(groceryItems, numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Checkout an item
				case 3:
					adjustQuantity(groceryItems, numRecords, CHECKOUT);
					
					// Save groceryItems to the file
					saveToFile(groceryItems, DATAFILE, numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Stock an item
				case 4:
					adjustQuantity(groceryItems, numRecords, STOCK);

					// Save groceryItems to the file
					saveToFile(groceryItems, DATAFILE, numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Add new item or update item
				case 5:
					addOrUpdateItem(groceryItems, &numRecords);

					// Save groceryItems to the file
					saveToFile(groceryItems, DATAFILE, numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Delete item
				case 6:
					//printf("Please enter the SKU: ");
					deleteItem(groceryItems, &numRecords);
					// load items after deletion
					loadItems(groceryItems, DATAFILE, &numRecords);
					pause();
					break;
				//----------------------------------------------------------

				// Search by name
				case 7:
					searchItem(groceryItems, numRecords);
					break;
				//----------------------------------------------------------

				default:
					break;
			}
		}
	}
}
//----------------------------------------------------------


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
	if (item.quantity <= item.minQuantity)
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
	newItem.price = getDoubleLimited(0.01, 1000.00);

	// Quantity
	printf("   Quantity: ");
	newItem.quantity = getIntLimited(1, MAX_QTY);

	// Minimum Quantity
	printf("Minimum Qty: ");
	newItem.minQuantity = getIntLimited(0, 100);

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
			(item.isTaxed ? "Yes" : "No"), // yes or no
			item.quantity,
			item.minQuantity,
			totalPrice,
			(isLowQuantity(item) == TRUE ? "***" : "") // *** or blank
		);
	}
	// Form printf
	else if (linear == FORM)
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
			(item.isTaxed ? "Yes" : "No"),
			(isLowQuantity(item) == TRUE ? "WARNING: Quantity low, please order ASAP!!!\n" : "")
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
		printf("%-4d", i + 1); // print the row number
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


// Function Implementations Milestone 3:

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION M3---------------------
---------------------------------------------------------------*/

// Search
void search(const struct Item item[], int NoOfRecs)
{
	int userInput = 0,
		index = 0; // array index

				   // Receive input from user
	printf("Please enter the SKU: ");
	userInput = getIntLimited(SKU_MIN, SKU_MAX);

	// Try to find the item
	locateItem(item, NoOfRecs, userInput, &index) == TRUE ? displayItem(item[index], FORM) : printf("Item not found!\n");

}
//----------------------------------------------------------

// Update Item
void updateItem(struct Item* itemptr)
{
	struct Item tempItem = { 0 };

	// Enter new data to be updated
	printf("Enter new data:\n");
	tempItem = itemEntry(itemptr->sku);

	// Confirm the update
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes() == TRUE)
	{
		*itemptr = tempItem;
		printf("--== Updated! ==--\n");
	}
	else
		printf("--== Aborted! ==--\n");

}
//----------------------------------------------------------

// Add Item
void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	struct Item tempItem = { 0 };

	if (*NoOfRecs >= MAX_ITEM_NO)
		printf("Can not add new item; Storage Full!\n");
	else
	{
		tempItem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");

		if (yes() == TRUE)
		{
			item[*NoOfRecs] = tempItem;
			*NoOfRecs = *NoOfRecs + 1;
			printf("--== Added! ==--\n");
		}
		else
			printf("--== Aborted! ==--\n");
	}

}
//----------------------------------------------------------

// Add Or Update Item
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int userInput = 0,
		index = 0;

	printf("Please enter the SKU: ");
	userInput = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, *NoOfRecs, userInput, &index) == TRUE)
	{
		displayItem(item[index], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes() == TRUE)
			updateItem(&item[index]);
		else
			printf("--== Aborted! ==--\n");
	}
	else
		addItem(item, NoOfRecs, userInput);

}
//----------------------------------------------------------

// Adjust Quantity
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int userInput = 0,
		index = 0,
		quantity = 0,
		quantityEntered = 0;

	char toStockOrCheckOut[12],
		toStock[9] = "to stock",
		toCheckOut[12] = "to checkout";

	printf("Please enter the SKU: ");
	userInput = getIntLimited(SKU_MIN, SKU_MAX);

	// Check if the item exists
	if (locateItem(item, NoOfRecs, userInput, &index) == TRUE)
	{
		displayItem(item[index], FORM);

		// Check the stock value to determine the action
		if (stock == STOCK)
		{
			strcpy(toStockOrCheckOut, toStock);
			quantity = MAX_QTY - item[index].quantity;
		}
		else if (stock == CHECKOUT)
		{
			strcpy(toStockOrCheckOut, toCheckOut);
			quantity = item[index].quantity;
		}

		// Ask the user for the quantity
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", toStockOrCheckOut, quantity);
		quantityEntered = getIntLimited(0, quantity);

		if (quantityEntered == 0)
			printf("--== Aborted! ==--\n");
		else
		{
			// Check if it's a stock or a checkout
			if (stock == STOCK)
			{
				item[index].quantity += quantityEntered;
				printf("--== Stocked! ==--\n");
			}
			else
			{
				item[index].quantity -= quantityEntered;
				printf("--== Checked out! ==--\n");
			}

		}

		// Check if the quantity is low (min quantity)
		if (isLowQuantity(item[index]) == TRUE)
			printf("Quantity is low, please reorder ASAP!!!\n");
	}

	// Item not found
	else
	{
		printf("SKU not found in storage!\n");
	}

}
//----------------------------------------------------------


// Function Implementations Milestone 4:

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION M4---------------------
---------------------------------------------------------------*/

// Save Item
void saveItem(struct Item item, FILE* dataFile)
{
	if(dataFile != NULL)
	// Writes the content of item to the dataFile
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}
//----------------------------------------------------------

// Load Item
int loadItem(struct Item* item, FILE* dataFile)
{
	int result = 0,
		fscanfFields = 0;

	// Read the item contents from the dataFile
	fscanfFields= fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]\n", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name);

	// returns TRUE if the file has 6 columns
	result = (fscanfFields == 6 ? TRUE : FALSE);
	
	return result;

}
//----------------------------------------------------------

// Save Items
int saveItems(const struct Item item[], char fileName[], int NoOfRecs)
{
	int result = 0,
		i = 0;

	FILE *fp = NULL;

	// Opens the fileName with writing mode (overwrite)
	fp = fopen(fileName, "w");

	// If the file is opened, save the items from the array
	if (fp != NULL)
	{
		for (i = 0; i < NoOfRecs; i++)
		{
			saveItem(item[i], fp);
			result = TRUE;
		}

		// Closes the file
		fclose(fp);
	}

	return result;
}
//----------------------------------------------------------

// Load Items
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr)
{
	int result = 0,
		i = 0;

	FILE *fp = NULL;

	// Opens the fileName with reading mode
	fp = fopen(fileName, "r");

	// If the file is opened, save the items from the array
	if (fp != NULL)
	{
		while (loadItem(&item[i], fp) == TRUE)
		{
			i++;
			result = TRUE;
		}

		// Closes the file
		fclose(fp);
	}

	// Change the counter value to i
	*NoOfRecsPtr = i;

	return result;
}
//----------------------------------------------------------


// Function Implementations Final Assembly:

/*---------------------------------------------------------------
-------------------------FINAL ASSEMBLY--------------------------
---------------------------------------------------------------*/

// Save To File
// this function is used to save an Item array to a file
void saveToFile(const struct Item item[], char fileName[], int NoOfRecs)
{
	if (saveItems(item, fileName, NoOfRecs) == FALSE)
		printf("could not update data file %s\n", DATAFILE);
}
//----------------------------------------------------------


// Function Implementations Milestone 5:

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION M5---------------------
---------------------------------------------------------------*/

// Delete Item
void deleteItem(struct Item item[], int* NoOfRecs)
{
	int userInput = 0,
		index = 0,
		i = 0;
	
	FILE *fp = NULL;

	printf("Please enter the SKU: ");
	userInput = getIntLimited(SKU_MIN, SKU_MAX);

	// locate the user input SKU
	if (locateItem(item, *NoOfRecs, userInput, &index) == TRUE)
	{
		displayItem(item[index], FORM);
		printf("This Item will be deleted, are you sure? (Y)es/(N)o: ");
		if (yes() == TRUE)
		{
			// open the file
			fp = fopen(DATAFILE, "w");

			// check if the file is opened
			if (fp != NULL)
			{
				// save items one by one, skipping the deleted
				for (i = 0; i < *NoOfRecs; i++)
				{
					if(i != index)
					saveItem(item[i], fp);
				}
			}

			// subtract the deleted item
			*NoOfRecs = *NoOfRecs-1;

			// close the file
			fclose(fp);

			printf("Deleted!\n");
		}
		else
			printf("Aborted!\n");
	}
	else
		printf("SKU not found!\n");
}

// Search Item
void searchItem(struct Item item[], const int NoOfRecs)
{
	char userInput[FILENAME_MAX];

	int matched = FALSE,
		i = 0;

	printf("Please enter part of the name: ");
	scanf("%[^\n]", userInput);
	flushKeyboard();

	for (i = 0; i < NoOfRecs; i++)
	{
		if (strstr(item[i].name, userInput) != FALSE)
		{
			displayItem(item[i], FORM);
			pause();
			matched = TRUE;
		}
	}

	if (matched == FALSE)
	{
		printf("No Item found in the system matching the value entered!\n");
		pause();
	}
}

/*---------------------------------------------------------------
--------------------------MAIN FUNCTION--------------------------
---------------------------------------------------------------*/

int main(void)
{

	// Final Assembly
	GroceryInventorySystem();

	return 0;
}
//----------------------------------------------------------
