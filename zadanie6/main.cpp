#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFileName, outputFileName;
    char startingCharacter;
    // Вводим имя входного файла и выходного файла
    std::cout << "name input: ";
    std::cin >> inputFileName;
    std::cout << "name output: ";
    std::cin >> outputFileName;
    std::cout << "Simvol: ";
    std::cin >> startingCharacter;
    // Открываем входной 
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Не удалось открыть входной файл!" << std::endl;
        return 1;
    }
    // Открываем выходной 
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Не удалось открыть выходной файл!" << std::endl;
        return 1;
    }
    // Читаем строки из входного файла и записываем нужные в выходной файл
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
