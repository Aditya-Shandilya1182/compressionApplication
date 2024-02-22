#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string rleCompress(const string& data){
    string encoded;
    int count = 1;
    for(size_t i = 1; i < data.size(); ++i){
        if(data[i] == data[i - 1]){
            ++count;
        } else {
            encoded += data[i - 1] + to_string(count);
            count = 1;
        }
    }
    encoded += data[data.size() - 1] + to_string(count);
    return encoded;
}

string rleDecompress(const string& data){
    string decoded;
    for(size_t i = 0; i < data.size(); i += 2){
        int count = data[i + 1] - '0';
        for(int j = 0; j < count; ++j){
            decoded += data[i];
        }
    }
    return decoded;
}

void compressFileRLE(const string& inputFile, const string& outputFile){
    
    ifstream inFile(inputFile);
    if(!inFile){
        cerr << "Error: unable to open input file" << endl;
        return;
    }

    ofstream outFile(outputFile);
    if(!outFile){
        cerr << "Error: unable to open output file" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    string compressed = rleCompress(content);
    outFile << compressed;

    inFile.close();
    outFile.close();

    cout << "File compressed successfully." << endl;
}

void decompressFileRLE(const string& inputFile, const string& outputFile){
    ifstream inFile(inputFile);
    if(!inFile){
        cerr << "Error: unable to open input file" << endl;
        return;
    }

    ofstream outFile(outputFile);
    if(!outFile){
        cerr << "Error: unable to open output file" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    string decompressed = rleDecompress(content);
    outFile << decompressed;

    inFile.close();
    outFile.close();

    cout << "File decompressed successfully." << endl;
}


