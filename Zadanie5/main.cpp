#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

const std::string FILENAME = "numbers.txt";

// ���������� ���������� �������
void fillFileWithRandomNumbers(int count) {
    std::ofstream outFile(FILENAME);
    if (!outFile.is_open()) {
        std::cerr << "������ �������� ����� ��� ������" << std::endl;
        return;
    }

    srand(static_cast<unsigned>(time(0))); // ��������� ��������� �����

    for (int i = 0; i < count; ++i) {
        // ������ � ����
        outFile << rand() % 100 << " "; 
    }

    outFile.close();
}


int findMinInFile() {
    std::ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        std::cerr << "������ �������� ����� ��� ������" << std::endl;
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
