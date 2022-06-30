#include <stdio.h>

int binsearch(int value, int array[], int length);

int main(void)
{
    int set[] = {1, 2, 4, 5, 8, 9, 12};
    printf("%i\n", binsearch(2, set, 7));
    return 0;
}

int binsearch(int value, int array[], int length)
{
    int min = 0;
    int max = length - 1;
    int mid;

    while (min < max)
    {
        mid = ((min + max) / 2) + 1;
        if (value >= array[mid]) // When value is equal to mid value, set min to mid (as mid will be set to the max val eventually from the +1)
        {
            min = mid; // The loop will terminate once the min is equal to the mid, which is equal to the max
        }
        else
        {
            max = mid - 1;
        }
    }
    if (array[mid] == value)
    {
        return mid;
    }
    return -1;
}