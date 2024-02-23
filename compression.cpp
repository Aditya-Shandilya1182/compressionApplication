#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <cstdint>
#include <cstring>

//LZW Compression
std::vector<int> encodingLZW(const std::string& input) {
    std::unordered_map<std::string, int> table;
    for (int i = 0; i <= 255; i++) {
        std::string ch = "";
        ch += char(i);
        table[ch] = i;
    }

    std::string p = "", c = "";
    p += input[0];
    int code = 256;
    std::vector<int> output_code;

    for (int i = 0; i < input.length(); i++) {
        if (i != input.length() - 1)
            c += input[i + 1];
        if (table.find(p + c) != table.end()) {
            p = p + c;
        } else {
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }
        c = "";
    }
    output_code.push_back(table[p]);
    return output_code;
}

std::string decodingLZW(const std::vector<int>& input) {
    if (input.empty()) {
        return ""; // Return an empty string if the input vector is empty
    }

    std::unordered_map<int, std::string> table;
    for (int i = 0; i <= 255; i++) {
        std::string ch = "";
        ch += char(i);
        table[i] = ch;
    }

    int old = input[0], n;
    std::string s = table[old];
    std::string c = "";
    c += s[0];
    std::string decoded = s;
    int count = 256;
    for (int i = 0; i < input.size() - 1; i++) {
        n = input[i + 1];
        std::string entry;
        if (table.find(n) == table.end()) {
            entry = table[old] + c;
        } else {
            entry = table[n];
        }
        decoded += entry;
        c = entry[0];
        table[count++] = table[old] + c;
        old = n;
    }
    return decoded;
}


void compressFileLZW(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream fin(inputFile, std::ios::binary);
    std::ofstream fout(outputFile, std::ios::binary);

    if (!fin || !fout) {
        std::cerr << "Error: Failed to inputen files." << std::endl;
        return;
    }

    std::string inputContent((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    std::vector<int> compressed = encodingLZW(inputContent);
    
    fout.write(reinterpret_cast<const char*>(&compressed[0]), compressed.size() * sizeof(int));

    fin.close();
    fout.close();
}

void decompressFileLZW(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream fin(inputFile, std::ios::binary);
    std::ofstream fout(outputFile, std::ios::binary);

    if (!fin || !fout) {
        std::cerr << "Error: Failed to open files." << std::endl;
        return;
    }

    fin.seekg(0, std::ios::end);
    std::streampos fileSize = fin.tellg();
    fin.seekg(0, std::ios::beg);

    std::vector<int> compressed(fileSize / sizeof(int));
    fin.read(reinterpret_cast<char*>(&compressed[0]), fileSize); // Read compressed data

    std::string decoded = decodingLZW(compressed); // Decode compressed data

    fout.write(decoded.c_str(), decoded.size()); // Write decoded data to output file

    fin.close();
    fout.close();
}


//Run Length Encoding
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

bool alpha_or_space(const char c) {
    return std::isalpha(c) || c == ' ';
}

std::string rleDecompress(const std::string& data) {
    std::string decoded;
    size_t i = 0;
    while (i < data.size()) {
        while (alpha_or_space(data[i])) {
            decoded += data[i++];
            if (i == data.size()) 
                break;
        }

        int repeat = 0;
        while (std::isdigit(data[i])) {
            repeat = 10 * repeat + (data[i++] - '0');
            if (i == data.size()) 
                break;
        }

        if (i < data.size()) { 
            char char_to_unroll = data[i++];
            for (int j = 0; j < repeat; ++j)
                decoded += char_to_unroll;
        }
    }
    return decoded;
}

void compressFileRLE(const std::string& inputFile, const std::string& outputFile){
    
    std::ifstream inFile(inputFile);
    if(!inFile){
        std::cerr << "Error: unable to inputen input file" << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if(!outFile){
        std::cerr << "Error: unable to inputen output file" << std::endl;
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
        std::cerr << "Error: unable to inputen input file" << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if(!outFile){
        std::cerr << "Error: unable to inputen output file" << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    std::string decompressed = rleDecompress(content);
    outFile << decompressed;

    inFile.close();
    outFile.close();

    std::cout << "File decompressed successfully." << std::endl;
}

//Utility functions
void welcomeMessage(){
    std::cout << "Welcome to the compression program!" << std::endl;
}

void printUsage(){
    printf("Usage:");
    printf("Modes: \n");
    printf("0 - LZW Compression\n");
    printf("1 - LZW Decompression\n");
    printf("2 - Run Length Encoding Compression\n");
    printf("3 - Run Length Encoding Decompression\n");
}

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
