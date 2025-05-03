//Enums are not like arrays or structs — they don’t store multiple values, just one value at a time.
//So the size of any enum is 4 bytes (the size of the int)

#include <stdio.h>

typedef enum {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    AND = '&',
    OR  = '|',
    NOT = '!'
} Operation;

int main() {
    int operand1, operand2;
    char op;
    printf("Enter first operand: ");
    scanf("%d", &operand1);
    printf("Enter second operand: ");
    scanf("%d", &operand2);
    printf("Enter operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &op);

    switch ((Operation)op) {
        case ADD:
            printf("Result: %d\n", operand1 + operand2);
            break;
        case SUB:
            printf("Result: %d\n", operand1 - operand2);
            break;
        case MUL:
            printf("Result: %d\n", operand1 * operand2);
            break;
        case DIV:
            if (operand2 != 0)
                printf("Result: %d\n", operand1 / operand2);
            else
                printf("Error: Division by zero\n");
            break;
        case AND:
            printf("Result: %d\n", operand1 & operand2);
            break;
        case OR:
            printf("Result: %d\n", operand1 | operand2);
            break;
        case NOT:
            printf("Result: !%d = %d, !%d = %d\n", operand1, !operand1, operand2, !operand2);
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}
