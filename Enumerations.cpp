// Enumerations.c
// Реалізація всіх функцій 
// Група: компмат1
// Прізвище: Чоботар

#include "EnumerationsCPP.h"
#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <vector>

// завдання 1

DayOfWeek inputDayOfWeek() {
    std::cout << "Enter day of the week:\n";
    std::cout << "0 - Monday, 1 - Tuesday, 2 - Wednesday, 3 - Thursday,\n";
    std::cout << "4 - Friday, 5 - Saturday, 6 - Sunday\n";
    std::cout << "Your choice: ";
    int day;
    std::cin >> day;
    return (day >= static_cast<int>(DayOfWeek::MONDAY) && day <= static_cast<int>(DayOfWeek::SUNDAY))
           ? static_cast<DayOfWeek>(day) 
           : DayOfWeek::MONDAY; // по дефолту день тижня понеділок
}


void printDayOfWeek(DayOfWeek day) {
    const char* days[] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
    printf("Day of the week: %s\n", days[static_cast<int>(day)]);
}


Month inputMonth() {
    std::cout << "Enter month:\n";
    std::cout << "0 - January, 1 - February, 2 - March, 3 - April, 4 - May, 5 - June,\n";
    std::cout << "6 - July, 7 - August, 8 - September, 9 - October, 10 - November, 11 - December\n";
    std::cout << "Your choice: ";
    int month;
    std::cin >> month;
    return (month >= static_cast<int>(Month::JANUARY) && month <= static_cast<int>(Month::DECEMBER))
           ? static_cast<Month>(month)
           : Month::JANUARY;  // по дефолту ставимо січень, якщо було введено число, що не входить у цей проміжок
}


void printMonth(Month month) {
    const char* months[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", 
                            "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    printf("Month: %s\n", months[static_cast<int>(month)]);
}


SpectrumColor inputSpectrumColor() {
    std::cout << "Enter spectrum color:\n";
    std::cout << "0 - Red, 1 - Orange, 2 - Yellow, 3 - Green, 4 - Blue, 5 - Indigo, 6 - Violet\n";
    std::cout << "Your choice: ";
    int color;
    std::cin >> color;
    return (color >= static_cast<int>(SpectrumColor::RED) && color <= static_cast<int>(SpectrumColor::VIOLET))
           ? static_cast<SpectrumColor>(color)
           : SpectrumColor::RED;  //по дефолту червоний
}


void printSpectrumColor(SpectrumColor color) {
    const char* colors[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"};
    printf("Spectrum color: %s\n", colors[static_cast<int>(color)]);
}

ChessPiece inputChessPiece() {
    std::cout << "Enter chess piece:\n";
    std::cout << "0 - Pawn, 1 - Knight, 2 - Bishop, 3 - Rook, 4 - Queen, 5 - King\n";
    std::cout << "Your choice: ";
    int piece;
    std::cin >> piece;
    return (piece >= static_cast<int>(ChessPiece::PAWN) && piece <= static_cast<int>(ChessPiece::KING))
           ? static_cast<ChessPiece>(piece)
           : ChessPiece::PAWN;  // по дефолту пішка
}


void printChessPiece(ChessPiece piece) {
    const char* pieces[] = {"PAWN", "KNIGHT", "BISHOP", "ROOK", "QUEEN", "KING"};
    printf("Chess piece: %s\n", pieces[static_cast<int>(piece)]);
}


// завдання 3

// функція для визначення, чи карта x б’є карту y
bool beat(const Card& x, const Card& y, Suit trumpSuit) {
    // якщо x і y мають однакову масть, порівнюємо їх ранг
    if (x.suit == y.suit) {
        return static_cast<int>(x.rank) > static_cast<int>(y.rank);
    }

    // якщо x - козир, а y - ні, то x б'є y
    if (x.suit == trumpSuit && y.suit != trumpSuit) {
        return true;
    }

    // якщо y - козир, а x - ні, то x не б'є y
    if (y.suit == trumpSuit && x.suit != trumpSuit) {
        return false;
    }

    // якщо масті різні і жодна з карт не є козирною, то x не б'є y
    return false;
}




void convertToMeters() {
    double length;  
    Measurements unit;
    int choice;     
    std::cout << "Enter length: ";
    std::cin >> length; 

    std::cout << "Choose the unit of measurement:\n";
    std::cout << "0 - Millimeters (mm)\n";
    std::cout << "1 - Centimeters (cm)\n";
    std::cout << "2 - Decimeters (dm)\n";
    std::cout << "3 - Meters (m)\n";
    std::cout << "4 - Kilometers (km)\n";
    std::cout << "Your choice: ";
    std::cin >> choice;  


    if (choice < 0 || choice > 4) {
        std::cout << "invalid unit selection!\n";
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
    std::cout << "Length in meters: " << lengthInMeters << " m\n";
}

void printDeclinedWord(const char* word, Case caseType) {
    
//відмінювання слова залежно від відмінка
    if (strcmp(word, "програмування") == 0) {
        switch (caseType) {
            case Case::NOMINATIVE:   std::cout << "програмування\n"; break;
            case Case::GENITIVE:     std::cout << "програмування\n"; break;
            case Case::DATIVE:       std::cout << "програмуванню\n"; break;
            case Case::ACCUSATIVE:   std::cout << "програмування\n"; break;
            case Case::INSTRUMENTAL: std::cout << "програмуванням\n"; break;
            case Case::LOCATIVE:     std::cout << "програмуванню, програмуванні\n"; break;
            case Case::VOCATIVE:     std::cout << "програмування\n"; break;
        }
    } else if (strcmp(word, "мова") == 0) {
        switch (caseType) {
            case Case::NOMINATIVE:   std::cout << "мова\n"; break;
            case Case::GENITIVE:     std::cout << "мови\n"; break;
            case Case::DATIVE:       std::cout << "мові\n"; break;
            case Case::ACCUSATIVE:   std::cout << "мову\n"; break;
            case Case::INSTRUMENTAL: std::cout << "мовою\n"; break;
            case Case::LOCATIVE:     std::cout << "мові\n"; break;
            case Case::VOCATIVE:     std::cout << "мово\n"; break;
        }
    } else if (strcmp(word, "комп'ютер") == 0) {
        switch (caseType) {
            case Case::NOMINATIVE:   std::cout << "комп'ютер\n"; break;
            case Case::GENITIVE:     std::cout << "комп'ютера\n"; break;
            case Case::DATIVE:       std::cout << "комп'ютерові, комп'ютеру\n"; break;
            case Case::ACCUSATIVE:   std::cout << "комп'ютер, комп'ютера\n"; break;
            case Case::INSTRUMENTAL: std::cout << "комп'ютером\n"; break;
            case Case::LOCATIVE:     std::cout << "комп'ютері, комп'ютерові, комп'ютеру\n"; break;
            case Case::VOCATIVE:     std::cout << "комп'ютере\n"; break;
        }
    } else {
        std::cout << "unknown word\n";  // якщо такого слова немає
    }
}

// завдання 5

bool isVowel(char c) {
    // перетворюємо символ в нижній регістр
    c = std::tolower(c);

    // і перевіряємо, чи є символ голосною
    return c == static_cast<char>(Vowel::a) || c == static_cast<char>(Vowel::e) ||
           c == static_cast<char>(Vowel::i) || c == static_cast<char>(Vowel::o) ||
           c == static_cast<char>(Vowel::u);
}


int countSyllables(const char *sentence) {
    int syllableCount = 0;
    bool inSyllable = false; // відстежується, чи ми зараз у складі

    // прохід через кожен символ у реченні
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isVowel(sentence[i])) {  // якщо це голосна
            if (!inSyllable) {  // якщо починається новий склад
                syllableCount++;
                inSyllable = true;  // входимо в склад
            }
        } else {
            inSyllable = false;  // якщо це не голосна, закінчуємо склад
        }
    }

    return syllableCount;
}


// завдання 6


// функція для зміни курсу корабля залежно від команди
void changeCourse(Course& course, Order order) {
    switch (order) {
        case Order::Forward:
            break;  // курс не змінюється
        case Order::Back:
            // змінюємо курс на протилежний
            course = static_cast<Course>((static_cast<int>(course) + 2) % 4);
            break;
        case Order::Left:
            // поворот вліво на 90 градусів
            course = static_cast<Course>((static_cast<int>(course) + 3) % 4);
            break;
        case Order::Right:
            // поворот вправо на 90 градусів
            course = static_cast<Course>((static_cast<int>(course) + 1) % 4);
            break;
        default:
            std::cerr << "Unknown order!" << std::endl;
            break;
    }
}

// функція для отримання назви курсу
std::string getCourseName(Course course) {
    switch (course) {
        case Course::North: return "North";
        case Course::South: return "South";
        case Course::West:  return "West";
        case Course::East:  return "East";
        default: return "Unknown";
    }
}

// функція для обчислення загального зміщення корабля
double calculateTotalDistance(double speed, const std::vector<double>& times) {
    double totalDistance = 0.0;
    for (double time : times) {
        totalDistance += speed * time;
    }
    return totalDistance;
}



