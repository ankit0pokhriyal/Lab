// Program to find the smallest number Greater than the given number
// and has the same set of digit as given number.

#include <stdio.h>

void NextGreatest(int number[], int n) {
    int i = n - 1;
	
	// Start from the rightmost digit and find the first
	// digit that is smaller than the digit next to it.
    while (i > 0 && number[i] <= number[i - 1]) {
        i--;
    }
	
	// If no such digit found, then all numbers are in
	// descending order, and no greater number is possible.
    if (i == 0 && number[i] <= number[i - 1]) {
        printf("Next number not possible\n");
        return;
    }
	
	// Find the smallest digit on the right side of
	// (i-1)'th digit that is greater than number[i-1].
    int x = number[i - 1];
    int smallest = i;
    for (int j = i + 1; j < n; j++) {
        if (number[j] > x && number[j] < number[smallest]) {
            smallest = j;
        }
    }
	
	// Swap the above found smallest digit with (i-1)'th.
    int temp = number[smallest];
    number[smallest] = number[i - 1];
    number[i - 1] = temp;
	
	// Convert the list up to i-1 into a number.
    int result = 0;
    for (int j = 0; j < i; j++) {
        result = result * 10 + number[j];
    }
	
	// Sort the digits after i-1 in ascending order.
    for (int j = i; j < n - 1; j++) {
        for (int k = i; k < n - 1 - j + i; k++) {
            if (number[k] > number[k + 1]) {
                temp = number[k];
                number[k] = number[k + 1];
                number[k + 1] = temp;
            }
        }
    }
	
	// Convert the remaining sorted digits into a number.
    for (int j = i; j < n; j++) {
        result = result * 10 + number[j];
    }
	
    printf("Next number with the same set of digits is %d\n", result);
}

int main() {
    char digits[] = "25486";
    int n = sizeof(digits) / sizeof(digits[0]) - 1;
    int number[n];
	
	// Convert the character array into an integer array.
    for (int i = 0; i < n; i++) {
        number[i] = digits[i] - '0';
    }
	
    NextGreatest(number, n);
	
    return 0;
}
