// Enumerations.h для C
// Група: компмат1
// Прізвище: Чоботар 

#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

#include <stdbool.h>



// завдання 1

typedef enum {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
} DayOfWeek;

typedef enum {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER = 12
} Month;

typedef enum {
    RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET
} SpectrumColor;

typedef enum {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} ChessPiece;

// функції для дня тижня
DayOfWeek inputDayOfWeek();
void printDayOfWeek(DayOfWeek day);

// функції для місяця
Month inputMonth();
void printMonth(Month month);

// функції для кольору спектру
SpectrumColor inputSpectrumColor();
void printSpectrumColor(SpectrumColor color);

// функції для шахової фігури
ChessPiece inputChessPiece();
void printChessPiece(ChessPiece piece);

// завдання 2

typedef enum {
    SPADES,   // Піка
    CLUBS,    // Трефи
    DIAMONDS, // Бубна
    HEARTS    // Чирва
} Suit;

// перерахування для рангу карти, робив з префіксом CARD_, бо до цього використав деякі назви в шахових фігурах
typedef enum {
    SEVEN = 7, EIGHT, NINE, TEN, CARD_JACK, CARD_QUEEN, CARD_KING, CARD_ACE
} Rank;

// структура для карти
typedef struct {
    Suit suit;
    Rank rank;
} Card;

// функція для перевірки, чи карта x б’є карту y з урахуванням козирної масті
int beat(Card x, Card y, Suit trumpSuit);


// завдання 3

typedef enum {
    MM, CM, DM, M, KM
} Measurements;

void convertToMeters();

// завдання 4

// перерахування для відмінків
typedef enum {
    NOMINATIVE,     // Називний
    GENITIVE,       // Родовий
    DATIVE,         // Давальний
    ACCUSATIVE,     // Знахідний
    INSTRUMENTAL,   // Орудний
    LOCATIVE,       // Місцевий
    VOCATIVE        // Кличний
} Case;


// функції для відмінювання слів
void printDeclinedWord(const char* word, Case caseType);



// завдання 5

typedef enum {
    A = 'A', E = 'E', I = 'I', O = 'O', U = 'U',
    a = 'a', e = 'e', i = 'i', o = 'o', u = 'u'
} Vowel;

// функція для перевірки, чи символ голосна літера
bool isVowel(char c);

// функція для підрахунку кількості складів у реченні
int countSyllables(const char *sentence);


// завдання 6
typedef enum {
    NN = 0,  // Північ
    SS = 1,  // Південь
    WW = 2,  // Захід
    EE = 3   // Схід
} Course;

// перерахування для напрямків руху корабля
typedef enum {
    Forward,
    Back,
    Left,
    Right
} Order;

void changeCourse(Course *course, Order order);
const char* getCourseName(Course course);
double calculateDistance(double speed, double time);
void readOrdersFromFile(Order* orders, double* times, int* count);
void writeResultsToFile(Course direction, double x, double y, double distance);

#endif 
