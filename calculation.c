#include <stdio.h>
#include <math.h>
#define length 10

void viewMeasurements(int measurements[], int count);
int enterMeasurements(int measurements[], int count);
void computeStats(int measurements[], int count);
void normalizeValues(int measurements[], int normalized[], int count);
int findMax(int measurements[], int count);
int findMin(int measurements[], int count);
float computeAverage(int measurements[], int count);

int main()
{
    int measurements[length] = {0};
    int count = 0;
    char choice;
    printf("Measurement tool 2.0\n");

    do
    {
        printf("VECRQ? ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'v':
        case 'V':
            viewMeasurements(measurements, count);
            break;
        case 'e':
        case 'E':
            count = enterMeasurements(measurements, count);
            break;
        case 'c':
        case 'C':
            if (count > 0)
            {
                computeStats(measurements, count);
            }
            else
            {
                printf("No measurements\n");
            }
            break;
        case 'r':
        case 'R':
            count = 0;
            printf("All measurements have been reset.\n");
            break;
        case 'q':
        case 'Q':
            printf("Exit Measurement tool\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 'q');
    return 0;
}

void viewMeasurements(int measurements[], int count)
{
    if (count == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        printf("[ ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", measurements[i]);
        }
        printf("]\n");
    }
}

int enterMeasurements(int measurements[], int count)
{
    int newMeasurement;
    char input;

    while (count < length)
    {
        printf("Enter measurement #%d (or q to quit): ", count + 1);
        if (scanf("%d", &newMeasurement) == 1)
        {
            measurements[count] = newMeasurement;
            count++;
        }
        else
        {
            scanf(" %c", &input);
            if (input == 'q')
            {
                break;
            }
            else
            {
                printf("Invalid input. Please enter an integer or 'q' to quit.\n");
            }
        }
    }

    if (count == length)
    {
        printf("Maximum measurements reached (10).\n");
    }
    return count;
}

void computeStats(int measurements[], int count)
{
    int max = findMax(measurements, count);
    int min = findMin(measurements, count);
    float average = computeAverage(measurements, count);
    int normalized[length];

    normalizeValues(measurements, normalized, count);

    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
    printf("Average value: %.2f\n", average);
    printf("Normalized values: [ ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", normalized[i]);
    }
    printf("]\n");
}

void normalizeValues(int measurements[], int normalized[], int count)
{
    float average = computeAverage(measurements, count);
    int roundedAvg = round(average);

    for (int i = 0; i < count; i++)
    {
        normalized[i] = measurements[i] - roundedAvg;
    }
}

int findMax(int measurements[], int count)
{
    int max = measurements[0];
    for (int i = 1; i < count; i++)
    {
        if (measurements[i] > max)
        {
            max = measurements[i];
        }
    }
    return max;
}

int findMin(int measurements[], int count)
{
    int min = measurements[0];
    for (int i = 1; i < count; i++)
    {
        if (measurements[i] < min)
        {
            min = measurements[i];
        }
    }
    return min;
}

float computeAverage(int measurements[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += measurements[i];
    }
    return (float)sum / count;
}