// Final Project Milestone 1
// Student defined values tester
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the UI tools
// and Application User Interface for submission.
//
/////////////////////////////////////////////////////////////////
#include <stdio.h>
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
// app interface
int yes(void);  
void GroceryInventorySystem(void); 
int menu(void);  


int main(void) {
   //int iVal;
   //double dVal;
   //welcome();

   // uncommnet each tester as you complete the develpment of that section:

   //// testing printTitle() 
   //printf("listing header and footer with grand total:\n");
   //printTitle();
   ////---------------------------------------------------------------


   //// Testing printFooter()  
   //
   //printFooter(1234.5678);
   //printf("listing header and footer without grand total:\n");
   //printTitle();
   //printFooter(-1);
   ////---------------------------------------------------------------

   //// Testing Pause() and flushKeyboard() 
   //pause();
   ////---------------------------------------------------------------


   //// Testing getInt() 
   //printf("Enter an integer: ");
   //iVal = getInt();
   //printf("You entered: %d\n", iVal);
   ////---------------------------------------------------------------


   //// Testing Get Int Limited 
   //printf("Enter an integer between 10 and 20: ");
   //iVal = getIntLimited(10, 20);
   //printf("Your entered %d\n", iVal);
   ////---------------------------------------------------------------


   //// Testing Get Double 
   //printf("Enter a floating point number: ");
   //dVal = getDouble();
   //printf("You entered: %0.2lf\n", dVal);
   ////---------------------------------------------------------------


   //// Tesing Get Double Limited 
   //printf("Enter a floating point number between 10.00 and 20.00: ");
   //dVal = getDoubleLimited(10.0, 20.0);
   //printf("You entered: %0.2lf\n", dVal);
   ////---------------------------------------------------------------



   // testing the App interface
   GroceryInventorySystem();
   //---------------------------------------------------------------

   printf("End of tester program for milestone one!\n");
   return 0;
}

