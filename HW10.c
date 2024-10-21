// 10.6d, 10.12
#include <stdio.h>

#define MAX_PRODUCTS 100

struct Product {
    int hrivnas;  
    int coins;     
};

int getPriceInCoins(struct Product product) {
    return product.hrivnas * 100 + product.coins;
}

struct Product findCheapest(struct Product products[], int count) {
    struct Product cheapest = products[0];
    for (int i = 1; i < count; i++) {
        if (getPriceInCoins(products[i]) < getPriceInCoins(cheapest)) {
            cheapest = products[i];
        }
    }
    return cheapest;
}

struct Product findMostExpensive(struct Product products[], int count) {
    struct Product mostExpensive = products[0];
    for (int i = 1; i < count; i++) {
        if (getPriceInCoins(products[i]) > getPriceInCoins(mostExpensive)) {
            mostExpensive = products[i];
        }
    }
    return mostExpensive;
}

void findProductsNearAverage(struct Product products[], int count) {
    int totalCoins = 0;


    for (int i = 0; i < count; i++) {
        totalCoins += getPriceInCoins(products[i]);
    }


    int averageCoins = totalCoins / count;

    printf("Products with price differing from average by no more than 10 hrivnas:\n");
    for (int i = 0; i < count; i++) {
        int priceInCoins = getPriceInCoins(products[i]);
        if (priceInCoins >= averageCoins - 1000 && priceInCoins <= averageCoins + 1000) {
            printf("Product: %d hrivnas %d coins\n", products[i].hrivnas, products[i].coins);
        }
    }
}

struct Seminar {
    char subject[50];   
    char lecturer[50];  
    int groupNumber;    
    char day[10];       
    int startHour;      
    int startMinute;    
    int duration;       
    char classroom[10]; 
};

void displaySeminarInfo(struct Seminar seminar) {
    printf("subject: %s\n", seminar.subject);
    printf("lecturer: %s\n", seminar.lecturer);
    printf("group Number: %d\n", seminar.groupNumber);
    printf("day of the Week: %s\n", seminar.day);
    printf("start Time: %02d:%02d\n", seminar.startHour, seminar.startMinute);
    printf("duration: %d minutes\n", seminar.duration);
    printf("classroom: %s\n", seminar.classroom);
}

int main() {
    struct Seminar seminar1 = {
        "C/C++",
        "Borodin V.A.",
        1,
        "Friday",
        10,
        30,
        90,
        "219"
    };
    displaySeminarInfo(seminar1);

    struct Product products[MAX_PRODUCTS];
    int count;
    printf("Enter the number of products: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Enter price of product %d (hrivnas and coins): ", i + 1);
        scanf("%d %d", &products[i].hrivnas, &products[i].coins);
    }
    struct Product cheapest = findCheapest(products, count);
    printf("Cheapest product: %d hrivnas %d coins\n", cheapest.hrivnas, cheapest.coins);
    struct Product mostExpensive = findMostExpensive(products, count);
    printf("Most expensive product: %d hrivnas %d coins\n", mostExpensive.hrivnas, mostExpensive.coins);
    findProductsNearAverage(products, count);
}

