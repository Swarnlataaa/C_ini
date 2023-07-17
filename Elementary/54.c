#include <stdio.h>

int main()
{
    char salesmanName[100];
    double totalSales, commissionRate, commissionEarned;

    // Input salesman name and total sales
    printf("Enter the name of the salesman: ");
    fgets(salesmanName, sizeof(salesmanName), stdin);

    printf("Enter the total sales made: ");
    scanf("%lf", &totalSales);

    // Calculate commission based on total sales
    if (totalSales >= 1 && totalSales <= 1000)
    {
        commissionRate = 0.03;
    }
    else if (totalSales >= 1001 && totalSales <= 4000)
    {
        commissionRate = 0.08;
    }
    else if (totalSales >= 4001 && totalSales <= 6000)
    {
        commissionRate = 0.12;
    }
    else if (totalSales >= 6001)
    {
        commissionRate = 0.15;
    }
    else
    {
        printf("Invalid total sales\n");
        return 0;
    }

    commissionEarned = totalSales * commissionRate;

    // Print commission earned
    printf("Salesman: %s", salesmanName);
    printf("Total Sales: %.2lf\n", totalSales);
    printf("Commission Rate: %.2lf%%\n", commissionRate * 100);
    printf("Commission Earned: %.2lf\n", commissionEarned);

    return 0;
}
