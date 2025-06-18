#include <stdio.h>

int main() {
    printf("Enter something (you may need to press Enter):\n");
    scanf("%c",'\n');  // Waits for a newline (press Enter)
    printf("Done.\n");
    return 0;
}