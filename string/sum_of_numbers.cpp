#include <stdio.h>
 
int main() {
    int n;
    scanf("%d ", &n);
 
    int sum = 0;
    while (n--) {
        char ch;
        scanf("%c", &ch);
        sum += ch - '0';
    }
    printf("%d\n", sum);

    return 0;
}