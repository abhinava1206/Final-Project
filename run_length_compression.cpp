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

int main()
{
    ifstream in;
    ofstream out;
    in.open("test.txt");
    out.open("RLE_compressed.txt");
    string input, output;
    stringstream buffer;

    buffer << in.rdbuf();
    input = buffer.str();
    output = run_length_encode(input);
    out << output;
    ofstream out2; ifstream in2;
    in2.open("RLE_compressed.txt", ios::in);
    std::string input2( (std::istreambuf_iterator<char>(in2) ),
                       (std::istreambuf_iterator<char>()    ) );
    string output2 = decompress_run_length(input2);
    out2.open("RLE_Decompressed.txt");
    out2 << output2;
    in.close();
    out.close();
    out2.close();
}
