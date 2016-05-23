//
// Created by Shaq on 25.04.2016.
//

#include "main.h"

int main() {
    printHeader();

    appMenu();

    return 0;
}

void appMenu() {
    unsigned command = 1;
    char src[30];
    char srcText[30];
    char dest[30];

    while (command != 0) {
        printf(RED "\nMENU - type number and click enter"
                       "\n0.Exit"
                       "\n1.Hide message in png file"
                       "\n2.Read message from png file"
                       "\nI choose: " RESET);

        scanf("%d", &command);
        char yn = 'n';

        switch (command) {
            case 0:
                printf("\nExiting program ...\n");
                break;
            case 1:
                while (yn != 'Y' && yn != 'y') {
                    printf("\n   Choose file paths - max length 30 chars each\n");
                    printf("a) Source(png) file path: ");
                    scanf("%s", src);
                    printf("b) Source(txt) file path: ");
                    scanf("%s", srcText);
                    printf("c) Destination(png) file path: ");
                    scanf("%s", dest);
                    printf("\nPaths\na) %s\nb) %s\nc) %s\nAre they correct?(Y/N): ", src, srcText, dest);
                    scanf(" %c", &yn);
                    clear();
                }
                //hideMsgInFile("imgIn/test.png", "txtIn/test.txt", "imgOut/test_modify.png");
                hideMsgInFile(src, srcText, dest);
                break;
            case 2:
                while (yn != 'Y' && yn != 'y') {
                    printf("\n   Choose file paths - max length 30 chars each\n");
                    printf("a) Source(png) file path: ");
                    scanf("%s", src);
                    printf("b) Destination(txt) file path: ");
                    scanf("%s", dest);
                    printf("\nPaths\na) %s\nb) %s2\nAre they correct?(Y/N): ", src, dest);
                    scanf(" %c", &yn);
                    clear();
                }
                //readMsgFromFile("imgOut/test_modify.png", "txtOut/test.txt");
                readMsgFromFile(src, dest);
                break;
            default:
                clear();
                printf("\nWrong command. Try again ...\n");
                break;
        }
    }

}

void clear() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}


void printHeader() {
    printf("  ____   _                              ___          ____ \n / ___| | |_  ___   __ _   ___   _ __  |_ _| _ __   / ___|\n"
                   " \\___ \\ | __|/ _ \\ / _` | / _ \\ | '_ \\  | | | '_ \\ | |    \n  ___) || |_|  __/| (_| || (_) || | | | | | | | | || |___ \n"
                   " |____/  \\__|\\___| \\__, | \\___/ |_| |_||___||_| |_| \\____|\n                   |___/                                  \n");
}