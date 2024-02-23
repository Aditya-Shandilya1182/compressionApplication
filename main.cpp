#include "compression.h"

int main(int argc, char* argv[]){
    welcomeMessage();
    //printUsage();
    int mode = atoi(argv[1]);
    std::string input = argv[2];
    std::string outputFileName = argv[3];
    double inputFileSize = calculateFileSize(input);

    switch(mode) {
        case 0:
        {
            auto start = std::chrono::high_resolution_clock::now();

            compressFileLZW(input, outputFileName);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            double outputFileSize = calculateFileSize(outputFileName);
            double ratio = compressionRatio(outputFileName, input);

            std::cout << "Original file size: " << inputFileSize << "bytes" << std::endl;
            std::cout << "Compressed file size: " << outputFileSize << "bytes" << std::endl;
            std::cout << "Compression ratio: " << ratio << std::endl;
            std::cout << "Compression time: " << duration.count() << "ms" << std::endl;

            break;
        }
        case 1:
        {
            auto start = std::chrono::high_resolution_clock::now();

            decompressFileLZW(input, outputFileName);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            std::cout << "Decompression time: " << duration.count() << "ms" << std::endl;

            break;
        }
        case 2:
        {
            auto start = std::chrono::high_resolution_clock::now();

            compressFileRLE(input, outputFileName);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            double outputFileSize = calculateFileSize(outputFileName);
            double ratio = compressionRatio(outputFileName, input);

            std::cout << "Original file size: " << inputFileSize << "bytes" << std::endl;
            std::cout << "Compressed file size: " << outputFileSize << "bytes" << std::endl;
            std::cout << "Compression ratio: " << ratio << std::endl;
            std::cout << "Compression time: " << duration.count() << "ms" << std::endl;

            break;
        }
        case 3:
        {
            auto start = std::chrono::high_resolution_clock::now();

            decompressFileRLE(input, outputFileName);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            std::cout << "Decompression time: " << duration.count() << "ms" << std::endl;

            break;
        }
        default:
        {
            printf("Error: Invalid mode\n");
            printUsage();
            return 1;
        }
    }
    return 0;
}