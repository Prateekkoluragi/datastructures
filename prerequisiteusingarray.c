//Name:Prateek Koluragi
//roll no 311
//modified on 4/05/2023

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate N random numbers between P and Q and write them to file
void generateNumbers(int N, int P, int Q) {
    FILE *fptr;
    int i;
    fptr = fopen("Input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    srand(time(0));
    for (i = 0; i < N; i++) {
        int num = (rand() % (Q - P + 1)) + P;
        fprintf(fptr, "%d ", num);
    }

    fclose(fptr);
}

// Function to swap two numbers
void swap(int *xp, int *yp)
{
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int n)
{
    int i,j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
// Function to perform selection sort on the array
void selectionSort(int arr[], int n)
{
    int i,j,min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
// Function to perform heap sort on the array
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
    int n,P,Q,x,f,arr[500],i=0;
    printf("Enter the lower and upper limit\n");
    scanf("%d %d",&P,&Q);
    printf("Enter number of numbers to be genrated\n");
    scanf("%d",&n);
    generateNumbers(n,P,Q);
    FILE *fptr;
    fptr = fopen("Input.txt", "r");
    while(!feof(fptr))
    {
      fscanf(fptr,"%d ",arr[i]);
      i++;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("enter choice\n");
    printf("1.bubble sort\n2.selection sort\n3.heap sort\n4.merge sort\n");
    scanf("%d",&x);
    clock_t t;
    t=clock();
    switch(x)
    {
        case 1: bubbleSort(arr,n);
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                break;
        case 2: selectionSort(arr,n);
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                break;
        case 3: heapSort(arr,n);
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                break;
        case 4: mergeSort(arr,0,n);
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                break;
    }
    t=clock()-t;
    float time_taken=((float)t)/CLOCKS_PER_SEC;
    printf("\nTime taken for this method %f",time_taken);

}
