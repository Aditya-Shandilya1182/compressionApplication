#include <string>
#include <iostream>
#include <fstream>

//using namespace std;

std::string rleCompress(const std::string& data){
    std::string encoded;
    int count = 1;
    for(size_t i = 1; i < data.size(); ++i){
        if(data[i] == data[i - 1]){
            ++count;
        } else {
            encoded += data[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    encoded += data[data.size() - 1] + std::to_string(count);
    return encoded;
}

std::string rleDecompress(const std::string& data){
    std::string decoded;
    for(size_t i = 0; i < data.size(); i += 2){
        int count = data[i + 1] - '0';
        for(int j = 0; j < count; ++j){
            decoded += data[i];
        }
    }
    return decoded;
}

void compressFileRLE(const std::string& inputFile, const std::string& outputFile){
    
    std::ifstream inFile(inputFile);
    if(!inFile){
        std::cerr << "Error: unable to open input file" << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if(!outFile){
        std::cerr << "Error: unable to open output file" << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    std::string compressed = rleCompress(content);
    outFile << compressed;

    inFile.close();
    outFile.close();

    std::cout << "File compressed successfully." << std::endl;
}

void decompressFileRLE(const std::string& inputFile, const std::string& outputFile){
    std::ifstream inFile(inputFile);
    if(!inFile){
        std::cerr << "Error: unable to open input file" << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if(!outFile){
        std::cerr << "Error: unable to open output file" << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    std::string decompressed = rleDecompress(content);
    outFile << decompressed;

    inFile.close();
    outFile.close();

    std::cout << "File decompressed successfully." << std::endl;
}


