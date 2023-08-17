#include <stdio.h>

#define MAX_ITEMS 100

typedef struct
{
    int weight;
    int value;
} Item;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int knapsackCapacity, Item items[], int numItems)
{
    int dp[numItems + 1][knapsackCapacity + 1];

    for (int i = 0; i <= numItems; i++)
    {
        for (int w = 0; w <= knapsackCapacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[numItems][knapsackCapacity];
}

int main()
{
    int numItems, knapsackCapacity;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    Item items[MAX_ITEMS];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &knapsackCapacity);

    int maxValue = knapsack(knapsackCapacity, items, numItems);
    printf("Maximum value: %d\n", maxValue);

    return 0;
}
