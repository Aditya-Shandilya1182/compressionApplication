#ifndef COMPRESS_H
#define COMPRESS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
std::vector<int> dictionaryCoderCompress(const std::string& data);
std::string dictionaryCoderDecompress(const std::vector<int>& data);
void compressFileDictionaryCoder(const std::string& inputFile, const std::string& outputFile);
void decompressFileDictionaryCoder(const std::string& inputFile, const std::string& outputFile);
std::string rleCompress(const std::string& data);
std::string rleDecompress(const std::string& data);
void compressFileRLE(const std::string& inputFile, const std::string& outputFile);
void decompressFileRLE(const std::string& inputFile, const std::string& outputFile);
double calculateFileSize(const std::string& fileName);
double compressionRatio(const std::string& compressedFileName, const std::string& originalFileName);
#endif