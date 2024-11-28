#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFileName, outputFileName;
    char startingCharacter;
    // ������ ��� �������� ����� � ��������� �����
    std::cout << "name input: ";
    std::cin >> inputFileName;
    std::cout << "name output: ";
    std::cin >> outputFileName;
    std::cout << "Simvol: ";
    std::cin >> startingCharacter;
    // ��������� ������� 
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "�� ������� ������� ������� ����!" << std::endl;
        return 1;
    }
    // ��������� �������� 
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "�� ������� ������� �������� ����!" << std::endl;
        return 1;
    }
    // ������ ������ �� �������� ����� � ���������� ������ � �������� ����
    std::string line;
    while (std::getline(inputFile, line)) {
        if (!line.empty() && line[0] == startingCharacter) {
            outputFile << line << std::endl;
        }
    }
    inputFile.close();
    outputFile.close();
    std::cout << "Gotovo'" <<  std::endl;

    return 0;
}
