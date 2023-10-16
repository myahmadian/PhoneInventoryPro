#include "functions.h"

// Declare a global array to hold up to 99 smartphones
struct smartphone inventory[99];

// Declare a global variable to keep track of the number of items in the array
int k = 0;

// Implement the functions
// Function definitions
void populateInventory() {
    FILE *file = fopen("inventory.txt", "r");  // Open the inventory.txt file for reading
    if (file == NULL) {
        perror("Error opening inventory.txt");
        return;  // Exit the function if the file couldn't be opened
    }

    // Loop through each line in the file and populate the inventory array
    while (fscanf(file, "%d %19s %19s %f %d %f %d %d %d %d",
                  &inventory[k].id,
                  inventory[k].brand,
                  inventory[k].model,
                  &inventory[k].screen_size,
                  &inventory[k].memory,
                  &inventory[k].camera_resolution,
                  &inventory[k].price_no_plan,
                  &inventory[k].price_one_year,
                  &inventory[k].price_two_year,
                  &inventory[k].stock) != EOF && k < 99) {
        k++;  // Increment k for each item successfully read
    }

    fclose(file);  // Close the file
    printf("Inventory populated with %d items.\n", k);
}

void buyItem() {
    int id, quantity, index = -1;

    // Prompt the user to enter the smartphone ID
    printf("Enter the smartphone ID: ");
    scanf("%d", &id);

    // Search for the smartphone in the inventory
    for (int i = 0; i < k; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // If the smartphone is not found, print an error message and return
    if (index == -1) {
        printf("Smartphone not found.\n");
        return;
    }

    // Prompt the user to enter the quantity and check the stock availability in a loop
    do {
        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        if (inventory[index].stock < quantity) {
            printf("Insufficient stock. Only %d units available. Please enter a new quantity.\n", inventory[index].stock);
        } else {
            break;  // Exit the loop if the requested quantity is available
        }
    } while (1);

    // If the requested quantity is available, process the transaction
    inventory[index].stock -= quantity;
    printf("Transaction successful. %d units of smartphone ID %d purchased.\n", quantity, id);
    printf("Remaining stock: %d\n", inventory[index].stock);
}

void returnItem() {
    int id, quantity, index = -1;

    // Prompt the user to enter the smartphone ID and the quantity they wish to return
    printf("Enter the smartphone ID: ");
    scanf("%d", &id);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // If quantity is negative or zero, print an error message and return
    if (quantity <= 0) {
        printf("Invalid quantity. Please enter a positive number.\n");
        return;
    }

    // Search for the smartphone in the inventory
    for (int i = 0; i < k; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // If the smartphone is not found, print an error message and return
    if (index == -1) {
        printf("Smartphone not found.\n");
        return;
    }

    // Process the return transaction
    inventory[index].stock += quantity;
    printf("Return transaction successful. %d units of smartphone ID %d returned.\n", quantity, id);
    printf("Updated stock: %d\n", inventory[index].stock);
}

void saveInventoryToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        perror("Failed to save inventory");
        return;
    }

    for (int i = 0; i < k; i++) {
        fprintf(file, "%d %s %s %.1f %d %.1f %d %d %d %d\n",
                inventory[i].id,
                inventory[i].brand,
                inventory[i].model,
                inventory[i].screen_size,
                inventory[i].memory,
                inventory[i].camera_resolution,
                inventory[i].price_no_plan,
                inventory[i].price_one_year,
                inventory[i].price_two_year,
                inventory[i].stock);
    }

    fclose(file);
    printf("Inventory saved successfully.\n");
}

void exitSystem() {
    char choice;
    printf("Do you want to save the inventory before exiting? (y/n): ");
    scanf(" %c", &choice);  // Space before %c to skip any whitespace characters

    if (choice == 'y' || choice == 'Y') {
        saveInventoryToFile();
    }

    printf("Exiting the system. Goodbye!\n");
    exit(0);  // Exit the program with a status of 0 (success)
}

// Function to print the table header
void printHeader() {
    printf("+----------------------------------------------------------------------------------------------------------------------+\n");
    printf("|%-5s |%-9s |%-15s |%-6s |%-6s |%-11s |%-11s |%-11s |%-11s |%-6s|\n",
           "ID", " Brand", " Model", "Screen", "Memory", " Resolution",
           "Price(no plan)", "Price(1-year)", "Price(2-year)", "  Stock ");
    printf("+----------------------------------------------------------------------------------------------------------------------+\n");
}

// Function to print a smartphone data
void printSmartphone(struct smartphone phone) {
    //printf("%-1d %-15s %-15s %-12.1f %-7d %-18.1f %-15d %-15d %-15d %-6d\n",
      printf("|  %-1d | %-8s |  %-13s |  %-4.1f | %-5d | %-10.1f |  %-12d |  %-11d |  %-11d |  %-6d|\n",
           phone.id,
           phone.brand,
           phone.model,
           phone.screen_size,
           phone.memory,
           phone.camera_resolution,
           phone.price_no_plan,
           phone.price_one_year,
           phone.price_two_year,
           phone.stock);
    printf("+----------------------------------------------------------------------------------------------------------------------+\n");
}

// Updated displayBrand function
void displayBrand() {
    char brand[20];  // To store the brand name entered by the user
    int found = 0;  // Flag to check if any smartphone of the entered brand is found

    // Prompt the user to enter the brand name
    printf("Enter the brand name: ");
    scanf("%19s", brand);  // Read up to 19 characters, to prevent buffer overflow

    // Print the header
    printHeader();

    // Loop through the inventory array and display the smartphones of the entered brand
    for (int i = 0; i < k; i++) {
        if (strcmp(inventory[i].brand, brand) == 0) {
            printSmartphone(inventory[i]);
            found = 1;  // Set found flag to 1, as we've found at least one smartphone of the entered brand
        }
    }

    // If no smartphone of the entered brand was found, print a message
    if (found == 0) {
        printf("No smartphones found for the brand: %s\n", brand);
    }
}

// Updated displayInventory function
void displayInventory() {
    // Print the header
    printHeader();

    // Loop through the inventory array and display each smartphone
    for (int i = 0; i < k; i++) {
        printSmartphone(inventory[i]);
    }
}
