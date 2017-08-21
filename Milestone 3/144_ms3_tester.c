#include <stdio.h>
/***************************************************************
Tester Function prototypes */
struct Item {
  double price;
  int sku;
  int isTaxed;
  int quantity;
  int minQuantity;
  char name[21];
};


#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21

void displayItem(struct Item item, int linear);








// ms3 prototypes

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// global array for testing

struct Item GI[21] = {
  { 4.4,275,0,10,2,"Royal Gala Apples" },
  { 5.99,386,0,20,4,"Honeydew Melon" },
  { 3.99,240,0,30,5,"Blueberries" },
  { 10.56,916,0,20,3,"Seedless Grapes" },
  { 2.5,385,0,5,2,"Pomegranate" },
  { 0.44,495,0,100,30,"Banana" },
  { 0.5,316,0,123,10,"Kiwifruit" },
  { 4.49,355,1,20,5,"Chicken Alfredo" },
  { 5.49,846,1,3,5,"Veal Parmigiana" },
  { 5.29,359,1,40,5,"Beffsteak Pie" },
  { 4.79,127,1,30,3,"Curry Checken" },
  { 16.99,238,1,10,2,"Tide Detergent" },
  { 10.49,324,1,40,5,"Tide Liq. Pods" },
  { 10.99,491,1,50,5,"Tide Powder Det." },
  { 3.69,538,1,1,5,"Lays Chips S&V" },
  { 3.29,649,1,15,5,"Joe Org Chips" },
  { 1.79,731,1,100,10,"Allen's Apple Juice" },
  { 6.69,984,1,30,3,"Coke 12 Pack" },
  { 7.29,350,1,50,5,"Nestea 12 Pack" },
  { 6.49,835,1,20,2,"7up 12 pack" }
};
int GNoOfRecs = 20;
// tester prototypes
void searchTest();
void updateTest();
void addTest();
void addOrUpdateTest();
void adjustQtyTest();
/*********************************
Uncomment what you want to test below:
*****************************/
int main() {
   //printf("================================\n");
   //searchTest();
   //printf("================================\n");
   //updateTest();
   printf("================================\n");
   addTest();
   //printf("================================\n");
   //addOrUpdateTest();
   //printf("================================\n");
   //adjustQtyTest();
   printf("================================\n");
   return 0;
}
/***************************************************************
Tester Functions */

void searchTest() {
   printf("================Search Test:\n");
   printf("Enter 731: \n");
   search(GI, GNoOfRecs);
   printf("Enter 222: \n");
   search(GI, GNoOfRecs);
}
void updateTest() {
   struct Item I = { 11.11,111,1,11,1,"Ones!" };
   printf("================Update Test:\n");
   printf("Enter the following: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: n\n");
   updateItem(&I);
   printf("Unchanged Item Data:\n");
   displayItem(I, FORM);
   printf("Enter the following: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   updateItem(&I);
   printf("Updated Item: \n");
   displayItem(I, FORM);
}
void addTest() {
   printf("================Add Test:\n");
   printf("Total items in Storage: %d, Max no: %d\n", GNoOfRecs, MAX_ITEM_NO);
   printf("Enter the following: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: n\n");
   addItem(GI, &GNoOfRecs, 222); //n
   printf("Garbage here! Nothing is added, No of items in storage: %d\n", GNoOfRecs);
   displayItem(GI[GNoOfRecs], FORM);
   printf("Enter the following: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: y\n");
   addItem(GI, &GNoOfRecs, 222); //y
   printf("New item is added, No of items in storage: %d\n", GNoOfRecs);
   displayItem(GI[GNoOfRecs - 1], FORM);
   printf("Adding 333: \n");
   addItem(GI, &GNoOfRecs, 333);
}
void addOrUpdateTest() {
   GNoOfRecs = MAX_ITEM_NO;
   printf("================AddOrUpdate Test:\n");
   printf("Enter 731 and then \'n\':\n");
   addOrUpdateItem(GI, &GNoOfRecs); // n
   printf("Enter 731, \'y\' and then:\n"
      "       Name: Apple\n"
      "      Price: 1.80\n"
      "   Quantity: 101\n"
      "Minimum Qty: 11\n"
      "   Is Taxed: n\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   addOrUpdateItem(GI, &GNoOfRecs); // yes new data Yes
   printf("Updated Item: \n");
   displayItem(GI[16], FORM);
   printf("Enter 444: \n");
   addOrUpdateItem(GI, &GNoOfRecs); //n
}

void adjustQtyTest() {
   printf("================AdjustQty Test:\n");
   printf("Invalid SKU Test; Enter 444:\n");
   adjustQuantity(GI, GNoOfRecs, STOCK);
   printf("Aborting Entry test; Enter 649 and then 0:\n");
   adjustQuantity(GI, GNoOfRecs, CHECKOUT);
   printf("Checking out with low quantity warning; Enter 649 and then 12:\n");
   adjustQuantity(GI, GNoOfRecs, CHECKOUT);
   printf("Stocking; Enter 649 and then 50:\n");
   adjustQuantity(GI, GNoOfRecs, STOCK);
   displayItem(GI[15], FORM);
}
/* End test functions
*********************************************************************/

