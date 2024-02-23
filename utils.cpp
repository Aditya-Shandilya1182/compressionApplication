#include <string>
#include <fstream>
#include <iostream>

double calculateFileSize(const std::string& fileName){
    std::ifstream file(fileName, std::ios::binary);
    file.seekg(0, std::ios::end);
    double sizeOfFile = (double)file.tellg();
    return sizeOfFile;
}

double compressionRatio(const std::string& compressedFileName, const std::string& originalFileName){
    double originalFileSize = calculateFileSize(originalFileName);
    double compressedFileSize = calculateFileSize(compressedFileName);
    double ratio = (originalFileSize) / (compressedFileSize);
    return ratio;
}
