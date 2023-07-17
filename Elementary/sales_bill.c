#include <stdio.h>

int main()
{
    // Input date of purchase, name of the buyer, price, and quantity of each item
    int date, month, year;
    char buyerName[100];
    float batPrice, wicketPrice, ballPrice;
    int batQuantity, wicketQuantity, ballQuantity;

    printf("Enter date of purchase (DD MM YYYY): ");
    scanf("%d %d %d", &date, &month, &year);

    printf("Enter name of the buyer: ");
    scanf(" %[^\n]", buyerName);

    printf("Enter price of each bat: ");
    scanf("%f", &batPrice);

    printf("Enter quantity of bats purchased: ");
    scanf("%d", &batQuantity);

    printf("Enter price of each wicket: ");
    scanf("%f", &wicketPrice);

    printf("Enter quantity of wickets purchased: ");
    scanf("%d", &wicketQuantity);

    printf("Enter price of each ball: ");
    scanf("%f", &ballPrice);

    printf("Enter quantity of balls purchased: ");
    scanf("%d", &ballQuantity);

    // Calculate the total sale amount
    float totalAmount = (batPrice * batQuantity) + (wicketPrice * wicketQuantity) + (ballPrice * ballQuantity);

    // Calculate the sales tax based on the total sale amount
    float salesTax;
    if (totalAmount > 300000)
    {
        salesTax = totalAmount * 0.175;
    }
    else if (totalAmount > 150000)
    {
        salesTax = totalAmount * 0.125;
    }
    else
    {
        salesTax = totalAmount * 0.07;
    }

    // Calculate the grand total
    float grandTotal = totalAmount + salesTax;

    // Display the sales bill
    printf("\nSales Bill:\n");
    printf("Date of Purchase: %02d/%02d/%04d\n", date, month, year);
    printf("Buyer Name: %s\n", buyerName);
    printf("--------------------------------------------------\n");
    printf("Item\t\tPrice\tQuantity\tTotal\n");
    printf("--------------------------------------------------\n");
    printf("Bats\t\t%.2f\t%d\t\t%.2f\n", batPrice, batQuantity, batPrice * batQuantity);
    printf("Wickets\t\t%.2f\t%d\t\t%.2f\n", wicketPrice, wicketQuantity, wicketPrice * wicketQuantity);
    printf("Balls\t\t%.2f\t%d\t\t%.2f\n", ballPrice, ballQuantity, ballPrice * ballQuantity);
    printf("--------------------------------------------------\n");
    printf("Total Amount:\t\t\t\t%.2f\n", totalAmount);
    printf("Sales Tax:\t\t\t\t%.2f\n", salesTax);
    printf("--------------------------------------------------\n");
    printf("Grand Total:\t\t\t\t%.2f\n", grandTotal);

    return 0;
}
