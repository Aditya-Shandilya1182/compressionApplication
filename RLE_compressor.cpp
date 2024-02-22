#include <string>
#include <iostream>

using namespace std;

string rleEncode(const string& data){
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

string rleDecode(const string& data){
    string decoded;
    for(size_t i = 0; i < data.size(); i += 2){
        int count = data[i + 1] - '0';
        for(int j = 0; j < count; ++j){
            decoded += data[i];
        }
    }
    return decoded;
}

int main(){
    string data = "aaaabbbbbbccccc";
    string output = rleEncode(data);
    string decoded = rleDecode(output);
    cout << output << std::endl;
    cout << decoded << std::endl;
    return 0;
}