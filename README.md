# Data Compression Application
A C++ application to use "Run Length Encoding" and "Dictionary Coder(Huffman)" for data compression and decompression.<br>
## Setup
Step 1 : ```git clone https://github.com/Aditya-Shandilya1182/compression_task.git```<br>
Step 2 : ```cd compression_task```<br>
Step 3 : ```g++ -o compressor main.cpp compression.cpp```<br>
## Usage
Type ```./compressor mode input-filename output-filename``` <br>
There are four modes : <br>
Mode 0 : Compress the input file using LZW Compression Algorithm.<br>
Mode 1 : Decompress the input file using LZW Decompression Algorithm.<br>
Mode 2 : Compress the input file using Run Length Encoding.<br>
Mode 3 : Decompress the input file using Run Length Encoding.<br>
