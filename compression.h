#ifndef COMPRESS_H
#define COMPRESS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <fstream>

std::vector<int> encodingLZW(const std::string& input);
std::string decodingLZW(const std::vector<int>& input);
void compressFileLZW(const std::string& inputFile, const std::string& outputFile);
void decompressFileLZW(const std::string& inputFile, const std::string& outputFile);
std::string rleCompress(const std::string& data);
bool alpha_or_space(const char c);
std::string rleDecompress(const std::string& data);
void compressFileRLE(const std::string& inputFile, const std::string& outputFile);
void decompressFileRLE(const std::string& inputFile, const std::string& outputFile);
void welcomeMessage();
void printUsage();
double calculateFileSize(const std::string& fileName);
double compressionRatio(const std::string& compressedFileName, const std::string& originalFileName);

#endif