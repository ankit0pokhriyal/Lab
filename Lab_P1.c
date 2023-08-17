// Program to find the smallest number Greater than the given number
// and has the same set of digit as given number.

#include <stdio.h>

void NextGreatest(int number[], int n) {
    int i = n - 1;
	
    while (i > 0 && number[i] <= number[i - 1]) {
        i--;
    }
	
    if (i == 0 ) {
        printf("Next number not possible\n");
        return;
    }
	
    int x = number[i - 1];
    int smallest = i;
    for (int j = i + 1; j < n; j++) {
        if (number[j] > x && number[j] < number[smallest]) {
            smallest = j;
        }
    }
	
    int temp = number[smallest];
    number[smallest] = number[i - 1];
    number[i - 1] = temp;
	
    int result = 0;
    for (int j = 0; j < i; j++) {
        result = result * 10 + number[j];
    }
	
	
    for (int j = i; j < n - 1; j++) {
        for (int k = i; k < n - 1 - j + i; k++) {
            if (number[k] > number[k + 1]) {
                temp = number[k];
                number[k] = number[k + 1];
                number[k + 1] = temp;
            }
        }
    }
	
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
