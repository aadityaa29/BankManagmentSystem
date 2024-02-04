/*
This is bank management project developed in C programming to language.
It uses the basic C features like file handling, structure and other I/O functionalities.
Developed by Aditya Pachouri, Rishabh Kapur
*/

// TO RUN THIS PROGRAM ENTER PASSWORD= "random"


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


/*Creating variables*/
int i;
int j;
int main_exit;
void menu();

/*Main structure to create store date, name, account number, address, citizenship,
phone number, accont type (namely Savings, Current) amount to be stored (in Rs).*/

struct date
{
    int month;
    int day;
    int year;
};
struct
{

    char name[60];
    int acc_no;
    int age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

/*Function float to calculate and return interest rate*/

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

/*Function new_acc to open a new account with various details and
store them in a file named record.dat*/

void new_acc()

{
    int choice;
    FILE *ptr; //Creating file pointer

    //Opening file record.dat
    ptr = fopen("record.dat", "a+");

account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }

    add.acc_no = check.acc_no;
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");

add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

/*Function view_list is to display the details of vaious customers of bank
stored in record.dat file until now.*/

void view_list()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}
/*Function edit to edit the data of users stored */

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address:");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)

            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
               
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("record.dat", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number:");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {

                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("cls");
        menu();
    }

    else
    {

        system("cls");
        close();
    }
}

// Function to calculate monthly payment
double calculateMonthlyPayment(double principal, double annualInterestRate, int loanTermYears) {
    double monthlyInterestRate = annualInterestRate / 12.0 / 100.0;
    int numberOfPayments = loanTermYears * 12;

    // Monthly payment formula
    double monthlyPayment = principal * (monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments)) /
                            (pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return monthlyPayment;
}

// Function to display the amortization schedule
void displayAmortizationSchedule(double principal, double annualInterestRate, int loanTermYears) {
    double monthlyInterestRate = annualInterestRate / 12.0 / 100.0;
    int numberOfPayments = loanTermYears * 12;

    double balance = principal;
    double monthlyPayment = calculateMonthlyPayment(principal, annualInterestRate, loanTermYears);

    printf("\nAmortization Schedule:\n");
    printf("%-15s%-15s%-15s%-15s\n", "Payment#", "Payment", "Interest", "Balance");

    for (int i = 1; i <= numberOfPayments; ++i) {
        double interestPayment = balance * monthlyInterestRate;
        double principalPayment = monthlyPayment - interestPayment;

        balance -= principalPayment;

        printf("%-15d$%-14.2f$%-14.2f$%.2f\n", i, monthlyPayment, interestPayment, balance);

        if (balance <= 0) {
            break; // Loan paid off
        }
    }
}

// Function to calculate the total cost of the loan
double calculateTotalCost(double monthlyPayment, int numberOfPayments) {
    return monthlyPayment * numberOfPayments;
}

// Function for input validation
double getValidDoubleInput(const char* prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1 && value > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive number.\n");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }
    return value;
}

// Function for input validation
int getValidIntegerInput(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer.\n");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }
    return value;
}

int loan_main() {
    double principal1, annualInterestRate1;
    int loanTermYears1;
    double principal2, annualInterestRate2;
    int loanTermYears2;

    // Input for the first loan
    printf("Enter details for the first loan:\n");
    principal1 = getValidDoubleInput("Loan Amount: ");
    annualInterestRate1 = getValidDoubleInput("Annual Interest Rate (in percentage): ");
    loanTermYears1 = getValidIntegerInput("Loan Term (in years): ");

    // Input for the second loan
    printf("\nEnter details for the second loan:\n");
    principal2 = getValidDoubleInput("Loan Amount: ");
    annualInterestRate2 = getValidDoubleInput("Annual Interest Rate (in percentage): ");
    loanTermYears2 = getValidIntegerInput("Loan Term (in years): ");

    // Calculate and display the monthly payment for each loan
    printf("\nMonthly Payment for Loan 1: $%.2f\n", calculateMonthlyPayment(principal1, annualInterestRate1, loanTermYears1));
    printf("Monthly Payment for Loan 2: $%.2f\n", calculateMonthlyPayment(principal2, annualInterestRate2, loanTermYears2));

    // Display the amortization schedule for the first loan
    printf("\nAmortization Schedule for Loan 1:\n");
    displayAmortizationSchedule(principal1, annualInterestRate1, loanTermYears1);

    // Display the amortization schedule for the second loan
    printf("\nAmortization Schedule for Loan 2:\n");
    displayAmortizationSchedule(principal2, annualInterestRate2, loanTermYears2);

    // Calculate and display the total cost for each loan
    printf("\nTotal Cost of Loan 1: $%.2f\n", calculateTotalCost(calculateMonthlyPayment(principal1, annualInterestRate1, loanTermYears1), loanTermYears1 * 12));
    printf("Total Cost of Loan 2: $%.2f\n", calculateTotalCost(calculateMonthlyPayment(principal2, annualInterestRate2, loanTermYears2), loanTermYears2 * 12));

    // To go to the main menu of bank management
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else
        close();
    
    return 0;
}

//####################### GAME ########################

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to play the guessing game
int playGuessingGame(int lowerBound, int upperBound, int prizeMultiplier) {
    int secretNumber = generateRandomNumber(lowerBound, upperBound);
    int guess;
    int attempts = 0;

    printf("\nWelcome to the Guessing Game!\n");
    printf("I have selected a number between %d and %d. Try to guess it!\n", lowerBound, upperBound);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            printf("You win $%d!\n", attempts * prizeMultiplier);
        }
    } while (guess != secretNumber);

    return attempts;
}

// Function to display available offers
void displayOffers() {
    printf("\nCheck out these amazing offers:\n");
    printf("a. Free trial for a week!\n");
    printf("b. Double cash prize on the next game!\n");
    printf("c. Skip to the next level instantly!\n");
    printf("Select an offer (a, b, or c): ");
}

int game_menu() {
    srand(time(NULL)); // Seed for random number generation

    int userChoice;
    int totalCashPrize = 0;
    int gameScore = 0;

    printf("Welcome to the Game Center!\n");

    do {
        printf("\n1. Play Guessing Game\n");
        printf("2. Check Offers\n");
        printf("3. Quit\n");
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                int level = gameScore / 10 + 1; // Increase difficulty every 10 points
                int upperBound = level * 50;
                int prizeMultiplier = level;

                printf("\n----- Level %d -----", level);
                int attempts = playGuessingGame(1, upperBound, prizeMultiplier);
                totalCashPrize += attempts * prizeMultiplier - attempts;
                gameScore += attempts;

                printf("Your total cash prize: $%d\n", totalCashPrize);
                printf("Your current score: %d\n", gameScore);
                break;
            }
            case 2: {
                displayOffers();
                char offerChoice;
                scanf(" %c", &offerChoice);

                switch (offerChoice) {
                    case 'a':
                        printf("Enjoy your free trial!\n");
                        break;
                    case 'b':
                        printf("Congratulations! You've unlocked a double cash prize on the next game.\n");
                        break;
                    case 'c':
                        printf("Level up! You've skipped to the next level instantly.\n");
                        gameScore += 10; // Increment score by 10
                        break;
                    default:
                        printf("Invalid offer choice.\n");
                        break;
                }
                break;
            }
            case 3:
                printf("\nThank you for playing!\n");
                printf("Your final cash prize: $%d\n", totalCashPrize);
                printf("Your final score: %d\n", gameScore);
                printf("\nEnter 1 to go to the main menu and 0 to exit:");
                scanf("%d", &main_exit);
                system("cls");
                if (main_exit == 1)
                    menu();
                else
                    close();
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    } while (userChoice != 3);

    return 0;
}

// Structure to represent a support ticket
struct Ticket {
    int ticketNumber;
    char customerName[50];
    char issue[200];
    int isOpen; // 1 if open, 0 if closed
};

// Function to create a new support ticket
struct Ticket createTicket(int ticketNumber, const char *customerName, const char *issue) {
    struct Ticket newTicket;
    newTicket.ticketNumber = ticketNumber;
    strcpy(newTicket.customerName, customerName);
    strcpy(newTicket.issue, issue);
    newTicket.isOpen = 1; // Ticket is initially open
    return newTicket;
}

// Function to display a support ticket
void displayTicket(const struct Ticket *ticket) {
    printf("Ticket Number: %d\n", ticket->ticketNumber);
    printf("Customer Name: %s\n", ticket->customerName);
    printf("Issue: %s\n", ticket->issue);
    printf("Status: %s\n", ticket->isOpen ? "Open" : "Closed");
    printf("\n");
}

// Function to close a support ticket
void closeTicket(struct Ticket *ticket) {
    if (ticket->isOpen) {
        ticket->isOpen = 0;
        printf("Ticket closed successfully!\n");
    } else {
        printf("Ticket is already closed.\n");
    }
}

int customer() {
    // Array to store support tickets
    struct Ticket tickets[100];
    int ticketCount = 0;

    int choice;
    do {
        // Display menu
        printf("Customer Support System\n");
        printf("1. Create Ticket\n");
        printf("2. View Open Tickets\n");
        printf("3. View Closed Tickets\n");
        printf("4. Close a Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a new ticket
                if (ticketCount < 100) {
                    int ticketNumber;
                    char customerName[50];
                    char issue[200];

                    printf("Enter Ticket Number: ");
                    scanf("%d", &ticketNumber);
                    printf("Enter Customer Name: ");
                    scanf("%s", customerName);
                    printf("Describe the Issue: ");
                    scanf(" %[^\n]s", issue); // Allowing spaces in the issue description

                    tickets[ticketCount++] = createTicket(ticketNumber, customerName, issue);
                    printf("Ticket created successfully!\n\n");
                } else {
                    printf("Ticket limit reached. Cannot create more tickets.\n\n");
                }
                break;

            case 2:
                // View all open tickets
                if (ticketCount!=0)
                {
                    printf("Open Tickets:\n");
                    for (int i = 0; i < ticketCount; i++) {
                        if (tickets[i].isOpen) {
                            displayTicket(&tickets[i]);
                        }
                    }
                }
                else
                {
                    printf("\n<<There are no open tickets currently>>\n");
                }
                break;

            case 3:
                // View all closed tickets
                printf("Closed Tickets:\n");
                for (int i = 0; i < ticketCount; i++) {
                    if (!tickets[i].isOpen) {
                        displayTicket(&tickets[i]);
                    }
                }
                break;

            case 4:
                // Close a ticket
                if (ticketCount > 0) {
                    int ticketToClose;
                    printf("Enter the Ticket Number to Close: ");
                    scanf("%d", &ticketToClose);

                    int found = 0;
                    for (int i = 0; i < ticketCount; i++) {
                        if (tickets[i].ticketNumber == ticketToClose) {
                            closeTicket(&tickets[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Ticket not found.\n");
                    }
                } else {
                    printf("No tickets available to close.\n");
                }
                break;

            case 5:
                // Exit the program
                printf("Exiting Customer Support System. Goodbye!\n");
                printf("\nEnter 1 to go to the main menu and 0 to exit:");
                scanf("%d", &main_exit);
                system("cls");
                if (main_exit == 1)
                    menu();
                else
                    close();
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void close(void)
{
    printf("\n\n\n\nThis C project is developed by- Aditya Pachouri,Rishabh Kapur");
}

void menu(void)
{
    int choice;
    system("cls");
    system("color 1");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n");
    printf("\n\n\t\t2.Update information of existing account\n");
    printf("\n\n\t\t3.For transactions\n");
    printf("\n\n\t\t4.Check the details of existing account\n");
    printf("\n\n\t\t5.Removing existing account\n");
    printf("\n\n\t\t6.View customer's list\n");
    printf("\n\n\t\t7.Loan\n");
    printf("\n\n\t\t8.Game and Offers\n");
    printf("\n\n\t\t9.Customer Support\n");
    printf("\n\n\t\t10.Exit\n");
    printf("Enter your choice: \n");

    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        loan_main();
        break;
    case 8:
        game_menu();
        break;
    case 9:
        customer();
        break;
    case 10:
        close();
        ;
    }
}


int main()
{
    char pass[10], password[10] = "random";
    int i = 0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s", pass);
    /*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {
            printf("*");
            pass[i]=getch();
            i++;
        }
    }while (pass[i]!=13);
    pass[10]='\0';*/
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
    }
    return 0;
}