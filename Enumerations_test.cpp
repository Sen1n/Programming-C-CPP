// enumerations_test.cpp
// Тестування всіх функцій 
// Група: компмат1
// Прізвище: Чоботар


#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>
#include "Enumerations.cpp"
#include <windows.h>
#include <chrono>
using namespace std::chrono;

void testBeatFunction() {
    // створення карт
    Card card1 = {Suit::HEARTS, Rank::JACK};   // Чирва, Валет
    Card card2 = {Suit::HEARTS, Rank::TEN};    // Чирва, 10
    Card card3 = {Suit::SPADES, Rank::ACE};    // Піка, Туз
    Card card4 = {Suit::DIAMONDS, Rank::KING}; // Бубна, Король
    Suit trump = Suit::HEARTS;                 // Козир - Чирва

    std::cout << "Card1 (HEARTS, JACK) vs Card2 (HEARTS, TEN): "
              << (beat(card1, card2, trump) ? "Card1 wins" : "Card2 wins") << std::endl;
    std::cout << "Card1 (HEARTS, JACK) vs Card3 (SPADES, ACE): "
              << (beat(card1, card3, trump) ? "Card1 wins" : "Card3 wins") << std::endl;
    std::cout << "Card3 (SPADES, ACE) vs Card4 (DIAMONDS, KING) trump SPADES: "
              << (beat(card3, card4, Suit::SPADES) ? "Card3 wins" : "Card4 wins") << std::endl;
}


void testPrintDeclinedWord() {
    std::cout << "testing for word мова in different cases:\n";
    // Тестуємо різні відмінки для слова мова
    printDeclinedWord("мова", Case::NOMINATIVE);
    printDeclinedWord("мова", Case::GENITIVE);
    printDeclinedWord("мова", Case::DATIVE);
    printDeclinedWord("мова", Case::ACCUSATIVE);
    printDeclinedWord("мова", Case::INSTRUMENTAL);
    printDeclinedWord("мова", Case::LOCATIVE);
    printDeclinedWord("мова", Case::VOCATIVE);
}



void testVowels() {
    char sentence[256];
    char choice[2];
    std::cout << "choose input method (C for console, F for file): ";
    std::cin >> choice;  

    std::cin.ignore(); // очистка залишків символів після scanf

    if (choice[0] == 'C' || choice[0] == 'c') {
        std::cout << "enter sentence: ";
        std::cin.getline(sentence, 256); 
    } 
    else if (choice[0] == 'F' || choice[0] == 'f') {
        std::ifstream file("EnumerationsCPP_test.txt");
        if (!file.is_open()) {
            std::cerr << "error opening file\n";
            return;
        }
        file.getline(sentence, 256);
        std::cout << "sentence read from file: " << sentence << std::endl;
        file.close();
    } 
    else {
        std::cout << "invalid choice\n";
        return;
    }

    //підрахунок складів
    int syllables = countSyllables(sentence);
    std::cout << "number of syllables: " << syllables << std::endl;
}


void testShip() {
    std::cout << "choose input method: 1 from file, 2 for entered data: ";
    int choice;
    std::cin >> choice;

    std::vector<Order> orders;
    std::vector<double> times;

    if (choice == 1) {
        orders = readOrdersFromFile();
        times = readTimesFromFile();
    } else {
        orders = {Order::Forward, Order::Right, Order::Forward, Order::Left, Order::Forward, Order::Back};
        times = {1, 1.5, 2, 1, 0.5, 1};
    }

    Course direction = Course::North; //початковий напрямок: Північ

    // ініціалізація позиції
    double x = 0, y = 0;

    for (size_t i = 0; i < orders.size(); i++) {
        switch (orders[i]) {
            case Order::Forward:
                // рухаємся за поточним напрямком
                if (direction == Course::North) {
                    y += times[i] * 30; // рух на північ
                } else if (direction == Course::South) {
                    y -= times[i] * 30; // рух на південь
                } else if (direction == Course::East) {
                    x += times[i] * 30; // рух на схід
                } else if (direction == Course::West) {
                    x -= times[i] * 30; // рух на захід
                }
                break;
            case Order::Back:
                // зміна напряму на протилежний
                if (direction == Course::North) {
                    direction = Course::South;
                } else if (direction == Course::South) {
                    direction = Course::North;
                } else if (direction == Course::East) {
                    direction = Course::West;
                } else if (direction == Course::West) {
                    direction = Course::East;
                }
                break;
            case Order::Left:
                // поворот на 90 градусів вліво
                if (direction == Course::North) {
                    direction = Course::West;
                } else if (direction == Course::West) {
                    direction = Course::South;
                } else if (direction == Course::South) {
                    direction = Course::East;
                } else if (direction == Course::East) {
                    direction = Course::North;
                }
                break;
            case Order::Right:
                // поворот на 90 градусів вправо
                if (direction == Course::North) {
                    direction = Course::East;
                } else if (direction == Course::East) {
                    direction = Course::South;
                } else if (direction == Course::South) {
                    direction = Course::West;
                } else if (direction == Course::West) {
                    direction = Course::North;
                }
                break;
        }
    }
    double distance = std::sqrt(x * x + y * y);

    //записування результатів у файл
    std::ofstream outputFile("test_shipCPP.txt");

    if (outputFile.is_open()) {
        outputFile << "final direction: ";
        switch (direction) {
            case Course::North: outputFile << "North\n"; break;
            case Course::South: outputFile << "South\n"; break;
            case Course::East: outputFile << "East\n"; break;
            case Course::West: outputFile << "West\n"; break;
        }

        outputFile << "final position: (" << x << ", " << y << ")\n";
        outputFile << "distance from start: " << distance << " km\n";
    } else {
        std::cerr << "cant to open file to write results." << std::endl;
    }

    outputFile.close();

    std::cout << "test results written to 'test_shipCPP.txt'" << std::endl;
}

std::vector<Order> readOrdersFromFile() {
    std::vector<Order> orders;
    std::ifstream inputFile("EnumerationsCPP_test.txt");

    if (inputFile.is_open()) {
        std::string command;
        while (inputFile >> command) {
            if (command == "Forward") {
                orders.push_back(Order::Forward);
            } else if (command == "Back") {
                orders.push_back(Order::Back);
            } else if (command == "Left") {
                orders.push_back(Order::Left);
            } else if (command == "Right") {
                orders.push_back(Order::Right);
            }
        }
    } else {
        std::cerr << "can't to open file for reading." << std::endl;
    }

    inputFile.close();
    return orders;
}

std::vector<double> readTimesFromFile() {
    std::vector<double> times;
    std::ifstream inputFile("EnumerationsCPP_test.txt");

    if (inputFile.is_open()) {
        std::string command;
        double time;
        while (inputFile >> command >> time) {
            times.push_back(time);
        }
    } else {
        std::cerr << "can't to open file for reading." << std::endl;
    }

    inputFile.close();
    return times;
}

void runAllTests() {
    std::cout << "Testing DayOfWeek:\n";
    DayOfWeek day = inputDayOfWeek();
    printDayOfWeek(day);

    std::cout << "Testing Month:\n";
    Month month = inputMonth();
    printMonth(month);


    std::cout << "Testing SpectrumColor:\n";
    SpectrumColor color = inputSpectrumColor();
    printSpectrumColor(color);

    
    
    std::cout << "Testing ChessPiece:\n";
    ChessPiece piece = inputChessPiece();
    printChessPiece(piece);

    std::cout << "Testing testBeatFunction:\n";
    testBeatFunction();


    std::cout << "Testing convertToMeters:\n";
    convertToMeters();  

    std::cout<< "Testing PrintDeclinedWord:\n";
    testPrintDeclinedWord();

            
    std::cout << "Testing Vowels:\n";
    testVowels();


    std::cout << "Testing Ship:\n";
    testShip();
}


void timeExecution(){
    auto start = high_resolution_clock::now();
    runAllTests();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    std::cout << duration.count() << std::endl;
}





int main() {
    SetConsoleOutputCP(65001);
    timeExecution(); //я одразу роблю тест на час і запускаю всі функції
}
