// Enumerations.h для CPP
// Група: компмат1
// Прізвище: Чоботар 

// завдання 1

#include <string>
#include <vector>

enum class DayOfWeek {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};


enum class Month {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};


enum class SpectrumColor {
    RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET
};


enum class ChessPiece {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

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

// перерахування для мастей карт 
enum class Suit {
    SPADES,   // Піка
    CLUBS,    // Трефи
    DIAMONDS, // Бубна
    HEARTS    // Чирва
};

// перерахування для рангу карт з enum class
enum class Rank {
    SEVEN = 7, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

// структура для карти
struct Card {
    Suit suit;  // масть карти
    Rank rank;  // ранг карти
};

// функція для перевірки, чи карта x б’є карту y з урахуванням козирної масті
bool beat(const Card& x, const Card& y, Suit trumpSuit);


// завдання 3


// перерахування для одиниць виміру з enum class
typedef enum {
    MM, CM, DM, M, KM
} Measurements;

void convertToMeters();

// завдання 4

// перерахування для відмінків з enum class
enum class Case {
    NOMINATIVE, GENITIVE, DATIVE, ACCUSATIVE, INSTRUMENTAL, LOCATIVE, VOCATIVE
};

// завдання 5

// перерахування для голосних з enum class
enum class Vowel {
    A = 'A', E = 'E', I = 'I', O = 'O', U = 'U',
    a = 'a', e = 'e', i = 'i', o = 'o', u = 'u'
};

// функція для перевірки, чи є символ голосною
bool isVowel(char c);

int countSyllables(const char *sentence);


// завдання 6

enum class Course {
    North,
    South,
    West,
    East
};

// перерахування для напрямків корабля
enum class Order {
    Forward,
    Back,
    Left,
    Right
};


void changeCourse(Course& course, Order order);
std::string getCourseName(Course course);
double calculateTotalDistance(double speed, const std::vector<double>& times);
std::vector<Order> readOrdersFromFile();
std::vector<double> readTimesFromFile();