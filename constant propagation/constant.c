#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct statement {
    char lhs;
    char op1;
    char op2;
    char opr; // operator (+, -, *, /)
    int value;
    int isConst;
};

int main() {
    int n,m;
    printf("Enter number of statements: ");
    scanf("%d", &n);

    struct statement s[10];

    // Input statements like:  a = b + c  OR  a = 5 + 2
    for (int i = 0; i < n; i++) {
        printf("Enter statement %d (e.g., a = b + c): ", i + 1);
        scanf(" %c = %c %c %c", &s[i].lhs, &s[i].op1, &s[i].opr, &s[i].op2);

        s[i].isConst = 0;
    }
do{
    // Pass 1: detect constant expressions
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i].op1) && isdigit(s[i].op2)) {
            int x = s[i].op1 - '0';
            int y = s[i].op2 - '0';
            switch (s[i].opr) {
                case '+': s[i].value = x + y; break;
                case '-': s[i].value = x - y; break;
                case '*': s[i].value = x * y; break;
                case '/': s[i].value = x / y; break;
            }
            s[i].isConst = 1;
        }
    }

    // Pass 2: replace constants in later statements
    for(int k=0; k<n;k++){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].isConst) {
                if (s[j].op1 == s[i].lhs) {
                    s[j].op1 = s[i].value + '0';
                }
                if (s[j].op2 == s[i].lhs) {
                    s[j].op2 = s[i].value + '0';
                }
            }
        }
    }}

    printf("\nAfter Constant Propagation:\n");
    for (int i = 0; i < n; i++) {
        if (s[i].isConst)
            printf("%c = %d\n", s[i].lhs, s[i].value);
        else
            printf("%c = %c %c %c\n", s[i].lhs, s[i].op1, s[i].opr, s[i].op2);
    }
    printf("Press 1 for stop , press  0 to continue ");
scanf("%d",&m);
}
    while(m==0);
   
   
    return 0;

}
