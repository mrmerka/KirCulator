#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Welcome to KirCulator 1.0\n");
    double num1, num2, result;
    char operation;

    printf("Please enter the operation: ");
    scanf(" %c", &operation); // Пробел перед %c — хорошая привычка

    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("The result is: %lf\n", result);
            break; // Останавливаем выполнение здесь

        case '-':
            result = num1 - num2;
            printf("The result is: %lf\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("The result is: %lf\n", result);
            break;

        case '/':
            if (num2 != 0) { // Исправил условие: если НЕ ноль
                result = num1 / num2;
                printf("The result is: %lf\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;

        default:
            printf("Your text is bullshit\n");
    }
    system("pause > nul");
    return 0;
}