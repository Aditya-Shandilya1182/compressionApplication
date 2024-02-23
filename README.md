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
<a  target="blank"><img align="center" src="\images\firstExecution.png" height="100" /></a>
Mode 0 : 
<a  target="blank"><img align="center" src="\images\mode0.png" height="100" /></a>
Mode 1 : 
<a  target="blank"><img align="center" src="\images\mode1.png" height="100" /></a>
Mode 2 :
<a  target="blank"><img align="center" src="\images\mode2.png" height="100" /></a>
Mode 3 : 
<a  target="blank"><img align="center" src="\images\mode3.png" height="100" /></a>

