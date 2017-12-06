#include<unordered_map>
#include<string>
#include<fstream>
#include<iostream>

class lzw {
    public:
        void compress(std::ifstream& in, std::ofstream& out);
        void decompress(std::ifstream& in, std::ofstream& out);  
};
