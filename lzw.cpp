#include<unordered_map>
#include<string>
#include<fstream>
#include<iostream>

using namespace std; 
void compress( ifstream& in, ofstream& out )
{
  std::unordered_map<std::string,unsigned int> codes;
  for ( unsigned int i = 0 ; i < 256 ; i++ )
    codes[std::string(1,(char)i)] = i; // makes the standard dictionary with ASCII values

  unsigned int next_index = 257;
  std::string current_string;
  char c;
  while (!in.eof()) { // reads from input file 
    
    in.read(&c, sizeof(char));
  
    current_string = current_string + c; // appends the character "c" to the current pattern
    if ( codes.find(current_string) == codes.end() ) { // if the pattern has not been found in the dictionary
      codes[ current_string ] = next_index++; 
      current_string.erase(current_string.size()-1);
      out.write((const char*) (&(codes[current_string])), sizeof(unsigned int));
      current_string = c;
    }
  }
  out.write((const char*) (&(codes[current_string])), sizeof(unsigned int));
}

void decompress( ifstream& in, ofstream& out )
{
  std::unordered_map<unsigned int,std::string> strings;
  for ( int unsigned i = 0 ; i < 256 ; i++ )
    strings[i] = std::string(1,i); // again we construct a standard ASCII dictionary

  std::string previous_string;
  std::string current_string;

  char c;
  unsigned int code;
  unsigned int next_index = 257;

  while (!in.eof()) {
    
    in.read((char*)&code, sizeof(unsigned int)); 
    if ( strings.find( code ) == strings.end() )  // has the opposite effect as compression
      strings[ code ] = previous_string + previous_string[0];
    out << strings[code];
    if ( previous_string.size() )
      strings[next_index++] = previous_string + strings[code][0];
    previous_string = strings[code];
    current_string = "";
  }
}

int main()
{
  ifstream fp_in;   // sample main I made for debugging
  ofstream fp_out;
  fp_in.open("test.txt", ios::in);    
  fp_out.open("file3.txt", ios::out);
  compress(fp_in, fp_out);
  fp_in.close();   
  fp_out.close();

  ifstream fp_in1;  
  ofstream fp_out1;
  fp_in1.open("file3.txt", ios::in);   
  fp_out1.open("file4.txt", ios::out);
  decompress(fp_in1, fp_out1);
  fp_in1.close();   
  fp_out1.close();
}





