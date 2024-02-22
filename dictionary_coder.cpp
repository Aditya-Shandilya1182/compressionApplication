#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int dictionarySize = 256;

vector<int> dictionaryCoderCompress(const string& data) {
  unordered_map<string, int> dictionary;
  vector<int> compressed;
  
  for (int i = 0; i < dictionarySize; ++i) {
    dictionary[string(1, i)] = i + 1;
  }

  string current;
  for (char c : data) {
    string nextSequence = current + c;
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

string dictionaryCoderDecompress(const vector<int>& data){
  unordered_map<int, string> dictionary;
  string decompressed;

  for(int i = 0; i < dictionarySize; ++i){
    dictionary[i + 1] = string(1, i);
  }

  int prev = data[0];
  decompressed = dictionary[prev];
  for(size_t i = 1; i < data.size(); ++i){
    int code = data[i];
    string entry;
    if(dictionary.find(code) != dictionary.end()){
      entry = dictionary[code];
    } else if (code == dictionary.size() + 1){
      entry = dictionary[prev] + dictionary[prev][0];
    } else {
            throw logic_error("Compression Error");
    }
    decompressed += entry;
    dictionary[dictionary.size() + 1] = dictionary[prev] + entry[0];
    prev = code;
  }
  return decompressed;
}

void compressFileDictionaryCoder(const string& inputFile, const string& outputFile){
  
  ifstream inFile(inputFile, ios::binary);
  if(!inFile){
    cerr << "Error: unable to open input file" << endl;
    return;
  }

  string data((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

  inFile.close();

  vector<int> compressedData = dictionaryCoderCompress(data);

  ofstream outFile(outputFile, ios::binary);
  if(!outFile){
    cerr << "Error: unable to open output file" << endl;
    return;
  }

  size_t dataSize = compressedData.size();
  outFile.write(reinterpret_cast<const char*>(&dataSize), sizeof(dataSize));

  outFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size() * sizeof(int));

  outFile.close();

  cout << "File compressed successfully." << endl;

}

void decompressFileDictionaryCoder(const string& inputFile, const string& outputFile){
  ifstream inFile(inputFile, ios::binary);
  if(!inFile){
    cerr << "Error: unable to open input file" << endl;
    return;
  }

  size_t dataSize;
  inFile.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

  vector<int> compressedData(dataSize);
  inFile.read(reinterpret_cast<char*>(compressedData.data()), dataSize * sizeof(int));

  inFile.close();

  string decompressedData = dictionaryCoderDecompress(compressedData);

  ofstream outFile(outputFile, ios::binary);
  if(!outFile){
    cerr << "Error: unable to open output file" << endl;
    return;
  }

  outFile.write(decompressedData.c_str(), decompressedData.size());

  outFile.close();

  cout << "File decompressed successfully." << endl;
}

