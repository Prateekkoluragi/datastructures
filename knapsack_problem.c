#include<stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    // Build the K[][] array in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main() {
    int i,j;
    int val[100], wt[100];
    int W, n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the values of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the maximum weight constraint: ");
    scanf("%d", &W);

    int maxVal = knapsack(W, wt, val, n);
    printf("Maximum value: %d\n", maxVal);

    return 0;
}
