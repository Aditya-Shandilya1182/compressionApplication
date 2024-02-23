#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

const int dictionarySize = 256;

std::vector<int> dictionaryCoderCompress(const std::string& data) {
  std::unordered_map<std::string, int> dictionary;
  std::vector<int> compressed;
  
  for (int i = 0; i < dictionarySize; ++i) {
    dictionary[std::string(1, i)] = i + 1;
  }

  std::string current;
  for (char c : data) {
    std::string nextSequence = current + c;
    if (dictionary.find(nextSequence) != dictionary.end()) {
      current = nextSequence;
    } else {
      compressed.push_back(dictionary[current]);
      dictionary[nextSequence] = dictionary.size() + 1;
      current = c;
    }
  }
  if (!current.empty()) {
    compressed.push_back(dictionary[current]);
  }
  return compressed;
}

std::string dictionaryCoderDecompress(const std::vector<int>& data){
  std::unordered_map<int, std::string> dictionary;
  std::string decompressed;

  for(int i = 0; i < dictionarySize; ++i){
    dictionary[i + 1] = std::string(1, i);
  }

  int prev = data[0];
  decompressed = dictionary[prev];
  for(size_t i = 1; i < data.size(); ++i){
    int code = data[i];
    std::string entry;
    if(dictionary.find(code) != dictionary.end()){
      entry = dictionary[code];
    } else if (code == dictionary.size() + 1){
      entry = dictionary[prev] + dictionary[prev][0];
    } else {
            throw std::logic_error("Compression Error");
    }
    decompressed += entry;
    dictionary[dictionary.size() + 1] = dictionary[prev] + entry[0];
    prev = code;
  }
  return decompressed;
}

void compressFileDictionaryCoder(const std::string& inputFile, const std::string& outputFile){
  
  std::ifstream inFile(inputFile, std::ios::binary);
  if(!inFile){
    std::cerr << "Error: unable to open input file" << std::endl;
    return;
  }

  std::string data((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

  inFile.close();

  std::vector<int> compressedData = dictionaryCoderCompress(data);

  std::ofstream outFile(outputFile, std::ios::binary);
  if(!outFile){
    std::cerr << "Error: unable to open output file" << std::endl;
    return;
  }

  size_t dataSize = compressedData.size();
  outFile.write(reinterpret_cast<const char*>(&dataSize), sizeof(dataSize));

  outFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size() * sizeof(int));

  outFile.close();

  std::cout << "File compressed successfully." << std::endl;

}

void decompressFileDictionaryCoder(const std::string& inputFile, const std::string& outputFile){
  std::ifstream inFile(inputFile, std::ios::binary);
  if(!inFile){
    std::cerr << "Error: unable to open input file" << std::endl;
    return;
  }

  size_t dataSize;
  inFile.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

  std::vector<int> compressedData(dataSize);
  inFile.read(reinterpret_cast<char*>(compressedData.data()), dataSize * sizeof(int));

  inFile.close();

  std::string decompressedData = dictionaryCoderDecompress(compressedData);

  std::ofstream outFile(outputFile, std::ios::binary);
  if(!outFile){
    std::cerr << "Error: unable to open output file" << std::endl;
    return;
  }

  outFile.write(decompressedData.c_str(), decompressedData.size());

  outFile.close();

  std::cout << "File decompressed successfully." << std::endl;
}

