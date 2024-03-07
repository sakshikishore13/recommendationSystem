#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a product
typedef struct ProductNode {
    char name[50];
    char category[20];
    float price;
    float rating;
    struct ProductNode* next;
} ProductNode;

// Define a structure to represent a user
typedef struct {
    char name[50];
    char preferredCategory[20];
} User;

// Function to create a new product node
ProductNode* createProductNode(char name[], char category[], float price, float rating) {
    ProductNode* newNode = (ProductNode*)malloc(sizeof(ProductNode));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->name, name);
    strcpy(newNode->category, category);
    newNode->price = price;
    newNode->rating = rating;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a product into the linked list
ProductNode* insertProduct(ProductNode* head, char name[], char category[], float price, float rating) {
    ProductNode* newNode = createProductNode(name, category, price, rating);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    return newNode;
}

// Function to recommend a product based on user preferences
void recommendProduct(User* user, ProductNode* head) {
    printf("\nHello, %s! Here are some product recommendations for you in the %s category:\n", user->name, user->preferredCategory);

    // Traverse the linked list and filter products based on the user's preferred category
    ProductNode* current = head;
    while (current != NULL) {
        if (strcmp(current->category, user->preferredCategory) == 0) {
            printf("Product: %s\n", current->name);
            printf("Category: %s\n", current->category);
            printf("Price: $%.2f\n", current->price);
            printf("Rating: %.1f\n", current->rating);
            printf("--------------\n");
        }
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeProductList(ProductNode* head) {
    ProductNode* current = head;
    while (current != NULL) {
        ProductNode* next = current->next;
        free(current);
        current = next;
    }
}

// ...

int main() {
    int numProducts = 15;
    printf("Welcome to the Awesome Recommender System!\n");

    // Initialize the linked list
    ProductNode* productList = NULL;

    // Insert product details into the linked list
    productList = insertProduct(productList, "Stylish T-shirt", "Clothing", 25.99, 4.5);
    productList = insertProduct(productList, "Casual Jeans", "Clothing", 45.99, 4.3);
    productList = insertProduct(productList, "Formal Shirt", "Clothing", 35.99, 4.2);
    productList = insertProduct(productList, "Summer Dress", "Clothing", 55.99, 4.7);

    productList = insertProduct(productList, "Smartwatch", "Electronics", 129.99, 4.0);
    productList = insertProduct(productList, "Bluetooth Headphones", "Electronics", 79.99, 4.8);
    productList = insertProduct(productList, "Fitness Tracker", "Electronics", 49.99, 4.6);
    productList = insertProduct(productList, "Wireless Earbuds", "Electronics", 69.99, 4.2);

    productList = insertProduct(productList, "Running Shoes", "Footwear", 59.99, 4.2);
    productList = insertProduct(productList, "Sneakers", "Footwear", 39.99, 4.0);
    productList = insertProduct(productList, "High Heels", "Footwear", 49.99, 4.5);
    productList = insertProduct(productList, "Hiking Boots", "Footwear", 79.99, 4.4);

    productList = insertProduct(productList, "Leather Wallet", "Accessories", 39.99, 4.0);
    productList = insertProduct(productList, "Sunglasses", "Accessories", 29.99, 4.2);
    productList = insertProduct(productList, "Backpack", "Accessories", 49.99, 4.6);
    productList = insertProduct(productList, "Wrist Watch", "Accessories", 89.99, 4.8);

    // Input user details
    User user;
    printf("\nEnter your name: ");
    scanf("%s", user.name);
    printf("Enter your preferred category: ");
    scanf("%s", user.preferredCategory);

    // Recommend products based on user preferences
    recommendProduct(&user, productList);

    // Free the memory allocated for the linked list
    freeProductList(productList);

    return 0;
}

