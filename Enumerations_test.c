// enumerations_test.c
// Тестування всіх функцій 
// Група: компмат1
// Прізвище: Чоботар

#include "Enumerations.c"
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

void testBeatFunction()
{       
    Card card1 = {HEARTS, CARD_JACK};   // Чирва, Валет
    Card card2 = {HEARTS, TEN};         // Чирва, 10
    Card card3 = {SPADES, CARD_ACE};    // Піка, Туз
    Card card4 = {DIAMONDS, CARD_KING}; // Бубна, Король
    Suit trumpSuit = HEARTS;            // Козир - Чирва

    printf("Card1 (HEARTS, JACK) vs Card2 (HEARTS, TEN): %s\n",
        beat(card1, card2, trumpSuit) ? "Card1 wins" : "Card2 wins");

    printf("Card1 (HEARTS, JACK) vs Card3 (SPADES, ACE): %s\n",
        beat(card1, card3, trumpSuit) ? "Card1 wins" : "Card3 wins");

    printf("Card3 (SPADES, ACE) vs Card4 (DIAMONDS, KING) trump SPADES: %s\n",
        beat(card3, card4, SPADES) ? "Card3 wins" : "Card4 wins");
}


void testPrintDeclinedWord() {
    printf("Testing for word 'мова' in different cases:\n");   
    // тестуємо різні відмінки для слова мова
    printDeclinedWord("мова", NOMINATIVE);
    printDeclinedWord("мова", GENITIVE);
    printDeclinedWord("мова", DATIVE);
    printDeclinedWord("мова", ACCUSATIVE);
    printDeclinedWord("мова", INSTRUMENTAL);
    printDeclinedWord("мова", LOCATIVE);
    printDeclinedWord("мова", VOCATIVE);
}

void testVowels() {
    char sentence[256];
    char choice[2];
    printf("choose input method (C for console, F for file): ");
    scanf("%1s", choice);  // зчитаємо лиш 1 символ

    // Очистка залишки символів після scanf
    while(getchar() != '\n');

    if (choice[0] == 'C' || choice[0] == 'c') {
        printf("enter a sentence: ");
        scanf("%[^\n]s", sentence); // "%[^\n]s" — це формат в scanf, 
       //  який дозволяє зчитати ввід до першого символу нового рядка (до символа '\n')
    } 
    else if (choice[0] == 'F' || choice[0] == 'f') {
        FILE *file = fopen("enumerations_test.txt", "r");
        if (file == NULL) {
            perror("error opening file");
            
        }
        if (fscanf(file, "%[^\n]s", sentence) != 1) {
            printf("error reading sentence from file\n");
            fclose(file);
                                                 
        }
        fclose(file);
        printf("sentence read from file: %s\n", sentence);
    } 
    else {
        printf("invalid choice\n");
        
    }

    // Виконуємо підрахунок складів
    int syllables = countSyllables(sentence);
    printf("number of syllables: %d\n", syllables);

}          


void testShip() {
    printf("choose input method: 1 from file, 2 for entered data: ");
    int choice;
    scanf("%d", &choice);

    Order orders[100];
    double times[100];
    int count = 0;

    if (choice == 1) {
        readOrdersFromFile(orders, times, &count);
    } else {
        // використовуємо вже задані значення
        orders[0] = Forward; times[0] = 1;
        orders[1] = Right; times[1] = 1.5;
        orders[2] = Forward; times[2] = 2;
        orders[3] = Left; times[3] = 1;
        orders[4] = Forward; times[4] = 0.5;
        orders[5] = Back; times[5] = 1;
        count = 6;
    }

    Course direction = NN; // початковий напрямок: північ
    double x = 0, y = 0;
    for (int i = 0; i < count; i++) {
        switch (orders[i]) {
            case Forward:
                // рух за поточним напрямком
                if (direction == NN) {
                    y += times[i] * 30; // рух на північ
                } else if (direction == SS) {
                    y -= times[i] * 30; // рух на південь
                } else if (direction == EE) {
                    x += times[i] * 30; // рух на схід
                } else if (direction == WW) {
                    x -= times[i] * 30; // рух на захід
                }
                break;
            case Back:
                // зміна напряму на протилежний
                if (direction == NN) {
                    direction = SS;
                } else if (direction == SS) {
                    direction = NN;
                } else if (direction == EE) {
                    direction = WW;
                } else if (direction == WW) {
                    direction = EE;
                }
                break;
            case Left:
                // поворот на 90 градусів вліво
                if (direction == NN) {
                    direction = WW;
                } else if (direction == WW) {
                    direction = SS;
                } else if (direction == SS) {
                    direction = EE;
                } else if (direction == EE) {
                    direction = NN;
                }
                break;
            case Right:
                // поворот на 90 градусів вправо
                if (direction == NN) {
                    direction = EE;
                } else if (direction == EE) {
                    direction = SS;
                } else if (direction == SS) {
                    direction = WW;
                } else if (direction == WW) {
                    direction = NN;
                }
                break;
        }
    }

    double distance = sqrt(x * x + y * y);
    writeResultsToFile(direction, x, y, distance);
}

void readOrdersFromFile(Order* orders, double* times, int* count) {
    FILE* inputFile = fopen("EnumerationsC_test.txt", "r");
    if (inputFile == NULL) {
        printf("cant to open file for reading.\n");
        return;
    }

    char command[10];
    double time;
    *count = 0;

    while (fscanf(inputFile, "%s %lf", command, &time) == 2) {
        if (strcmp(command, "Forward") == 0) {
            orders[*count] = Forward;
        } else if (strcmp(command, "Back") == 0) {
            orders[*count] = Back;
        } else if (strcmp(command, "Left") == 0) {
            orders[*count] = Left;
        } else if (strcmp(command, "Right") == 0) {
            orders[*count] = Right;
        }
        times[*count] = time;
        (*count)++;
    }

    fclose(inputFile);
}

void writeResultsToFile(Course direction, double x, double y, double distance) {
    FILE* outputFile = fopen("test_shipC.txt", "w");
    if (outputFile == NULL) {
        printf("can't open file for writing\n");
        return;
    }

    fprintf(outputFile, "final direction: ");
    switch (direction) {
        case NN: fprintf(outputFile, "North\n"); break;
        case SS: fprintf(outputFile, "South\n"); break;
        case EE: fprintf(outputFile, "East\n"); break;
        case WW: fprintf(outputFile, "West\n"); break;
    }

    fprintf(outputFile, "final position: (%.2f, %.2f)\n", x, y);
    fprintf(outputFile, "distance from the start: %.2f km\n", distance);

    fclose(outputFile);
    printf("test results have been written to 'test_shipC.txt'\n");
}

void runAllTests(){
    printf("Testing DayOfWeek:\n");
       DayOfWeek day = inputDayOfWeek();
       printDayOfWeek(day);

       printf("\nTesting Month:\n");
       Month month = inputMonth();
       printMonth(month);

       printf("\nTesting SpectrumColor:\n");
       SpectrumColor color = inputSpectrumColor();
       printSpectrumColor(color);

       printf("\nTesting ChessPiece:\n");
       ChessPiece piece = inputChessPiece();
       printChessPiece(piece);

       printf("\nTesting BeatFunction:\n");
       testBeatFunction();
       
       printf("\nTesting ConvertToMeters:\n");
       convertToMeters();

       printf("\nTesting DeclinedWord:\n");                    
       testPrintDeclinedWord();

       printf("\nTesting Vowels:\n"); 
       testVowels();


       printf("\nTesting Ship:\n");
       testShip(); 
}

void timeExecution(){
    clock_t begin = clock();
    runAllTests();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf", time_spent);
}

int main()
{
    
    SetConsoleOutputCP(65001);
    timeExecution(); //я одразу роблю тест на час і запускаю всі функції
       
}
