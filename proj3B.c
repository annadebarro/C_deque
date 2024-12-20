#include "proj3B_deque.h"
#define MAX 20

int main() {
    Deque *longDeque = createDeque();
    Deque *strDeque = createDeque();

    char input[MAX];
    do{
        printf("Please enter an integer or a string (empty to exit): ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	printf("\n");

	if(strlen(input) > 0) {
	    char *endptr;
	    long num = strtol(input, &endptr, 10);
	    if(*endptr == '\0') {
	        // Integer
		if(longDeque->count % 2 == 0) {
		    insertFront(longDeque, &num, sizeof(long));
		}
		else {
		    insertBack(longDeque, &num, sizeof(long));
		}
		printf("You entered the number: %ld\n", num);
	    }
	    else {
	        // String
		if(strDeque->count % 2 == 0) {
		    insertFront(strDeque, input, strlen(input) + 1);
		}
		else {
		    insertBack(strDeque, input, strlen(input) + 1);
		}
		printf("You entered the string: \"%s\"\n", input);
	    }
	}
    } while(strlen(input) > 0);

    printf("\nPrinting string deque\n");
    printDeque(strDeque, printStr);

    printf("\nPrinting long deque\n");
    printDeque(longDeque, printLong);

    printf("\nRemoving string deque data using count\n");
    while(strDeque->count > 0) {
        if(strDeque->count % 2 == 0) {
	    char removedStr[MAX];
	    removeBack(strDeque, removedStr, sizeof(removedStr));
	    printf("Removing %s\n", removedStr);
	}
	else {
	    char removedStr[MAX];
	    removeFront(strDeque, removedStr, sizeof(removedStr));
	    printf("Removing %s\n", removedStr);
	}
    }

    printf("\nRemoving long deque data using count\n");
    while(longDeque->count > 0) {
        if(longDeque->count % 2 == 0) {
	    long removedNum;
	    removeBack(longDeque, &removedNum, sizeof(long));
	    printf("Removing %ld\n", removedNum);
	}
	else {
	    long removedNum;
	    removeFront(longDeque, &removedNum, sizeof(long));
	    printf("Removing %ld\n", removedNum);
	}
    }

    freeDeque(strDeque);
    freeDeque(longDeque);

    return 0;
}
