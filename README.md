# Data Compression Application
A C++ application to use "Run Length Encoding" and "Dictionary Coder(Huffman)" for data compression and decompression.
## Setup
Step 1 : git clone
Step 2 : cd
Step 3 : g++ -o compressor main.cpp compression.cpp
## Usage
Type ./compressor mode <input-filename> <output-filename>
There are four modes : 
Mode 0 : Compress the input file using LZW Compression Algorithm.
Mode 1 : Decompress the input file using LZW Decompression Algorithm.
Mode 2 : Compress the input file using Run Length Encoding.
Mode 3 : Decompress the input file using Run Length Encoding.
## Example:
Executing the file:
![alt text](firstExecution.png)
Mode 0 : 
![alt text](<mode 0.png>)
Mode 1 : 
![alt text](<mode 1.png>)
Mode 2 :
![alt text](<mode 2.png>)
Mode 3 : 
![alt text](<mode 3.png>)

