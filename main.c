#include <stdio.h>
#include <stdlib.h>

// --- БЛОК КРОССПЛАТФОРМЕННОСТИ ---
#ifdef _WIN32
    #include <windows.h>
    // Определяем флаг для включения ANSI-кодов, если его нет в старых заголовках
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
#endif

// Цветовые коды (ANSI Escape Codes)
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

void init_system() {
    #ifdef _WIN32
        // 1. Ставим заголовок окна (только для Windows)
        SetConsoleTitle("KirCulator 1.0 - Professional Edition");

        // 2. Включаем поддержку цветов (тот самый Win32 API)
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);

        // 3. Ставим кодировку UTF-8 для корректного вывода
        SetConsoleOutputCP(65001);
    #else
        // Для Linux/macOS просто меняем заголовок через ANSI
        printf("\033]0;KirCulator 1.0\007");
    #endif
}

int main(void) {
    init_system(); // Запускаем наши настройки

    printf(BLUE "Welcome to KirCulator 2.0" RESET "\n\n");

    double num1, num2, result;
    char operation;

    printf("Please enter the operation (" YELLOW "+, -, *, /" RESET "): ");
    scanf(" %c", &operation);

    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    printf("\n" BLUE "--- Calculating ---" RESET "\n");

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("The result is: " GREEN "%.2lf" RESET "\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("The result is: " GREEN "%.2lf" RESET "\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("The result is: " GREEN "%.2lf" RESET "\n", result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("The result is: " GREEN "%.2lf" RESET "\n", result);
            } else {
                printf(RED "Error: Division by zero, you stupid bastard!" RESET "\n");
            }
            break;

        default:
            printf(RED "Your operation is bullshit!" RESET "\n");
    }

    printf("\n" YELLOW "Press any key to exit..." RESET);

    #ifdef _WIN32
        system("pause > nul");
    #else
        getchar(); getchar(); // На Linux/Mac просто ждем нажатия
    #endif

    return 0;
}
