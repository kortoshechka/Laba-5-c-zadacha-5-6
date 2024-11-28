#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

const std::string FILENAME = "numbers.txt";

// заполнения случайными числами
void fillFileWithRandomNumbers(int count) {
    std::ofstream outFile(FILENAME);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return;
    }

    srand(static_cast<unsigned>(time(0))); // генератор случайных чисел

    for (int i = 0; i < count; ++i) {
        // запись в файл
        outFile << rand() % 100 << " "; 
    }

    outFile.close();
}


int findMinInFile() {
    std::ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения" << std::endl;
        return std::numeric_limits<int>::max(); 
    }

    int number;
    int minValue = std::numeric_limits<int>::max(); 

    while (inFile >> number) {
        if (number < minValue) {
            minValue = number; 
        }
    }

    inFile.close();
    return minValue;
}

int main() {
    int count;

    std::cout << "kol-vo chisel v fail: ";
    std::cin >> count;

    fillFileWithRandomNumbers(count);
    int minElement = findMinInFile();

    if (minElement != std::numeric_limits<int>::max()) {
        std::cout << "min: " << minElement << std::endl;
    }
    else {
        std::cout << ":error ne mogy naiti min:" << std::endl;
    }

    return 0;
}
