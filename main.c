#include "functions.h"

int main() {
    int choice;
    do {
        displayMenu();
        printf("                         Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                populateInventory();
                break;
            case 2:
                displayBrand();
                break;
            case 3:
                buyItem();
                break;
            case 4:
                returnItem();
                break;
            case 5:
                displayInventory();
                break;
            case 6:
                exitSystem();
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);

    return 0;
}

void displayMenu() {
    printf("           +===================================================+\n");
    printf("           |            Smartphone Inventory Management        |\n");
    printf("           +---------------------------+-----------------------+\n");
    printf("           | 1-Populate Inventory      |   4-Return an Item    |\n");
    printf("           +---------------------------+-----------------------+\n");
    printf("           | 2-Display Items by Brand  |   5-Display All Items |\n");
    printf("           +---------------------------+-----------------------+\n");
    printf("           | 3-Buy an Item             |   6-Exit              |\n");
    printf("           +---------------------------+-----------------------+\n");
    printf("           |      Please enter your choice (1-6):              |\n");
    printf("           +===================================================+\n");
}
