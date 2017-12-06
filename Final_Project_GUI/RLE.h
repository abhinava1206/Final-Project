#include<iostream>
#include<string>
#include<cassert>
#include <climits>
#include <fstream>
#include <sstream>

class rle {
    public:
        void compress(std::ifstream& in, std::ofstream& out);
        void decompress(std::ifstream& in, std::ofstream& out);
};
