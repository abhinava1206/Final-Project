#include<iostream>
#include<string>
#include<cassert>
#include <climits>
#include <fstream>
#include <sstream>
using namespace std;

string run_length_encode(string s)
{
    if (s == "")
    {
        return s;
    }
    string encoded_string = "";
    char i = s[0];
    unsigned char count = 0;
    encoded_string += i;
    while (i == s[0] && count < UCHAR_MAX)
    {
        s.erase(0,1);
        count ++;
    }
    encoded_string += count;
    return encoded_string + run_length_encode(s);
}

string decompress_run_length(string s) {
    if (s == "")
    {
        return s;
    }
    char i = s[0];
    unsigned char j = s[1];
    string decompressed = "";
    for (int k = j; k != 0; k--)
    {
        decompressed += i;
    }
    s.erase(0,2);
    return decompressed + decompress_run_length(s);

}

string generateString() {
    string s;
    long length = rand() % 10;
    while(length--) {
        char rand_char = (rand() % 127) + 1;
        long number_of_char = (rand() % 512) + 1;
        s.append(number_of_char, rand_char);
    }
    return s;
}

void RLE::compress (std::ifstream& in, std::ofstream& out)
{
    string output;
    std::string input( (std::istreambuf_iterator<char>(in) ),
                       (std::istreambuf_iterator<char>()    ) );
    cout << input << endl;
    output = run_length_encode(input);
    out << output;
}

void RLE::decompress (ifstream& in, ofstream& out)
{
    string output2;
    std::string input2( (std::istreambuf_iterator<char>(in) ),
                       (std::istreambuf_iterator<char>()    ) );
    cout << input2 << endl;
    output2 = decompress_run_length(input2);
    out << output2;
}


