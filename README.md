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
## Example:
Executing the file:<br>
<a  target="blank"><img align="center" src="\images\firstExecution.png" width="800" height="70" /></a><br>
Mode 0 : <br>
<a  target="blank"><img align="center" src="\images\mode0.png" width="400" height="100" /></a><br>
Mode 1 : <br>
<a  target="blank"><img align="center" src="\images\mode1.png" width="600" height="70" /></a><br>
Mode 2 :<br>
<a  target="blank"><img align="center" src="\images\mode2.png" width="400" height="100" /></a><br>
Mode 3 : <br>
<a  target="blank"><img align="center" src="\images\mode3.png" width="600" height="70" /></a><br>

## For Test:
"input.txt" file is provided to perform tests. For storing compressed data "compressed.txt" is provided and for storing decompressed data "decompressed.txt" is provided.
