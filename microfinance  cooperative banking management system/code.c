#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "products.txt"

struct Product {
    int id;
    char name[50];
    char type[20];
    float interestRate;
    float minAmount;
    float maxAmount;
};

void addProduct();
void displayProducts();
void menu();

int main() 
{
    menu();
    return 0;
}

void menu() 
{
    int choice;

    while (1) {
        printf("\n============================================\n");
        printf("  MICROFINANCE COOPERATIVE BANKING SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

void addProduct() 
{
    struct Product p;
    FILE *fp = fopen(FILE_NAME, "a");

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Add New Product ---\n");
    printf("Enter Product ID: ");
    scanf("%d", &p.id);

    printf("Enter Product Name: ");
    getchar(); 
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Product Type (Loan/Savings/Insurance): ");
    fgets(p.type, sizeof(p.type), stdin);
    p.type[strcspn(p.type, "\n")] = 0;

    printf("Enter Interest Rate (%%): ");
    scanf("%f", &p.interestRate);

    printf("Enter Minimum Amount: ");
    scanf("%f", &p.minAmount);

    printf("Enter Maximum Amount: ");
    scanf("%f", &p.maxAmount);

    fprintf(fp, "%d|%s|%s|%.2f|%.2f|%.2f\n", 
            p.id, p.name, p.type, p.interestRate, p.minAmount, p.maxAmount);

    fclose(fp);

    printf("\nProduct added successfully!\n");
}

void displayProducts() 
{
    FILE *fp = fopen(FILE_NAME, "r");
    struct Product p;

    if (!fp) {
        printf("No product records found!\n");
        return;
    }

    printf("\n============================================\n");
    printf("         MICROFINANCE PRODUCT LIST\n");
    printf("============================================\n");

    while (fscanf(fp, "%d|%[^|]|%[^|]|%f|%f|%f\n",
                  &p.id, p.name, p.type, &p.interestRate, 
                  &p.minAmount, &p.maxAmount) != EOF)
    {
        printf("\nProduct ID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Type: %s\n", p.type);
        printf("Interest Rate: %.2f%%\n", p.interestRate);
        printf("Min Amount: %.2f\n", p.minAmount);
        printf("Max Amount: %.2f\n", p.maxAmount);
    }

    fclose(fp);
}
