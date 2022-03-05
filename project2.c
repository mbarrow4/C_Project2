/******************************************************************************

* Program Name: COP 2220 Project 2
* Description: A program that calculates a mortgage loan
* Author: Monica Barrow (N01505878)
* Due Date: October 25th, 2021

*******************************************************************************/

//Pre-processor derectives
#include <stdio.h>
#include <math.h>

// Defined constants
#define MIN_YEARS 2
#define MAX_YEARS 40
#define MIN_INT_RATE 1
#define MAX_INT_RATE 20
#define MIN_TOTAL 5000
#define MAX_TOTAL 2000000

// Function prototypes
int get_LoanYears();
double get_IntRate();
int get_Total();
double calcLoan(double int_Rate, int loanTotal, double loanPayments);

int terminateProgram = 0;

int main() {
    do {
printf("********************AMORTIZATION OF A MORTGAGE LOAN********************\n\n\n");

    // Get years for the loan
   int loan_term = get_LoanYears() * 12;
        if (terminateProgram == 1) {
            break;}

    // Get interest rate of loan (annual)
    double loan_rate = get_IntRate();
        if (terminateProgram == 1) {
            break;} 

    // Get amount of loan
        int loan_amt = get_Total();
        if (terminateProgram == 1) {
            break;}

    // Calculate and print amortization table
        calcLoan(loan_rate, loan_amt, loan_term);

    } while (!0);
        printf("********************PROGRAM ENDED.********************");
    return 0;
}

/*************************get_LoanYears function*******************************/
//get_LoanYears function that returns loanYears between 2-40 or quits
//function does NOT take any parameters because it  is input from the user
int get_LoanYears(void) {
    int loanYears = 0;
    //User Prompt and input for term of loan years (2-40) integers.
    printf("Enter in the number of years (2-40 years) for this loan or '0' to quit: ");
    scanf("%d", &loanYears);

    // If input is equal to '0' the program will quit.
    if (loanYears == 0) {
        terminateProgram = 1;} 
    // If input is negative the program will give a warning.
    else if (loanYears < MIN_YEARS) {
        printf("TOO LOW! Loan term must be HIGHER than 2 years.\n\n");
        get_LoanYears();}
    
    // If input is more than 40 the program will give a warning.  
    else if (loanYears > MAX_YEARS) {
        printf("TOO HIGH! Loan must LOWER than 40 years.\n\n");
        get_LoanYears();
    }
    return loanYears; }
/*********************End of get_LoanYears function****************************/






/*************************get_IntRate function*******************************/
//get_IntRate function that returns intRate (interest rate) between 1-20 or quits
//function does NOT take any parameters because it  is input from the user

double get_IntRate(void) {
    double intRate = 0;
    //User Prompt and input for interest rate (1-20) of loan (double)
    printf("Enter the interest rate (1-20) for this loan or '0' to quit: ");
    scanf("%lf", &intRate);

    // If input is equal to '0' the program will quit.
    if (intRate == 0) {
        terminateProgram = 1;} 
    
    // If input is negative the program will give a warning.
    else if (intRate < MIN_INT_RATE) {
        printf("TOO LOW! Loan interest rate must be HIGHER than 1 percent.\n\n");
        get_IntRate();}
        
     // If input is more than 25 the program will give a warning. 
    else if (intRate > MAX_INT_RATE) {
        printf("TOO HIGH! Loan interest rate must be LOWER than 20 percent.\n\n");
        get_IntRate();}
        
    return (intRate / 1200); }
    
/*********************End of get_IntRate function****************************/





/*****************************get_Total function*******************************/
//get_Total function that returns loanTotal between 5 thousand to 2 million or quits
//function does NOT take any parameters because it is input from the user


int get_Total() {
    int loanTotal = 0;
    //User Prompt and input for total loan amount (5k- 2M) in integers.
    printf("Enter in the total amount of the loan (5 thousand to 2 million) or '0' to quit: ");
    scanf("%d", &loanTotal);

    // If input is equal to '0' the program will quit.
    if (loanTotal == 0) {
        terminateProgram = 1;} 
    
    else if (loanTotal < MIN_TOTAL) {
        printf("TOO LOW! Loan total must be HIGHER than 5 thousand.\n\n");
        get_Total();}
    
    else if (loanTotal > MAX_TOTAL) {
        printf("TOO HIGH! Loan total must be LOWER than 2 million.\n\n");
        get_Total();}
         
    return loanTotal;}
    
    
/*****************************End of get_Total function*******************************/


    
    
/*****************************calcLoan function*******************************/
//calcLoan function calculates the loan
//function's paratments are: Interest rate, amount of loan and monthly payments

double calcLoan(double int_Rate, int loanTotal, double loanPayments) {
    int month = 1;
    double balance = loanTotal, payment, interestMonth, principle;
    double power = 1 + int_Rate;
    payment = loanTotal * (int_Rate + (int_Rate / (pow(power, loanPayments)-1)));
    double total_Interest;
    double total_Principle;

    printf("Mnt\tInt\tPrinciple\t Balance\n");
    for (double i = loanPayments; i > 0; i--) {
        balance = balance - principle; 
        interestMonth = int_Rate * balance; 
        principle = payment - interestMonth; 
        total_Principle = total_Principle + principle; 
        total_Interest = total_Interest + interestMonth; 
        printf("%3d  \t%.2lf   %.2lf\t\t %.2lf\n", month, interestMonth, principle, balance);
        month++;}


    printf("Total interest paid: \t$%.2lf\n", total_Interest);
    printf("Total principle paid: \t$%.2lf\n", total_Principle); 
    printf("Total cost of loan: \t$%.2lf\n\n\n", loanTotal + total_Interest);
    
    //Restarts program
    int main();
    return 0;
}