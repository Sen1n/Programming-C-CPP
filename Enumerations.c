// Enumerations.c
// Реалізація всіх функцій 
// Група: компмат1
// Прізвище: Чоботар

#include "EnumerationsC.h"
#include <stdio.h>
#include <string.h> 
#include <ctype.h>



// функції для дня тижня
DayOfWeek inputDayOfWeek() {
    int day;
    printf("Enter day of the week:\n");
    printf("0 - Monday, 1 - Tuesday, 2 - Wednesday, 3 - Thursday,\n");
    printf("4 - Friday, 5 - Saturday, 6 - Sunday\n");
    printf("Your choice: ");
    scanf("%d", &day);
    return (day >= MONDAY && day <= SUNDAY) ? (DayOfWeek)day : MONDAY;
}

void printDayOfWeek(DayOfWeek day) {
    const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    printf("Day of the week: %s\n", days[day]);
}

// функції для місяця (починається з 1 для січня)
Month inputMonth() {
    int month;
    printf("Enter month:\n");
    printf("1 - January, 2 - February, 3 - March, 4 - April, 5 - May, 6 - June,\n");
    printf("7 - July, 8 - August, 9 - September, 10 - October, 11 - November, 12 - December\n");
    printf("Your choice: ");
    scanf("%d", &month);
    return (month >= JANUARY && month <= DECEMBER) ? (Month)month : JANUARY;
}

void printMonth(Month month) {
    const char *months[] = {"", "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    printf("Month: %s\n", months[month]);
}

// функції для кольору спектру
SpectrumColor inputSpectrumColor() {
    int color;
    printf("Enter spectrum color:\n");
    printf("0 - Red, 1 - Orange, 2 - Yellow, 3 - Green, 4 - Blue, 5 - Indigo, 6 - Violet\n");
    printf("Your choice: ");
    scanf("%d", &color);
    return (color >= RED && color <= VIOLET) ? (SpectrumColor)color : RED;
}

void printSpectrumColor(SpectrumColor color) {
    const char *colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
    printf("Spectrum color: %s\n", colors[color]);
}

// функції для шахової фігури
ChessPiece inputChessPiece() {
    int piece;
    printf("Enter chess piece:\n");
    printf("0 - Pawn, 1 - Knight, 2 - Bishop, 3 - Rook, 4 - Queen, 5 - King\n");
    printf("Your choice: ");
    scanf("%d", &piece);
    return (piece >= PAWN && piece <= KING) ? (ChessPiece)piece : PAWN;
}

void printChessPiece(ChessPiece piece) {
    const char *pieces[] = {"Pawn", "Knight", "Bishop", "Rook", "Queen", "King"};
    printf("Chess piece: %s\n", pieces[piece]);
}


int beat(Card x, Card y, Suit trumpSuit) {
    // якщо x і y мають однакову масть, порівнюємо їх ранг
    if (x.suit == y.suit) {
        return x.rank > y.rank;
    }
    // якщо x - козир, а y - ні, то x б'є y
    if (x.suit == trumpSuit && y.suit != trumpSuit) {
        return 1;
    }
    // якщо y - козир, а x - ні, то x не б'є y
    if (y.suit == trumpSuit && x.suit != trumpSuit) {
        return 0;
    }
    // якщо масті різні і жодна з карт не є козирною, то x не б'є y
    return 0;
}


// завдання 3
// функція для перетворення різних вимірювань довжини в метри
void convertToMeters() {
    double length; // мінна для зберігання довжини, введеної користувачем
    Measurements unit; // змінна для зберігання вибраної одиниці

    printf("Enter length: "); 
    scanf("%lf", &length); 

    //варіанти одиниць вимірювання для користувача
    printf("Choose the unit of measurement:\n");
    printf("0 - Millimeters (mm)\n");
    printf("1 - Centimeters (cm)\n");
    printf("2 - Decimeters (dm)\n");
    printf("3 - Meters (m)\n");
    printf("4 - Kilometers (km)\n");
    printf("Your choice: ");
    int choice; // вибір користувача
    scanf("%d", &choice);

    if (choice < 0 || choice > 4) {
        printf("Invalid unit selection!\n"); // повідомлення про помилку для недійсного вибору
        return; 
    }
    
    unit = (Measurements)choice;
    double lengthInMeters;

    switch (unit) {
        case MM:
            lengthInMeters = length / 1000; // 1 м = 1000 мм
            break;
        case CM:
            lengthInMeters = length / 100;  // 1 м = 100 см
            break;
        case DM:
            lengthInMeters = length / 10;   // 1 м = 10 дм
            break;
        case M:
            lengthInMeters = length;           // 1 м = 1 м
            break;
        case KM:
            lengthInMeters = length * 1000; // 1 км = 1000 м
            break;
    }

    //довжина в метрах
    printf("Length in meters: %.3f m\n", lengthInMeters);  
}

//завдання 4


//відмінювання слова залежно від відмінка
void printDeclinedWord(const char* word, Case caseType) {
    if (strcmp(word, "програмування") == 0) {
        switch (caseType) {
            case NOMINATIVE:     printf("програмування\n"); break;
            case GENITIVE:       printf("програмування\n"); break;
            case DATIVE:         printf("програмуванню\n"); break;
            case ACCUSATIVE:     printf("програмування\n"); break;
            case INSTRUMENTAL:   printf("програмуванням\n"); break;
            case LOCATIVE:       printf("програмуванню, програмуванні\n"); break;
            case VOCATIVE:       printf("програмування\n"); break;
        }
    } else if (strcmp(word, "мова") == 0) {
        switch (caseType) {
            case NOMINATIVE:     printf("мова\n"); break;
            case GENITIVE:       printf("мови\n"); break;
            case DATIVE:         printf("мові\n"); break;
            case ACCUSATIVE:     printf("мову\n"); break;
            case INSTRUMENTAL:   printf("мовою\n"); break;
            case LOCATIVE:       printf("мові\n"); break;
            case VOCATIVE:       printf("мово\n"); break;
        }
    } else if (strcmp(word, "комп'ютер") == 0) {
        switch (caseType) {
            case NOMINATIVE:     printf("комп'ютер\n"); break;
            case GENITIVE:       printf("комп'ютера\n"); break;
            case DATIVE:         printf("комп'ютерові, комп'ютеру\n"); break;
            case ACCUSATIVE:     printf("комп'ютер, комп'ютера\n"); break;
            case INSTRUMENTAL:   printf("комп'ютером\n"); break;
            case LOCATIVE:       printf("комп'ютері, комп'ютерові, комп'ютеру\n"); break;
            case VOCATIVE:       printf("комп'ютере\n"); break;
        }
    } else {
        printf("unknown word\n");
    }
}




//завдання 5

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

//кількість складів у реченні
int countSyllables(const char *sentence) {
    int syllableCount = 0;
    bool inSyllable = false; // відстежування чи ми зараз у складі

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isVowel(sentence[i])) {
            if (!inSyllable) { // якщо це початок нового складу
                syllableCount++;
                inSyllable = true; // Переходимо в стан складу
            }
        } else {
            inSyllable = false; // Якщо не голосна, виходимо зі складу
        }
    }

    return syllableCount;
}


// завдання 6

//функція для зміни курсу корабля залежно від команди
void changeCourse(Course *course, Order order) {
    switch (order) {
        case Forward:
            break;  //курс не змінюється, корабель рухається вперед
        case Back:
            // змінюємо курс на протилежний
            *course = (*course + 2) % 4;
            break;
        case Left:
            // поворот вліво на 90 градусів
            *course = (*course + 3) % 4;
            break;
        case Right:
            // поворот вправо на 90 градусів
            *course = (*course + 1) % 4;
            break;
        default:
            printf("Unknown order!\n");
            break;
    }
}

// функція для визначення кінцевого напрямку корабля
const char* getCourseName(Course course) {
    switch (course) {
        case NN: return "North";
        case SS: return "South";
        case WW: return "West";
        case EE: return "East";
        default: return "Unknown";
    }
}

// функція для обчислення зміщення корабля
double calculateDistance(double speed, double time) {
    return speed * time;  // відстань = швидкість * час
}