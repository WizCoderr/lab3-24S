#include <stdio.h>

void printBinary(short int val) {
    for (int i = 15; i >= 0; i--) {
        putchar((val & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {
    short int flags; 
    char c;
    printf("Enter the flag: ");
    scanf("%d",&flags);
    printf("Initial flags: ");
    printBinary(flags);

    printf("Enter characters (Ctrl+D to end input):\n");
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            flags |= 1 << (c - '0'); 
        }
    }

    printf("Final flags: ");
    printBinary(flags);

    for (int i = 0; i < 10; i++) {
        printf("%d: %s\n", i, (flags & (1 << i)) ? "Yes" : "No");
    }

    return 0;
}
